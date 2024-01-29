# Technical Specification Document | Team 4

--- 
 
<details>
<summary>Table of Content</summary>

- [Technical Specification Document | Team 4](#technical-specification-document--team-4)
  - [Introduction](#introduction)
    - [Overview](#overview)
    - [Disclaimer](#disclaimer)
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
  - [Compiler](#compiler)
    - [File Loading](#file-loading)
    - [Line Parsing](#line-parsing)
    - [Binary File](#binary-file)
    - [Diagram](#diagram)
  - [Interpreter](#interpreter)
    - [Step 1 Tokenization](#step-1-tokenization)
    - [Step 2 Parsing](#step-2-parsing)
    - [Step 3 Interpreter Core](#step-3-interpreter-core)
    - [Error Handling](#error-handling)
    - [Diagrams](#diagrams)
  - [Glossary](#glossary)

</details>

---

## Introduction

### Overview

This document is the technical specification of a project commissioned to us by ALGOSUP. The project consist in creating a virtual processor and it's component.

### Disclaimer

This document will not describe the assembly language and it's working, those information will be available in the [functional specification](/documents/functional/functionalSpecification.md).

### Content

This document will contain the details of the compiler, the details of the interpreter, the architecture of the project as well as some pseudo code exemple of some importante function.

---

## Architecture

### Technicalities

The program will be develloped in C(no matter the version), with the GCC compiler. It will be develloped on Windows and Linux, but must support any other OS.

### Naming Conventions

```
GitHub branches: kebab-case
const: ALL_CAPS
variables: camelCase
functions: snake_case
struct/typedef: camelCase
macros: ALL_CAPS
file: snake_case
enum: PascalCase
enum member: ALL_CAPS
```

### File Organisation
```
src-----
        main.c
        lib------
                interpret.h
                file.h
                utils.h
                errors.h
----------------
```

- interpret.h will handle the interpretert of the program,
- file.h will handle the lexical analysis of the compiler,
- utils.h
- errors.h will handle all the errors,

### Endians

The program will use little endians, for it is advantageous in processor architecture and we preshot using our program on a real processor and not a virtual one.

### CISC/RISC

The program will based itself on the RISC, as a RISC architecture provides less inctruction, which in turn allow us to reduce th complexity of the program.

### Principles

#### Libraries

The only libraries allowed are the [C standard Libraries](https://en.cppreference.com/w/c/header).

#### Comments

Each functions and process are to be explained with comments.

### Virtual Terminal

The Virtual Terminal is a part of the vitual processor; it will be used to display the inputs and outputs of the program, such as the name of the file the user wish to use.

--- 

## Compiler

### File Loading

- ask for a file;
- if it exits, check the format;
- if it doesn't exist ask again,
- if it isn't in the right format, throw an error and ask for another file

### Line Parsing

- isolate a line;
- malloc the line;
- extract the operand and the arguments;
- add them into the struct line;
- check if null:
  - if null throw an error free the line and go to the next one*;
  - if not null check the types and number:
    - if incorrect throw an error, free the line and go to the next one*;
    - if correct convert to machine code;
- add to the output array;
- free the line;
- if check if EOF:
  - if not EOF go back to the beginning of the loop
  - if EOF -> 

### Binary File

### Diagram

Here is a visual representation of how the compiler works:

![Compiler Diagram](/documents/.data/pictures/UML_preprocessor.png)

---
TODO: refactor this part entirely
## Interpreter

### Step 1 Tokenization

Go through the machine code and create a new token every x byte.

### Step 2 Parsing

For each token parse at x byte to get the operand, at x byte to get the first argument and the rest of the bytes is arg 2.

### Step 3 Interpreter Core

interpret the parsed tokens 

### Error Handling

### Diagrams

Here is a visual representaion of how the intepreter works:

---

## Glossary

- virtual processor: 

- compiler:

- interpreter:

- assembly code: is the closest language to the machine that humans can understand and write in,

- keyword: words that have a specials meaning and are recognized by the compiler/interpreter,

- identifier: is a symbol/lexical token that names the language entities(i.e. variables, data types),

- instruction: is an order given to the computer processor by a computer program,

- logic: is a set of principles that delineates how elements should be arranged so a computer can perform specific tasks,

- stack: is an abstract data type that serves as a collection of elements with two main operations: push and pop,

- semantic: is a description of the process a computer follows when executing a computer program in a specific language

- debugging: is the process of finding and fixing mistakes in a the source code of any software.
