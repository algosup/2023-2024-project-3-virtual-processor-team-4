# Technical Specification Document  Team 4

--- 
 
<details>
<summary>Table of Content</summary>

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
    - [Error Handling](#error-handling)
      - [Error Message Type](#error-message-type)
  - [Assembler](#assembler)
    - [Preprocessing](#preprocessing)
    - [Line Parsing](#line-parsing)
    - [Binary File](#binary-file)
    - [Diagram](#diagram)
  - [Interpreter](#interpreter)
    - [Parsing](#parsing)
    - [Output](#output)
    - [Diagrams](#diagrams)
  - [Challenges](#challenges)
  - [Glossary](#glossary)

</details>

---

## Introduction

### Overview

This document is the technical specification of a project commissioned to us by ALGOSUP. The project consist in creating a virtual processor[^1] and it's components.

#### Audience

This document is intended for:

- the different Software Engineers;
- the QA;
- the Project Manager;

#### Disclaimer

This document will not describe the assembly[^2] language and it's workings, those informations will be available in the [functional specification](/documents/functional/functionalSpecification.md).

### Requirement

The requirement for this project are as follows:
- invent a minimal assembly language,
- create a C[^3] program that can read our assembly language and run it,
- the C program must also be able do check the syntax and semantics of the assembly language,
- implement a virtual terminal to make sure that the program is running and displaying informations to the user,
- write small assembly programs executable by the C program,

### Content

This document will detail the [architecture of the project](#architecture), [the assembler[^4]](#assembler) and [the interpreter[^5]](#interpreter).

---

## Architecture

### Technicalities

The program will be develloped in C, with the GCC compiler[^6]. It will be developed on Windows and Linux, but must support any other OS[^7].

### Naming Conventions

```
GitHub branches: kebab-case
const: ALL_CAPS
variables: camelCase
functions: snake_case
struct/typedef: camelCase
struct/union object: camalCase
macros: ALL_CAPS
file: snake_case
enum/typedef: PascalCase
enum member: ALL_CAPS
```

### File Organisation

The GitHub repository will be organised as such:
```
📦2023-2024-project3-virtual-processor
└── 📁 .github
    └── 📁 ISSUE_TEMPLATE
        └── 📝 bug_report.md
└── 📁 documents
    └── 📁 .data
        └──pictures
    └── 📁 QA
        └── 📝 test_plan.md
    └── 📁 functional
        └── 📝 function_specification.md
    └── 📁 management
        └──.weekly_report
    └── 📁 technical
        └── 📝 technical-specification.md
    └── 📄 project_charter.md
└── 📁 src
    └── 📁 libs
    └── 📄 main.c
└── 📄 .gitignore
└── 📄 LICENCE
└── 📝 README.md
```
Here is a detailled version of the `src` folder:
```
└── 📁 src
    └── 📄 main.c
    └── 📁 libs
        └── 📄 assembler.h
        └── 📄 preprocessor.h
        └── 📄 processor.h
        └── 📄 utils.h
```
- main.c will contain the main loop and the virtual terminal;
- assembler.h will contain all the functions pertaining to the assembler and the error handling;
- preprocessor.h will contain all the functions pertaining to the preprocessor[^8];
- processor.h will contain all the functions pertaining to the processor;
- utils.h will contain the miscellianous objects, such as `enum ErrorType` or `enume InstructionType`;


### Endians

The program will use little endians[^9], for it is advantageous in processor architecture and we expect at some point to use our virtual processor on a physical processor.

### CISC/RISC

The program will be based on the RISC[^10] and not CISK[^11], as a RISC architecture provides less instruction, which in turn allow us to reduce the complexity of the program.

### Principles

#### Libraries

The only libraries[^12] allowed are the [C standard Libraries](https://en.cppreference.com/w/c/header).

#### Comments

Each functions and process are to be explained with comments.

#### Header

The header must be defined as such:
```
#ifndef HEADER_h

// libraries

#endif
```

### Virtual Terminal

The Virtual Terminal is a part of the vitual processor; it will be used to display the inputs and outputs of the program, such as asking the name of the file that the user wish to use.

### Error Handling

For errors that happens in the preprocessing phase, the program ask for a correct file name/format; in the assembler phase, the program waits for the file to finish assembling before returning all the errors; in the interpreter phase if there is an error, the program stops and return an error.

#### Error Message Type

Here is an exemple of a error message:
```
error + error number: type of error line of the error: '';
```

--- 

## Assembler

### Preprocessing

- ask for a file;
- if it exits, check the format;
- if it doesn't exist ask again,
- if it isn't in the right format, throw an error and ask for another file

### Line Parsing

- isolate a line;
- allocate memory for the line;
- extract the operand[^13] and the arguments[^14];
- add them into the struct line;
- check if null:
  - if null throw an error free the memory allocated to the line and go to the next one;
  - if not null check the types and number:
    - if incorrect throw an error, free the memory allocated to the line and go to the next one;
    - if correct convert the line to machine code[^15];
- add to the output array;
- free the memory allocated to the line;
- if check if EOF[^16]:
  - if not EOF go back to the beginning of the loop

### Binary File

 - if EOF:
   - if there are errors return them;
   - if there are no error indicate that the compilation was successful;
 - return the binary file;
 - start the [Interpretation](#interpreter);

### Diagram

Here is a visual representation of how the assembler works:

![assembler Diagram](/documents/.data/pictures/UML_preprocessor.png)

---

## Interpreter

### Parsing

- open the binary file;
- enter the loop;
- parse the code by chunks of 32 bits[^17] characters(32 characters = 1 instruction[^18]);
- allocate memory to the chunk;
- parse the x first bits to obtain the operand of the instruction;
- parse the next x bits to obtain the first argument of the instruction;
- parse the remaining bits to obtain the second argument of the instruction;

### Output

- add to the output array;
- free the memory allocated to the chunk;
- check EOF:
  - if EOF, indicate the interpretation was succesful;
  - if not EOF, continue the loop; 

### Diagrams

Here is a visual representaion of how the intepreter works:

![Interpreter Diagram](/documents/.data/pictures/UML_interpreter.png)

---

## Challenges

Here are the technical challenges that we must overcome for our project to succeed:
- making sure our program can handle various assembly programs in terms of complexity,
- making sure our program can handle various assembly programs in terms of size
- have our preprocessor enforce rigorously the syntax and semantics correctness of the assembly programs,
- making sure our program execute the more complexe instruction, such as  'call' and 'ret',

---

## Glossary
 
 [^1]: virtual processor: is a program that simulate the inner workings of a physical processor;
 [^2]: assembly: or assembly language is a low level language, or a language that is very close to the language of the machine;
 [^3]: C: is a general purpose programming language;  
 [^4]: assembler: is a program that transform a file in assembly into machine code;
 [^5]: interpreter: is a program that execute a file line by line(in our case it's a binary file);
 [^6]: GCC compiler: is a compiler system used widely for compiling C, C++ and C#;
 [^7]: OS: or Operating System, is a system software that manages computer hardware and software ressource;
 [^8]: prepocessor: is a program that processes it's input data to produce output that is used a input for another program;
 [^9]: little endians: endianness designate the order in which bytes of a word of digitale data are stored in memory and little endians store the least significant byte first;
 [^10]: RISC: or Reduced Instruction Set Computer, is a computer architcture designated to simplify the individual instructions given to a computer;
 [^11]: CISK: or Complex Instruction Set Computer, is a computer architecture in which a single instruction can execute several operations;
 [^12]: library: is a collection of ressources used by computer program, often for computer developement;
 [^13]: operand: is a representation of a data type: a variable, a constant or a function's result;
 [^14]: argument: is a value that is passed between programs, subroutine or functions;
 [^15]: machine code: is a name of the language of machine(can also be called binary);  
 [^16]: EOF: short for End Of File, indicate the end of a file;
 [^17]: bit: unit of measure for the memory  
 [^18]: instruction: is an order given to a processor by a program;  
