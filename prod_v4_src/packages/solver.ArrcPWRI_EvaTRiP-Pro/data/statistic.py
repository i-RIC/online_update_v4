import logging
import os
import iric
import numpy as np

import common

OUTPUT_MAX = 'STAT_Max'
OUTPUT_MIN = 'STAT_Min'
OUTPUT_AVG = 'STAT_Avg'
OUTPUT_STDDEV = 'STAT_Stddev'
OUTPUT_STDDEV_AVG = 'STAT_CV'

AVG_MIN = 1.0e-8

target = None
target_other = None

omit_dry_area = None
dry_area_threshold = None
group_num = None
group_val = None

time_whole = None
time_start = None
time_end = None

output_max = None
output_min = None
output_avg = None
output_stddev = None
output_stddev_div_avg = None

node_max = None
node_min = None
node_sum = None
node_sum_count = None

csv_enable = None
csv_name = None

def init():
    global target, target_other, omit_dry_area, dry_area_threshold, group_num, group_val
    global time_whole, time_start, time_end
    global output_max, output_min, output_avg, output_stddev, output_stddev_div_avg
    global csv_enable, csv_name

    target = iric.cg_iRIC_Read_Integer(common.write_fid, 'stat_target')
    logging.debug('target = {0}'.format(target))
    if target == 3:
        target_other = iric.cg_iRIC_Read_String(common.write_fid, 'stat_target_other')
        logging.debug('target_other = {0}'.format(target_other))
    omit_dry_area = iric.cg_iRIC_Read_Integer(common.write_fid, 'stat_dryarea_enabled')
    logging.debug('omit_dry_area = {0}'.format(omit_dry_area))
    dry_area_threshold = iric.cg_iRIC_Read_Real(common.write_fid, 'stat_dryarea_threshold')
    logging.debug('dry_area_threshold = {0}'.format(dry_area_threshold))

    group_num = iric.cg_iRIC_Read_Complex_Count(common.write_fid, "stat_area")
    logging.debug('group_num = {0}'.format(group_num))
    group_val = iric.cg_iRIC_Read_Grid_Complex_Node(common.write_fid, "stat_area")

    time_whole = iric.cg_iRIC_Read_Integer(common.write_fid, 'stat_timeranage_whole')
    logging.debug('time_whole = {0}'.format(time_whole))
    time_start = iric.cg_iRIC_Read_Real(common.write_fid, 'stat_timerange_start')
    logging.debug('time_start = {0}'.format(time_start))
    time_end = iric.cg_iRIC_Read_Real(common.write_fid, 'stat_timerange_end')
    logging.debug('time_end = {0}'.format(time_end))

    if time_end < time_start:
        logging.error('Start Time[s] > End Time[s].')
        exit()

    output_max = iric.cg_iRIC_Read_Integer(common.write_fid, 'stat_max_enabled')
    logging.debug('output_max = {0}'.format(output_max))
    output_min = iric.cg_iRIC_Read_Integer(common.write_fid, 'stat_min_enabled')
    logging.debug('output_min = {0}'.format(output_min))
    output_avg = iric.cg_iRIC_Read_Integer(common.write_fid, 'stat_avg_enabled')
    logging.debug('output_avg = {0}'.format(output_avg))
    output_stddev = iric.cg_iRIC_Read_Integer(common.write_fid, 'stat_stddev_enabled')
    logging.debug('output_stddev = {0}'.format(output_stddev))
    output_stddev_div_avg = iric.cg_iRIC_Read_Integer(common.write_fid, 'stat_stddev_avg_enabled')
    logging.debug('output_stddev_div_avg = {0}'.format(output_stddev_div_avg))

    csv_enable = iric.cg_iRIC_Read_Integer(common.write_fid, 'stat_csv_enable')
    logging.debug('csv_enable = {0}'.format(csv_enable))
    csv_name = iric.cg_iRIC_Read_String(common.write_fid, 'stat_csv_name')
    logging.debug('csv_name = {0}'.format(csv_name))

    if csv_enable:
        _output_area_statistics_header()

