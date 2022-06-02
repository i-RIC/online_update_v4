import logging
import numpy as np
import iric

import common

OUTPUT_FROUDE_NAME = 'COMP_Froude'
OUTPUT_DIAMETER_NAME = 'COMP_CriticalDiameter'
OUTPUT_STRENGTH_NAME = 'COMP_FluidForce'
OUTPUT_MANUAL_NAME = 'COMP_Manual'

DEPTH_MIN = 1.0e-8
G = 9.8

v1_name = None
v2_name = None

result_v1 = None
result_v2 = None

output_froude = None
output_diameter = None
output_strength = None
output_manual = None

n = None
roughness = None

manual_func = None

def init():
    global v1_name, v2_name
    global output_froude, output_diameter, output_strength
    global output_manual
    global n
    global manual_func

    output_froude = iric.cg_iRIC_Read_Integer(common.write_fid, 'comp_output_froude')
    logging.debug('output_froude = {0}'.format(output_froude))
    output_diameter = iric.cg_iRIC_Read_Integer(common.write_fid, 'comp_output_diameter')
    logging.debug('output_diameter = {0}'.format(output_diameter))
    output_strength = iric.cg_iRIC_Read_Integer(common.write_fid, 'comp_output_strength')
    logging.debug('output_strength = {0}'.format(output_strength))
    output_manual = iric.cg_iRIC_Read_Integer(common.write_fid, 'comp_output_manual')
    logging.debug('output_manual = {0}'.format(output_manual))
    n = iric.cg_iRIC_Read_Real(common.write_fid, 'comp_n')
    logging.debug('n = {0}'.format(n))

    if output_diameter:
        _setup_roughness()

    if output_manual:
        v1_name = iric.cg_iRIC_Read_String(common.write_fid, 'comp_v1')
        logging.debug('v1_name = {0}'.format(v1_name))
        v2_name = iric.cg_iRIC_Read_String(common.write_fid, 'comp_v2')
        logging.debug('v2_name = {0}'.format(v2_name))

        manual_def = iric.cg_iRIC_Read_String(common.write_fid, 'comp_manual')
        logging.debug('manual_def = {0}'.format(manual_def))

        def_str = 'def f(depth, wse, vx, vy, val1, val2, v):\n'
        for line in manual_def.split('\n'):
            def_str += '    ' + line + '\n'
        def_str += 'tmpf = f'
        d = {}
        exec(def_str, globals(), d)
        manual_func = d['f']

def process_step():
    global result_v1, result_v2
    if output_manual:
        if v1_name != '':
            result_v1 = iric.cg_iRIC_Read_Sol_Node_Real(common.read_fid, common.step, v1_name)

        if v2_name != '':
            result_v2 = iric.cg_iRIC_Read_Sol_Node_Real(common.read_fid, common.step, v2_name)

    if output_froude:
        _process_step_froude()

    if output_diameter:
        _process_step_diameter()
    
    if output_strength:
        _process_step_strength()
    
    if output_manual:
        _process_step_manual()    

def finalize():
    if output_froude:
        _output_dummy(OUTPUT_FROUDE_NAME)

    if output_diameter:
        _output_dummy(OUTPUT_DIAMETER_NAME)
    
    if output_strength:
        _output_dummy(OUTPUT_STRENGTH_NAME)
    
    if output_manual:
        _output_dummy(OUTPUT_MANUAL_NAME)

def _process_step_froude():
    depth = np.where(common.result_depth > DEPTH_MIN, common.result_depth, DEPTH_MIN)
    fr = common.result_velocity / np.sqrt(depth * G)
    iric.cg_iRIC_Write_Sol_Node_Real(common.write_fid, OUTPUT_FROUDE_NAME, fr)

