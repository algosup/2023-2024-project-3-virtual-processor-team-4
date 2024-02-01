# Appendix A - Instruction Set Manual

<!-- TODO: Fix opcodes -->

Note for all immediate instruction: Since the difference between a register and an immediate value can easily be made, the mnemonics with immediate values (I type) can be written like their register (R type) counterpart. Example `addi ra 5` can be written `add ra 5`.

<style>
    h2 {
        page-break-before: always;
    }

    li ul {
        /*
            Since we cannot have per-file configuration,
            instead we hide the extra levels of the ToC.
        */
        display: none;
    }
</style>

- [ADD - Addition](#add---addition)
  - [Description](#description)
  - [Syntax](#syntax)
  - [Operands](#operands)
  - [Operation](#operation)
  - [Machine code](#machine-code)
  - [Restrictions](#restrictions)
  - [Example](#example)
- [ADDI - Addition with immediate](#addi---addition-with-immediate)
  - [Description](#description-1)
  - [Syntax](#syntax-1)
  - [Operands](#operands-1)
  - [Operation](#operation-1)
  - [Machine code](#machine-code-1)
  - [Restrictions](#restrictions-1)
  - [Example](#example-1)
- [AND - Logical AND](#and---logical-and)
  - [Description](#description-2)
  - [Syntax](#syntax-2)
  - [Operands](#operands-2)
  - [Operation](#operation-2)
  - [Machine code](#machine-code-2)
  - [Restrictions](#restrictions-2)
  - [Example](#example-2)
- [ANDI - Logical AND with immediate](#andi---logical-and-with-immediate)
  - [Description](#description-3)
  - [Syntax](#syntax-3)
  - [Operands](#operands-3)
  - [Operation](#operation-3)
  - [Machine code](#machine-code-3)
  - [Restrictions](#restrictions-3)
  - [Example](#example-3)
- [CALL - Call subroutine (Jump and link) ](#call---call-subroutine-jump-and-link-)
  - [Description](#description-4)
  - [Syntax](#syntax-4)
  - [Operands](#operands-4)
  - [Operation](#operation-4)
  - [Machine code](#machine-code-4)
  - [Restrictions](#restrictions-4)
  - [Example](#example-4)
- [DIV - Division](#div---division)
  - [Description](#description-5)
  - [Syntax](#syntax-5)
  - [Operands](#operands-5)
  - [Operation](#operation-5)
  - [Machine code](#machine-code-5)
  - [Restrictions](#restrictions-5)
  - [Example](#example-5)
- [JABS - Absolute jump ](#jabs---absolute-jump-)
  - [Description](#description-6)
  - [Syntax](#syntax-6)
  - [Operands](#operands-6)
  - [Operation](#operation-6)
  - [Machine code](#machine-code-6)
  - [Restrictions](#restrictions-6)
  - [Example](#example-6)
- [JNZ - Relative jump if not zero ](#jnz---relative-jump-if-not-zero-)
  - [Description](#description-7)
  - [Syntax](#syntax-7)
  - [Operands](#operands-7)
  - [Operation](#operation-7)
  - [Machine code](#machine-code-7)
  - [Restrictions](#restrictions-7)
  - [Example](#example-7)
- [JZ - Relative jump if zero ](#jz---relative-jump-if-zero-)
  - [Description](#description-8)
  - [Syntax](#syntax-8)
  - [Operands](#operands-8)
  - [Operation](#operation-8)
  - [Machine code](#machine-code-8)
  - [Restrictions](#restrictions-8)
  - [Example](#example-8)
- [LD - Load with direct addressing ](#ld---load-with-direct-addressing-)
  - [Description](#description-9)
  - [Syntax](#syntax-9)
  - [Operands](#operands-9)
  - [Operation](#operation-9)
  - [Machine code](#machine-code-9)
  - [Restrictions](#restrictions-9)
  - [Example](#example-9)
- [LDI - Load with direct immediate addressing ](#ldi---load-with-direct-immediate-addressing-)
  - [Description](#description-10)
  - [Syntax](#syntax-10)
  - [Operands](#operands-10)
  - [Operation](#operation-10)
  - [Machine code](#machine-code-10)
  - [Restrictions](#restrictions-10)
  - [Example](#example-10)
- [LDP - Load with indirect addressing ](#ldp---load-with-indirect-addressing-)
  - [Description](#description-11)
  - [Syntax](#syntax-11)
  - [Operands](#operands-11)
  - [Operation](#operation-11)
  - [Machine code](#machine-code-11)
  - [Restrictions](#restrictions-11)
  - [Example](#example-11)
- [MUL - Multiplication](#mul---multiplication)
  - [Description](#description-12)
  - [Syntax](#syntax-12)
  - [Operands](#operands-12)
  - [Operation](#operation-12)
  - [Machine code](#machine-code-12)
  - [Restrictions](#restrictions-12)
  - [Example](#example-12)
- [OR - Logical OR](#or---logical-or)
  - [Description](#description-13)
  - [Syntax](#syntax-13)
  - [Operands](#operands-13)
  - [Operation](#operation-13)
  - [Machine code](#machine-code-13)
  - [Restrictions](#restrictions-13)
  - [Example](#example-13)
- [ORI - Logical OR with immediate](#ori---logical-or-with-immediate)
  - [Description](#description-14)
  - [Syntax](#syntax-14)
  - [Operands](#operands-14)
  - [Operation](#operation-14)
  - [Machine code](#machine-code-14)
  - [Restrictions](#restrictions-14)
  - [Example](#example-14)
- [POP - Pop register from stack ](#pop---pop-register-from-stack-)
  - [Description](#description-15)
  - [Syntax](#syntax-15)
  - [Operands](#operands-15)
  - [Operation](#operation-15)
  - [Machine code](#machine-code-15)
  - [Restrictions](#restrictions-15)
  - [Example](#example-15)
- [PUSH - Push register on stack ](#push---push-register-on-stack-)
  - [Description](#description-16)
  - [Syntax](#syntax-16)
  - [Operands](#operands-16)
  - [Operation](#operation-16)
  - [Machine code](#machine-code-16)
  - [Restrictions](#restrictions-16)
  - [Example](#example-16)
- [RET - Return from subroutine ](#ret---return-from-subroutine-)
  - [Description](#description-17)
  - [Syntax](#syntax-17)
  - [Operands](#operands-17)
  - [Operation](#operation-17)
  - [Machine code](#machine-code-17)
  - [Restrictions](#restrictions-17)
  - [Example](#example-17)
- [STR - Store with direct addressing ](#str---store-with-direct-addressing-)
  - [Description](#description-18)
  - [Syntax](#syntax-18)
  - [Operands](#operands-18)
  - [Operation](#operation-18)
  - [Machine code](#machine-code-18)
  - [Restrictions](#restrictions-18)
  - [Example](#example-18)
- [STRI - Store with direct immediate addressing ](#stri---store-with-direct-immediate-addressing-)
  - [Description](#description-19)
  - [Syntax](#syntax-19)
  - [Operands](#operands-19)
  - [Operation](#operation-19)
  - [Machine code](#machine-code-19)
  - [Restrictions](#restrictions-19)
  - [Example](#example-19)
- [STRP - Store with indirect addressing ](#strp---store-with-indirect-addressing-)
  - [Description](#description-20)
  - [Syntax](#syntax-20)
  - [Operands](#operands-20)
  - [Operation](#operation-20)
  - [Machine code](#machine-code-20)
  - [Restrictions](#restrictions-20)
  - [Example](#example-20)
- [SUB - Subtraction](#sub---subtraction)
  - [Description](#description-21)
  - [Syntax](#syntax-21)
  - [Operands](#operands-21)
  - [Operation](#operation-21)
  - [Machine code](#machine-code-21)
  - [Restrictions](#restrictions-21)
  - [Example](#example-21)
- [SUBI - Subtraction with immediate](#subi---subtraction-with-immediate)
  - [Syntax](#syntax-22)
  - [Operands](#operands-22)
  - [Operation](#operation-22)
  - [Machine code](#machine-code-22)
  - [Restrictions](#restrictions-22)
  - [Example](#example-22)
- [TEQ - Test if equal ](#teq---test-if-equal-)
  - [Description](#description-22)
  - [Syntax](#syntax-23)
  - [Operands](#operands-23)
  - [Operation](#operation-23)
  - [Machine code](#machine-code-23)
  - [Restrictions](#restrictions-23)
  - [Example](#example-23)
- [TEQI - Test if equal with immediate ](#teqi---test-if-equal-with-immediate-)
  - [Description](#description-23)
  - [Syntax](#syntax-24)
  - [Operands](#operands-24)
  - [Operation](#operation-24)
  - [Machine code](#machine-code-24)
  - [Restrictions](#restrictions-24)
  - [Example](#example-24)
- [TGE - Test if greater or equal ](#tge---test-if-greater-or-equal-)
  - [Description](#description-24)
  - [Syntax](#syntax-25)
  - [Operands](#operands-25)
  - [Operation](#operation-25)
  - [Machine code](#machine-code-25)
  - [Restrictions](#restrictions-25)
  - [Example](#example-25)
- [TGEI - Test if greater or equal with immediate ](#tgei---test-if-greater-or-equal-with-immediate-)
  - [Description](#description-25)
  - [Syntax](#syntax-26)
  - [Operands](#operands-26)
  - [Operation](#operation-26)
  - [Machine code](#machine-code-26)
  - [Restrictions](#restrictions-26)
  - [Example](#example-26)
- [TGT - Test if strictly greater ](#tgt---test-if-strictly-greater-)
  - [Description](#description-26)
  - [Syntax](#syntax-27)
  - [Operands](#operands-27)
  - [Operation](#operation-27)
  - [Machine code](#machine-code-27)
  - [Restrictions](#restrictions-27)
  - [Example](#example-27)
- [TGTI - Test if strictly greater with immediate ](#tgti---test-if-strictly-greater-with-immediate-)
  - [Description](#description-27)
  - [Syntax](#syntax-28)
  - [Operands](#operands-28)
  - [Operation](#operation-28)
  - [Machine code](#machine-code-28)
  - [Restrictions](#restrictions-28)
  - [Example](#example-28)
- [TLE - Test if lower or equal ](#tle---test-if-lower-or-equal-)
  - [Description](#description-28)
  - [Syntax](#syntax-29)
  - [Operands](#operands-29)
  - [Operation](#operation-29)
  - [Machine code](#machine-code-29)
  - [Restrictions](#restrictions-29)
  - [Example](#example-29)
- [TLEI - Test if lower or equal with immediate ](#tlei---test-if-lower-or-equal-with-immediate-)
  - [Description](#description-29)
  - [Syntax](#syntax-30)
  - [Operands](#operands-30)
  - [Operation](#operation-30)
  - [Machine code](#machine-code-30)
  - [Restrictions](#restrictions-30)
  - [Example](#example-30)
- [TLT - Test if strictly lower ](#tlt---test-if-strictly-lower-)
  - [Description](#description-30)
  - [Syntax](#syntax-31)
  - [Operands](#operands-31)
  - [Operation](#operation-31)
  - [Machine code](#machine-code-31)
  - [Restrictions](#restrictions-31)
  - [Example](#example-31)
- [TLTI - Test if strictly lower with immediate ](#tlti---test-if-strictly-lower-with-immediate-)
  - [Description](#description-31)
  - [Syntax](#syntax-32)
  - [Operands](#operands-32)
  - [Operation](#operation-32)
  - [Machine code](#machine-code-32)
  - [Restrictions](#restrictions-32)
  - [Example](#example-32)
- [TNE - Test if not equal ](#tne---test-if-not-equal-)
  - [Description](#description-32)
  - [Syntax](#syntax-33)
  - [Operands](#operands-33)
  - [Operation](#operation-33)
  - [Machine code](#machine-code-33)
  - [Restrictions](#restrictions-33)
  - [Example](#example-33)
- [TNEI - Test if not equal with immediate ](#tnei---test-if-not-equal-with-immediate-)
  - [Description](#description-33)
  - [Syntax](#syntax-34)
  - [Operands](#operands-34)
  - [Operation](#operation-34)
  - [Machine code](#machine-code-34)
  - [Restrictions](#restrictions-34)
  - [Example](#example-34)
- [XCHG - Exchange registers ](#xchg---exchange-registers-)
  - [Description](#description-34)
  - [Syntax](#syntax-35)
  - [Operands](#operands-35)
  - [Operation](#operation-35)
  - [Machine code](#machine-code-35)
  - [Restrictions](#restrictions-35)
  - [Example](#example-35)
- [XOR - Logical XOR](#xor---logical-xor)
  - [Description](#description-35)
  - [Syntax](#syntax-36)
  - [Operands](#operands-36)
  - [Operation](#operation-36)
  - [Machine code](#machine-code-36)
  - [Restrictions](#restrictions-36)
  - [Example](#example-36)
- [XORI - Logical XOR with immediate](#xori---logical-xor-with-immediate)
  - [Description](#description-36)
  - [Syntax](#syntax-37)
  - [Operands](#operands-37)
  - [Operation](#operation-37)
  - [Machine code](#machine-code-37)
  - [Restrictions](#restrictions-37)
  - [Example](#example-37)






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





## CALL - Call subroutine (Jump and link) <!-- TODO ########## -->

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
div rc ra rb // rc = ra / rb
div rz sp // rz /= sp
```





## JABS - Absolute jump <!-- TODO ########## -->

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





## JNZ - Relative jump if not zero <!-- TODO ########## -->

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





## JZ - Relative jump if zero <!-- TODO ########## -->

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





## LD - Load with direct addressing <!-- TODO ########## -->

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





## LDI - Load with direct immediate addressing <!-- TODO ########## -->

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





## LDP - Load with indirect addressing <!-- TODO ########## -->

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





## XCHG - Exchange registers <!-- TODO ########## -->

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