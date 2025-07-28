@echo off
gcc -Wall -Wextra main.c hashmap_c.c -o hashmap.exe

if errorlevel 1 (
    exit /b
)

hashmap.exe

echo.