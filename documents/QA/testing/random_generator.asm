// Your seed
set ra 5

// Constants
set rb 2147483648
set rc 1103515245
set rd 12345

random:
// future result in re
addi re ra 0
addi rf rb 0
addi rg rc 0
mul re rg
add re rd
div re rf           // TODO MODULO
addi re rf 0