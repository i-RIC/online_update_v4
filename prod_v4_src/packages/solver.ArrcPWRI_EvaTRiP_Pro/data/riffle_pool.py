import logging
import numpy as np
import iric

import common

OUTPUT_FR_CLASSES = 'HABITAT_Fr_Classes'
OUTPUT_MANUAL = 'HABITAT_Manual'

DEPTH_MIN = 1.0e-8
DEPTH_THRESHOLD = 1.0e-2
G = 9.8

d1 = None
v1 = None
v2 = None

output_manual = None
output_fr_classes = None


def init():
    global algorithm

    global d1
    global v1
    global v2
    global output_riffle, output_pool, output_rapid
    global output_manual
    global output_fr_classes

    d1 = iric.cg_iRIC_Read_Real(common.write_fid, 'rp_d1')
    logging.debug('rp_d1 = {0}'.format(d1))
    v1 = iric.cg_iRIC_Read_Real(common.write_fid, 'rp_v1')
    logging.debug('rp_v1 = {0}'.format(v1))
    v2 = iric.cg_iRIC_Read_Real(common.write_fid, 'rp_v2')
    logging.debug('rp_v2 = {0}'.format(v2))

    output_manual = iric.cg_iRIC_Read_Integer(common.write_fid, 'rp_output_manual')
    logging.debug('rp_output_manual = {0}'.format(output_manual))
    output_fr_classes = iric.cg_iRIC_Read_Integer(common.write_fid, 'rp_output_fr_classes')
    logging.debug('rp_output_fr_classes = {0}'.format(output_fr_classes))


def process_step():
    _process_step_manual()
    _process_step_ent()


def finalize():
    _finalize_manual()
    _finalize_ent()


def _process_step_manual():
    if not output_manual:
        return

    manual = np.zeros(common.result_depth.shape, dtype=np.uint8)

    # pool
    cond1 = np.where(common.result_depth >= d1, 1, 0)
    cond2 = np.where(common.result_velocity <= v1, 1, 0)
    manual = np.where(cond1 & cond2, 1, manual)

    # riffle
    cond1 = np.where(common.result_depth <= d1, 1, 0)
    cond2 = np.where(common.result_velocity >= v1, 1, 0)
    cond3 = np.where(common.result_velocity <= v2, 1, 0)
    manual = np.where(cond1 & cond2 & cond3, 2, manual)

    # rapid
    cond1 = np.where(common.result_depth <= d1, 1, 0)
    cond2 = np.where(common.result_velocity >= v2, 1, 0)
    manual = np.where(cond1 & cond2, 3, manual)

    iric.cg_iRIC_Write_Sol_Node_Integer(common.write_fid, OUTPUT_MANUAL, manual)


def _process_step_ent():
    if not output_fr_classes:
        return

    # depth smaller than DEPTH_MIN is replaced with DEPTH_MIN.
    depth = np.where(common.result_depth > DEPTH_MIN, common.result_depth, DEPTH_MIN)
    fr = common.result_velocity / np.sqrt(depth * G)

    classes = np.zeros(common.result_depth.shape, dtype=np.int8)
    classes += np.where(fr < 0.04, 1, 0)
    classes += np.where((0.04 <= fr) & (fr < 0.15), 2, 0)
    classes += np.where((0.15 <= fr) & (fr < 0.245), 3, 0)
    classes += np.where((0.245 <= fr) & (fr < 0.49), 4, 0)
    classes += np.where(fr >= 0.49, 5, 0)
    classes = np.where(depth < DEPTH_THRESHOLD, 0, classes)

    iric.cg_iRIC_Write_Sol_Node_Integer(common.write_fid, OUTPUT_FR_CLASSES, classes)


def _finalize_manual():
    if not output_manual:
        return

    zeros = np.zeros(common.result_depth.shape, dtype=np.int8)
    iric.cg_iRIC_Write_Sol_Node_Integer(common.write_fid, OUTPUT_MANUAL, zeros)


def _finalize_ent():
    if not output_fr_classes:
        return

    zeros = np.zeros(common.result_depth.shape, dtype=np.int8)
    iric.cg_iRIC_Write_Sol_Node_Integer(common.write_fid, OUTPUT_FR_CLASSES, zeros)
