import math
import logging
import numpy as np
import iric

import common

DEPTH_MIN = 1.0e-10

OUTPUT_DEP_ESTIMATE = 'pla_DepEstimate'
OUTPUT_VEL_DEP_ESTIMATE = 'pla_VelDepEstimate'
OUTPUT_WOI_ESTIMATE = 'pla_WOIEstimate'
OUTPUT_AVG_DEP_ESTIMATE = 'AVG_pla_DepEstimate'
OUTPUT_AVG_VEL_DEP_ESTIMATE = 'AVG_pla_VelDepEstimate'
OUTPUT_MAX_WOI_ESTIMATE = 'MAX_pla_WOIEstimate'

limit_depth1 = None
limit_depth2 = None
limit_depth3 = None

hest_param1 = None
hest_param2 = None

dmid = None
dmax = None


def init():
    global limit_depth1
    global limit_depth2
    global limit_depth3
    global hest_param1
    global hest_param2
    global dmid
    global dmax

    limit_depth1 = iric.cg_iRIC_Read_Real(common.write_fid, 'limit_depth1')
    logging.debug('limit_depth1 = {0}'.format(limit_depth1))
    limit_depth2 = iric.cg_iRIC_Read_Real(common.write_fid, 'limit_depth2')
    logging.debug('limit_depth2 = {0}'.format(limit_depth2))
    limit_depth3 = iric.cg_iRIC_Read_Real(common.write_fid, 'limit_depth3')
    logging.debug('limit_depth3 = {0}'.format(limit_depth3))

    hest_param1 = iric.cg_iRIC_Read_Real(common.write_fid, 'hest_param1')
    logging.debug('hest_param1 = {0}'.format(hest_param1))
    hest_param2 = iric.cg_iRIC_Read_Real(common.write_fid, 'hest_param2')
    logging.debug('hest_param2 = {0}'.format(hest_param2))

    dmid = iric.cg_iRIC_Read_Grid_Real_Node(common.write_fid, 'd50')
    dmax = iric.cg_iRIC_Read_Grid_Real_Node(common.write_fid, 'd90')


def process_step():
    _process_habitat_depth()
    _process_habitat_depth_vel()
    _process_habitat_woi()


def finalize():
    _finalize_habitat_depth()
    _finalize_habitat_depth_vel()
    _finalize_habitat_woi()


def _process_habitat_depth():
    h = common.result_depth

    flag = _calc_dep_estimate(h)
    iric.cg_iRIC_Write_Sol_Node_Integer(common.write_fid, OUTPUT_DEP_ESTIMATE, flag)

    zeros = np.zeros(h.shape, dtype=np.uint8)
    iric.cg_iRIC_Write_Sol_Node_Integer(common.write_fid, OUTPUT_AVG_DEP_ESTIMATE, zeros)


def _process_habitat_depth_vel():
    h = common.result_depth
    v = common.result_velocity

    ret = _calc_vel_dep_estimate(h, v)
    iric.cg_iRIC_Write_Sol_Node_Integer(common.write_fid, OUTPUT_VEL_DEP_ESTIMATE, ret)

    zeros = np.zeros(h.shape, dtype=np.uint8)
    iric.cg_iRIC_Write_Sol_Node_Integer(common.write_fid, OUTPUT_AVG_VEL_DEP_ESTIMATE, zeros)


def _process_habitat_woi():
    h = common.result_depth
    v = common.result_velocity
    n = common.roughness

    woi = _calc_woi(h, v, n)
    iric.cg_iRIC_Write_Sol_Node_Real(common.write_fid, OUTPUT_WOI_ESTIMATE, np.where(woi >= 1, 1, 0))

    zeros = np.zeros(h.shape, dtype=np.uint8)
    iric.cg_iRIC_Write_Sol_Node_Integer(common.write_fid, OUTPUT_MAX_WOI_ESTIMATE, zeros)


def _finalize_habitat_depth():
    zeros = np.zeros(common.result_depth.shape, dtype=np.int8)
    iric.cg_iRIC_Write_Sol_Node_Integer(common.write_fid, OUTPUT_DEP_ESTIMATE, zeros)

    h = common.result_depth_avg
    flag = _calc_dep_estimate(h)
    iric.cg_iRIC_Write_Sol_Node_Integer(common.write_fid, OUTPUT_AVG_DEP_ESTIMATE, flag)


def _finalize_habitat_depth_vel():
    zeros = np.zeros(common.result_depth.shape, dtype=np.int8)
    iric.cg_iRIC_Write_Sol_Node_Integer(common.write_fid, OUTPUT_VEL_DEP_ESTIMATE, zeros)

    h = common.result_depth_avg
    v = common.result_velocity_avg

    ret = _calc_vel_dep_estimate(h, v)
    iric.cg_iRIC_Write_Sol_Node_Integer(common.write_fid, OUTPUT_AVG_VEL_DEP_ESTIMATE, ret)


def _finalize_habitat_woi():
    zeros = np.zeros(common.result_depth.shape, dtype=np.float32)
    iric.cg_iRIC_Write_Sol_Node_Real(common.write_fid, OUTPUT_WOI_ESTIMATE, zeros)

    h = common.result_depth_max
    v = common.result_velocity_max
    n = common.roughness

    woi = _calc_woi(h, v, n)
    iric.cg_iRIC_Write_Sol_Node_Real(common.write_fid, OUTPUT_MAX_WOI_ESTIMATE, np.where(woi >= 1, 1, 0))


def _calc_dep_estimate(h: np.array):
    flag = np.zeros(h.shape, dtype=np.uint8)
    flag = np.where(h > limit_depth3, 3, flag)
    flag = np.where((h > limit_depth2) & (flag == 0), 2, flag)
    flag = np.where((h > limit_depth1) & (flag == 0), 1, flag)

    return flag


def _calc_vel_dep_estimate(h: np.array, v: np.array):
    h_est = hest_param1 * np.log(v) + hest_param2
    ret = np.zeros(h.shape, dtype=np.uint8)
    ret = np.where(h_est < h, 1, ret)

    return ret


def _calc_woi(h: np.array, v: np.array, n: np.array):
    hh = np.where(h < DEPTH_MIN, DEPTH_MIN, h)
    ie = n * n * v * v / (hh ** (4 / 3))
    taumax = (math.log10(19.0) / np.log10(19.0 * dmax / dmid)) ** 2 * 0.06
    woi = hh * ie / 1.65 / dmax / taumax

    return woi
