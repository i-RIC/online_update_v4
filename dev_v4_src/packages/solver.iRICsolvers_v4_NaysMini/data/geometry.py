import numpy as np

def dsdn(x2,y2,ds,dn,nx,ny):
    for i in np.arange(0,nx+1):
        for j in np.arange(0,ny+1):
            if i>0 :
                ds[i,j]=np.sqrt((x2[i,j]-x2[i-1,j])**2+(y2[i,j]-y2[i-1,j])**2)
            if j>0:
                dn[i,j]=np.sqrt((x2[i,j]-x2[i,j-1])**2+(y2[i,j]-y2[i,j-1])**2)
#            if i>0 and j>0:
#                area[i,j]=ds[i,j]*dn[i,j]
    return(ds,dn)
