set ra 0

call celsiusToKelvin
call celisusToFarhenheit
exit

celsiusToKelvin:
addi rb ra 0
addi rb 273
ret

celsiusToFarenheit:
addi rc ra 0
set rd 9
set re 5
mul rc rd
div rc re
addi rc 32
ret