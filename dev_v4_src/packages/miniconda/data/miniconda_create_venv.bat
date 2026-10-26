@echo off
rem %1 : Miniconda3 folder
setlocal
set "MC=%~1"
set "ENV=%MC%\envs\iric"

rem Prevent Python settings of other software from affecting conda
set PYTHONHOME=
set PYTHONPATH=
rem Make conda tolerant to slow / unstable connections
set CONDA_REMOTE_MAX_RETRIES=10
set CONDA_REMOTE_CONNECT_TIMEOUT_SECS=30
set CONDA_REMOTE_READ_TIMEOUT_SECS=120
set CONDA_SSL_VERIFY=truststore

"%ENV%\python.exe" -c "import numpy, matplotlib" > nul 2>&1
if not errorlevel 1 exit /b 0

set TRY=0
:retry
set /a TRY+=1
if exist "%ENV%" rmdir /s /q "%ENV%"
call "%MC%\condabin\conda.bat" create -p "%ENV%" --override-channels -c conda-forge python=3.12 numpy=1.26.4 numba=0.59.1 scipy=1.13.1 gdal=3.8 pandas=2.2.2 matplotlib=3.8.4 requests=2.32.2 beautifulsoup4=4.12.3 pyproj=3.6.1 -y -q
"%ENV%\python.exe" -c "import numpy, matplotlib" > nul 2>&1
if not errorlevel 1 exit /b 0
if %TRY% LSS 5 (
  timeout /t 10 /nobreak > nul
  goto :retry
)
exit /b 1
