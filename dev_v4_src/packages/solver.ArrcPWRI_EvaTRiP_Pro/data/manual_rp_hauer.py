import numpy as np


def decisionNCv(vv):
    ret = np.zeros(vv.shape, dtype=np.uint8)
    ret = np.where(vv <= 0.1, 1, ret)
    ret = np.where((vv <= 0.25) & (ret == 0), 2, ret)
    ret = np.where((vv <= 0.40) & (ret == 0), 3, ret)
    ret = np.where((vv <= 0.75) & (ret == 0), 4, ret)
    ret = np.where((ret == 0), 5, ret)
    return ret


def decisionNCd(dd):
    ret = np.zeros(dd.shape, dtype=np.uint8)
    ret = np.where((dd >= 0.01) & (dd <= 0.4), 5, ret)
    ret = np.where((dd <= 0.8) & (ret == 0), 4, ret)
    ret = np.where((dd <= 1.2) & (ret == 0), 3, ret)
    ret = np.where((dd <= 1.5) & (ret == 0), 2, ret)
    ret = np.where(ret == 0, 1, ret)
    return ret


def decisionNCval1(tt):
    ret = np.zeros(tt.shape, dtype=np.uint8)
    ret[:] = 2  # default value
    ret = np.where(tt <= 2.0, 0, ret)
    ret = np.where(tt <= 20, 1, ret)
    return ret


def decisionHC(mmh, dd):
    habitat = np.zeros(mmh.shape)
    habitat[:] = 2  # backwater
    habitat = np.where(mmh == 20, 6, habitat)  # riffle
    habitat = np.where((mmh >= 10) & (mmh <= 18) & (habitat == 2), 5, habitat)  # fast run
    habitat = np.where((mmh >= 5) & (mmh <= 9) & (habitat == 2), 4, habitat)  # run
    habitat = np.where((mmh >= 2) & (mmh <= 4) & (habitat == 2), 3, habitat)  # pool
    habitat = np.where((dd <= 0.01) & (habitat == 2), 0, habitat)  # drywater
    habitat = np.where((dd <= 0.8) & (habitat == 2), 1, habitat)  # shallow

    return habitat


def f(elevation, depth, wse, vx, vy, val1, val2, v):
    """Calculate riffle and pool from depth, v (velocity), val1"""
    """Please enter ShearStress in val1"""

    ncv = decisionNCv(v)
    ncd = decisionNCd(depth)
    ncval1 = decisionNCval1(val1)

    mh = (ncd + ncv) * ncval1
    mh = np.where(depth <= 0.01, 0, mh)

    return decisionHC(mh, depth)
