@echo off
gcc -Wall -Wextra main.c chashmap.c -o hashmap.exe

if errorlevel 1 (
    exit /b
)

hashmap.exe

echo.