@echo off
mkdir %2
"%1\Miniconda3-py312_24.4.0-0-Windows-x86_64.exe" /InstallationType=JustMe /RegisterPython=0 /AddToPath=0 /S /D=%2
%2\condabin\conda.bat update --all -y
