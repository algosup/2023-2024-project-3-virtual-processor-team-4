// set a random number
set ra xFFFFFF

// set the length of the number
set ry 6

// set the power
set rz 0

// set the division/multiplication
set rd 16

loop:
// check if there is any other hexadecimal digit
teqi rt ry 0
bnz rt exitProg
subi ry 1
addi rb ra 0
// select the last digit
andi rb x0F
// check the value of the digit
tlti rt rb x9
bnz rt addNum
teqi rt rb xA
bnz rt isA
teqi rt rb xB
bnz rt xB
teqi rt rb xC
bnz rt isC
teqi rt rb xD
bnz rt isD
teqi rt rb xE
bnz rt isE
teqi rt rb xF
bnz rt isF

isA:
// convert hexa digit in decimal number
set rb 10
jmp addNum

isB:
// convert hexa digit in decimal number
set rb 11
jmp addNum

isC:
// convert hexa digit in decimal number
set rb 12
jmp addNum

isD:
// convert hexa digit in decimal number
set rb 13
jmp addNum

isE:
// convert hexa digit in decimal number
set rb 14
jmp addNum

isF:
// convert hexa digit in decimal number
set rb 15

addNum:
addi rc rz 0
// check the rank of the digit
tnei rt rc 0
bnz rt innerLoop
// if rc = 0 add the value without modification
add rs rb
jmp shift
innerLoop:
// loop that multiply by 16 rb until the rc become null
teqi rt rc 0
bnz rt endInnerLoop
mul rb rd
subi rc 1
jmp innerLoop
endInnerLoop:
add rs rb

shift:
// increment rz, shift to the right, return to loop
addi rz 1
div ra rd
jmp loop

exitProg:
// exit the prog