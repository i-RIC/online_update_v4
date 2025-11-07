@echo off
%1\condabin\conda.bat update -n base -c conda-forge conda -y
%1\condabin\conda.bat update -n base -c conda-forge --all -y
