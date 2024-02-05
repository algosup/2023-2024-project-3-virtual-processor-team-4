set ra xFFFFFF
set rb 32
set rc 64
SeparateRGB:
teqi rt ra xFFFFFF
bnz rt redComponent
teqi rt ra x00FFFF
bnz rt greenComponent
teqi rt ra x0000FF
bnz rt blueComponent
exit


redComponent:
// Isolate the red component from ra in rz
addi rz ra 0
andi rz xFF0000
addi rd rc 0
div rz rc
andi ra 0x00FFFF

greenComponent:
// Isolate the red component from ra in ry
addi ry ra 0
andi ry x00FF00
addi rd rb 0
div ry rd
andi ra x0000FF

blueComponent:
// Isolate the red component from ra in rx
addi rx ra 0
addi rd rb 0
div ra rd
exit