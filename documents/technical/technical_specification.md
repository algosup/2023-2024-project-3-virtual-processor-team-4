# Technical Specification Document | Team 4

--- 

<details>
<summary>Table of Content</summary>

- [Technical Specification Document | Team 4](#technical-specification-document--team-4)
  - [Introduction](#introduction)
    - [Overview](#overview)
    - [Disclaimer](#disclaimer)
  - [Architecture](#architecture)
    - [Naming Conventions](#naming-conventions)
    - [File Organisation](#file-organisation)
  - [Interpreter](#interpreter)
    - [Step 1 Tokenization](#step-1-tokenization)
    - [Step 2 Parsing](#step-2-parsing)
    - [Step 3 Interpreter Core](#step-3-interpreter-core)
    - [Step 4 Error Handling](#step-4-error-handling)
  - [Glossary and Functions](#glossary-and-functions)
    - [Glossary](#glossary)
    - [Functions](#functions)

</details>

---

## Introduction

### Overview

This document is the technical specification of a project commissioned to us by ALGOSUP. The project consist in creating a virtual processor and an interpretor for running assembly code on that processor.

### Disclaimer

This document will not describe the assembly language and it's working, those information will be available in the [functional specification](/documents/functional/functionalSpecification.md).

---

## Architecture

### Naming Conventions

```
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
----------------
```

interpret.h will contain the functions relative to the interpreter.
file.h will contain the functions relative to the file handling.
utils.h will contain some miscellianous function.

---

## Interpreter

### Step 1 Tokenization

Scan the input code and break it down into token, token that represent a basic unit of the language such as keywords or identifiers.
Can be called a Lexer and is represented in the project as [```lexen_file```](#functions).

### Step 2 Parsing

Analyse the code based on the tokens generated by the lexer. We input the result of the parsing in ```struct instruction```.
This step is represented as the functions [``` parse_instruction```](#functions).

### Step 3 Interpreter Core

The logic that go through the AST and interpret the statements, evaluate the expressions and handle the control flow.
The Core is composed of 3 functions in our project[```ìnterpret_instruction```](#functions)and [```execute_function```](#functions).

### Step 4 Error Handling

Syntax error, runtime error and semantics error are to be handled and error message are to be explicit to aid in the debugging.

---

## Glossary and Functions

### Glossary

- virtual processor: 
- interpreter:
- assembly code:
- keyword:
- identifiers:
- instruction:
- logic:
- stack:
- call frames:
- semantic:
- debugging:

### Functions

Here you will find a pseudo code example of the functions named in the document(these example are not complete functions and are not to be taken as face value).


- lexen_file:
```
function lexen_file(file)
{
line   integer
token  integer
c       character

loop:
    read a character into c
    if c is a blank or a tab then
      do nothing

    else if c is a new line then
      nLine += 1

    else if c is a digit then
      create a token of this digit and the following
      return nToken
    [...]
}
```
- parse_instruction:
```
function parse_instruction(tokens)
{
  if token is null then
    return no more token

  else if token is an integer then
    return instruction(type integer, val1 = value, val2 = value, line = numero de ligne du fichier)
    // create a new object in the struct instruction
  [...] // all the other type of instruction
  else if no case match
  throw syntax_error("Unexpected token " + token)
}
```
- interpret_instruction: 
```
function interpret_expression(instruction, env)
{
  // go throught all the instruction type 
  switch instruction type:
    case int:
      int_(instruction)
      break
  [...]
  default break
}
```
- execute_function:
```
function execute_function(functionName, arguments):
    switch functionName:
        case "add":
            return executeAddFunction(arguments)

        [...]

        default:
            throw RuntimeError("Function '" + functionName + "' not found")

function executeAddFunction(arguments):
    if length(arguments) != 2:
        throw RuntimeError("Function 'add' expects 2 arguments")

    arg1 = interpretExpression(arguments[0])
    arg2 = interpretExpression(arguments[1])

    if arg1.type == INT and arg2.type == INT:
        return createValue(INT, arg1.data + arg2.data)
    else if arg1.type == FLOAT or arg2.type == FLOAT:
        return createValue(FLOAT, arg1.data + arg2.data)
    else:
        throw RuntimeError("Invalid types for addition")
[...]
```