import csv
import sys
import numpy as np

import iric

DIFF_LIMIT = 0.01

ELEV_BEFORE = 'Elevation_before'
ELEV_AFTER = 'Elevation_after'
TARGET = 'Target'
ELEV_DIFF = 'ElevationChange(m)'
ELEV_BEFORE_OUTPUT = 'ElevationBefore(m)'
ELEV_AFTER_OUTPUT = 'ElevationAfter(m)'
FILL_CUT = 'Fill_Cut'


def main(cgnsName):
    fid = iric.cg_iRIC_Open(cgnsName, iric.IRIC_MODE_MODIFY)

    isize, jsize = iric.cg_iRIC_Read_Grid2d_Str_Size(fid)
    x, y = iric.cg_iRIC_Read_Grid2d_Coords(fid)
    elev_before = iric.cg_iRIC_Read_Grid_Real_Node(fid, ELEV_BEFORE)
    elev_after = iric.cg_iRIC_Read_Grid_Real_Node(fid, ELEV_AFTER)
    target = iric.cg_iRIC_Read_Grid_Integer_Node(fid, TARGET)

    output_xsec_csv = iric.cg_iRIC_Read_Integer(fid, "output_xsec_csv")
    csv_fname = iric.cg_iRIC_Read_String(fid, "csv_fname")

    # calculate diff
    elev_diff = elev_after - elev_before
    # mask with target
    elev_diff = np.where(target == 0, 0, elev_diff)

    # calculate fill_cut
    fill_cut = np.zeros(elev_diff.shape, dtype=np.uint8)
    fill_cut = np.where(elev_diff < -DIFF_LIMIT, -1, fill_cut)
    fill_cut = np.where(elev_diff > DIFF_LIMIT, 1, fill_cut)

    # output values
    iric.cg_iRIC_Write_Sol_Time(fid, 0)
    iric.cg_iRIC_Write_Sol_Node_Real(fid, ELEV_BEFORE_OUTPUT, elev_before)
    iric.cg_iRIC_Write_Sol_Node_Real(fid, ELEV_AFTER_OUTPUT, elev_after)
    iric.cg_iRIC_Write_Sol_Node_Real(fid, ELEV_DIFF, elev_diff)
    iric.cg_iRIC_Write_Sol_Node_Real(fid, FILL_CUT, fill_cut)

    # calculate embankment and cutting
    x = x.reshape(isize, jsize, order='F')
    y = y.reshape(isize, jsize, order='F')
    elev_diff = elev_diff.reshape((isize, jsize), order='F')

    # calculate average value of elev_before and elev_after for each cell

    diff_cell_average = (
        elev_diff[:-1, :-1] +
        elev_diff[1:, :-1] +
        elev_diff[:-1, 1:] +
        elev_diff[1:, 1:]) / 4

    x1 = x[:-1, :-1]
    x2 = x[1:, :-1]
    x3 = x[1:, 1:]
    x4 = x[:-1, 1:]
    y1 = y[:-1, :-1]
    y2 = y[1:, :-1]
    y3 = y[1:, 1:]
    y4 = y[:-1, 1:]
    cell_area = _calc_triangle(x1, y1, x2, y2, x3, y3) + _calc_triangle(x3, y3, x4, y4, x1, y1)

    diff_positive = np.where(diff_cell_average > 0, diff_cell_average, 0)
    diff_negative = np.where(diff_cell_average < 0, - diff_cell_average, 0)

    embankment = diff_positive * cell_area
    cutting = diff_negative * cell_area
    total_balance = embankment - cutting

    embankment_sum = np.sum(embankment)
    cutting_sum = np.sum(cutting)
    total_balance_sum = embankment_sum - cutting_sum

    print('Embankment: {0:.3f} [m^3]'.format(embankment_sum))
    print('Cutting: {0:.3f} [m^3]'.format(np.sum(cutting_sum)))
    print('Total Balance: {0:.3f} [m^3]'.format(total_balance_sum))

    if output_xsec_csv:
        with open(csv_fname, 'w', newline='') as f:
            writer = csv.writer(f)
            writer.writerow(('I', 'Embankment', 'Cutting', 'Total Balance'))
            isize, _ = embankment.shape
            for i in range(isize):
                e = '{0:.3f}'.format(np.sum(embankment[i, :]))
                c = '{0:.3f}'.format(np.sum(cutting[i, :]))
                b = '{0:.3f}'.format(np.sum(total_balance[i, :]))
                writer.writerow((str(i + 1), e, c, b))

        print('{} output.'.format(csv_fname))


def _calc_triangle(x1: np.array, y1: np.array, x2: np.array, y2: np.array, x3: np.array, y3: np.array) -> np.array:
    return 0.5 * np.abs((x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3))


if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("Error: CGNS file name not specified.")
        exit()

    cgnsName = sys.argv[1]
    main(cgnsName)
