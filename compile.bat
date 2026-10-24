@echo off
echo ========================================================
echo   Compiling LIVE-ASCII-ART (Week 1 Build)
echo ========================================================

:: Compile main.cpp which includes all student modules
g++ -std=c++17 main.cpp -o ascii_art.exe

if %errorlevel% equ 0 (
    echo [SUCCESS] Build completed successfully!
    echo Running ascii_art.exe ...
    echo.
    ascii_art.exe
) else (
    echo [ERROR] Compilation failed. Please check the error messages above.
)

echo.
pause
