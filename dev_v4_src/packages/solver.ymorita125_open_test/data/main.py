import sys
import iric
import numpy as np
import random

# --------------------------------------------------
# 計算結果出力関数
# --------------------------------------------------


def write_calc_result(fid, ctime, xx, yy, zz, ss, qq, uu, vv, hh, zb, hs):

    ier = 0

    # # write time
    iric.cg_iRIC_Write_Sol_Time(fid, ctime)

    # # write discharge
    iric.cg_iRIC_Write_Sol_BaseIterative_Real(fid, 'Discharge', qq)

    # # write grid
    iric.cg_iRIC_Write_Sol_Grid2d_Coords(fid, xx.reshape(-1), yy.reshape(-1))

    # # write node values
    # iric.cg_iRIC_Write_Sol_Integer("for integer array", zz.reshape(-1))
    iric.cg_iRIC_Write_Sol_Node_Real(fid, "Elevation", zz.reshape(-1))
    iric.cg_iRIC_Write_Sol_Node_Real(fid, "VelocityX", uu.reshape(-1))
    iric.cg_iRIC_Write_Sol_Node_Real(fid, "VelocityY", vv.reshape(-1))

    # # write cell values
    iric.cg_iRIC_Write_Sol_Cell_Real(fid, "ManningN_c", ss.reshape(-1))
    iric.cg_iRIC_Write_Sol_Cell_Real(fid, "Elevation_c", zb.reshape(-1))
    iric.cg_iRIC_Write_Sol_Cell_Real(fid, "Depth_c", hs.reshape(-1))
    iric.cg_iRIC_Write_Sol_Cell_Real(fid, "WaterLevel_c", hh.reshape(-1))

    return ier
# --------------------------------------------------
# main 関数
# --------------------------------------------------


def main(fname0):

    ier = 0

    # ファイルを開く
    fid = iric.cg_iRIC_Open(fname0, iric.CG_MODE_MODIFY)

    # 計算格子数
    ni, nj = iric.cg_iRIC_Read_Grid2d_Str_Size(fid)

    # 計算格子x,y
    x, y = iric.cg_iRIC_Read_Grid2d_Coords(fid)
    xx = x.reshape(nj, ni)  # 1次元配列で読みこまれるため２次元配列に形状変更
    yy = y.reshape(nj, ni)  # 1次元配列で読みこまれるため２次元配列に形状変更

    # 格子属性　標高
    z = iric.cg_iRIC_Read_Grid_Real_Node(fid, 'Elevation')
    zz = z.reshape(nj, ni)  # 1次元配列で読みこまれるため２次元配列に形状変更

    # 格子属性　粗度
    s = iric.cg_iRIC_Read_Grid_Real_Cell(fid, 'ManningN')
    ss = s.reshape(nj-1, ni-1)  # 1次元配列で読みこまれるため２次元配列に形状変更

    # ## for debug 2d plot
    # fig, ax = plt.subplots()
    # ax.contourf(xx, yy, zz, 20)
    # plt.show()

    # 計算条件の読込
    # 関数リファレンス
    # https://iric-solver-dev-manual-jp.readthedocs.io/ja/latest/06/03_reference.html
    cip = iric.cg_iRIC_Read_Integer(fid, 'iflow')
    conf = iric.cg_iRIC_Read_Integer(fid, 'isediment')

    # 流量条件
    t_series = 3600. * iric.cg_iRIC_Read_FunctionalWithName(fid, 'tqh', 'time')
    q_series = iric.cg_iRIC_Read_FunctionalWithName(fid, 'tqh', 'discharge')

    # 時間条件の設定
    t_start = t_series[0]
    t_end = t_series[-1]
    t_out = iric.cg_iRIC_Read_Real(fid, 'tout')
    dt = iric.cg_iRIC_Read_Real(fid, 'dt')

    istart = int(t_start / dt)
    iend = int(t_end / dt) + 1
    iout = int(t_out / dt)

    # 流れ計算の初期条件を設定する
    uu = np.random.rand(nj*ni).reshape(nj, ni)
    vv = np.random.rand(nj*ni).reshape(nj, ni)
    hs = np.random.rand((nj-1)*(ni-1)).reshape(nj-1, ni-1)
    # uu = np.zeros(nj*ni, dtype = np.float64).reshape(nj, ni)
    # vv = np.zeros(nj*ni, dtype = np.float64).reshape(nj, ni)
    # hs = np.zeros((nj-1)*(ni-1), dtype = np.float64).reshape(nj-1, ni-1)

    zb = 0.25*(zz[0:nj-1, 0:ni-1]+zz[1:nj, 0:ni-1] +
               zz[0:nj-1, 1:ni]+zz[1:nj, 1:ni])
    hh = hs + zb

    # 　時間ループ
    for it in range(istart, iend):

        # 現在時刻
        ctime = dt*it

        # 現時刻の上流端流量・下流端水位設定
        qq = 0  # 　scipyなど利用すると様々な補間関数が利用できるがここで暫定値とする

        # 出力
        if it % iout == 0:
            print('time:{:.1f} [min]'.format(ctime/60.))
            ier = write_calc_result(
                fid, ctime, xx, yy, zz, ss, qq, uu, vv, hh, zb, hs)

        # 流況更新・河床高更新など
        # 更新される変数は、uu,vv, hh, hs (河床変動が有効の場合zbも)
        facX = random.random() * 0.0001
        uu = uu + facX * uu
        vv = vv + facX * vv
        hs = hs + facX * hs
        hh = hs + zb

    # ファイルを閉じる
    iric.cg_iRIC_Close(fid)

    return ier


if __name__ == '__main__':
    import time

    if len(sys.argv) == 2:
        start_time = time.time()
        print('> Program starts.')
        if main(sys.argv[1]) == 0:
            process_time = time.time() - start_time
            print('> It took {:.1f} [sec] for this calculation.'.format(
                process_time))  # 2桁まで表示
            # print("It took {}[sec] for this calculation.", process_time)
            print('> Program ended normaly.')
        else:
            print('>>Error : Something\'s wrong.')
    else:
        print('>>Error : Specify the CGNS file as the arguments.')
