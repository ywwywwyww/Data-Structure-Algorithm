:loop
3g > 3.in
3 < 3.in > 3.out
32 < 3.in > 32.out
fc 3.out 32.out
if %errorlevel%==0 goto loop
pause