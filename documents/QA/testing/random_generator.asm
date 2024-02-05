// Your seed
sub ra ra
addi ra 5

// Constants
sub rb rb
addi rb 2147483648
sub rc rc
addi rc 1103515245
sub rd rd
addi rd 12345

random:
// future result in re
sub re re
add re ra
sub rf rf
add rf rb
sub rg rg
add rg rc
mul re rg
add re rd
div re rf
sub re re
add re rf