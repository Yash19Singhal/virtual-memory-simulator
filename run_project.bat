@echo off
echo Compiling project...
g++ -std=c++17 -Wall main.cpp fifo.cpp lru.cpp optimal.cpp utils.cpp -o virtualmemory.exe
if %errorlevel% neq 0 (
    echo Compilation failed.
    exit /b %errorlevel%
)
echo Running project...
virtualmemory.exe
pause
