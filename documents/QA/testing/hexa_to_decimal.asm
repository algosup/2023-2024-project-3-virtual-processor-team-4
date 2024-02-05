// set a random number
sub ra ra
addi ra xFFFFFF

// set the length of the number
sub ry ry
add ry 6

// set the power
sub rz rz
add rz 0

// set the division/multiplication
sub rd rd
add rd 16

loop:
// check if there is any other hexadecimal digit
teqi ry 0
jnz exitProg
subi ry 1
sub rb rb
add rb ra
// select the last digit
andi rb x0F
// check the value of the digit
tlei rb x9
jnz addNum
teqi rb xA
jnz isA
teqi rb xB
jnz xB
teqi rb xC
jnz isC
teqi rb xD
jnz isD
teqi rb xE
jnz isE
teqi rb xF
jnz isF

exitProg:
exit

isA:
// convert hexa digit in decimal number
sub rb rb
addi rb 10
jabs addNum

isB:
// convert hexa digit in decimal number
sub rb rb
addi rb 11
jabs addNum

isC:
// convert hexa digit in decimal number
sub rb rb
addi rb 12
jabs addNum

isD:
// convert hexa digit in decimal number
sub rb rb
addi rb 13
jabs addNum

isE:
// convert hexa digit in decimal number
sub rb rb
addi rb 14
jabs addNum

isF:
// convert hexa digit in decimal number
sub rb rb
addi rb 15

addNum:
sub rc rc
add rc rz
// check the rank of the digit
tnei rc 0
jnz innerLoop
// if rc = 0 add the value without modification
add rs rb
jabs shift
innerLoop:
// loop that multiply by 16 rb until the rc become null
teqi rc 0
jnz endInnerLoop
mul rb rd
subi rc 1
jabs innerLoop
endInnerLoop:
add rs rb

shift:
// increment rz, shift to the right, return to loop
addi rz 1
div ra rd
jabs loop