@echo off
setlocal enabledelayedexpansion

:: ============================================================
:: Configuration
:: ============================================================
set COMPILER=gcc
set OUTPUT=Abyss-IDE.exe
set MAIN=src\main.c

:: Include paths
set INCLUDES=-Iinclude -Iexternal\include -Iexternal\include\nvg

:: GLFW_STATIC tells GLFW headers not to use __declspec(dllimport)-Iexternal\include
set DEFINES=-DGLFW_STATIC

:: Static link against libglfw3.a + every Win32 lib GLFW needs
set LIBS=-Lexternal\libs -lglfw3 -lopengl32 -lgdi32 -luser32 -lkernel32 -lshell32 -lwinmm -ldwmapi

:: ============================================================
:: Collect all .c files
:: ============================================================
set C_FILES=

:: src/ (excluding main.c to avoid duplicate entry point)
for /r src %%f in (*.c) do (
    if /i not "%%f"=="%CD%\src\main.c" (
        set C_FILES=!C_FILES! "%%f"
    )
)

:: external/src/
for /r external\src %%f in (*.c) do (
    set C_FILES=!C_FILES! "%%f"
)

:: ============================================================
:: Build
:: ============================================================
echo.
echo [BUILD] Compiling all .c files...
echo [ENTRY] %MAIN%
echo.

%COMPILER% %MAIN% !C_FILES! %INCLUDES% %DEFINES% %LIBS% -o %OUTPUT%

if %ERRORLEVEL% == 0 (
    echo.
    echo [OK] Build succeeded: %OUTPUT%
) else (
    echo.
    echo [FAIL] Build failed with error code %ERRORLEVEL%
)

endlocal
pause