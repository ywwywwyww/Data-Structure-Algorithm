:loop
4g > 4.in
4 < 4.in > 4.out
42 < 4.in > 42.out
fc 4.out 42.out
if %errorlevel%==0 goto loop
pause
