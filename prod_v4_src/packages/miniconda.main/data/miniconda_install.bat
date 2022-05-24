@echo off
mkdir %2
"%1\Miniconda3-py38_4.9.2-Windows-x86_64.exe" /InstallationType=JustMe /RegisterPython=0 /AddToPath=0 /S /D=%2
%2\condabin\conda.bat create -p %2\envs\iric python=3.8 numpy -y -q
