import logging
import sys

import iric

import classify
import common
import compose
import response
import riffle_pool
import statistic

f_riffle_pool = False
f_statistics = False
f_classification = False
f_composition = False
f_response = False

def evatrip_init(cgnsName):
    # open CGNS file to write
    common.write_fid = iric.cg_iRIC_Open(cgnsName, iric.IRIC_MODE_MODIFY)

    _logging_init()

    # open CGNS file to read
    read_cgnsName = iric.cg_iRIC_Read_String(common.write_fid, 'inputfile')
    logging.debug('Opening {0}'.format(read_cgnsName))

    common.read_fid = iric.cg_iRIC_Open(read_cgnsName, iric.IRIC_MODE_READ)

    _set_result_names()
    logging.debug('_set_result_names() finished')
    _load_functions()
    logging.debug('_load_functions() finished')

    # initialize modules
    if f_riffle_pool:
        riffle_pool.init()
        logging.debug('riffle_pool.init() finished')

    if f_statistics:
        statistic.init()
        logging.debug('statistic.init() finished')

    if f_classification:
        classify.init()
        logging.debug('classify.init() finished')
    
    if f_composition:
        compose.init()
        logging.debug('compose.init() finished')

    if f_response:
        response.init()
        logging.debug('response.init() finished')

def evatrip_process_steps():
    result_steps = iric.cg_iRIC_Read_Sol_Count(common.read_fid)
    for i in range(result_steps):
        # copy t value
        common.step = i + 1

        t = iric.cg_iRIC_Read_Sol_Time(common.read_fid, common.step)
        iric.cg_iRIC_Write_Sol_Time(common.write_fid, t)
        common.time = t

        # process data for step
        common.read_result()

        if f_riffle_pool:
            riffle_pool.process_step()
            logging.debug('riffle_pool.process_step() finished')

        if f_statistics:
            statistic.process_step()
            logging.debug('statistic.process_step() finished')
        
        if f_classification:
            classify.process_step()
            logging.debug('classify.process_step() finished')
        
        if f_composition:
            compose.process_step()
            logging.debug('compose.process_step() finished')
        
        if f_response:
            response.process_step()
            logging.debug('response.process_step() finished')

        logging.info('Processing data at t = {0} finished'.format(t))

def evatrip_finalize():
    _output_final_time()
    logging.debug('_output_final_time() finished')

    if f_riffle_pool:
        riffle_pool.finalize()
        logging.debug('riffle_pool.finalize() finished')
    
    if f_statistics:
        statistic.finalize()
        logging.debug('statistic.finalize() finished')
    
    if f_classification:
        classify.finalize()
        logging.debug('classify.finalize() finished')
    
    if f_composition:
        compose.finalize()
        logging.debug('compose.finalize() finished')
    
    if f_response:
        response.finalize()
        logging.debug('response.finalize() finished')

def _output_final_time():
    count = iric.cg_iRIC_Read_Sol_Count(common.read_fid)
    lasttime = iric.cg_iRIC_Read_Sol_Time(common.read_fid, count)
    t = 1
    while t <= lasttime:
        t *= 10

    iric.cg_iRIC_Write_Sol_Time(common.write_fid, t)

def main(cgnsName):
    evatrip_init(cgnsName)
    evatrip_process_steps()
    evatrip_finalize()

def _logging_init():
    log_level = iric.cg_iRIC_Read_Integer(common.write_fid, 'log_level')
    level = logging.INFO
    if log_level == 1:
        level = logging.DEBUG

    logging.basicConfig(format='%(levelname)s: %(message)s', level=level)

    logging.debug('Logging configuration setup.')

def _set_result_names():
    common.result_depth_name = iric.cg_iRIC_Read_String(common.write_fid, 'result_depth')
    logging.debug('depth value read from {0}'.format(common.result_depth_name))
    common.result_water_surface_elevation_name = iric.cg_iRIC_Read_String(common.write_fid, 'result_wse')
    logging.debug('water surface elevation value read from {0}'.format(common.result_water_surface_elevation_name))
    common.result_velocityX_name = iric.cg_iRIC_Read_String(common.write_fid, 'result_vx')
    logging.debug('velocity x value read from {0}'.format(common.result_velocityX_name))
    common.result_velocityY_name = iric.cg_iRIC_Read_String(common.write_fid, 'result_vy')
    logging.debug('velocity y value read from {0}'.format(common.result_velocityY_name))

def _load_functions():
    global f_riffle_pool
    global f_statistics
    global f_classification
    global f_composition
    global f_response

    f_riffle_pool = iric.cg_iRIC_Read_Integer(common.write_fid, 'f_riffle_pool')
    f_statistics = iric.cg_iRIC_Read_Integer(common.write_fid, 'f_statistics')
    f_classification = iric.cg_iRIC_Read_Integer(common.write_fid, 'f_classification')
    f_composition = iric.cg_iRIC_Read_Integer(common.write_fid, 'f_composition')
    f_response = iric.cg_iRIC_Read_Integer(common.write_fid, 'f_response')

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("Error: CGNS file name not specified.")
        exit()

    cgnsName = sys.argv[1]
    main(cgnsName)
