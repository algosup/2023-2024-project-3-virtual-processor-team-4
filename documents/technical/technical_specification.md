# Technical Specification Document  Team 4

--- 
 
<details>
<summary>Table of Contents</summary>

- [Technical Specification Document  Team 4](#technical-specification-document--team-4)
  - [Introduction](#introduction)
    - [Overview](#overview)
      - [Audience](#audience)
      - [Disclaimer](#disclaimer)
    - [Requirement](#requirement)
    - [Content](#content)
  - [Architecture](#architecture)
    - [Technicalities](#technicalities)
    - [Naming Conventions](#naming-conventions)
    - [File Organisation](#file-organisation)
    - [Endians](#endians)
    - [CISC/RISC](#ciscrisc)
    - [Principles](#principles)
      - [Libraries](#libraries)
      - [Comments](#comments)
      - [Header](#header)
    - [Virtual Terminal](#virtual-terminal)
    - [Virtual Memory](#virtual-memory)
    - [Error Handling](#error-handling)
      - [Error Message Type](#error-message-type)
  - [Assembler](#assembler)
    - [File Processing](#file-processing)
    - [Line Parsing](#line-parsing)
    - [Output](#output)
    - [Diagram](#diagram)
  - [Emulator](#emulator)
    - [Parsing](#parsing)
    - [Output](#output-1)
    - [Diagram](#diagram-1)
  - [Challenges](#challenges)
  - [Clock](#clock)
  - [Glossary](#glossary)

</details>

---

## Introduction

### Overview

This document is the technical specification of a project commissioned to us by ALGOSUP. The project consists of creating a virtual processor[^1] and its components.

#### Audience

This document is intended for:

- the different Software Engineers;
- the QA;
- the Project Manager;

#### Disclaimer

This document will not describe the assembly language and its workings, those information will be available in the [functional specification](/documents/functional/functional_specification.md).

### Requirement

The requirements for this project are as follows:
- invent a minimal assembly language;
- create a C program that can read our assembly language and run it;
- the C program must also be able to check the syntax and semantics of the assembly language;
- implement a virtual terminal to make sure that the program is running and displaying information to the user;
- write small assembly programs executable by the C program;

### Content

This document will detail the [architecture of the project](#architecture), [the assembler[^2]](#assembler) and [the interpreter[^3]](#interpreter).

---

## Architecture

### Technicalities

We will use:
- [VSCode](https://code.visualstudio.com/) as our IDE(Integrated Development Environment);
- C 17[^4] as our programming language;
- [GCC](https://gcc.gnu.org/) as our compiler(we use v13.2 for Windows and 12.0 for Linux);
- [GitHub](https://github.com/) as our source control management;

### Naming Conventions

```
GitHub branches: kebab-case
const: ALL_CAPS
variables: camelCase
functions: snake_case
struct/typedef: camelCase
struct/union object: camelCase
macros: ALL_CAPS
files: snake_case
enum/typedef: PascalCase
enum member: ALL_CAPS
```

### File Organisation

The GitHub repository will be organized as such:
```
📦2023-2024-project3-virtual-processor
└── 📁 .github
    └── 📁 ISSUE_TEMPLATE
        └── 📝 bug_report.md
└── 📁 documents
    └── 📁 .data
        └── 📁 pictures
    └── 📁 QA
        └── 📝 test_plan.md
    └──communication
        └── 📝 minutes_of_the_client_meeting_on_january_24th.md
    └── 📁 functional
        └── 📁 pictures
        └── 📝 appendix_a_instruction_set_manual.md
        └── 📝 appendix_a_instruction_set_manual.pdf
        └── 📝 function_specification.md
    └── 📁 management
        └── 📁 weekly_report
        └── 📝 mangement_artifact.md
    └── 📁 technical
        └── 📝 technical_specification.md
    └── 📄 project_charter.md
└── 📁 src
    └── 📄 assembler.c
    └── 📄 emulator.c
    └── 📁 libs
        └── 📄 assembler.h
        └── 📄 clock.h
        └── 📄 preprocessor.h
        └── 📄 runtime.h
        └── 📄 utils.h
└── 📄 .gitignore
└── 📄 LICENCE
└── 📝 README.md
```
Here is an explanation of the `src` folder:

- assembler.c is the main file for the assembler it includes assembler.h and preprocessor.h
- emulator.c is the main file for the emulator, it includes runtime.h and clock.h
- assembler.h will contain all the functions pertaining to the assembler;
- clock.h will house the workload of the clock;
- preprocessor.h will contain all the functions pertaining to the preprocessor[^5] and the error handling;
- runtime.h will contain all the functions pertaining to the processor;
- utils.h will contain the miscellaneous objects, such as `enum ErrorType` or `enum InstructionType`;


### Endians

The program will use little-endian[^6], for it is advantageous in processor architecture, and we expect at some point to use our virtual processor on a physical processor.

### CISC/RISC

The program will be based on the RISC[^7] and not CISC[^8], as a RISC architecture provides less instruction, which in turn allows us to reduce the complexity of the program.

### Principles

#### Libraries

The only libraries allowed are the [C standard Libraries](https://en.cppreference.com/w/c/header).

#### Comments

The code will be documented and explained via comments and will cover all the functions.

#### Header

The header must be defined as such:
```
#ifndef HEADER_h

// libraries

#endif
```

### Virtual Terminal

The Virtual Terminal is a part of the virtual processor; it will be used to display the inputs and outputs of the program, such as asking for the name of the file that the user wishes to use.

### Virtual Memory

Memory Map:

- Code Section:
  - Encoding: [in the functional](/documents/functional/functional_specification.md)
  - Size: 32 MB
- Data Section:
  - Encoding: byte per byte
  - Size: 1 GB
- Peripheric Section:
  - Input Section:
    - Encoding: ASCII-8
    - Size: 32 KB
  - Output Section:
    - Encoding: ASCII-8
    - Size: 1 KB
  - Video Memory:
    - Encoding: (1000x500px) x 4bit/pixel
    - Size: 256 KB



### Error Handling

For errors that happen in the preprocessing phase, the program asks for a correct file name/format; in the assembler phase, the program waits for the file to finish assembling before returning all the errors; in the interpreter phase, if there is an error, the program stops and return an error.

#### Error Message Type

Here is an example of an error message:
```
error + error number: type of error line of the error: '';
```

--- 

## Assembler

### File Processing

- ask for a file;
- if it exits, check the format;
- if it doesn't exist, ask again;
- if it isn't in the right format, throw an error and ask for another file;

### Line Parsing

- isolate a line;
- allocate memory for the line;
- extract the operand and the arguments;
- add them into the struct line;
- check if null:
  - if null, throw an error, free the memory allocated to the line, and go to the next one;
  - if not null, check the types and numbers:
    - if incorrect, throw an error, free the memory allocated to the line, and go to the next one;
    - if correct, convert the line to machine code;
- add to the output array;
- free the memory allocated to the line;
- if check if EOF[^9]:
  - if not EOF, go back to the beginning of the loop;

### Output

 - if EOF:
   - if there are errors, return them;
   - if there is no error, indicate that the compilation was successful;
 - return the binary file;
 - start the [Interpretation](#interpreter);

### Diagram

Here is a visual representation of how the assembler works:

![assembler Diagram](/documents/.data/pictures/UML_preprocessor.png)

---

## Emulator

### Parsing

- open the binary file;
- enter the loop;
- parse the code by chunks of 32 bits characters(32 characters = 1 instruction);
- allocate memory to the chunk;
- parse the x first bits to obtain the operand of the instruction;
- parse the next x bits to obtain the first argument of the instruction;
- parse the remaining bits to obtain the second argument of the instruction;

### Output

- add to the output array;
- free the memory allocated to the chunk;
- check EOF:
  - if EOF, indicates the interpretation was successful;
  - if not EOF, continue the loop; 

### Diagram

Here is a visual representation of how the interpreter works:

![Interpreter Diagram](/documents/.data/pictures/UML_interpreter.png)

---

## Challenges

Here are the technical challenges that we must overcome for our project to succeed:
- making sure our program can handle various assembly programs in terms of complexity;
- making sure our program can handle various assembly programs in terms of size;
- have our preprocessor enforce rigorously the syntax and semantics correctness of the assembly programs;
- making sure our program executes the more complex instructions, such as  'call' and 'ret';

---

## Clock

We implemented a clock system to smooth the number of instructions executed per second and make it consistent; at the start of the compiling we create a second thread apart from the execution thread, we execute a huge number of operations every second, by doing so we limit the number of operation the CPU can do. This clock is also used in the execution thread for the comparison.


pseudo-code of the clock:
```
CONST TARGET_OPS_PER_SEC = 10000 // here we chose 10000 but it can be another number

pthread_mutex_t mutex;
int loopCounter = 0; // the number of seconds spent in the program
int operationCounter = 0; // the number of operations in one loop

void perform_workload()
{
  loop
    {
      lock the thread;
      operationCounter++;
      unlock the thread;
    }
}

void print_operations()
{
  loop
    {
      wait for 1 second;
      lock the thread;
      opsInLastSecond = operationCounter; // save the number of operations for the print before reset
      operationCounter = 0; // reset the operation counter for the next loop
      unlock the thread;

      print(opsInLastSecond) // 
    }
}
```
---

## Glossary
 
 [^1]: virtual processor: is a program that simulates the inner workings of a physical processor;

 [^2]: C: is a general-purpose programming language, 17 is the version of C that we use;

 [^3]: assembler: is a program that transforms a file in assembly into machine code;

 [^4]: interpreter: is a program that executes a file line by line(in our case it's a binary file);

 [^5]: preprocessor: is a program that processes its input data to produce output that is used as input for another program;

 [^6]: little-endian: endianness designates the order in which bytes of a word of digital data are stored in memory, and little-endian stores the least significant byte first;

 [^7]: RISC: or Reduced Instruction Set Computer, is a computer architecture designated to simplify the individual instructions given to a computer;

 [^8]: CISC: or Complex Instruction Set Computer, is a computer architecture in which a single instruction can execute several operations;

 [^9]: EOF: short for End Of File, indicates the end of a file;
