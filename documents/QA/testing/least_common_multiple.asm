set ra 30
set rb 40

tgt rt ra rb
bnz rt greaterThan
// rc will be the greater and rd the smallest
addi rc rb 0
addi rd ra 0
// set the incrementation
addi rz rb 0
jmp next
greaterThan:
addi rc ra 0
addi rd rb 0
addi rz ra 0

next:
addi re rc 0
addi rf rd 0
addi rm re 0
calli modulo
teqi rt rm 0
bnz rt end
add rc rz
jmp next

modulo:
tlt rt rm rf
bnz rt endModulo
sub rm rf
jmp modulo
endModulo:
ret

end:
// exit the prog