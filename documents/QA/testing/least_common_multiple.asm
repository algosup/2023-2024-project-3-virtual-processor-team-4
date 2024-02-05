sub ra ra
addi ra ...
sub rb rb
addi rb ...

tgt ra rb
jnz greaterThan
// rc will be the greater and rd the smallest
sub rc rc
add rc rb
sub rd rd
add rd ra
// set the incrementation
sub rz rz
add rz rb
jabs next
greaterThan:
sub rc rc
add rc ra
sub rd rd
add rd rb
sub rz rz
add rz ra

next:
sub re re
add re rc
sub rf rf
add rf rd
div re rf
teqi rf 0
jnz end
add rc rz
jabs next

end:
exit