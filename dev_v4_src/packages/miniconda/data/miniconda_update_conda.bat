@echo off
rem %1 : Miniconda3 folder
setlocal
set "MC=%~1"

set PYTHONHOME=
set PYTHONPATH=
set CONDA_REMOTE_MAX_RETRIES=10
set CONDA_REMOTE_CONNECT_TIMEOUT_SECS=30
set CONDA_REMOTE_READ_TIMEOUT_SECS=120
set CONDA_SSL_VERIFY=truststore

call "%MC%\condabin\conda.bat" update -n base --override-channels -c conda-forge conda -y
rem Failure here is not fatal; the iric environment is created separately
exit /b 0
