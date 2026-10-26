@echo off
rem %1 : folder containing the Miniconda installer
rem %2 : Miniconda3 folder to install to
setlocal
set "SRC=%~1"
set "MC=%~2"

rem Prevent Python settings of other software from affecting conda
set PYTHONHOME=
set PYTHONPATH=

if exist "%MC%\python.exe" if exist "%MC%\condabin\conda.bat" goto :configure

rem Remove half-installed Miniconda3 folder
if exist "%MC%" rmdir /s /q "%MC%"
mkdir "%MC%"
start "" /wait "%SRC%\Miniconda3-py312_24.4.0-0-Windows-x86_64.exe" /InstallationType=JustMe /RegisterPython=0 /AddToPath=0 /S /D=%MC%
if not exist "%MC%\python.exe" exit /b 1

:configure
call "%MC%\condabin\conda.bat" init
call "%MC%\condabin\conda.bat" config --remove channels defaults
call "%MC%\condabin\conda.bat" config --add channels conda-forge
exit /b 0
