@echo off
echo %0 %1 %2

rem Укажите путь, по которому установлен masm32
set masm32home=c:\masm32

if "%2" == "" goto usage
if not exist %masm32home%\bin\nul goto error_masm32
if not exist %masm32home%\lib\nul goto error_masm32
if not exist %masm32home%\include\nul goto error_masm32

if "%1" == "-asm" goto asm
if "%1" == "-disasm" goto disasm
if "%1" == "-link:windows" goto link_windows
if "%1" == "-link:console" goto link_console
if "%1" == "-build:windows" goto asm
if "%1" == "-build:console" goto asm
goto usage

:asm
echo.
echo Трансляция файла %2.asm ...
echo.
if not exist %masm32home%\bin\ml.exe goto error_no_ml
if exist %2.obj del %2.obj
if exist %2.exe del %2.exe
%masm32home%\bin\ml.exe /I%masm32home%\include /c /coff /Fo%2.obj %2.asm 
if errorlevel 1 goto error_asm
if "%1" == "-build:windows" goto link_windows
if "%1" == "-build:console" goto link_console
rem dir %2.*
goto TheEnd

:link_windows
echo.
echo Компоновка файла %2.obj ...
echo.
if not exist %masm32home%\bin\link.exe goto error_no_link
if exist %2.exe del %2.exe
%masm32home%\bin\link.exe /LIBPATH:%masm32home%\lib /SUBSYSTEM:WINDOWS /OUT:%2.exe %2.obj
if errorlevel 1 goto error_link
rem dir %2.*
goto TheEnd

:link_console
echo.
echo Компоновка файла %2.obj ...
echo.
if not exist %masm32home%\bin\link.exe goto error_no_link
if exist %2.exe del %2.exe
%masm32home%\bin\link.exe /LIBPATH:%masm32home%\lib /SUBSYSTEM:CONSOLE /OUT:%2.exe %2.obj
if errorlevel 1 goto error_link
rem dir %2.*
goto TheEnd

:disasm
echo.
echo Дизассемблирование файла %2 ...
echo.
if not exist %masm32home%\bin\dumppe.exe goto error_no_dumppe
%masm32home%\bin\dumppe.exe -disasm %2 > %2.txt
start notepad %2.txt
goto TheEnd

:error_no_ml
echo ===================================
echo   Ошибка: файл %masm32home%\bin\ml.exe,
echo   необходимый для трансляции, не найден
echo ===================================
goto TheEnd

:error_no_link
echo ===================================
echo   Ошибка: файл %masm32home%\bin\link.exe,
echo   необходимый для компоновки, не найден
echo ===================================
goto TheEnd

:error_no_dumppe
echo ===================================
echo   Ошибка: файл %masm32home%\bin\dumppe.exe,
echo   необходимый для дизассемблирования, не найден
echo ===================================
goto TheEnd

:error_masm32
echo ===================================
echo   Ошибка: MASM32 не найден
echo   Возможная причина: неверно 
echo   установлена переменная masm32home
echo   или нарушена структура каталогов
echo ===================================
goto TheEnd

:error_asm
echo ==============================
echo   Ошибка: ошибка трансляции
echo ==============================
goto TheEnd

:error_link
echo ==============================
echo   Ошибка: ошибка компоновки
echo ==============================
goto TheEnd

:usage
echo masm32.bat - пакетный файл для трансляции / компоновки / сборки / дизассемблирования
echo.
echo Использование:
echo.
echo   masm32.bat -asm file
echo     трансляция файла file.asm
echo.
echo   masm32.bat -disasm file.exe
echo     дизассемблирование файла file.exe
echo.
echo   masm32.bat -link:windows file 
echo     компоновка файла file.obj в режиме Windows GUI
echo.
echo   masm32.bat -link:console file 
echo     компоновка файла file.obj в режиме Console
echo.
echo   masm32.bat -build:windows file 
echo     сборка (трансляция+компоновка) файла file.asm в режиме Windows GUI
echo.
echo   masm32.bat -link:console file 
echo     сборка (трансляиця+компоновка) файла file.asm в режиме Console
echo.
goto TheEnd

:TheEnd
pause
