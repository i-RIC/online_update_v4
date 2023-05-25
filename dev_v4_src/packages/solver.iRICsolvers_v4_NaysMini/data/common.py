import iric
import numpy as np

read_fid = None
write_fid = None
step = None
time = None

result_depth_name = None
result_water_surface_elevation_name = None
result_velocityX_name = None
result_velocityY_name = None

result_depth = None
result_water_surface_elevation = None
result_velocityX = None
result_velocityY = None
result_velocity = None

def read_result():
    global result_depth
    global result_water_surface_elevation
    global result_velocityX
    global result_velocityY
    global result_velocity

    result_depth = iric.cg_iRIC_Read_Sol_Real_Mul(read_fid, step, result_depth_name)
    result_water_surface_elevation = iric.cg_iRIC_Read_Sol_Real_Mul(read_fid, step, result_water_surface_elevation_name)
    result_velocityX = iric.cg_iRIC_Read_Sol_Real_Mul(read_fid, step, result_velocityX_name)
    result_velocityY = iric.cg_iRIC_Read_Sol_Real_Mul(read_fid, step, result_velocityY_name)

    vx = result_velocityX
    vy = result_velocityY
    result_velocity = np.sqrt(vx * vx + vy * vy)