def _process_step_diameter():
    global roughness
    if roughness is None:
        roughness = np.zeros(common.result_depth.shape)
        roughness[:] = n

    depth = np.where(common.result_depth > DEPTH_MIN, common.result_depth, DEPTH_MIN)
    I = roughness * roughness * common.result_velocity / (np.power(depth, 4/3))
    # u2 [cm^2/s^2]
    u2 = G * depth * I * 10000 # u* = sqrt(ghI)
    d = np.zeros(u2.shape)

    # d [mm]
    d += np.where(u2 < 1.469, u2 / 226.0 * 10, 0)
    d += np.where((1.469 <= u2) & (u2 < 3.1075), np.power(u2 / 8.41, 32/11) * 10, 0)
    d += np.where((3.1075 <= u2) & (u2 < 6.49), u2 / 55.0 * 10, 0)
    d += np.where((6.49 <= u2) & (u2 < 24.5127), np.power(u2 / 134.6, 22/31) * 10, 0)
    d += np.where(24.5127 <= u2, u2 / 80.9 * 10, 0)
    iric.cg_iRIC_Write_Sol_Node_Real(common.write_fid, OUTPUT_DIAMETER_NAME, d)

def _process_step_strength():
    h = common.result_depth
    v = common.result_velocity

    strength = h * v * v
    iric.cg_iRIC_Write_Sol_Node_Real(common.write_fid, OUTPUT_STRENGTH_NAME, strength)


def _process_step_manual():
    depth = common.result_depth
    wse = common.result_water_surface_elevation
    vx = common.result_velocityX
    vy = common.result_velocityY
    v1 = result_v1
    v2 = result_v2
    v = np.sqrt(vx * vx + vy * vy)

    result = manual_func(depth, wse, vx, vy, v1, v2, v)
    iric.cg_iRIC_Write_Sol_Node_Real(common.write_fid, OUTPUT_MANUAL_NAME, result)

def _output_dummy(name):
    zeros = np.zeros(common.result_depth.shape)
    iric.cg_iRIC_Write_Sol_Node_Real(common.write_fid, name, zeros)

def _setup_roughness():
    global roughness
    structured = False
    try:
        # for structured grid
        isize, jsize = iric.cg_iRIC_Read_Grid2d_Str_Size(common.read_fid)
        structured = True
    except:
        pass

    tmp_roughness = None
    if structured:
        # structured grid
        try:
            # try roughnes_cell
            roughness_cell = iric.cg_iRIC_Read_Grid_Real_Cell(common.read_fid, 'roughness_cell')
            roughness_cell = roughness_cell.reshape((jsize - 1, isize - 1))

            r1 = _build_nan(isize, jsize)
            r1[:-1,:-1] = roughness_cell[:,:]
            r1 = r1.reshape((r1.size))

            r2 = _build_nan(isize, jsize)
            r2[1:, :-1] = roughness_cell[:,:]
            r2 = r2.reshape((r2.size))

            r3 = _build_nan(isize, jsize)
            r3[:-1, 1:] = roughness_cell[:,:]
            r3 = r3.reshape((r3.size))

            r4 = _build_nan(isize, jsize)
            r4[1:, 1:] = roughness_cell[:,:]
            r4 = r4.reshape((r4.size))

            r = np.stack([r1, r2, r3, r4])
            roughness = np.nanmax(r, axis=0)
            logging.info('Manning\'s roughness read from roughness_cell.')
            return
        except:
            pass
    try:
        # try Roughness
        roughness = iric.cg_iRIC_Read_Grid_Real_Node(common.read_fid, 'Roughness')
        logging.info('Manning\'s roughness read from Roughness.')
        return
    except:
        pass

    try:
        # try roughness
        roughness = iric.cg_iRIC_Read_Grid_Real_Node(common.read_fid, 'roughness')
        logging.info('Manning\'s roughness read from roughness.')
        return
    except:
        pass

    try:
        # try initial_cd (for SToRM)
        roughness = iric.cg_iRIC_Read_Grid_Real_Node(common.read_fid, 'initial_cd')
        logging.info('Manning\'s roughness read from initial_cd.')
        return
    except:
        pass

    # use roughness read from calculation condition
    logging.info('Manning\'s roughness value not found in input CGNS file, so calculation condition value {0} used.'.format(n))

def _build_nan(isize, jsize):
    r = np.zeros((jsize, isize))
    r[:,:] = np.nan
    return r
