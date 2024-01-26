# Virtual processor - Functional specifications

This project was requested by [ALGOSUP](https://algosup.com), a French computer science school.

The goal of the project is to create a virtual processor and an interpreter for running assembly code on 
that processor.
The assembly language will also be created and tailored by us.

<details>
<summary>Table of Contents</summary>

- [Stakeholders](#stakeholders)
  - [Project members](#project-members)
  - [Other stakeholders](#other-stakeholders)
- [Project scope](#project-scope)
- [Functional requirements](#functional-requirements)
- [Deliverables and milestones](#deliverables-and-milestones)
- [Personas and use cases](#personas-and-use-cases)
  - [Persona 1 - Pascal Thomas](#persona-1---pascal-thomas)
    - [Introduction](#introduction)
    - [Goals](#goals)
    - [Challenges](#challenges)
  - [Persona 2 - Violette Mayers](#persona-2---violette-mayers)
    - [Introduction](#introduction-1)
    - [Goals](#goals-1)
    - [Challenges](#challenges-1)
  - [Persona 3 - Patricia Farmer](#persona-3---patricia-farmer)
    - [Introduction](#introduction-2)
    - [Goals](#goals-2)
    - [Challenges](#challenges-2)
- [Acceptance criteria](#acceptance-criteria)
- [Solution overview](#solution-overview)
  - [System architecture](#system-architecture)
  - [Assembly syntax](#assembly-syntax)
  - [Assembly instructions](#assembly-instructions)
    - [Per parameter type](#per-parameter-type)
  - [Errors](#errors)
  - [Machine code](#machine-code)
  - [Usage](#usage)
- [Non-functional requirements](#non-functional-requirements)
  - [Performance](#performance)
  - [Scalability](#scalability)
  - [Portability](#portability)
  - [Usability](#usability)
- [Examples](#examples)
- [Timeline](#timeline)
- [Resources](#resources)
- [Risks and assumptions](#risks-and-assumptions)
- [Future improvements](#future-improvements)
- [Glossary](#glossary)
</summary></details>

## Stakeholders

### Project members

| Full name       | Occupation               | Links                                                             |
| --------------- | ------------------------ | ----------------------------------------------------------------- |
| Benoît DE KEYN  | Project manager          | [LinkedIn](https://linkedin.com/in/beno%C3%AEt-de-keyn-71611b293) |
| Léo CHARTIER    | Program manager          | [LinkedIn](https://linkedin.com/in/l%C3%A9o-chartier-367111221)   |
| Jason GROSSO    | Tech lead                | [LinkedIn](https://linkedin.com/in/jason-grosso-847b39251)        |
| Max BERNARD     | Senior software engineer | [LinkedIn](https://linkedin.com/in/max-bernard-b77680210)         |
| Antoine PREVOST | Junior software engineer | [LinkedIn](https://linkedin.com/in/antoine-prevost-dev)           |
| Maxime THIZEAU  | Quality assurance        | [LinkedIn](https://linkedin.com/in/maxime-thizeau-0b311a293)      |

### Other stakeholders

| Name           | Occupation                  | Links                          |
| -------------- | --------------------------- | ------------------------------ |
| Franck JEANNIN | Client (ALGOSUP's director) | [Website](https://algosup.com) |

## Project scope

We have multiple objectives for this project:
- Creation of an assembly language and [Instruction Set Architecture](#glossary) (defined further down in this document)
- Implementation of this ISA in the form of a [virtual processor](#glossary)
- Implementation of an interpreter to run code onto this virtual processor (in other words, encode the instructions of the CPU)
- Provision of sample assembly scripts that can be run by the interpreter

## Functional requirements

<!-- TODO: Update with both compiler and emulator -->
The instructions of the language must allow for the following actions:
- Data handling i.e. writing data between a register and
  - an immediate value (a constant),
  - another register,
  - the memory (RAM)
  - the virtual keyboard/display
- Calculations
  - The four basic mathematical operations (addition, subtraction, multiplication, division)
  - The four basic logical operations (not, and, or, xor)
- Branching
  - Comparison between registers and values
  - Conditional and unconditional jumping
  - Calling and returning from subroutines

The interpreter must be able to be compiled and run on any real computer architecture. No libraries outside of the standard ones should be used, and the libraries that are operating system-specific must have existing alternatives.

The interpreter must also detect syntactical errors such as invalid lines or invalid parameters. When those happen, the interpreter must stop the program and alert the user.

Since we are emulating the execution of the machine code, the instructions must be run with a duration similar to what it would be on real hardware.
This means that if an instruction takes 4 clock cycles and another one takes 7, if the first runs in 1.3ms and the second one 3.7ms, we would have to slow the first instruction to have a time factor closer to the real thing. We allow a 10% margin between the time-to-clock cycles of the fastest and slowest instructions (in terms of clock cycles).

## Deliverables and milestones

| Date and time          | Deliverable              |
| ---------------------- | ------------------------ |
| 30 January 2023, 5 PM  | Functional specification |
| 9 February 2023, 5 PM  | Technical specification  |
| 16 February 2023, 5 PM | Test plan                |
| 23 February 2023, 5 PM | Final product            |

## Personas and use cases

### Persona 1 - Pascal Thomas

#### Introduction
Pascal Thomas is a 47-year-old senior software engineer. He has been in this field for 20 years and has had the opportunity to work with many different languages during this time. Pascal works in a little company that handles two small projects every year. He currently lives in London and works from home.

#### Goals
  - Pascal needs to learn a new assembly language to complete his client's requirements. He discovered our assembly language and saw that it would perfectly fit his client's requirements.
  - He prefers working on his Windows computer even if he also has a macOS.

#### Challenges
  - Pascal wants a virtual processor effective with the language.
  - He doesn't want to search for a separate interpreter.

### Persona 2 - Violette Mayers

#### Introduction
  Violette Mayers is a 23-year-old junior software engineer. She just got her diploma and got a job in a little company in New York City. Violette doesn't know a lot of languages except C and web languages.

#### Goals
  - Her primary goal is to understand assembly language to improve her global comprehension of high-level languages and to have an added value in her curriculum vitae.
  - She wants to become more familiar with a new operating system like Linux.

#### Challenges
  - The principal challenge here is to provide a comprehensible assembly language with a simple instruction set.
  - Struggles with the Linux command system.

### Persona 3 - Patricia Farmer

#### Introduction
  Patricia Farmer is a 31-year-old kind-hearted Educator who wants the well-being of her students. She works in a computer science school in the city of Berlin, where she lives as well. She has been doing this job for the last eight years, and after that, she obtained her master's in her courses at the same school where she is currently working.

#### Goals
  - She wants to rehearse her level in low-level programming for her courses.
  - Her main goal is to know if the language she found could be a good first approach for her second-year students because she knows that assembly could be a plus for them.

#### Challenges
  - The main challenge here is to have an Assembly language that can be easily run and understood.
  - The virtual processor must be portable because her students aren't in the same operating system.

## Acceptance criteria

The sample scripts -- which cover every instruction -- should be executed without any problem and their result should meet the expected output.

The program should be fail-safe with no segmentation fault, memory corruption, or other issue. In the event that those still happen, the program should catch them and alert the user of the error.

To ensure that the project is viable, all the specifications must be approved by the client and the program must also be tested by other teams (and potentially external people) to collect their feedback and improve the software.

## Solution overview

### System architecture

The architecture will use 32-bit integers to run. Unless otherwise specified, those integers are supposed signed.

We will consider to have 16 registers. Those are denoted by the letter `r` followed by an uppercase hexadecimal digit (r0, r1, ..., rE, rF). This notation allows for easy recognizability and easy expansion if necessary.

The processor will also allow for four flags (boolean outputs from the ALU). They are denoted with the letter `f` followed by an uppercase letter.
| Representation | Meaning    | Description                                                                                                                                                                    |
| -------------- | ---------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| fC             | Carry flag | When an operation is executed, the flag is set if the unsigned result cannot fit in the register.                                                                              |
| fS             | Sign flag  | When a value is moved, when an operation is executed, or when a comparison is done, the flag is set if the result is strictly negative (i.e. the most significant bit is set). |
| fZ             | Zero flag  | When a value is moved, when an operation is executed, or when a comparison is done, the flag is set if the result is equal to zero.                                            |

All the flags default to false when the interpreter starts.

Since the overflow flag is set when there is an overflow into the sign bit, we assume the sign flag can be used instead.

<!-- TODO: Memory layout -->

### Assembly syntax

The syntax for the instructions follows one of those patterns:
- `mnem`
- `mnem param`
- `mnem param1 param2`

where `mnem` is the mnemonic for the instruction in lowercase and the rest is parameters. For alignment reasons, we allow any number more than one space before the parameters.

A label should be on a line with no instruction, written in camel case, and followed by a colon: `camelCase:`. A label may only be defined once in a file but jumped to or called any amount of time.

A line only composed with whitespace is to be ignored.

Comments can be added at the end of any line with an instruction or label, starting with a double slash `//`. Any whitespace before the symbol and any text after it until the end of the line is to be ignored.

The immediate values can be written either in decimal or in hexadecimal prefixed with a lowercase `x`.

### Assembly instructions

| Mnemonic | Parameter 1 | Parameter 2 | Behavior                                                                                                                                                  | Modifies flags (fP, fS, FZ) |
| -------- | ----------- | ----------- | --------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------- |
| noop     |             |             | Does nothing (used for padding or hogging clock cycles).                                                                                                  | No                          |
| set      | Register    | Immediate   | Sets the value of the register to the specified immediate value.                                                                                          | Yes                         |
| copy     | Register    | Register    | Copies the value from the second register* to the first.                                                                                                  | Yes                         |
| load     | Register    | Register    | Loads the value in memory at the address stored in the second register into the first register.                                                           | Yes                         |
| load     | Register    | Immediate   | Loads the value in memory at the address specified by the immediate value into the register.                                                              | Yes                         |
| store    | Register    | Register    | Stores the value of the second register to the memory address stored in the first register.                                                               | Yes                         |
| store    | Immediate   | Register    | Stores the value of the register to the memory address specified by the immediate value.                                                                  | Yes                         |
| add      | Register    | Register    | Adds the value of the second register to the first register.                                                                                              | Yes (also modifies fC)      |
| add      | Register    | Immediate   | Adds the immediate value to the register.                                                                                                                 | Yes (also modifies fC)      |
| sub      | Register    | Register    | Subtracts the value of the second register to the first register.                                                                                         | Yes (also modifies fC)      |
| sub      | Register    | Immeditate  | Subtracts the immediate value to the register.                                                                                                            | Yes (also modifies fC)      |
| mul      | Register    | Register    | Multiplies the values of the two registers. The first register gets the lower half of the result while the second one takes the high half.                | Yes (also modifies fC)      |
| div      | Register    | Register    | Divides the value of the first register by the value of the second register. The first register gets the quotient and the second one takes the remainder. | Yes (also modifies fC)      |
| not      | Register    |             | Flips all the bits of the value of the register.                                                                                                          | Yes                         |
| and      | Register    | Register    | Performs a bitwise AND operation on the value of the first register with the value of the second register.                                                | Yes                         |
| and      | Register    | Immediate   | Performs a bitwise AND operation on the value of the register with the value of the second register.                                                      | Yes                         |
| or       | Register    | Register    | Performs a bitwise OR operation on the value of the first register with the value of the second register.                                                 | Yes                         |
| or       | Register    | Immediate   | Performs a bitwise OR operation on the value of the register with the value of the second register.                                                       | Yes                         |
| xor      | Register    | Register    | Performs a bitwise XOR operation on the value of the first register with the value of the second register.                                                | Yes                         |
| xor      | Register    | Immediate   | Performs a bitwise XOR operation on the value of the register with the value of the second register.                                                      | Yes                         |
| cmp      | Register    | Register    | Compares the value in the first register and the value in the second register and sets the flags correspondingly.                                         | Yes                         |
| cmp      | Register    | Immediate   | Compares the value in the register and the immediate value and sets the flags correspondingly.                                                            | Yes                         |
| cmp      | Immediate   | Register    | Compares the immediate value and the value in the register and sets the flags correspondingly.                                                            | Yes                         |
| jeq      | Label       |             | Jumps conditionally to the specified label if the `fZ` flag is true.                                                                                      | No                          |
| jneq     | Label       |             | Jumps conditionally to the specified label if the `fZ` flag is false.                                                                                     | No                          |
| jgeq     | Label       |             | Jumps conditionally to the specified label if the `fS` flag is false or the `fZ` flag is true.                                                            | No                          |
| jgt      | Label       |             | Jumps conditionally to the specified label if the `fS` flag is false and the `fZ` flag is false.                                                          | No                          |
| jleq     | Label       |             | Jumps conditionally to the specified label if the `fS` flag is true or the `fZ` flag is true.                                                             | No                          |
| jlt      | Label       |             | Jumps conditionally to the specified label if the `fS` flag is true and the `fZ` flag is false.                                                           | No                          |
| jc       | Label       |             | Jumps conditionally to the specified label if the `fC` flag is true.                                                                                      | No                          |
| jnc      | Label       |             | Jumps conditionally to the specified label if the `fC` flag is false.                                                                                     | No                          |
| jump     | Label       |             | Jumps unconditionally to the specified label.                                                                                                             | No                          |
| call     | Label       |             | Calls a subroutine by jumping to the specified label.                                                                                                     | No                          |
| ret      |             |             | Returns from the current subroutine by jumping back right after the call instruction.                                                                     | No                          |
| push     | Register    |             | Adds the value in the register to the top of the stack.                                                                                                   | Yes                         |
| pop      | Register    |             | Retrieves and deletes the value from the top of the stack into the register.                                                                              | Yes                         |
| exit     |             |             | Terminates the execution of the program.                                                                                                                  | No                          |

*For the `copy` instruction, the source register (second parameter) can also be `sp` or `ln`, respectively the address of the stack pointer and the number of the currently executed instruction. Those values are read-only.

<!-- TODO: Scancode appendix -->

#### Per parameter type
<!-- TODO -->

### Errors

The assembly of the code should abort with the program exiting if:
- a line of code does not fit one of the previously mentioned rules (syntax error)
- an instruction whose mnemonic is invalid or with parameters not corresponding (syntax error)

The execution of the code should stop if:
- a division by zero occurs (arithmetic error)
- the stack is popped when empty (index error)
- the user presses Ctrl+C (interrupt error)

### Machine code

Patterns:
  - Register/Register:  `                ##SSSSDDDD0OOOCC`
  - Register/Immediate: `IIIIIIIIIIIIIIIIIIIIIIDDDD1OOOCC`
  - Push/Pop:           `                ######DDDDP#0101`
  - Label (jump):       `AAAAAAAAAAAAAAAAAAAAAAAAAAAOOO11`
Bits:
  - C: Category
  - O: Opcode
  - D: Destination
  - S: Source
  - I: Immediate
  - P: Stack direction (0 = push, 1 = pop)
  - A: Address

| Mnemonic  | Category              | Opcode | Type |
| --------- | --------------------- | -----: | ---- |
| add       | Arithmetic/Logic (00) |    000 | R?   |
| sub       | Arithmetic/Logic (00) |    001 | R?   |
| mul       | Arithmetic/Logic (00) |    010 | RR   |
| div       | Arithmetic/Logic (00) |    011 | RR   |
| and       | Arithmetic/Logic (00) |    100 | R?   |
| or        | Arithmetic/Logic (00) |    101 | R?   |
| xor       | Arithmetic/Logic (00) |    110 | R?   |
| RESERVED  | Arithmetic/Logic (00) |    111 | X    |
| set/copy  | Memory (01)           |  [0]00 | R?   |
| push/pop  | Memory (01)           |  [0]01 | R    |
| load      | Memory (01)           |  [0]10 | R?   |
| store     | Memory (01)           |  [0]11 | R?   |
| RESERVED? | Memory (01)           |    100 | X    |
| RESERVED? | Memory (01)           |    101 | X    |
| RESERVED? | Memory (01)           |    110 | X    |
| RESERVED? | Memory (01)           |    111 | X    |
| jump      | Branching (10)        |     00 | L    |
| cmp       | Branching (10)        |     01 | R?   |
| call      | Branching (10)        |     10 | L    |
| ret       | Branching (10)        |     11 | TBD  |
| jeq       | Cond branch (11)      |    000 | L    |
| jneq      | Cond branch (11)      |    001 | L    |
| jgeq      | Cond branch (11)      |    010 | L    |
| jgt       | Cond branch (11)      |    011 | L    |
| jleq      | Cond branch (11)      |    100 | L    |
| jlt       | Cond branch (11)      |    101 | L    |
| jc        | Cond branch (11)      |    110 | L    |
| jnc       | Cond branch (11)      |    111 | L    |

### Usage

<!-- TODO -->

Execution of the program starts at the first line and ends when the end of the file is reached, the `exit` instruction is used, or when a runtime error occurs.

## Non-functional requirements

### Performance
Since our language will be interpreted, our software must do so quite rapidly to not hinder the user experience.

### Scalability
In case the client decides to change their requirements, or if we realize that the current instruction set is insufficient, we must be able to easily update the way the instructions are run.

### Portability
As mentioned earlier, the software must run on any computer architecture which has a working C compiler.

### Usability
Although a debugger is not required, it might be useful for the developers to implement one for their own debugging needs.

## Examples

<!-- TODO -->

## Timeline

<!-- TODO -->

## Resources

Man-hours:
- 8 weeks
- 27 half-days (each of 3.5 hours)
- 567 manhours

Budget:
- None

## Risks and assumptions

<!-- TODO -->
<!-- Clock: 32-bit timestamp ends in 2038 -->

## Future improvements

<!-- TODO -->
<!-- shl shr neg jmpoffset -->

## Glossary

<!-- TODO -->

**Instruction Set Architecture (ISA)** \
An architecture defining how a microprocessor and its related components should work. It includes the instructions to run, the different registers, and memory partitioning among other things.
[Wikipedia](https://en.wikipedia.org/wiki/Instruction_set_architecture)

**Virtual processor** \

**Machine code** \

**Processor / Central Processing Unit (CPU)** \

**RAM** \

**Register** \

**Arithmetic and Logic Unit (ALU)** \

**Immediate value** \
A constant