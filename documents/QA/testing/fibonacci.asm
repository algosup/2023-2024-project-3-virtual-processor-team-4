// TODO: Ask for value of c
sub rc rc
add rc 8 // Calculate the 8th value
sub ra ra
add ra 0
sub rb rb
add rb 1
loop:
add ra rb
xchg ra rb
subi rc 1
teqi rc 1
jz loop
// TODO: Print result (=21)