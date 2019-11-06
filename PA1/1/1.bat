:loop
1g > 1.in
1
12 < 1.in > 12.out
fc 1.out 12.out
if %errorlevel%==0 goto loop
pause
