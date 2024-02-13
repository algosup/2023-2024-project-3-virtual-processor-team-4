set ra 30
set rb 40

tge rt ra rb
bnz rt greaterOrEqual
addi rc rb 0
jmp next
greatetOrEqual:
addi rc ra 0

next:
teqi rt rc 0
bnz rt end
addi ry ra 0
addi rz rb 0
addi rd rc 0
addi rm ry 0
call modulo
teqi rt rm 0
bnz rt secondTest
subi rc 1
jmp next

secondTest:
addi rd rc 0
addi rm rz 0
call modulo
teqi rt rm 0
bnz rt end
subi rc 1
jmp next

modulo:
tlt rt rm rd
bnz rt endModulo
sub rm rd
jmp modulo
endModulo:
ret

end:
exit