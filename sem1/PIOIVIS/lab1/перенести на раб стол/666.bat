@chcp 65001 
echo off
set a=%1
set b=%2
tasklist /FI "MEMUSAGE ge %a% " /FI "MEMUSAGE le %b% " /FO "CSV"> fgh.txt
(for /f  "skip=1 tokens=1 delims=,"  %%p in ('type fgh.txt') do (echo %%p >> last1.txt))
sort last1.txt>>last2.txt
SetLocal EnableDelayedExpansion
for /f "usebackq delims=" %%A in ("last2.txt") do set "nkav=%%A" & call :zp "%nkav%"
exit /b
:zp
 echo.%nkav:"=%>>"rrrr.txt"





