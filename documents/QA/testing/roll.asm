set ra x234561

tle rt ra xF
bnz rt end
addi rb ra 0
addi rc ra 0
tle rt ra xFF
bnz rt twoDigits
tle rt ra xFFF
bnz rt threeDigits
tle rt ra xFFFF
bnz rt fourDigits
tle rt ra xFFFFF
bnz rt fiveDigits
tle rt ra xFFFFFF
bnz rt sixDigits
exit

twoDigits:
set rd 16
addi re rd 0
call roll
exit

threeDigits:
set rd 256
set re 16
call roll
exit

fourDigits:
set rd 4096
set re 16
call roll
exit

fiveDigits:
set rd 65536
set re 16
call roll
exit

sixDigits:
set rd 1048576
set re 16
call roll
exit

roll:
andi rb x0F
mul rb rd
div rc re
add rb rc
ret