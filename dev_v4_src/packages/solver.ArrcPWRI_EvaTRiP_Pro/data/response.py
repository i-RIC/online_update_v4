import numpy as np
import iric
import common

OUTPUT_SUM_NAME = 'RESP_Sum'
OUTPUT_AMEAN_NAME = 'RESP_A_Mean'
OUTPUT_GMEAN_NAME = 'RESP_G_Mean'

funcs = list()
output_sum = None
output_arigh = None
output_geom = None

class ResponseFunction(object):
    def __init__(self, id, num, other, CIndex, x, y):
        self._id = id
        self._num = num
        self._other = other
        self._CIndex = CIndex
        self._x = x
        self._y = y

    def exec(self):
        result = _get_result(self._num, self._other, self._CIndex)
        x = self._x
        y = self._y
        size = x.size

        out = np.zeros(result.shape)
        out += np.where(result < x[0], y[0], 0)
        out += np.where(result >= x[size - 1], y[size - 1], 0)
        for i in range(size - 1):
            out += np.where((x[i] <= result) & (result < x[i + 1]), 1, 0) * \
                (y[i] + (y[i + 1] - y[i]) / (x[i + 1] - x[i]) * (result - x[i]))

        outName = 'RESP_F{}'.format(self._id)
        iric.cg_iRIC_Write_Sol_Node_Real(common.write_fid, outName, out)

        return out

    def execDummy(self):
        out = np.zeros(common.result_depth.shape)
        outName = 'RESP_F{}'.format(self._id)
        iric.cg_iRIC_Write_Sol_Node_Real(common.write_fid, outName, out)

def init():
    global funcs, output_sum, output_arigh, output_geom

    for i in range(1, 4):
        out = iric.cg_iRIC_Read_Integer(common.write_fid, 'resp_f{0}_output'.format(i))
        if out == 0: continue

        target = iric.cg_iRIC_Read_Integer(common.write_fid, 'resp_f{0}_target'.format(i))
        target_other = None
        if target == 3:
            target_other = iric.cg_iRIC_Read_String(common.write_fid, 'resp_f{0}_target_other'.format(i))
        target_coverindex = None
        if target == 4:
            target_coverindex = iric.cg_iRIC_Read_Grid_Real_Node(common.write_fid, 'CoverIndex')

        x, y = iric.cg_iRIC_Read_Functional(common.write_fid, 'resp_f{0}_def'.format(i))

        f = ResponseFunction(i, target, target_other, target_coverindex, x, y)
        funcs.append(f)

    output_sum = iric.cg_iRIC_Read_Integer(common.write_fid, 'resp_comp_output_sum')
    output_arigh = iric.cg_iRIC_Read_Integer(common.write_fid, 'resp_comp_output_arigh')
    output_geom = iric.cg_iRIC_Read_Integer(common.write_fid, 'resp_comp_output_geom')

def process_step():
    result_list = list()
    for f in funcs:
        result_list.append(f.exec())

    _output_sum_and_arighmetic_mean(result_list)
    _output_geometric_mean(result_list)

def finalize():
    for f in funcs:
        f.execDummy()

    if len(funcs) == 0: return

    zeros = np.zeros(common.result_depth.shape)
    if output_sum:
        iric.cg_iRIC_Write_Sol_Node_Real(common.write_fid, OUTPUT_SUM_NAME, zeros)
    if output_arigh:
        iric.cg_iRIC_Write_Sol_Node_Real(common.write_fid, OUTPUT_AMEAN_NAME, zeros)
    if output_geom:
        iric.cg_iRIC_Write_Sol_Node_Real(common.write_fid, OUTPUT_GMEAN_NAME, zeros)

def _output_sum_and_arighmetic_mean(vals):
    if not (output_sum or output_arigh): return
    if len(vals) == 0: return

    sum = np.zeros(vals[0].shape)
    for val in vals:
        sum += val

    if output_sum:
        iric.cg_iRIC_Write_Sol_Node_Real(common.write_fid, OUTPUT_SUM_NAME, sum)

    if output_arigh:
        mean = sum / len(vals)
        iric.cg_iRIC_Write_Sol_Node_Real(common.write_fid, OUTPUT_AMEAN_NAME, mean)

def _output_geometric_mean(vals):
    if not output_geom: return
    if len(vals) == 0: return

    mean = np.ones(vals[0].shape)
    for val in vals:
        mean *= val

    mean = np.power(mean, 1.0 / len(vals))
    iric.cg_iRIC_Write_Sol_Node_Real(common.write_fid, OUTPUT_GMEAN_NAME, mean)

def _get_result(num, other, CIndex):
    if num == 0:
        return common.result_depth
    elif num == 1:
        return common.result_water_surface_elevation
    elif num == 2:
        return common.result_velocity
    elif num == 3:
        return iric.cg_iRIC_Read_Sol_Node_Real(common.read_fid, common.step, other)
    elif num == 4:
        return iric.cg_iRIC_Read_Grid_Real_Node(common.write_fid, 'CoverIndex')