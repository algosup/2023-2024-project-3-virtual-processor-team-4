set ra x234561

tle rt ra xF
bnz rt exitProg
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
jmp exitProg

twoDigits:
set rd 16
addi re rd 0
calli roll
jmp exitProg

threeDigits:
set rd 256
set re 16
calli roll
jmp exitProg

fourDigits:
set rd 4096
set re 16
calli roll
jmp exitProg

fiveDigits:
set rd 65536
set re 16
calli roll
jmp exitProg

sixDigits:
set rd 1048576
set re 16
calli roll
jmp exitProg

roll:
andi rb x0F
mul rb rd
div rc re
add rb rc
ret

exitProg:
// exit the prog