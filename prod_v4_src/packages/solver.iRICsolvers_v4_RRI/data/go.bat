@echo off

echo --------------------------------------------------
echo # arguments
rem argument0 
echo %%0 = %0

rem argument1
echo %%1 = %1


rem Get directory for rri execute
echo --------------------------------------------------
echo # RRI execute file path is
echo %~dp0
set exe_dir=%~dp0
echo -


rem Get current directory
echo --------------------------------------------------
echo # Current directory is
echo %cd%
set cur_dir=%cd%
rem echo %cur_dir%\out
echo -

rem Check existence for out directory
IF EXIST %cur_dir%\out (
echo --------------------------------------------------
echo # delete "%cur_di%\out"
rd /s /q out
echo # make "%cur_di%\out"
md out
echo -
) ELSE (
echo --------------------------------------------------
echo # make "%cur_di%\out"
md out
echo -
)

rem Check existence for topo directory
IF EXIST %cur_dir%\topo (
echo --------------------------------------------------
echo # delete "%cur_di%\topo"
rd /s /q topo
echo # make "%cur_di%\topo"
md topo
echo -
) ELSE (
echo --------------------------------------------------
echo # make "%cur_di%\topo"
md topo
echo -
)

rem execute rri.exe
echo --------------------------------------------------
echo # Start RRI.exe
echo %date%_%time%

rem the check type of execution and run
%exe_dir%\check_cgns.exe %1

for /f %%a in (runtype.txt) do (
	rem echo %%a

	if %%a == 0 (
		
		echo --------------------------------------------------
		echo # run demAdjust2.exe only
		%exe_dir%\demAdjust2.exe %1

	) else if %%a == 1 (


		echo --------------------------------------------------
		echo # run demAdjust2.exe
		%exe_dir%\demAdjust2.exe %1


		echo --------------------------------------------------
		echo # run rri.exe
		%exe_dir%\rri.exe %1


	) else if %%a == 2 (

		echo --------------------------------------------------
		echo # run rri.exe only
		rem Run rri.exe
		%exe_dir%\rri.exe %1

	)

)

echo --------------------------------------------------
echo # End RRI.exe
echo %date%_%time%