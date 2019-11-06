:loop
2g > 2.in
2
23 < 2.in > 22.out
fc 2.out 22.out
if %errorlevel%==0 goto loop
pause
