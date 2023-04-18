@echo off

set MINGW_BIN_PATH=C:\MinGW\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin

PATH=%PATH%;%MINGW_BIN_PATH%

set PROG_NAME=SDL2_Platformer.exe

set CXX=g++.exe
set COMPILE_FILES=.\*.cpp .\ui\*.cpp
set CFLAGS_DEBUG=-Wall -fexceptions -g
set CFLAGS_RELEASE=-Wall -fexceptions -O2

set DEBUG_OUTPUT_FOLDER=bin\Debug
set DEBUG_OUTFILE=%DEBUG_OUTPUT_FOLDER%\%PROG_NAME%

set RELEASE_OUTPUT_FOLDER=bin\Release
set RELEASE_OUTFILE=%RELEASE_OUTPUT_FOLDER%\%PROG_NAME%

set SDL2_VER=2.26.5
set SDL2_TTF_VER=2.20.2
set SDL2_MIXER_VER=2.6.3
set SDL2_IMAGE_VER=2.6.3

set SDL2_INC_PARAM=-IC:\SDL\SDL2-%SDL2_VER%\i686-w64-mingw32\include -IC:\SDL\SDL2_ttf-%SDL2_TTF_VER%\i686-w64-mingw32\include -IC:\SDL\SDL2_mixer-%SDL2_MIXER_VER%\i686-w64-mingw32\include -IC:\SDL\SDL2_image-%SDL2_IMAGE_VER%\i686-w64-mingw32\include
set SDL2_LIB_PARAM=-LC:\SDL\SDL2-%SDL2_VER%\i686-w64-mingw32\lib -LC:\SDL\SDL2_ttf-%SDL2_TTF_VER%\i686-w64-mingw32\lib -LC:\SDL\SDL2_mixer-%SDL2_MIXER_VER%\x86_64-w64-mingw32\lib -LC:\SDL\SDL2_image-%SDL2_IMAGE_VER%\i686-w64-mingw32\lib

set SDL2_LD_PARAM=-lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_mixer -lSDL2_image

set BUILD_TYPE=%1

if "%BUILD_TYPE%" EQU "debug" (
    echo "Compiling in Debug mode"

    if not exist %DEBUG_OUTPUT_FOLDER%\*.* mkdir %DEBUG_OUTPUT_FOLDER%

    %CXX% %CFLAGS_DEBUG% %SDL2_INC_PARAM% %SDL2_LIB_PARAM% %COMPILE_FILES% -o %DEBUG_OUTFILE% %SDL2_LD_PARAM%

    xcopy /E /Y assets %DEBUG_OUTPUT_FOLDER%\assets\
    xcopy /E /Y lang %DEBUG_OUTPUT_FOLDER%\lang\
    xcopy /E /Y deps\debug %DEBUG_OUTPUT_FOLDER%\
) else if "%BUILD_TYPE%" EQU "release" (
    echo "Compiling in Release mode"

    if not exist %RELEASE_OUTPUT_FOLDER%\*.* mkdir %RELEASE_OUTPUT_FOLDER%

    %CXX% %CFLAGS_RELEASE% %SDL2_INC_PARAM% %SDL2_LIB_PARAM% %COMPILE_FILES% -o %RELEASE_OUTFILE% %SDL2_LD_PARAM%

    xcopy /E /Y assets %RELEASE_OUTPUT_FOLDER%\assets\
    xcopy /E /Y lang %RELEASE_OUTPUT_FOLDER%\lang\
    xcopy /E /Y deps\release %RELEASE_OUTPUT_FOLDER%\
) else if "%BUILD_TYPE%" EQU "clean" (
    echo "Clean all builds"

    if exist %DEBUG_OUTPUT_FOLDER%\*.* (
        rmdir /S /Q %DEBUG_OUTPUT_FOLDER%
    )

    if exist %RELEASE_OUTPUT_FOLDER%\*.* (
        rmdir /S /Q %RELEASE_OUTPUT_FOLDER%
    )
) else (
    echo "I don't understand you..."
)
