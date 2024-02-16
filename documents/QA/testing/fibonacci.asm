// TODO: Ask for value of c
set rc 8 // Calculate the 8th value
set ra 0
set rb 1
loop:
add ra rb
xchg ra rb
subi rc 1
teqi rt rc 1
bz rt loop
// TODO: Print result (=21)