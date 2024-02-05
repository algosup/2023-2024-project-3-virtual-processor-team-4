sub ra ra
addi ra x234561

tleq ra xF
jnz end
sub rb rb
add rb ra
sub rc rc
add rc ra
tleq ra xFF
jnz twoDigits
tleq ra xFFF
jnz threeDigits
tleq ra xFFFF
jnz fourDigits
tleq ra xFFFFF
jnz fiveDigits
tleq ra xFFFFFF
jnz sixDigits
exit

twoDigits:
sub rd rd
addi rd 16
sub re re
add re rd
call roll
exit

threeDigits:
sub rd rd
addi rd 32
sub re re
addi re 16
call roll
exit

fourDigits:
sub rd rd
addi rd 48
sub re re
addi re 16
call roll
exit

fiveDigits:
sub rd rd
addi rd 64
sub re re
addi re 16
call roll
exit

sixDigits:
sub rd rd
addi rd 80
sub re re
addi re 16
call roll
exit

roll:
andi rb x0F
mul rb rd
div rc re
add rb rc
ret