# Technical Specification Document | Team 4

--- 
 
<details>
<summary>Table of Content</summary>

- [Technical Specification Document | Team 4](#technical-specification-document--team-4)
  - [Introduction](#introduction)
    - [Overview](#overview)
      - [Audience](#audience)
      - [Disclaimer](#disclaimer)
    - [Requiremnet](#requiremnet)
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
    - [Virtual Terminal](#virtual-terminal)
    - [Error Handling](#error-handling)
      - [Error Message Type](#error-message-type)
  - [File Loading](#file-loading)
  - [Assembler](#assembler)
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

This document is the technical specification of a project commissioned to us by ALGOSUP. The project consist in creating a virtual processor[^1] and it's component.

#### Audience

This document is intended for:

- the different Software Engineers;
- the QA;
- the Project Manager;

#### Disclaimer

This document will not describe the assembly[^2] language and it's working, those information will be available in the [functional specification](/documents/functional/functionalSpecification.md).

### Requiremnet

The requirement for this prokect are as follows:
- invent a minimal assembly language,
- create a C program that can read our assembly language and run it,
- the C program must also be able do check the syntax and semantics of the assembly language,
- implement a virtual terminal to make sure that the program is running and displaying information to the user,
- write small assembly programs executable by the C program,

### Content

This document will contain the details of the assembler[^3], the details of the interpreter[^4], the architecture of the project.

---

## Architecture

### Technicalities

The program will be develloped in C[^5](no matter the version), with the GCC assembler[^6]. It will be develloped on Windows and Linux, but must support any other OS[^7].

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

### Endians

The program will use little endians[^8], for it is advantageous in processor architecture and we preshot using our program on a real processor and not a virtual one.

### CISC/RISC

The program will based itself on the RISC[^9] and not CISK[^10], as a RISC architecture provides less instruction, which in turn allow us to reduce the complexity of the program.

### Principles

#### Libraries

The only libraries[^11] allowed are the [C standard Libraries](https://en.cppreference.com/w/c/header).

#### Comments

Each functions and process are to be explained with comments.

### Virtual Terminal

The Virtual Terminal is a part of the vitual processor; it will be used to display the inputs and outputs of the program, such as the name of the file the user wish to use.

### Error Handling

For errors that happens in the file loading phase, the program ask for a correct file name/format; in the assembler phase, the program waits for the file to finish assembling before returning all the errors; in the interpreter phase if there is an error, the program stops and return an error.

#### Error Message Type

Here is an exemple of a error message:
```
error + error number: type of error line of the error: '';
```

--- 

## File Loading

- ask for a file;
- if it exits, check the format;
- if it doesn't exist ask again,
- if it isn't in the right format, throw an error and ask for another file

--- 

## Assembler

### Line Parsing

- isolate a line;
- malloc[^12] the line;
- extract the operand[^13] and the arguments[^14];
- add them into the struct line;
- check if null:
  - if null throw an error free the line and go to the next one;
  - if not null check the types[^15] and number:
    - if incorrect throw an error, free the line and go to the next one;
    - if correct convert to machine code[^16];
- add to the output array;
- free[^17] the line;
- if check if EOF[^18]:
  - if not EOF go back to the beginning of the loop
  - if EOF [go to the binary[^19] file](#binary-file)

### Binary File

 - when EOF:
   - if there are errors return then;
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
- parse the code by chunks of 32 bits[^20] characters(32 characters = 1 instruction[^21]);
- malloc the chunk;
- parse the x first bits to obtain the operand of the instruction;
- parse the next x bits to obtain the first argument[^22] of the instruction;
- parse the remaining bits to obtain the second argument of the instruction;

### Output

- add to the output array;
- check EOF:
  - if EOF, indicate the interpretation was succesful;
  - if not EOF, continue the loop; 

### Diagrams

Here is a visual representaion of how the intepreter works:

![Interpreter Diagram](/documents/.data/pictures/UML_interpreter.png)

---

## Challenges

Here are the technical challenges that we must overcome for our project to succeed:
- making sure our program can handle various assembly programs in terme of complexity,
- making sure our program can handle various assembly programs in terme of size
- have our assembler enforce rigorously the syntax and semantics correctness of the assembly programs,
- making sure our program execute the more complexe instruction, such as  'call' and 'ret',

---

## Glossary
[^1]: virtual processor:
[^2]: assembly:
[^3]: assembler:
[^4]: interpreter:
[^5]: C:
[^6]: GCC assembler:
[^7]: OS:
[^8]: endian:
[^9]: CISC:
[^10]: RISC:
[^11]: librarie:
[^12]: malloc:
[^13]: operand:
[^14]: argument:
[^15]: types:
[^16]: machine code:
[^17]: free
[^18]: EOF:
[^19]: binary:
[^20]: bit:
[^21]: instruction:
[^22]: argument: