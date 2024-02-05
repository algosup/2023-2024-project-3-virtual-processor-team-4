sub ra ra
add ra xFFFFFF
sub rb rb
add rb 32
sub rc rc
add rc 64
SeparateRGB:
teqi ra xFFFFFF
jnz redComponent
teqi ra x00FFFF
jnz greenComponent
teqi ra x0000FF
jnz blueComponent
exit


redComponent:
// Isolate the red component from ra in rz
sub rz rz
add rz ra
andi rz xFF0000
sub rd rd
add rd rc
div rz rc
andi ra 0x00FFFF

greenComponent:
// Isolate the red component from ra in ry
sub ry ry
add ry ra
andi ry x00FF00
sub rd rd
add rd rb
div ry rd
andi ra x0000FF

blueComponent:
// Isolate the red component from ra in rx
sub rx rx
add rx ra
sub rd rd
add rd rb
div ra rd
exit