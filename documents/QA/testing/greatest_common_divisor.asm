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
div ry rd           // TODO MODULO
teqi rt rd 0
bnz rt secondTest
subi rc 1
jmp next

secondTest:
addi rd rc 0
div rz rd           // TODO MODULO
teqi rt rd 0
bnz rt end
subi rc 1
jmp next

end:
exit