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
  - [Persona 1](#persona-1)
  - [Persona ...](#persona-)
- [Acceptance criteria](#acceptance-criteria)
- [Solution overview](#solution-overview)
  - [System architecture](#system-architecture)
  - [Syntax](#syntax)
  - [Instructions](#instructions)
    - [Per parameter type](#per-parameter-type)
  - [Exceptions](#exceptions)
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
| Representation | Meaning          | Description                                                                                                                                                                    |
| -------------- | ---------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| fO             | Overflow flag    | When an operation is executed, the flag is set if the result cannot fit in the register (32 bits).                                                                             |
| fZ             | Zero flag        | When a value is moved, when an operation is executed, or when a comparison is done, the flag is set if the result is equal to zero.                                            |
| fS             | Sign flag        | When a value is moved, when an operation is executed, or when a comparison is done, the flag is set if the result is strictly negative (i.e. the most significant bit is set). |
| fJ             | Jump status flag | After a comparison is done, the flag is set if the specified values match the operator.                                                                                        |

All the flags default to false when the interpreter starts.

### Syntax

The syntax for the instructions follows one of those patterns:
- `mnem`
- `mnem param`
- `mnem param1, param2`

where `mnem` is the mnemonic for the instruction and the rest is parameters. Everything should be in lowercase. For alignment reasons, we allow any number more than one space before the parameters.

A label should be on a line with no instruction, written in camel case, and followed by a colon: `camelCase:`

A line only composed with whitespace is to be ignored.

Comments can be added at the end of any line with an instruction or label, starting with a double slash `//`. Any whitespace before the symbol and any text after it until the end of the line is to be ignored.

The immediate values can be written either in decimal or in hexadecimal prefixed with a lowercase `x`.

### Instructions

| Mnemonic | Parameter 1 | Parameter 2 | Behavior                                                                                                                                   |
| -------- | ----------- | ----------- | ------------------------------------------------------------------------------------------------------------------------------------------ |
| noop     |             |             | Does nothing (used for padding or hogging clock cycles).                                                                                   |
| set      | Register    | Immediate   | Sets the value of the register to the specified immediate value.                                                                           |
| copy     | Register    | Register    | Copies the value from the second register* to the first.                                                                                   |
| load     | Register    | Register    | Loads the value in memory at the address stored in the second register into the first register.                                            |
| load     | Register    | Immediate   | Loads the value in memory at the address specified by the immediate value into the register.                                               |
| store    | Register    | Register    | Stores the value of the second register to the memory address stored in the first register.                                                |
| store    | Immediate   | Register    | Stores the value of the register to the memory address specified by the immediate value.                                                   |
| store    | Immediate   | Immediate   | Stores the second immediate values to the memory address specified by the first immediate value.                                           |
| add      | Register    | Register    | Adds the value of the second register to the first register.                                                                               |
| add      | Register    | Immediate   | Adds the immediate value to the register.                                                                                                  |
| sub      | Register    | Register    | Subtracts the value of the second register to the first register.                                                                          |
| sub      | Register    | Immeditate  | Subtracts the immediate value to the register.                                                                                             |
| mul      | Register    | Register    | Multiplies the values of the two registers. The first register gets the lower half of the result while the second one takes the high half. |
| div      | Register    | Register    | Divides the value of the first register by the value of the second register.                                                               |
| not      | Register    |             | Flips all the bits of the value of the register.                                                                                           |
| and      | Register    | Register    | Performs a bitwise AND operation on the value of the first register with the value of the second register.                                 |
| and      | Register    | Immediate   | Performs a bitwise AND operation on the value of the register with the value of the second register.                                       |
| or       | Register    | Register    | Performs a bitwise OR operation on the value of the first register with the value of the second register.                                  |
| or       | Register    | Immediate   | Performs a bitwise OR operation on the value of the register with the value of the second register.                                        |
| xor      | Register    | Register    | Performs a bitwise XOR operation on the value of the first register with the value of the second register.                                 |
| xor      | Register    | Immediate   | Performs a bitwise XOR operation on the value of the register with the value of the second register.                                       |
| cmpeq    | Register    | Register    | Tests if the values stores in both registers are equal and sets the `fJ` flag correspondingly.                                             |
| cmpeq    | Register    | Immediate   | Tests if the value in the register is equal to the immediate values and sets the `fJ` flag correspondingly.                                |
| cmpge    | Register    | Register    | Tests if the value in the first register is greater or equal to the value in the second register and sets the `fJ` flag correspondingly.   |
| cmpge    | Register    | Immediate   | Tests if the value in the register is greater or equal to the immediate value and sets the `fJ` flag correspondingly.                      |
| cmpge    | Immediate   | Register    | Tests if the immediate value is greater or equal to the value in the register and sets the `fJ` flag correspondingly.                      |
| jtrue    | Label       |             | Jumps conditionally to the specified label if the `fJ` flag is true.                                                                       |
| jfalse   | Label       |             | Jumps conditionally to the specified label if the `fJ` flag is false.                                                                      |
| jump     | Label       |             | Jumps unconditionally to the specified label.                                                                                              |
| call     | Label       |             | Calls a subroutine by jumping to the specified label.                                                                                      |
| ret      |             |             | Returns from the current subrouting by jumping back right after the call instruction.                                                      |
| input    | Register    |             | Reads the scan code from the virtual keyboard into the specified register in a non-blocking way (value of 0 if no key is pressed).         |
| output   | Register    |             | Writes the ASCII value stored in the specified register to the virtual terminal**.                                                         |
| output   | Immediate   |             | Writes the specified immediate ASCII value to the virtual terminal**.                                                                      |
| clock    | Register    |             | Writes the current timestamp of the physical computer into the specified register.                                                         |
| exit     |             |             | Terminates the execution of the program.                                                                                                   |

*For the `copy` instruction, the source register (second parameter) can also be `sp` or `ln`, respectively the address of the stack pointer and the number of the currently executed instruction. Those values are read-only.
**The virtual terminal should correctly handle the backspace, new line, and carriage return control characters. Other control characters are to be silently omitted.

<!-- TODO: Scancode appendix -->

#### Per parameter type
| Parameters         | Instructions                                                      |
| ------------------ | ----------------------------------------------------------------- |
| None               | noop, ret, halt                                                   |
| 1 Immediate        | output                                                            |
| 1 Register         | not, input, output                                                |
| 2 Immediates       | store                                                             |
| 2 Registers        | copy, load, store, add, sub, mul, div, and, or, xor, cmpeq, cmpge |
| Immediate/Register | store, cmpge                                                      |
| Register/Immediate | set, load, add, sub, and, or, xor, cmpeq, cmpge                   |
| Label              | jtrue, jfalse, jump, call                                         |

### Exceptions

The execution of the code should be ended with the program exiting if:
- a line of code does not fit one of the previously mentioned rules (syntax error)
- an instruction whose mnemonic is invalid or with parameters not corresponding (syntax error)
- a division by zero occurs (arithmetic error)
- the user presses Ctrl+C (interrupt error)

### Usage

<!-- TODO -->

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