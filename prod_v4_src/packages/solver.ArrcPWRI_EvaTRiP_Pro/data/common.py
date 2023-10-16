import logging

import iric
import numpy as np

read_fid = None
write_fid = None
step = None
time = None

roughness = None

ave_time_start = None
ave_time_end = None

result_elevation_name = None
result_depth_name = None
result_water_surface_elevation_name = None
result_velocityX_name = None
result_velocityY_name = None

result_elevation = None
result_depth = None
result_water_surface_elevation = None
result_velocityX = None
result_velocityY = None
result_velocity = None

result_depth_avg = None
result_depth_max = None
result_velocity_avg = None
result_velocity_max = None

average_target_count = 0


def read_roughness():
    global roughness

    # try to read roughness_cell
    try:
        isize, jsize = iric.cg_iRIC_Read_Grid2d_Str_Size(read_fid)
        roughness_cell = iric.cg_iRIC_Read_Grid_Real_Cell(read_fid, 'roughness_cell')
        roughness_cell = roughness_cell.reshape((isize - 1, jsize - 1), order='F')

        # calculate roughness as max of roughness_cell
        roughness = np.zeros((isize, jsize), dtype=np.float32, order='F')
        # corners
        roughness[0, 0] = roughness_cell[0, 0]
        roughness[-1, 0] = roughness_cell[-1, 0]
        roughness[0, -1] = roughness_cell[0, -1]
        roughness[-1, -1] = roughness_cell[-1, -1]
        # edges
        roughness[1:-1, 0] = np.maximum(roughness_cell[:-1, 0], roughness_cell[1:, 0])
        roughness[1:-1, -1] = np.maximum(roughness_cell[:-1, -1], roughness_cell[1:, -1])
        roughness[0, 1:-1] = np.maximum(roughness_cell[0, :-1], roughness_cell[0, 1:])
        roughness[-1, 1:-1] = np.maximum(roughness_cell[-1, :-1], roughness_cell[-1, 1:])
        # internal
        roughness[1:-1, 1:-1] = max4(
            roughness_cell[:-1, :-1],
            roughness_cell[1:, :-1],
            roughness_cell[:-1, 1:],
            roughness_cell[1:, 1:],
        )
        roughness = roughness.flatten(order='F')
        logging.debug('roughness loaded from \'roughness_cell\'')
        return
    except:
        pass

    # try to read roughness defined at node, from 'roughness', 'Roughness', 'initial_cd'
    names = ['Roughness', 'roughness', 'initial_cd']
    for name in names:
        try:
            roughness = iric.cg_iRIC_Read_Grid_Real_Node(read_fid, name)
            logging.debug('roughness loaded from \'{}\''.format(name))
            return
        except:
            pass

    raise RuntimeError('Failed to read roughness value')


def max4(v1: np.array, v2: np.array, v3: np.array, v4: np.array):
    return np.maximum(v1, np.maximum(v2, np.maximum(v3, v4)))


def read_result():
    global result_elevation
    global result_depth
    global result_water_surface_elevation
    global result_velocityX
    global result_velocityY
    global result_velocity
    global result_depth_avg
    global result_depth_max
    global result_velocity_avg
    global result_velocity_max
    global average_target_count

    result_elevation = iric.cg_iRIC_Read_Sol_Node_Real(read_fid, step, result_elevation_name)
    result_depth = iric.cg_iRIC_Read_Sol_Node_Real(read_fid, step, result_depth_name)
    result_water_surface_elevation = iric.cg_iRIC_Read_Sol_Node_Real(
        read_fid, step, result_water_surface_elevation_name)
    result_velocityX = iric.cg_iRIC_Read_Sol_Node_Real(read_fid, step, result_velocityX_name)
    result_velocityY = iric.cg_iRIC_Read_Sol_Node_Real(read_fid, step, result_velocityY_name)

    vx = result_velocityX
    vy = result_velocityY
    result_velocity = np.sqrt(vx * vx + vy * vy)

    if result_depth_avg is None:
        result_depth_avg = np.zeros(result_depth.shape, dtype=np.float64)

    if result_depth_max is None:
        result_depth_max = np.zeros(result_depth.shape, dtype=np.float64)
        result_depth_max[:] = np.finfo(np.float64).min

    if result_velocity_avg is None:
        result_velocity_avg = np.zeros(result_velocity.shape, dtype=np.float64)

    if result_velocity_max is None:
        result_velocity_max = np.zeros(result_velocity.shape, dtype=np.float64)
        result_velocity_max[:] = np.finfo(np.float64).min

    if (ave_time_start < 0 or time >= ave_time_start) and (ave_time_end < 0 or time <= ave_time_end):
        result_depth_avg += result_depth
        result_depth_max = np.maximum(result_depth_max, result_depth)
        result_velocity_avg += result_velocity
        result_velocity_max = np.maximum(result_velocity_max, result_velocity)
        average_target_count += 1


def finalize_result():
    global result_depth_avg
    global result_velocity_avg
    if average_target_count == 0:
        return

    result_depth_avg /= average_target_count
    result_velocity_avg /= average_target_count


def write_result():
    iric.cg_iRIC_Write_Sol_Node_Real(write_fid, result_elevation_name, result_elevation)
    iric.cg_iRIC_Write_Sol_Node_Real(write_fid, result_depth_name, result_depth)
    iric.cg_iRIC_Write_Sol_Node_Real(write_fid, result_water_surface_elevation_name, result_water_surface_elevation)
    iric.cg_iRIC_Write_Sol_Node_Real(write_fid, result_velocityX_name, result_velocityX)
    iric.cg_iRIC_Write_Sol_Node_Real(write_fid, result_velocityY_name, result_velocityY)


def write_dummy_result():
    dummy = np.zeros(result_elevation.shape, dtype=np.float64)
    iric.cg_iRIC_Write_Sol_Node_Real(write_fid, result_elevation_name, dummy)
    iric.cg_iRIC_Write_Sol_Node_Real(write_fid, result_depth_name, dummy)
    iric.cg_iRIC_Write_Sol_Node_Real(write_fid, result_water_surface_elevation_name, dummy)
    iric.cg_iRIC_Write_Sol_Node_Real(write_fid, result_velocityX_name, dummy)
    iric.cg_iRIC_Write_Sol_Node_Real(write_fid, result_velocityY_name, dummy)