def process_step():
    zeros = np.zeros(common.result_depth.shape)
    vals = _get_target_value()

    if output_max:
        iric.cg_iRIC_Write_Sol_Node_Real(common.write_fid, OUTPUT_MAX, zeros)
        _update_node_max(vals)

    if output_min:
        iric.cg_iRIC_Write_Sol_Node_Real(common.write_fid, OUTPUT_MIN, zeros)
        _update_node_min(vals)

    if output_avg:
        iric.cg_iRIC_Write_Sol_Node_Real(common.write_fid, OUTPUT_AVG, zeros)

    if output_stddev:
        iric.cg_iRIC_Write_Sol_Node_Real(common.write_fid, OUTPUT_STDDEV, zeros)

    if output_stddev_div_avg:
        iric.cg_iRIC_Write_Sol_Node_Real(common.write_fid, OUTPUT_STDDEV_AVG, zeros)

    if output_avg or output_stddev or output_stddev_div_avg:
        _update_node_average(vals)

    if csv_enable:
        _output_area_statistics_values(vals)

def finalize():
    zeros = np.zeros(common.result_depth.shape)
    if output_max:
        if node_max is None:
            logging.warn('Time range setting is invalid. No data is output to {0}.'.format(OUTPUT_MAX))
            iric.cg_iRIC_Write_Sol_Node_Real(common.write_fid, OUTPUT_MAX, zeros)
        else:
            iric.cg_iRIC_Write_Sol_Node_Real(common.write_fid, OUTPUT_MAX, node_max)
    
    if output_min:
        if node_min is None:
            logging.warn('Time range setting is invalid. No data is output to {0}.'.format(OUTPUT_MIN))
            iric.cg_iRIC_Write_Sol_Node_Real(common.write_fid, OUTPUT_MIN, zeros)
        else:
            iric.cg_iRIC_Write_Sol_Node_Real(common.write_fid, OUTPUT_MIN, node_min)

    if output_avg or output_stddev or output_stddev_div_avg:
        if node_sum is None:
            node_avg = zeros
        else:
            node_avg = node_sum / node_sum_count

    if output_avg:
        if node_sum is None:
            logging.warn('Time range setting is invalid. No data is output to {0}.'.format(OUTPUT_AVG))
            iric.cg_iRIC_Write_Sol_Node_Real(common.write_fid, OUTPUT_AVG, zeros)
        else:
            iric.cg_iRIC_Write_Sol_Node_Real(common.write_fid, OUTPUT_AVG, node_avg)

    node_stddev = None

    if (output_stddev_div_avg or output_stddev_div_avg) and not (node_sum is None):
        # calc d2sum
        d2sum = np.zeros(common.result_depth.shape)

        result_steps = iric.cg_iRIC_Read_Sol_Count(common.read_fid)
        for i in range(result_steps):
            step = i + 1
            t = iric.cg_iRIC_Read_Sol_Time(common.read_fid, step)
            if time_whole == 0 and (t < time_start or t > time_end): continue

            val = _get_target_value_at(step)

            d = val - node_avg
            d2sum = d2sum + d * d
        
        node_stddev = d2sum / node_sum_count

    if output_stddev:
        if node_stddev is None:
            logging.warn('Time range setting is invalid. No data is output to {0}.'.format(OUTPUT_STDDEV))
            iric.cg_iRIC_Write_Sol_Node_Real(common.write_fid, OUTPUT_STDDEV, zeros)
        else:
            iric.cg_iRIC_Write_Sol_Node_Real(common.write_fid, OUTPUT_STDDEV, node_stddev)
    
    if output_stddev_div_avg:
        if node_stddev is None:
            logging.warn('Time range setting is invalid. No data is output to {0}.'.format(OUTPUT_STDDEV_AVG))
            iric.cg_iRIC_Write_Sol_Node_Real(common.write_fid, OUTPUT_STDDEV_AVG, zeros)
        else:
            node_avg = np.where(node_avg > AVG_MIN, node_avg, AVG_MIN)
            iric.cg_iRIC_Write_Sol_Node_Real(common.write_fid, OUTPUT_STDDEV_AVG, node_stddev / node_avg)

