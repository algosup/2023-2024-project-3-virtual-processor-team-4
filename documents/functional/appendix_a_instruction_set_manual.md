# Appendix A - Instruction Set Manual

Note: This document takes time to write and will not be done before the deadline of the functional specifications. You may refer to the program manager for further information in the meantime.

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

- [TEMPLATE - An example](#template---an-example)
  - [Description](#description)
  - [Syntax](#syntax)
  - [Operands](#operands)
  - [Operation](#operation)
  - [Machine code](#machine-code)
  - [Restrictions](#restrictions)
  - [Example](#example)
- [ADD - Addition](#add---addition)
  - [Description](#description-1)
  - [Syntax](#syntax-1)
  - [Operands](#operands-1)
  - [Operation](#operation-1)
  - [Machine code](#machine-code-1)
  - [Restrictions](#restrictions-1)
  - [Example](#example-1)
- [SUB - Subtraction](#sub---subtraction)
  - [Description](#description-2)
  - [Syntax](#syntax-2)
  - [Operands](#operands-2)
  - [Operation](#operation-2)
  - [Machine code](#machine-code-2)
  - [Restrictions](#restrictions-2)
  - [Example](#example-2)
- [MUL - Multiplication](#mul---multiplication)
- [DIV - Division](#div---division)
- [OR - Logical OR](#or---logical-or)
- [AND - Logical AND](#and---logical-and)
- [XOR - Logical XOR](#xor---logical-xor)
- [TEQ - Test if equal](#teq---test-if-equal)
- [TNE - Test if not equal](#tne---test-if-not-equal)
- [TLT - Test if strictly lower](#tlt---test-if-strictly-lower)
- [TLE - Test if lower or equal](#tle---test-if-lower-or-equal)
- [TGT - Test if strictly greater](#tgt---test-if-strictly-greater)
- [TGE - Test if greater or equal](#tge---test-if-greater-or-equal)
- [PUSH - Push register on stack](#push---push-register-on-stack)
- [POP - Pop register from stack](#pop---pop-register-from-stack)
- [STR - Store with direct addressing](#str---store-with-direct-addressing)
- [LD - Load with direct addressing](#ld---load-with-direct-addressing)
- [STRP - Store with indirect addressing](#strp---store-with-indirect-addressing)
- [LDP - Load with indirect addressing](#ldp---load-with-indirect-addressing)
- [XCHG - Exchange registers](#xchg---exchange-registers)
- [ADDI - Addition with immediate](#addi---addition-with-immediate)
- [SUBI - Subtraction with immediate](#subi---subtraction-with-immediate)
- [ORI - Logical OR with immediate](#ori---logical-or-with-immediate)
- [ANDI - Logical AND with immediate](#andi---logical-and-with-immediate)
- [XORI - Logical XOR with immediate](#xori---logical-xor-with-immediate)
- [TEQI - Test if equal with immediate](#teqi---test-if-equal-with-immediate)
- [TNEI - Test if not equal with immediate](#tnei---test-if-not-equal-with-immediate)
- [TLTI - Test if strictly lower with immediate](#tlti---test-if-strictly-lower-with-immediate)
- [TLEI - Test if lower or equal with immediate](#tlei---test-if-lower-or-equal-with-immediate)
- [TGTI - Test if strictly greater with immediate](#tgti---test-if-strictly-greater-with-immediate)
- [TGEI - Test if greater or equal with immediate](#tgei---test-if-greater-or-equal-with-immediate)
- [STRI - Store with direct immediate addressing](#stri---store-with-direct-immediate-addressing)
- [LDI - Load with direct immediate addressing](#ldi---load-with-direct-immediate-addressing)
- [JZ - Relative jump if zero](#jz---relative-jump-if-zero)
- [JNZ - Relative jump if not zero](#jnz---relative-jump-if-not-zero)
- [CALL - Call subroutine (Jump and link)](#call---call-subroutine-jump-and-link)
- [RET - Return from subroutine](#ret---return-from-subroutine)
- [JABS - Absolute jump](#jabs---absolute-jump)

## TEMPLATE - An example

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

`0000000? ???????? ?SSSSSSS SSSDDDDD`

### Restrictions

`rd` cannot be `sp` or `ip`. Same condition applies for `rs` if no destination register is specified.

### Example

```
add rc ra rb // rc = ra + rb
add rz sp // rz += sp
```




## SUB - Subtraction

### Description

Subtracts the content of the second register from the content of the first one without carry and stores the result in the destination register.

### Syntax

`sub [rd] rs rt`

### Operands

- `rd`: Optional destination register, defaults to `rs`
- `rs`: First source register
- `rt`: Second source register

### Operation

`rd <- rs - rt`

### Machine code

`0000000? ???????? ?SSSSSSS SSSDDDDD`

### Restrictions

`rd` cannot be `sp` or `ip`. Same condition applies for `rs` if no destination register is specified.

### Example

```
sub rc ra rb // rc = ra - rb
sub rz sp // rz -= sp
```




## MUL - Multiplication
## DIV - Division
## OR - Logical OR
## AND - Logical AND
## XOR - Logical XOR
## TEQ - Test if equal
## TNE - Test if not equal
## TLT - Test if strictly lower
## TLE - Test if lower or equal
## TGT - Test if strictly greater
## TGE - Test if greater or equal
## PUSH - Push register on stack
## POP - Pop register from stack
## STR - Store with direct addressing
## LD - Load with direct addressing
## STRP - Store with indirect addressing
## LDP - Load with indirect addressing
## XCHG - Exchange registers
## ADDI - Addition with immediate
## SUBI - Subtraction with immediate
## ORI - Logical OR with immediate
## ANDI - Logical AND with immediate
## XORI - Logical XOR with immediate
## TEQI - Test if equal with immediate
## TNEI - Test if not equal with immediate
## TLTI - Test if strictly lower with immediate
## TLEI - Test if lower or equal with immediate
## TGTI - Test if strictly greater with immediate
## TGEI - Test if greater or equal with immediate
## STRI - Store with direct immediate addressing
## LDI - Load with direct immediate addressing
## JZ - Relative jump if zero
## JNZ - Relative jump if not zero
## CALL - Call subroutine (Jump and link)
## RET - Return from subroutine
## JABS - Absolute jump