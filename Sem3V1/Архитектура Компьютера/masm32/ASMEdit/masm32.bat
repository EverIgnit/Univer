@echo off
echo %0 %1 %2

rem ������ ����, �� ���஬� ��⠭����� masm32
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
echo �࠭���� 䠩�� %2.asm ...
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
echo ���������� 䠩�� %2.obj ...
echo.
if not exist %masm32home%\bin\link.exe goto error_no_link
if exist %2.exe del %2.exe
%masm32home%\bin\link.exe /LIBPATH:%masm32home%\lib /SUBSYSTEM:WINDOWS /OUT:%2.exe %2.obj
if errorlevel 1 goto error_link
rem dir %2.*
goto TheEnd

:link_console
echo.
echo ���������� 䠩�� %2.obj ...
echo.
if not exist %masm32home%\bin\link.exe goto error_no_link
if exist %2.exe del %2.exe
%masm32home%\bin\link.exe /LIBPATH:%masm32home%\lib /SUBSYSTEM:CONSOLE /OUT:%2.exe %2.obj
if errorlevel 1 goto error_link
rem dir %2.*
goto TheEnd

:disasm
echo.
echo �����ᥬ���஢���� 䠩�� %2 ...
echo.
if not exist %masm32home%\bin\dumppe.exe goto error_no_dumppe
%masm32home%\bin\dumppe.exe -disasm %2 > %2.txt
start notepad %2.txt
goto TheEnd

:error_no_ml
echo ===================================
echo   �訡��: 䠩� %masm32home%\bin\ml.exe,
echo   ����室��� ��� �࠭��樨, �� ������
echo ===================================
goto TheEnd

:error_no_link
echo ===================================
echo   �訡��: 䠩� %masm32home%\bin\link.exe,
echo   ����室��� ��� ����������, �� ������
echo ===================================
goto TheEnd

:error_no_dumppe
echo ===================================
echo   �訡��: 䠩� %masm32home%\bin\dumppe.exe,
echo   ����室��� ��� �����ᥬ���஢����, �� ������
echo ===================================
goto TheEnd

:error_masm32
echo ===================================
echo   �訡��: MASM32 �� ������
echo   ��������� ��稭�: ����୮ 
echo   ��⠭������ ��६����� masm32home
echo   ��� ����襭� ������� ��⠫����
echo ===================================
goto TheEnd

:error_asm
echo ==============================
echo   �訡��: �訡�� �࠭��樨
echo ==============================
goto TheEnd

:error_link
echo ==============================
echo   �訡��: �訡�� ����������
echo ==============================
goto TheEnd

:usage
echo masm32.bat - ������ 䠩� ��� �࠭��樨 / ���������� / ᡮન / �����ᥬ���஢����
echo.
echo �ᯮ�짮�����:
echo.
echo   masm32.bat -asm file
echo     �࠭���� 䠩�� file.asm
echo.
echo   masm32.bat -disasm file.exe
echo     �����ᥬ���஢���� 䠩�� file.exe
echo.
echo   masm32.bat -link:windows file 
echo     ���������� 䠩�� file.obj � ०��� Windows GUI
echo.
echo   masm32.bat -link:console file 
echo     ���������� 䠩�� file.obj � ०��� Console
echo.
echo   masm32.bat -build:windows file 
echo     ᡮઠ (�࠭����+����������) 䠩�� file.asm � ०��� Windows GUI
echo.
echo   masm32.bat -link:console file 
echo     ᡮઠ (�࠭����+����������) 䠩�� file.asm � ०��� Console
echo.
goto TheEnd

:TheEnd
pause
