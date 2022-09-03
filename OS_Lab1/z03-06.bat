echo off
cls
echo --1st param: %1
echo --2nd param: %2
echo --3rd param: %3
set /A a = %1%
set /A b = %2%
set /A c = %3%
set /A res = %1 %3 %2
echo %res%
pause