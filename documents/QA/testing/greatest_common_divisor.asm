sub ra ra
addi ra ...
sub rb rb
addi rb ...

tgeq ra rb
jnz greaterOrEqual
sub rc rc
add rc rb
jabs next
greatetOrEqual:
sub rc rc
add rc ra

next:
teqi rc 0
jnz end
sub ry ry
add ry ra
sub rz rz
add rz rb
sub rd rd
add rd rc
div ry rd
teqi rd 0
jnz secondTest
subi rc 1
jabs next

secondTest:
sub rd rd
add rd rc
div rz rd
teqi rd 0
jnz end
subi rc 1
jabs next

end:
exit