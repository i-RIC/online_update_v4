@echo off
%2\condabin\conda.bat create -p %2\envs\iric python=3.12 numpy=1.26.4 numba=0.59.1 scipy=1.13.1 gdal=3.6.2 h5py=3.11.0 pandas=2.2.2 matplotlib=3.8.4 requests=2.32.2 beautifulsoup4=4.12.3 pyproj=3.6.1 -y -q
