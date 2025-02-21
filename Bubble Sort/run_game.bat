@echo off
setlocal
cls

REM Change to the script directory
cd /d "%~dp0"

REM Set SFML library path
set SFML_LIB_PATH="P:\Git HUB _Repositories\Bubble-Sort-Simulation\Bubble Sort\SFML-2.6.2\lib"
set PATH=%SFML_LIB_PATH%;%PATH%

REM Check if Bubble Sort.exe exists
if not exist "Bubble Sort.exe" (
    echo Error: Bubble Sort.exe not found!
    pause
    exit
)

REM Run the executable
start "" /B "Bubble Sort.exe"

REM Exit script
exit
