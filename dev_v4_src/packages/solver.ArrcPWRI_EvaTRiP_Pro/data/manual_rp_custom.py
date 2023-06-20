import numpy as np

THRESHOLD_DEPTH1 = 0.5
THRESHOLD_DEPTH2 = 0.8
THRESHOLD_V1 = 0.5
THRESHOLD_V2 = 0.9


def f(elevation, depth, wse, vx, vy, val1, val2, v):
    """Calculate riffle and pool from depth, v (velocity)"""

    ret = np.zeros(depth.shape, dtype=np.uint8)
    # THRESHOLD_DEPTH1 <= depth < THRESHOLD_DEPTH2 and
    # v <= THRESHOLD_V1
    # -> ret = 1
    ret = np.where(
        (depth >= THRESHOLD_DEPTH1) &
        (depth < THRESHOLD_DEPTH2) &
        (v <= THRESHOLD_V1), 1, ret)

    # THRESHOLD_DEPTH2 <= depth and
    # v <= THRESHOLD_V1
    # -> ret = 2
    ret = np.where(
        (depth >= THRESHOLD_DEPTH2) &
        (v <= THRESHOLD_V1), 2, ret)

    # depth <= THRESHOLD_DEPTH1 and
    # THRESHOLD_V1 <= v < THRESHOLD_V2
    # -> ret = 3
    ret = np.where(
        (depth <= THRESHOLD_DEPTH1) &
        (v >= THRESHOLD_V1) &
        (v < THRESHOLD_V2), 3, ret)

    # depth <= THRESHOLD_DEPTH1 and
    # THRESHOLD_V2 <= v
    # -> ret = 4
    ret = np.where(
        (depth <= THRESHOLD_DEPTH1) &
        (v >= THRESHOLD_V2), 4, ret)

    return ret
