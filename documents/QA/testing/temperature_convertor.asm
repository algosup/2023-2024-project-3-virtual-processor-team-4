sub ra ra
addi ra 0

call celsiusToKelvin
call celisusToFarhenheit
exit

celsiusToKelvin:
sub rb rb
add rb ra
addi rb 273
ret

celsiusToFarenheit:
sub rc rc
add rc ra
sub rd rd
addi rd 9
sub re re
addi re 5
mul rc rd
div rc re
addi rc 32
ret