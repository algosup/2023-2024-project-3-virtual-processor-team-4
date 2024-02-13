# Appendix A - Instruction Set Manual

<!-- TODO: Fix opcodes -->

In this document, all optional parameters in the assembly are denoted in square brackets. For example, the absolute value (`abs [rd] rs`) using the same register as the destination and source (`abs ra ra`) can be shortened without specifying the destination (`abs ra`).

Note for all immediate instruction: Since the difference between a register and an immediate value can easily be made, the mnemonics with immediate values (I type) can be written like their register (R type) counterpart. Example `addi ra 5` can be written `add ra 5`.

<style>
    h2 {
        page-break-before: always;
    }
</style>

- [ABS - Absolute value](#abs---absolute-value)
- [ADD - Addition](#add---addition)
- [ADDI - Addition with immediate](#addi---addition-with-immediate)
- [AND - Logical AND](#and---logical-and)
- [ANDI - Logical AND with immediate](#andi---logical-and-with-immediate)
- [B - Relative indirect jump](#b---relative-indirect-jump)
- [BI - Relative jump](#bi---relative-jump)
- [BNZ - Relative jump if not zero](#bnz---relative-jump-if-not-zero)
- [BZ - Relative jump if zero](#bz---relative-jump-if-zero)
- [CALL - Call indirect subroutine (Jump and link)](#call---call-indirect-subroutine-jump-and-link)
- [CALLI - Call subroutine (Jump and link)](#calli---call-subroutine-jump-and-link)
- [DIV - Division](#div---division)
- [JMP - Absolute jump](#jmp---absolute-jump)
- [LD - Load with direct addressing](#ld---load-with-direct-addressing)
- [LDI - Load with direct immediate addressing](#ldi---load-with-direct-immediate-addressing)
- [LDP - Load with indirect addressing](#ldp---load-with-indirect-addressing)
- [MUL - Multiplication](#mul---multiplication)
- [OR - Logical OR](#or---logical-or)
- [ORI - Logical OR with immediate](#ori---logical-or-with-immediate)
- [POP - Pop register from stack ](#pop---pop-register-from-stack-)
- [PUSH - Push register on stack ](#push---push-register-on-stack-)
- [RET - Return from subroutine ](#ret---return-from-subroutine-)
- [SET - Set register to immediate ](#set---set-register-to-immediate-)
- [STR - Store with direct addressing ](#str---store-with-direct-addressing-)
- [STRI - Store with direct immediate addressing ](#stri---store-with-direct-immediate-addressing-)
- [STRP - Store with indirect addressing ](#strp---store-with-indirect-addressing-)
- [SUB - Subtraction](#sub---subtraction)
- [SUBI - Subtraction with immediate](#subi---subtraction-with-immediate)
- [TEQ - Test if equal ](#teq---test-if-equal-)
- [TEQI - Test if equal with immediate ](#teqi---test-if-equal-with-immediate-)
- [TGE - Test if greater or equal ](#tge---test-if-greater-or-equal-)
- [TGEI - Test if greater or equal with immediate ](#tgei---test-if-greater-or-equal-with-immediate-)
- [TGT - Test if strictly greater ](#tgt---test-if-strictly-greater-)
- [TGTI - Test if strictly greater with immediate ](#tgti---test-if-strictly-greater-with-immediate-)
- [TLE - Test if lower or equal ](#tle---test-if-lower-or-equal-)
- [TLEI - Test if lower or equal with immediate ](#tlei---test-if-lower-or-equal-with-immediate-)
- [TLT - Test if strictly lower ](#tlt---test-if-strictly-lower-)
- [TLTI - Test if strictly lower with immediate ](#tlti---test-if-strictly-lower-with-immediate-)
- [TNE - Test if not equal ](#tne---test-if-not-equal-)
- [TNEI - Test if not equal with immediate ](#tnei---test-if-not-equal-with-immediate-)
- [XCHG - Exchange registers](#xchg---exchange-registers)
- [XOR - Logical XOR](#xor---logical-xor)
- [XORI - Logical XOR with immediate](#xori---logical-xor-with-immediate)






## ABS - Absolute value

### Description

Calculates the absolute value of the source register and stores the result in the destination register.

### Syntax

`abs [rd] rs`

### Operands

- `rd`: Optional destination register, defaults to `rs`
- `rs`: Source register

### Operation

```
if (rs < 0)
  rd <- -rs
else
  rd >- rs
```

### Machine code

`0000000? ???????? ??????SS SSSDDDDD`

### Restrictions

`rd` cannot be `sp` or `ip`. Same condition applies for `rs` if no destination register is specified.

### Example

```
set ra -5
abs rb ra
```





## ADD - Addition

### Description

Adds the content of two registers without carry and stores the result in the destination register.

### Syntax

`add [rd] rs rt`

### Operands

- `rd`: Optional destination register, defaults to `rs`
- `rs`: First source register
- `rt`: Second source register

### Operation

`rd <- rs + rt`

### Machine code

`0000000? ???????? ?TTTTTSS SSSDDDDD`

### Restrictions

`rd` cannot be `sp` or `ip`. Same condition applies for `rs` if no destination register is specified.

### Example

```
add rc ra rb // rc = ra + rb
add rz sp // rz += sp
```





## ADDI - Addition with immediate

### Description

Adds the content of two registers without carry and stores the result in the destination register.

### Syntax

`add[i] [rd] rs imm`

### Operands

- `rd`: Optional destination register, defaults to `rs`
- `rs`: Source register
- `imm`: Immediate value of the subtrahend

### Operation

`rd <- rs + imm`

### Machine code

`0000000I IIIIIIII IIIIIISS SSSDDDDD`

### Restrictions

`rd` cannot be `sp` or `ip`. Same condition applies for `rs` if no destination register is specified.

### Example

```
addi rb ra 5 // rb = ra + 5
add rz -26 // rz += -26
```





## AND - Logical AND

### Description

Performs a bitwise logical AND operation between two registers and stores the result in the destination register.

### Syntax

`and [rd] rs rt`

### Operands

- `rd`: Optional destination register, defaults to `rs`
- `rs`: First source register
- `rt`: Second source register

### Operation

`rd <- rs & rt`

### Machine code

`0000000? ???????? ?TTTTTSS SSSDDDDD`

### Restrictions

`rd` cannot be `sp` or `ip`. Same condition applies for `rs` if no destination register is specified.

### Example

```
and rc ra rb // rc = ra & rb
and rz sp // rz &= sp
```





## ANDI - Logical AND with immediate

### Description

Performs a bitwise logical AND operation between the source register and the immediate value and stores the result in the destination register.

### Syntax

`and[i] [rd] rs imm`

### Operands

- `rd`: Optional destination register, defaults to `rs`
- `rs`: First source register
- `imm`: Immediate value

### Operation

`rd <- rs & imm`

### Machine code

`0000000I IIIIIIII IIIIIISS SSSDDDDD`

### Restrictions

`rd` cannot be `sp` or `ip`. Same condition applies for `rs` if no destination register is specified.

### Example

```
andi rb ra 5 // rb = ra & 5
and rz 26 // rz &= 26
```





## B - Relative indirect jump

### Description

Branches from the current address by the base in the specified register and a specific offset.

### Syntax

`b rb [off]`

### Operands

- `rb`: Base address register
- `off`: Optional offset, defaults to `0`

### Operation

`ip <- rb + offset`

### Machine code

`1000OOOO OOOOOOOO OOOOOOOO OOORRRRR`

### Restrictions

None

### Example

```
// switch case
tgei rb ra 3
jmp rb default
b ra 1
jmp case_0
jmp case_1
jmp case_2
switch_return:
```





## BI - Relative jump

### Description

Branches from the current address by the specified amount.

### Syntax

`bi imm`

### Operands

- `imm`: Signed offset for the address

### Operation

`ip <- ip + imm`

### Machine code

`1000AAAA AAAAAAAA AAAAAAAA AAARRRRR`

### Restrictions

None

### Example

<!-- TODO -->
```
```





## BNZ - Relative jump if not zero

### Description

Branches to the address if the value in the specified register is different from zero. 

### Syntax

`bnz reg imm`

### Operands

- `reg`: Comparison register
- `imm`: Signed offset for the address

### Operation


```
if (reg != 0)
  ip <- ip + imm
```

### Machine code

`1000AAAA AAAAAAAA AAAAAAAA AAARRRRR`

### Restrictions

None

### Example

```
bnz ra afterInitialization
// Initialize the value
afterInitialization:
```





## BZ - Relative jump if zero

### Description

Branches to the address if the value in the specified register is equal to zero. 

### Syntax

`bz reg imm`

### Operands

- `reg`: Comparison register
- `imm`: Signed offset for the address

### Operation


```
if (reg = 0)
  ip <- ip + imm
```

### Machine code

`1000AAAA AAAAAAAA AAAAAAAA AAARRRRR`

### Restrictions

None

### Example

```
bz ra dealWithDivisionByZero
div rb ra
```





## CALL - Call indirect subroutine (Jump and link)

### Description

Branches from the current address by the base in the specified register and a specific offset. Stores the address of the next current instruction on the top of the stack.

### Syntax

`call rb [off]`

### Operands

- `rb`: Base address register
- `off`: Optional offset, defaults to `0`

### Operation

```
[sp] <- ip + 1
sp <- sp + 1
ip <- rb + offset
```

### Machine code

`1000OOOO OOOOOOOO OOOOOOOO OOORRRRR`

### Restrictions

None

### Example

<!-- TODO -->

```
```





## CALLI - Call subroutine (Jump and link)

### Description

Branches from the current address by the specified amount. Stores the address of the next current instruction on the top of the stack.

### Syntax

`calli imm`

### Operands

- `imm`: Signed offset for the address

### Operation

`ip <- ip + imm`

### Machine code

`1000AAAA AAAAAAAA AAAAAAAA AAARRRRR`

### Restrictions

None

### Example

<!-- TODO -->
```
```





## DIV - Division

### Description

Performs an integer division of the content of the first source register by the content of the second one and stores the result in the destination register.

### Syntax

`div [rd] rs rt`

### Operands

- `rd`: Optional destination register, defaults to `rs`
- `rs`: Source register for the dividend
- `rt`: Source register for the divisor

### Operation

`rd <- rs / rt`

### Machine code

`0000000? ???????? ?TTTTTSS SSSDDDDD`

### Restrictions

`rd` cannot be `sp` or `ip`. Same condition applies for `rs` if no destination register is specified.

The value of `rt` must be different than 0.

### Example

```
[sp] <- ip + 1
sp <- sp + 1
ip <- ip + imm
```





## JMP - Absolute jump

### Description

Jumps to the specified absolute address.

### Syntax

`jmp addr`

### Operands

- `addr`: Absolute address to jump to

### Operation

`ip <- addr`

### Machine code

`1000AAAA AAAAAAAA AAAAAAAA AAAAAAAA`

### Restrictions

None

### Example

```
infiniteLoop:
jmp infiniteLoop
```





## LD - Load with direct addressing

### Description

Reads the address stored in the source register and loads the value at that address in the destination register.

### Syntax

`ld rd rs`

### Operands

- `rd`: Destination register
- `rs`: Source register holding the address

### Operation

`rd <- [rs]`

### Machine code

`00OOOOO? ???????? ??????SS SSSDDDDD`

### Restrictions

`rd` cannot be `sp` or `ip`

### Example

```
// rp: pointer to a 0-ended array of integers
set ra 0
sum:
ld rt rp
add ra ra rt
bnz rt sum
// ra: holds the sum
```





## LDI - Load with direct immediate addressing

### Description

Loads the value stored at the immediate address and stores it in the destination register.

### Syntax

`ldi rd imm`

### Operands

- `rd`: Destination register
- `imm`: Immediate address of the value

### Operation

`rd <- [imm]`

### Machine code

`01OOOOII IIIIIIII IIIIIIII IIIDDDDD`

### Restrictions

`rd` cannot be `sp` or `ip`

### Example

<!-- TODO -->
```
```





## LDP - Load with indirect addressing

### Description

Reads the address of the pointer stored in the source register and loads the value at the address pointed by the register into the destination register.

### Syntax

`ld rd rs`

### Operands

- `rd`: Destination register
- `rs`: Source register holding the address

### Operation

`rd <- [[rs]]`

or 

```
temp <- [rs]
rd <- [temp]
```

### Machine code

`00OOOOO? ???????? ??????SS SSSDDDDD`

### Restrictions

Neither `rd` nor `rs` can be `sp` or `ip`

### Example

<!-- TODO -->
```
```





## MUL - Multiplication

### Description

Multiplies the content of two registers without carry and stores the result in the destination register.

In case of overflow, the extra bits are discarded.

### Syntax

`mul [rd] rs rt`

### Operands

- `rd`: Optional destination register, defaults to `rs`
- `rs`: First source register
- `rt`: Second source register

### Operation

`rd <- rs * rt`

### Machine code

`0000000? ???????? ?TTTTTSS SSSDDDDD`

### Restrictions

`rd` cannot be `sp` or `ip`. Same condition applies for `rs` if no destination register is specified.

### Example

```
mul rc ra rb // rc = ra * rb
mul rz sp // rz * sp
```





## OR - Logical OR

### Description

Performs a bitwise logical OR operation between two registers and stores the result in the destination register.

### Syntax

`or [rd] rs rt`

### Operands

- `rd`: Optional destination register, defaults to `rs`
- `rs`: First source register
- `rt`: Second source register

### Operation

`rd <- rs | rt`

### Machine code

`0000000? ???????? ?TTTTTSS SSSDDDDD`

### Restrictions

`rd` cannot be `sp` or `ip`. Same condition applies for `rs` if no destination register is specified.

### Example

```
or rc ra rb // rc = ra | rb
or rz sp // rz |= sp
```





## ORI - Logical OR with immediate

### Description

Performs a bitwise logical OR operation between the source register and the immediate value and stores the result in the destination register.

### Syntax

`or[i] [rd] rs imm`

### Operands

- `rd`: Optional destination register, defaults to `rs`
- `rs`: First source register
- `imm`: Immediate value

### Operation

`rd <- rs | imm`

### Machine code

`0000000I IIIIIIII IIIIIISS SSSDDDDD`

### Restrictions

`rd` cannot be `sp` or `ip`. Same condition applies for `rs` if no destination register is specified.

### Example

```
ori rb ra 5 // rb = ra | 5
or rz 26 // rz |= 26
```





## POP - Pop register from stack <!-- TODO ########## -->

### Description

Here is a short description of what the instruction does.

### Syntax

`temp rd rs rt`

### Operands

- `rd`: Destination register

### Operation

`yes <- "Hello world"`

### Machine code

`???????? ???????? ???????? ????????`

### Restrictions

`rd` cannot be `sp` or `ip`

### Example

```
Just a sample program
that uses the instruction
```





## PUSH - Push register on stack <!-- TODO ########## -->

### Description

Here is a short description of what the instruction does.

### Syntax

`temp rd rs rt`

### Operands

- `rd`: Destination register

### Operation

`yes <- "Hello world"`

### Machine code

`???????? ???????? ???????? ????????`

### Restrictions

`rd` cannot be `sp` or `ip`

### Example

```
Just a sample program
that uses the instruction
```





## RET - Return from subroutine <!-- TODO ########## -->

### Description

Here is a short description of what the instruction does.

### Syntax

`temp rd rs rt`

### Operands

- `rd`: Destination register

### Operation

`yes <- "Hello world"`

### Machine code

`???????? ???????? ???????? ????????`

### Restrictions

`rd` cannot be `sp` or `ip`

### Example

```
Just a sample program
that uses the instruction
```





## SET - Set register to immediate <!-- TODO ########## -->

### Description

Here is a short description of what the instruction does.

### Syntax

`temp rd rs rt`

### Operands

- `rd`: Destination register

### Operation

`yes <- "Hello world"`

### Machine code

`???????? ???????? ???????? ????????`

### Restrictions

`rd` cannot be `sp` or `ip`

### Example

```
Just a sample program
that uses the instruction
```





## STR - Store with direct addressing <!-- TODO ########## -->

### Description

Here is a short description of what the instruction does.

### Syntax

`temp rd rs rt`

### Operands

- `rd`: Destination register

### Operation

`yes <- "Hello world"`

### Machine code

`???????? ???????? ???????? ????????`

### Restrictions

`rd` cannot be `sp` or `ip`

### Example

```
Just a sample program
that uses the instruction
```





## STRI - Store with direct immediate addressing <!-- TODO ########## -->

### Description

Here is a short description of what the instruction does.

### Syntax

`temp rd rs rt`

### Operands

- `rd`: Destination register

### Operation

`yes <- "Hello world"`

### Machine code

`???????? ???????? ???????? ????????`

### Restrictions

`rd` cannot be `sp` or `ip`

### Example

```
Just a sample program
that uses the instruction
```





## STRP - Store with indirect addressing <!-- TODO ########## -->

### Description

Here is a short description of what the instruction does.

### Syntax

`temp rd rs rt`

### Operands

- `rd`: Destination register

### Operation

`yes <- "Hello world"`

### Machine code

`???????? ???????? ???????? ????????`

### Restrictions

`rd` cannot be `sp` or `ip`

### Example

```
Just a sample program
that uses the instruction
```





## SUB - Subtraction

### Description

Subtracts the content of the second source register from the content of the first one without carry and stores the result in the destination register.

### Syntax

`sub [rd] rs rt`

### Operands

- `rd`: Optional destination register, defaults to `rs`
- `rs`: Source register for the minuhend
- `rt`: Source register for the subtrahend

### Operation

`rd <- rs - rt`

### Machine code

`0000000? ???????? ?TTTTTSS SSSDDDDD`

### Restrictions

`rd` cannot be `sp` or `ip`. Same condition applies for `rs` if no destination register is specified.

### Example

```
sub rc ra rb // rc = ra - rb
sub rz sp // rz -= sp
```





## SUBI - Subtraction with immediate

Subtracts the immediate value from the content of the source register without carry and stores the result in the destination register.

### Syntax

`sub[i] [rd] rs imm`

### Operands

- `rd`: Optional destination register, defaults to `rs`
- `rs`: Source register for the minuhend
- `imm`: Subtrahend immediate value

### Operation

`rd <- rs - imm`

### Machine code

`0000000I IIIIIIII IIIIIISS SSSDDDDD`

### Restrictions

`rd` cannot be `sp` or `ip`. Same condition applies for `rs` if no destination register is specified.

### Example

```
subi rb ra 5 // rb = ra - 5
sub rz -26 // rz -= -26
```





## TEQ - Test if equal <!-- TODO ########## -->

### Description

Here is a short description of what the instruction does.

### Syntax

`temp rd rs rt`

### Operands

- `rd`: Destination register

### Operation

`yes <- "Hello world"`

### Machine code

`???????? ???????? ???????? ????????`

### Restrictions

`rd` cannot be `sp` or `ip`

### Example

```
Just a sample program
that uses the instruction
```





## TEQI - Test if equal with immediate <!-- TODO ########## -->

### Description

Here is a short description of what the instruction does.

### Syntax

`temp rd rs rt`

### Operands

- `rd`: Destination register

### Operation

`yes <- "Hello world"`

### Machine code

`???????? ???????? ???????? ????????`

### Restrictions

`rd` cannot be `sp` or `ip`

### Example

```
Just a sample program
that uses the instruction
```





## TGE - Test if greater or equal <!-- TODO ########## -->

### Description

Here is a short description of what the instruction does.

### Syntax

`temp rd rs rt`

### Operands

- `rd`: Destination register

### Operation

`yes <- "Hello world"`

### Machine code

`???????? ???????? ???????? ????????`

### Restrictions

`rd` cannot be `sp` or `ip`

### Example

```
Just a sample program
that uses the instruction
```





## TGEI - Test if greater or equal with immediate <!-- TODO ########## -->

### Description

Here is a short description of what the instruction does.

### Syntax

`temp rd rs rt`

### Operands

- `rd`: Destination register

### Operation

`yes <- "Hello world"`

### Machine code

`???????? ???????? ???????? ????????`

### Restrictions

`rd` cannot be `sp` or `ip`

### Example

```
Just a sample program
that uses the instruction
```





## TGT - Test if strictly greater <!-- TODO ########## -->

### Description

Here is a short description of what the instruction does.

### Syntax

`temp rd rs rt`

### Operands

- `rd`: Destination register

### Operation

`yes <- "Hello world"`

### Machine code

`???????? ???????? ???????? ????????`

### Restrictions

`rd` cannot be `sp` or `ip`

### Example

```
Just a sample program
that uses the instruction
```





## TGTI - Test if strictly greater with immediate <!-- TODO ########## -->

### Description

Here is a short description of what the instruction does.

### Syntax

`temp rd rs rt`

### Operands

- `rd`: Destination register

### Operation

`yes <- "Hello world"`

### Machine code

`???????? ???????? ???????? ????????`

### Restrictions

`rd` cannot be `sp` or `ip`

### Example

```
Just a sample program
that uses the instruction
```





## TLE - Test if lower or equal <!-- TODO ########## -->

### Description

Here is a short description of what the instruction does.

### Syntax

`temp rd rs rt`

### Operands

- `rd`: Destination register

### Operation

`yes <- "Hello world"`

### Machine code

`???????? ???????? ???????? ????????`

### Restrictions

`rd` cannot be `sp` or `ip`

### Example

```
Just a sample program
that uses the instruction
```





## TLEI - Test if lower or equal with immediate <!-- TODO ########## -->

### Description

Here is a short description of what the instruction does.

### Syntax

`temp rd rs rt`

### Operands

- `rd`: Destination register

### Operation

`yes <- "Hello world"`

### Machine code

`???????? ???????? ???????? ????????`

### Restrictions

`rd` cannot be `sp` or `ip`

### Example

```
Just a sample program
that uses the instruction
```





## TLT - Test if strictly lower <!-- TODO ########## -->

### Description

Here is a short description of what the instruction does.

### Syntax

`temp rd rs rt`

### Operands

- `rd`: Destination register

### Operation

`yes <- "Hello world"`

### Machine code

`???????? ???????? ???????? ????????`

### Restrictions

`rd` cannot be `sp` or `ip`

### Example

```
Just a sample program
that uses the instruction
```





## TLTI - Test if strictly lower with immediate <!-- TODO ########## -->

### Description

Here is a short description of what the instruction does.

### Syntax

`temp rd rs rt`

### Operands

- `rd`: Destination register

### Operation

`yes <- "Hello world"`

### Machine code

`???????? ???????? ???????? ????????`

### Restrictions

`rd` cannot be `sp` or `ip`

### Example

```
Just a sample program
that uses the instruction
```





## TNE - Test if not equal <!-- TODO ########## -->

### Description

Here is a short description of what the instruction does.

### Syntax

`temp rd rs rt`

### Operands

- `rd`: Destination register

### Operation

`yes <- "Hello world"`

### Machine code

`???????? ???????? ???????? ????????`

### Restrictions

`rd` cannot be `sp` or `ip`

### Example

```
Just a sample program
that uses the instruction
```





## TNEI - Test if not equal with immediate <!-- TODO ########## -->

### Description

Here is a short description of what the instruction does.

### Syntax

`temp rd rs rt`

### Operands

- `rd`: Destination register

### Operation

`yes <- "Hello world"`

### Machine code

`???????? ???????? ???????? ????????`

### Restrictions

`rd` cannot be `sp` or `ip`

### Example

```
Just a sample program
that uses the instruction
```





## XCHG - Exchange registers

### Description

Swaps the content of two registers.

### Syntax

`xchg r1 r2`

### Operands

- `r1`: First register
- `r2`: Second register

### Operation

```
interal <- r1
r1 <- r2
r2 <- internal
```

### Machine code

`0000000? ???????? ??????SS SSSDDDDD`

### Restrictions

`r1` and `r2` cannot be `sp` or `ip`.

### Example

```
loopFibonacci:
add ra ra rb
xchg ra rb
jmp loopFibonacci
```





## XOR - Logical XOR

### Description

Performs a bitwise logical XOR operation between two registers and stores the result in the destination register.

### Syntax

`xor [rd] rs rt`

### Operands

- `rd`: Optional destination register, defaults to `rs`
- `rs`: First source register
- `rt`: Second source register

### Operation

`rd <- rs ^ rt`

### Machine code

`0000000? ???????? ?TTTTTSS SSSDDDDD`

### Restrictions

`rd` cannot be `sp` or `ip`. Same condition applies for `rs` if no destination register is specified.

### Example

```
xor rc ra rb // rc = ra ^ rb
xor rz sp // rz ^= sp
```





## XORI - Logical XOR with immediate

### Description

Performs a bitwise logical XOR operation between the source register and the immediate value and stores the result in the destination register.

### Syntax

`xor[i] [rd] rs imm`

### Operands

- `rd`: Optional destination register, defaults to `rs`
- `rs`: First source register
- `imm`: Immediate value

### Operation

`rd <- rs ^ imm`

### Machine code

`0000000I IIIIIIII IIIIIISS SSSDDDDD`

### Restrictions

`rd` cannot be `sp` or `ip`. Same condition applies for `rs` if no destination register is specified.

### Example

```
xori rb ra 5 // rb = ra ^ 5
xor rz 26 // rz ^= 26
```