def _update_node_max(vals):
    global node_max
    if time_whole == 0 and (common.time < time_start or common.time > time_end):
        return

    if node_max is None:
        node_max = vals
    else:
        node_max = np.maximum(node_max, vals)

def _update_node_min(vals):
    global node_min
    if time_whole == 0 and (common.time < time_start or common.time > time_end):
        return

    if node_min is None:
        node_min = vals
    else:
        node_min = np.minimum(node_max, vals)

def _update_node_average(vals):
    global node_sum, node_sum_count
    if time_whole == 0 and (common.time < time_start or common.time > time_end):
        return

    if node_sum is None:
        node_sum = vals
        node_sum_count = 1
    else:
        node_sum += vals
        node_sum_count += 1

def _output_dummy(name):
    zeros = np.zeros(common.result_depth.shape)
    iric.cg_iRIC_Write_Sol_Node_Real(common.write_fid, name, zeros)

def _output_area_statistics_header():
    group_names = list()
    for i in range(group_num):
        group_name = iric.cg_iRIC_Read_Complex_String(common.write_fid, "stat_area", i + 1, "_caption")
        group_names.append(group_name)

    outputs = list()
    outputs.append('time')
    for group_name in group_names:
        outputs.append('{0} {1}'.format(group_name, 'Count'))

        if output_max:
            outputs.append('{0} {1}'.format(group_name, 'Max'))

        if output_min:
            outputs.append('{0} {1}'.format(group_name, 'Min'))

        if output_avg:
            outputs.append('{0} {1}'.format(group_name, 'Avg'))
        
        if output_stddev:
            outputs.append('{0} {1}'.format(group_name, 'Stddev'))
        
        if output_stddev_div_avg:
            outputs.append('{0} {1}'.format(group_name, 'CV'))

    with open(csv_name, 'w', encoding='utf-8') as f:
        f.write(','.join(outputs) + '\n')

def _output_area_statistics_values(vals):
    if omit_dry_area == 1:
        dry_mask = np.where(common.result_depth >= dry_area_threshold, 1, 0)
    else:
        dry_mask = np.ones(group_val.shape)

    outputs = list()
    outputs.append(str(common.time))
    for i in range(group_num):
        nodecount = int(np.nansum(np.where((dry_mask == 1) & (group_val == i + 1), 1, np.nan)))

        outputs.append(str(nodecount))

        if nodecount == 0:
            if output_max:
                outputs.append('-')

            if output_min:
                outputs.append('-')

            if output_avg:
                outputs.append('-')
            
            if output_stddev:
                outputs.append('-')
            
            if output_stddev_div_avg:
                outputs.append('-')

        else:
            if output_max:
                outputs.append(str(np.nanmax(np.where((dry_mask == 1) & (group_val == i + 1), vals, np.nan))))

            if output_min:
                outputs.append(str(np.nanmin(np.where((dry_mask == 1) & (group_val == i + 1), vals, np.nan))))

            if output_avg or output_stddev_div_avg:
                avg = np.nanmean(np.where((dry_mask == 1) & (group_val == i + 1), vals, np.nan))

            if output_avg:
                outputs.append(str(avg))

            if output_stddev or output_stddev_div_avg:
                std = np.nanstd(np.where((dry_mask == 1) & (group_val == i + 1), vals, np.nan))

            if output_stddev:
                outputs.append(str(std))
            
            if output_stddev_div_avg:
                outputs.append(str(std / avg))

    with open(csv_name, 'a', encoding='utf-8') as f:
        f.write(','.join(outputs) + '\n')

def _get_target_value():
    if target == 0:
        return common.result_depth
    elif target == 1:
        return common.result_water_surface_elevation
    elif target == 2:
        return common.result_velocity
    elif target == 3:
        return iric.cg_iRIC_Read_Sol_Node_Real(common.read_fid, common.step, target_other)

def _get_target_value_at(step):
    target_name = None

    if target == 0:
        target_name = common.result_depth_name
    elif target == 1:
        target_name = common.result_water_surface_elevation
    elif target == 2:
        target_name = common.result_velocity
    elif target == 3:
        target_name = target_other
    
    return iric.cg_iRIC_Read_Sol_Node_Real(common.read_fid, step, target_name)
