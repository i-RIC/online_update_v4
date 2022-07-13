import iric
import numpy as np

import common

OUTPUT_NAME = 'CLASS_result'

target = None
target_other = None
x = None
y = None
threshold = None
output = None

def init():
    global target, target_other, x, y, threshold, output
    target = iric.cg_iRIC_Read_Integer(common.write_fid, 'class_target')
    if target == 3:
        target_other = iric.cg_iRIC_Read_String(common.write_fid, 'class_target_other')
    x, y = iric.cg_iRIC_Read_Functional(common.write_fid, 'class_def')
    threshold = iric.cg_iRIC_Read_Integer(common.write_fid, 'class_threshold')
    output = iric.cg_iRIC_Read_Integer(common.write_fid, 'class_output')

def process_step():
    if not output:
        return

    size = x.size

    val = None
    if target == 0:
        val = common.result_depth
    elif target == 1:
        val = common.result_water_surface_elevation
    elif target == 2:
        val = common.result_velocity
    else:
        val = iric.cg_iRIC_Read_Sol_Node_Real(common.read_fid, common.step, target_other)

    if threshold == 0:
        # threshold is inclued to left range
        result = np.zeros(val.shape)
        result += np.where(val <= x[0], y[1], 0)
        result += np.where(val > x[size - 1], y[size - 1], 0)
        for i in range(size - 1):
            result += np.where((x[i] < val) & (val <= x[i + 1]), y[i + 1] ,0)

    elif threshold == 1:
        # threshold is inclued to right range
        result = np.zeros(val.shape)
        result += np.where(val < x[0], y[1], 0)
        result += np.where(val >= x[size - 1], y[size - 1], 0)
        for i in range(size - 1):
            result += np.where((x[i] <= val) & (val < x[i + 1]), y[i + 1] ,0)

    iric.cg_iRIC_Write_Sol_Node_Integer(common.write_fid, OUTPUT_NAME, result)

def finalize():
    if not output:
        return
    
    zeros = np.zeros(common.result_depth.shape)
    iric.cg_iRIC_Write_Sol_Node_Integer(common.write_fid, OUTPUT_NAME, zeros)
