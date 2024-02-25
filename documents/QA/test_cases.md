# Virtual processor - Test Cases

## Overview

This document will have the entire test cases created to ensure the well-functioning of the product.

## Priority

|Number|Priority|
|------|--------|
|1     |High    |
|2     |Medium  |
|3     |Low     |

## Test Cases Assembler

### Assembler: Compilation

| Test Case ID              | 1                                                                               |
|---------------------------|---------------------------------------------------------------------------------|
| Test case Name            | Assembler: Compilation                                                          |
| Test Case Description     | Verify if the file ```assembler.c``` could create ```assembler.exe``` and could be run without errors.               |
| Test Case Pre-conditions  | The product isn't running.                                                      |
| Test Case Steps           | 1. Open ```assembler.c``` in Visual Studio Code. <br> 2. Compile the file with GCC, and run it.      |
| Test Case Expected Result | The file runs without errors and you get another file named ```assembler.exe```. |
| Test Case Actual Result   | ---                                                                             |
| Test Case Status          | To Test                                                                         |
| Test Case Priority        | High 1                                                                          |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                             |

### Assembler: No parameter

| Test Case ID              | 2                                                                       |
|---------------------------|-------------------------------------------------------------------------|
| Test case Name            | Assembler: No parameter                                                 |
| Test Case Description     | Help the user to use the ```assembler.exe```.                           |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.                                      |
| Test Case Steps           | 1. Type ```assembler.exe``` in the terminal. <br> 2. Press ```enter```. |
| Test Case Expected Result | A help message should be sent.                                          |
| Test Case Actual Result   | ---                                                                     |
| Test Case Status          | To Test                                                                 |
| Test Case Priority        | Low 3                                                                   |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                     |

### Assembler: One parameter

| Test Case ID              | 3                                                                                   |
|---------------------------|-------------------------------------------------------------------------------------|
| Test case Name            | Assembler: One parameter                                                            |
| Test Case Description     | Help the user to use the ```assembler.exe```.                                       |
| Test Case Pre-conditions  | ```assembler.exe``` must be build. <br> ```example.asm``` must exist.               |
| Test Case Steps           | 1. Type ```assembler.exe example.asm``` in the terminal. <br> 2. Press ```enter```. |
| Test Case Expected Result | A help message should be sent but the product should run.                           |
| Test Case Actual Result   | ---                                                                                 |
| Test Case Status          | To Test                                                                             |
| Test Case Priority        | Low 3                                                                               |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                                 |

### Assembler: File not found

| Test Case ID              | 4                                                                                              |
|---------------------------|------------------------------------------------------------------------------------------------|
| Test case Name            | Assembler: File not found                                                                      |
| Test Case Description     | Search if the assembly file already exists or not.                                             |
| Test Case Pre-conditions  | ```assembler.exe``` must be build. <br> ```example.asm``` must not exist.                      |
| Test Case Steps           | 1. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 2. Press ```enter```. |
| Test Case Expected Result | An error must be sent.                                                                         |
| Test Case Actual Result   | ---                                                                                            |
| Test Case Status          | To Test                                                                                        |
| Test Case Priority        | Medium 2                                                                                       |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                                            |

### Invalid parameter

| Test Case ID              | 5                                                                                                                                                       |
|---------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------|
| Test case Name            | Invalid parameter                                                                                                                                       |
| Test Case Description     | Search if an error happens when an invalid parameter.                                                                                                      |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.                                                                                                                      |
| Test Case Steps           | 1. Create ```example.asm``` containing ```add 0```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```. |
| Test Case Expected Result | An error must be sent.                                                                                                                                  |
| Test Case Actual Result   | ---                                                                                                                                                     |
| Test Case Status          | To Test                                                                                                                                                 |
| Test Case Priority        | High 1                                                                                                                                                  |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                                                                                                     |

### Missing first parameter

| Test Case ID              | 6                                                                                                                                                      |
|---------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------|
| Test case Name            | Missing first parameter                                                                                                                                |
| Test Case Description     | Search if it misses the first parameter in a line.                                                                                                     |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.                                                                                                                     |
| Test Case Steps           | 1. Create ```example.asm``` containing ```add```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.  |
| Test Case Expected Result | An error must be sent.                                                                                                                                 |
| Test Case Actual Result   | ---                                                                                                                                                    |
| Test Case Status          | To Test                                                                                                                                                |
| Test Case Priority        | High 1                                                                                                                                                 |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                                                                                                    |

### Missing second parameter

| Test Case ID              | 7                                                                                                                                                        |
|---------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------|
| Test case Name            | Missing second parameter                                                                                                                                 |
| Test Case Description     | Search if it misses the second parameter in a line.                                                                                                      |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.                                                                                                                       |
| Test Case Steps           | 1. Create ```example.asm``` containing ```add ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```. |
| Test Case Expected Result | An error must be sent.                                                                                                                                   |
| Test Case Actual Result   | ---                                                                                                                                                      |
| Test Case Status          | To Test                                                                                                                                                  |
| Test Case Priority        | High 1                                                                                                                                                   |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                                                                                                      |

### Missing third parameter

| Test Case ID              | 8                                                                                                                                                            |
|---------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Test case Name            | Missing third parameter                                                                                                                                       |
| Test Case Description     | Search if it misses the third parameter in a line.                                                                                                                   |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.                                                                                                                           |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tlt rt ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```. |
| Test Case Expected Result | An error must be sent.                                                                                                                                       |
| Test Case Actual Result   | ---                                                                                                                                                          |
| Test Case Status          | To Test                                                                                                                                                      |
| Test Case Priority        | High 1                                                                                                                                                       |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                                                                                                          |

### Too many parameters

| Test Case ID              | 9                                                                                                                                                                  |
|---------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Test case Name            | Too much parameters                                                                                                                                                |
| Test Case Description     | Search if it contains too many parameters in a line.                                                                                                               |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.                                                                                                                                 |
| Test Case Steps           | 1. Create ```example.asm``` containing ```add ra rb rc rd```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.  |
| Test Case Expected Result | An error must be sent.                                                                                                                                             |
| Test Case Actual Result   | ---                                                                                                                                                                |
| Test Case Status          | To Test                                                                                                                                                            |
| Test Case Priority        | High 1                                                                                                                                                             |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                                                                                                                |

### Wrong mnemonic

| Test Case ID              | 10                                                                                                                                                           |
|---------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Test case Name            | Wrong mnemonic                                                                                                                                               |
| Test Case Description     | Search if there is a misspell in a mnemonic.                                                                                                                 |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.                                                                                                                           |
| Test Case Steps           | 1. Create ```example.asm``` containing ```adc ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.  |
| Test Case Expected Result | An error must be sent.                                                                                                                                       |
| Test Case Actual Result   | ---                                                                                                                                                          |
| Test Case Status          | To Test                                                                                                                                                      |
| Test Case Priority        | High 1                                                                                                                                                       |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                                                                                                          |

### Wrong first register

| Test Case ID              | 11                                                                                                                                                           |
|---------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Test case Name            | Wrong first register                                                                                                                                         |
| Test Case Description     | Search if the first register is existing.                                                                                                                     |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.                                                                                                                           |
| Test Case Steps           | 1. Create ```example.asm``` containing ```add r0 rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.  |
| Test Case Expected Result | An error must be sent.                                                                                                                                       |
| Test Case Actual Result   | ---                                                                                                                                                          |
| Test Case Status          | To Test                                                                                                                                                      |
| Test Case Priority        | High 1                                                                                                                                                       |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                                                                                                          |

### Wrong second register

| Test Case ID              | 12                                                                                                                                                           |
|---------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Test case Name            | Wrong second register                                                                                                                                        |
| Test Case Description     | Search if the second register is existing.                                                                                                                   |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.                                                                                                                           |
| Test Case Steps           | 1. Create ```example.asm``` containing ```add ra r0```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.  |
| Test Case Expected Result | An error must be sent.                                                                                                                                       |
| Test Case Actual Result   | ---                                                                                                                                                          |
| Test Case Status          | To Test                                                                                                                                                      |
| Test Case Priority        | High 1                                                                                                                                                       |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                                                                                                          |

### Wrong third register

| Test Case ID              | 13                                                                                                                                                              |
|---------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Test case Name            | Wrong third register                                                                                                                                            |
| Test Case Description     | Search if the third register is existing.                                                                                                                       |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.                                                                                                                              |
| Test Case Steps           | 1. Create ```example.asm``` containing ```add ra rb r0```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.  |
| Test Case Expected Result | An error must be sent.                                                                                                                                          |
| Test Case Actual Result   | ---                                                                                                                                                             |
| Test Case Status          | To Test                                                                                                                                                         |
| Test Case Priority        | High 1                                                                                                                                                          |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                                                                                                             |

### No mnemonic

| Test Case ID              | 14                                                                                                                                                    |
|---------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------|
| Test case Name            | No mnemonic                                                                                                                                           |
| Test Case Description     | Search if there is missing a mnemonic.                                                                                                                |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.                                                                                                                    |
| Test Case Steps           | 1. Create ```example.asm``` containing ```ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.  |
| Test Case Expected Result | An error must be sent.                                                                                                                                |
| Test Case Actual Result   | ---                                                                                                                                                   |
| Test Case Status          | To Test                                                                                                                                               |
| Test Case Priority        | High 1                                                                                                                                                |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                                                                                                   |

### No immediate as the second parameter

| Test Case ID              | 15                                                                                                                                                            |
|---------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Test case Name            | No immediate as second parameter                                                                                                                                                  |
| Test Case Description     | Search if there is missing an immediate value as the second parameter.                                                                                                                |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.                                                                                                                            |
| Test Case Steps           | 1. Create ```example.asm``` containing ```addi ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.  |
| Test Case Expected Result | An error must be sent.                                                                                                                                        |
| Test Case Actual Result   | ---                                                                                                                                                           |
| Test Case Status          | To Test                                                                                                                                                       |
| Test Case Priority        | High 1                                                                                                                                                        |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                                                                                                           |

### No immediate as the third parameter

| Test Case ID              | 16                                                                                                                                                            |
|---------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Test case Name            | No immediate as third parameter                                                                                                                                                 |
| Test Case Description     | Search if there is missing an immediate value as the third parameter.                                                                                                                |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.                                                                                                                            |
| Test Case Steps           | 1. Create ```example.asm``` containing ```addi ra rb rc```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.  |
| Test Case Expected Result | An error must be sent.                                                                                                                                        |
| Test Case Actual Result   | ---                                                                                                                                                           |
| Test Case Status          | To Test                                                                                                                                                       |
| Test Case Priority        | High 1                                                                                                                                                        |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                                                                                                           |

### Undefined label

| Test Case ID              | 17                                                                                                                                                           |
|---------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Test case Name            | Undefined label                                                                                                                                              |
| Test Case Description     | Search if there is a label not defined.                                                                                                                      |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.                                                                                                                           |
| Test Case Steps           | 1. Create ```example.asm``` containing ```jmp next```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.  |
| Test Case Expected Result | An error must be sent.                                                                                                                                       |
| Test Case Actual Result   | ---                                                                                                                                                          |
| Test Case Status          | To Test                                                                                                                                                      |
| Test Case Priority        | High 1                                                                                                                                                       |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                                                                                                          |

### Label unexpected

| Test Case ID              | 18                                                                                                                                                              |
|---------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Test case Name            | Label unexpected                                                                                                                                                |
| Test Case Description     | Search if there is a label at a place it should not be.                                                                                                         |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.                                                                                                                              |
| Test Case Steps           | 1. Create ```example.asm``` containing ```add ra label```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.  |
| Test Case Expected Result | An error must be sent.                                                                                                                                          |
| Test Case Actual Result   | ---                                                                                                                                                             |
| Test Case Status          | To Test                                                                                                                                                         |
| Test Case Priority        | High 1                                                                                                                                                          |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                                                                                                             |

### No register where to stock the result

| Test Case ID              | 19                                                                                                                                                          |
|---------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Test case Name            | No register where to stock the result                                                                                                                       |
| Test Case Description     | Search if there is a register where to stock the result.                                                                                                    |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.                                                                                                                          |
| Test Case Steps           | 1. Create ```example.asm``` containing ```addi 1 2```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.  |
| Test Case Expected Result | An error must be sent.                                                                                                                                      |
| Test Case Actual Result   | ---                                                                                                                                                         |
| Test Case Status          | To Test                                                                                                                                                     |
| Test Case Priority        | High 1                                                                                                                                                      |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                                                                                                         |

### Label or immediate value expected

| Test Case ID              | 20                                                                                                                                                         |
|---------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Test case Name            | Label or immediate value expected                                                                                                                          |
| Test Case Description     | Search if there is a label or an immediate value where it is expected.                                                                                     |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.                                                                                                                         |
| Test Case Steps           | 1. Create ```example.asm``` containing ```jmp ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.  |
| Test Case Expected Result | An error must be sent.                                                                                                                                     |
| Test Case Actual Result   | ---                                                                                                                                                        |
| Test Case Status          | To Test                                                                                                                                                    |
| Test Case Priority        | High 1                                                                                                                                                     |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                                                                                                        |

### Negative value

| Test Case ID              | 21                                                                                                                                                           |
|---------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Test case Name            | Negative value                                                                                                                                               |
| Test Case Description     | Check if the product can handle negative values.                                                                                                             |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.                                                                                                                           |
| Test Case Steps           | 1. Create ```example.asm``` containing ```set ra -3```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.  |
| Test Case Expected Result | The product should run without any errors.                                                                                                                   |
| Test Case Actual Result   | ---                                                                                                                                                          |
| Test Case Status          | To Test                                                                                                                                                      |
| Test Case Priority        | High 1                                                                                                                                                       |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                                                                                                          |

### Too many arguments in jump

| Test Case ID              | 22                                                                                                                                                             |
|---------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Test case Name            | Too many arguments in jump                                                                                                                                     |
| Test Case Description     | Check if there is one or more arguments not necessary to the conditional jump.                                                                                 |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.                                                                                                                             |
| Test Case Steps           | 1. Create ```example.asm``` containing ```bi label rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.  |
| Test Case Expected Result | The product should return an error.                                                                                                                            |
| Test Case Actual Result   | ---                                                                                                                                                            |
| Test Case Status          | To Test                                                                                                                                                        |
| Test Case Priority        | High 1                                                                                                                                                         |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                                                                                                            |

### Too many arguments in return

| Test Case ID              | 23                                                                                                                                                        |
|---------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------|
| Test case Name            | Too many arguments in return                                                                                                                                 |
| Test Case Description     | Check if there is one or more arguments not necessary to the return.                                                                                      |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.                                                                                                                        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```ret ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.  |
| Test Case Expected Result | The product should return an error.                                                                                                                       |
| Test Case Actual Result   | ---                                                                                                                                                       |
| Test Case Status          | To Test                                                                                                                                                   |
| Test Case Priority        | High 1                                                                                                                                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                                                                                                       |

### Commentary

| Test Case ID              | 24                                                                                                                                                                          |
|---------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Test case Name            | Commentary                                                                                                                                                                  |
| Test Case Description     | Check if the product can handle commentaries.                                                                                                                               |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.                                                                                                                                          |
| Test Case Steps           | 1. Create ```example.asm``` containing ```// This is a commentary.```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.  |
| Test Case Expected Result | The product should run without any errors.                                                                                                                                   |
| Test Case Actual Result   | ---                                                                                                                                                                         |
| Test Case Status          | To Test                                                                                                                                                                     |
| Test Case Priority        | High 1                                                                                                                                                                      |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                                                                                                                         |

### Tabulation

| Test Case ID              | 25                                                                                                                                                        |
|---------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------|
| Test case Name            | Tabulation                                                                                                                                                |
| Test Case Description     | Check if the product can handle tabulations.                                                                                                              |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.                                                                                                                        |
| Test Case Steps           | 1. Create ```example.asm``` containing a tabulation. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.  |
| Test Case Expected Result | The product should run without any errors.                                                                                                                 |
| Test Case Actual Result   | ---                                                                                                                                                       |
| Test Case Status          | To Test                                                                                                                                                   |
| Test Case Priority        | High 1                                                                                                                                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                                                                                                       |

### White space

| Test Case ID              | 26                                                                                                                                                         |
|---------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Test case Name            | White space                                                                                                                                                |
| Test Case Description     | Check if the product can handle white space.                                                                                                               |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.                                                                                                                         |
| Test Case Steps           | 1. Create ```example.asm``` containing a white space. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.  |
| Test Case Expected Result | The product should run without any errors.                                                                                                                  |
| Test Case Actual Result   | ---                                                                                                                                                        |
| Test Case Status          | To Test                                                                                                                                                    |
| Test Case Priority        | High 1                                                                                                                                                     |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                                                                                                        |

### Return carriage

| Test Case ID              | 27                                                                                                                                                             |
|---------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Test case Name            | Return carriage                                                                                                                                                |
| Test Case Description     | Check if the product can handle return carriage.                                                                                                               |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.                                                                                                                             |
| Test Case Steps           | 1. Create ```example.asm``` containing a return carriage between 2 lines of code. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.  |
| Test Case Expected Result | The product should run without any errors.                                                                                                                      |
| Test Case Actual Result   | ---                                                                                                                                                            |
| Test Case Status          | To Test                                                                                                                                                        |
| Test Case Priority        | High 1                                                                                                                                                         |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                                                                                                            |

### Specific character in commentary

| Test Case ID              | 28                                                                                                                                                                                             |
|---------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Test case Name            | Specific character in commentary                                                                                                                                                               |
| Test Case Description     | Check if the product can handle specific characters in commentaries.                                                                                                                           |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.                                                                                                                                                             |
| Test Case Steps           | 1. Create ```example.asm``` containing a commentary with one or many specific characters. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.  |
| Test Case Expected Result | The product should run without any errors.                                                                                                                                                      |
| Test Case Actual Result   | ---                                                                                                                                                                                            |
| Test Case Status          | To Test                                                                                                                                                                                        |
| Test Case Priority        | High 1                                                                                                                                                                                         |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                                                                                                                                            |

### Specific character out commentary

| Test Case ID              | 29                                                                                                                                                                                                |
|---------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Test case Name            | Specific character out commentary                                                                                                                                                                 |
| Test Case Description     | Check if the product can handle specific characters outside commentaries.                                                                                                                         |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.                                                                                                                                                                |
| Test Case Steps           | 1. Create ```example.asm``` containing one or many specific characters outside a commentary. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.  |
| Test Case Expected Result | The product should return an error.                                                                                                                                                         |
| Test Case Actual Result   | ---                                                                                                                                                                                               |
| Test Case Status          | To Test                                                                                                                                                                                           |
| Test Case Priority        | High 1                                                                                                                                                                                            |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                                                                                                                                               |

### Hexadecimal value

| Test Case ID              | 30                                                                                                                                                            |
|---------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Test case Name            | Hexadecimal value                                                                                                                                             |
| Test Case Description     | Check if the product can handle hexadecimal value.                                                                                                            |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.                                                                                                                            |
| Test Case Steps           | 1. Create ```example.asm``` containing ```set ra xFF```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.  |
| Test Case Expected Result | The product should run without any errors.                                                                                                                     |
| Test Case Actual Result   | ---                                                                                                                                                           |
| Test Case Status          | To Test                                                                                                                                                       |
| Test Case Priority        | High 1                                                                                                                                                        |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                                                                                                           |

### ip read-only

| Test Case ID              | 31                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | ip read-only                              |
| Test Case Description     | Check if we can write in the ip register. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```set ip 2```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product should send an error.         |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### sp read-only

| Test Case ID              | 32                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | sp read-only                              |
| Test Case Description     | Check if we can write in the sp register. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```set sp 2```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product should send an error.         |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

## Test Cases Instruction

### ABS - Absolute Value

#### One Register

| Test Case ID              | 33 - 1                                    |
|---------------------------|-------------------------------------------|
| Test Case Name            | ABS - One Register                        |
| Test Case Description     | Check if it assembles. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```abs ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 33 - 2                                    |
|---------------------------|-------------------------------------------|
| Test Case Name            | ABS - Two Registers                       |
| Test Case Description     | Check if it assembles. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```abs ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors it is an optional feature so it is not high priority.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | Medium 2                                  |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Three Registers

| Test Case ID              | 33 - 3                                    |
|---------------------------|-------------------------------------------|
| Test Case Name            | ABS - Three Registers                     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```abs ra rb rc```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 33 - 4                                    |
|---------------------------|-------------------------------------------|
| Test Case Name            | ABS - One Immediate                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```abs 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate And Register

| Test Case ID              | 33 - 5                                    |
|---------------------------|-------------------------------------------|
| Test Case Name            | ABS - One Immediate And Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```abs ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate And Two Register

| Test Case ID              | 33 - 6                                    |
|---------------------------|-------------------------------------------|
| Test Case Name            | ABS - One Immediate And Two Registers     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```abs ra rb 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### ADD - Addition

#### One Register

| Test Case ID              | 34 - 1                                    |
|---------------------------|-------------------------------------------|
| Test Case Name            | ADD - One Register                        |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```add ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 34 - 2                                    |
|---------------------------|-------------------------------------------|
| Test Case Name            | ADD - Two Registers                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```add ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Three Registers

| Test Case ID              | 34 - 3                                    |
|---------------------------|-------------------------------------------|
| Test Case Name            | ADD - Three Registers                     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```add ra rb rc```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | Medium 2                                  |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Four Registers

| Test Case ID              | 34 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | ADD - Four Registers                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```add ra rb rc rd```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 34 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | ADD - One Immediate                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```add 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 34 - 6                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | ADD - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```add ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Two Registers

| Test Case ID              | 34 - 7                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | ADD - One Immediate and Two Registers     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```add ra rb 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### ADDI - Addition With Immediate

#### One Register

| Test Case ID              | 35 - 1                                       |
|---------------------------|-------------------------------------------|
| Test Case Name            | ADDI - One Register                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```addi ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 35 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | ADDI - Two Registers                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```addi ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Three Registers

| Test Case ID              | 35 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | ADDI - Three Registers                    |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```addi ra rb rc```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Four Registers

| Test Case ID              | 35 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | ADDI - Four Registers                     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```addi ra rb rc rd```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 35 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | ADDI - One Immediate                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```addi 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 35 - 6                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | ADDI - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```addi ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.      |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Two Registers

| Test Case ID              | 35 - 7                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | ADDI - One Immediate and Two Registers    |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```addi ra rb 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.      |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | Medium 2                                  |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### AND - Logical And

#### One Register

| Test Case ID              | 36 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | AND - One Register                        |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```and ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.               |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 36 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | AND - Two Registers                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```and ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Three Registers

| Test Case ID              | 36 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | AND - Three Registers                     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```and ra rb rc```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.      |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | Medium 2                                  |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Four Registers

| Test Case ID              | 36 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | AND - Four Registers                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```and ra rb rc rd```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 36 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | AND - One Immediate                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```and 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 36 - 6                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | AND - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```and ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Two Registers

| Test Case ID              | 36 - 7                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | AND - One Immediate and Two Registers     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```and ra rb 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### ANDI - Logical And With Immediate

#### One Register

| Test Case ID              | 37 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | ANDI - One Register                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```andi ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 37 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | ANDI - Two Registers                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```andi ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Three Registers

| Test Case ID              | 37 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | ANDI - Three Registers                    |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```andi ra rb rc```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Four Registers

| Test Case ID              | 37 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | ANDI - Four Registers                     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```andi ra rb rc rd```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 37 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | ANDI - One Immediate                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```andi 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.               |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 37 - 6                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | ANDI - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```andi ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.      |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Two Registers

| Test Case ID              | 37 - 7                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | ANDI - One Immediate and Two Registers    |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```andi ra rb 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.      |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | Medium 2                                  |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### B - Relative Indirect Jump

#### One Register

| Test Case ID              | 38 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | B - One Register                          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```b ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.      |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 38 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | B - Two Registers                         |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```b ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Three Registers

| Test Case ID              | 38 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | B - Three Registers                     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```b ra rb rc```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.      |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                  |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 38 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | B - One Immediate                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```b 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 38 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | B - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```b ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | Medium 2                                  |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Two Registers

| Test Case ID              | 38 - 6                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | B - One Immediate and Two Registers     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```b ra rb 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### BI - Relative Jump

#### One Register

| Test Case ID              | 39 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | BI - One Register                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```bi ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 39 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | BI - Two Registers                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```bi ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 39 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | BI - One Immediate                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```bi 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.      |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 39 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | BI - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```bi ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.      |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Label

| Test Case ID              | 39 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | BI - One Label                            |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```bi label```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.      |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### BNZ - Relative Jump If Not Zero

#### One Register

| Test Case ID              | 40 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | BNZ - One Register                        |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```bnz ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.               |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 40 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | BNZ - Two Registers                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```bnz ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Three Registers

| Test Case ID              | 40 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | BNZ - Three Registers                     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```bnz ra rb rc```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.      |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                          |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 40 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | BNZ - One Immediate                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```bnz 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 40 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | BNZ - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```bnz ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Two Registers

| Test Case ID              | 40 - 6                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | BNZ - One Immediate and Two Registers     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```bnz ra rb 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Label

| Test Case ID              | 40 - 7                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | BNZ - One Label                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing on the first line ```bnz label ``` and on the second ```label:```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Label and Register

| Test Case ID              | 40 - 8                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | BNZ - One Label and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing on the first line ```bnz ra label``` and on the second ```label:```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Label and Two Registers

| Test Case ID              | 40 - 9                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | BNZ - One Label and Two Registers     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing on the first line ```bnz ra rb label``` and on the second ```label:```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### BZ - Relative Jump If Zero

#### One Register

| Test Case ID              | 41 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | BZ - One Register                        |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```bz ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.               |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 41 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | BZ - Two Registers                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```bz ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Three Registers

| Test Case ID              | 41 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | BZ - Three Registers                     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```bz ra rb rc```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.      |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                          |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 41 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | BZ - One Immediate                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```bz 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 41 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | BZ - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```bz ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Two Registers

| Test Case ID              | 41 - 6                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | BZ - One Immediate and Two Registers     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```bz ra rb 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Label

| Test Case ID              | 41 - 7                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | BZ - One Label                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing on the first line ```bz label ``` and on the second ```label:```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Label and Register

| Test Case ID              | 41 - 8                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | BZ - One Label and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing on the first line ```bz ra label``` and on the second ```label:```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Label and Two Registers

| Test Case ID              | 41 - 9                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | BZ - One Label and Two Registers     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing on the first line ```bz ra rb label``` and on the second ```label:```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### CALL - Call Indirect Subroutine (Jump And Link)

#### One Register

| Test Case ID              | 42 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | CALL - One Register                        |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```call ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.               |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 42 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | CALL - Two Registers                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```call ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Three Registers

| Test Case ID              | 42 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | CALL - Three Registers                     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```call ra rb rc```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.      |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                          |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 42 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | CALL - One Immediate                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```call 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 42 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | CALL - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```call ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | Medium 2                                  |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Two Registers

| Test Case ID              | 42 - 6                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | CALL - One Immediate and Two Registers     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```call ra rb 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Label

| Test Case ID              | 42 - 7                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | CALL - One Label                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing on the first line ```call label ``` and on the second ```label:```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Label and Register

| Test Case ID              | 42 - 8                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | CALL - One Label and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing on the first line ```call ra label``` and on the second ```label:```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | Medium 2                                  |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Label and Two Registers

| Test Case ID              | 42 - 9                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | CALL - One Label and Two Registers     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing on the first line ```call ra rb label``` and on the second ```label:```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### CALLI - Call Subroutine (Jump And Link)

#### One Register

| Test Case ID              | 43 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | CALLI - One Register                        |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```calli ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.               |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 43 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | CALLI - Two Registers                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```calli ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 43 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | CALLI - One Immediate                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```calli 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 43 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | CALLI - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```calli ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Label

| Test Case ID              | 43 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | CALLI - One Label                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing on the first line ```calli label ``` and on the second ```label:```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Label and Register

| Test Case ID              | 43 - 6                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | CALLI - One Label and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing on the first line ```calli ra label``` and on the second ```label:```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.               |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### DIV - Division

#### One Register

| Test Case ID              | 44 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | DIV - One Register                        |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```div ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 44 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | DIV - Two Registers                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```div ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Three Registers

| Test Case ID              | 44 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | DIV - Three Registers                     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```div ra rb rc```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | Medium 2                                  |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Four Registers

| Test Case ID              | 44 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | DIV - Four Registers                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```div ra rb rc rd```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 44 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | DIV - One Immediate                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```div 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 44 - 6                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | DIV - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```div ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Two Registers

| Test Case ID              | 44 - 7                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | DIV - One Immediate and Two Registers     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```div ra rb 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### HALT - Stop The Program

#### No Parameter

| Test Case ID              | 45 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | HALT - No Parameter                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```halt```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Register

| Test Case ID              | 45 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | HALT - One Register                        |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```halt ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 45 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | HALT - One Immediate                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```halt 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Label

| Test Case ID              | 45 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | HALT - One Label                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing on the first line ```halt label ``` and on the second ```label:```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.               |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### JMP - Absolute Jump

#### One Register

| Test Case ID              | 46 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | JMP - One Register                        |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```jmp ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 46 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | JMP - Two Registers                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```jmp ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 46 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | JMP - One Immediate                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```jmp 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 46 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | JMP - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```jmp ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Label

| Test Case ID              | 46 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | JMP - One Label                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing on the first line ```jmp label ``` and on the second ```label:```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Label and Register

| Test Case ID              | 46 - 6                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | JMP - One Label and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing on the first line ```jmp ra label``` and on the second ```label:```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.               |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### LD - Load With Direct Addressing

#### One Register

| Test Case ID              | 47 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | LD - One Register                        |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```ld ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 47 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | LD - Two Registers                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```ld ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Three Registers

| Test Case ID              | 47 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | LD - Three Registers                     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```ld ra rb rc```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 47 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | LD - One Immediate                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```ld 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 47 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | LD - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```ld ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Two Registers

| Test Case ID              | 47 - 6                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | LD - One Immediate and Two Registers     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```ld ra rb 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### LDI - Load With Direct Immediate Addressing

#### One Register

| Test Case ID              | 48 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | LDI - One Register                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```ldi ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 48 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | LDI - Two Registers                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```ldi ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Three Registers

| Test Case ID              | 48 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | LDI - Three Registers                    |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```ldi ra rb rc```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 48 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | LDI - One Immediate                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```ldi 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 48 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | LDI - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```ldi ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.      |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Two Registers

| Test Case ID              | 48 - 6                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | LDI - One Immediate and Two Registers    |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```ldi ra rb 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.      |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### LDP - Load With Indirect Addressing

#### One Register

| Test Case ID              | 49 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | LDP - One Register                        |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```ldp ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 49 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | LDP - Two Registers                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```ldp ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Three Registers

| Test Case ID              | 49 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | LDP - Three Registers                     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```ldp ra rb rc```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 49 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | LDP - One Immediate                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```ldp 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 49 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | LDP - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```ldp ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Two Registers

| Test Case ID              | 49 - 6                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | LDP - One Immediate and Two Registers     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```ldp ra rb 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### MUL - Multiplication

#### One Register

| Test Case ID              | 50 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | MUL - One Register                        |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```mul ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 50 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | MUL - Two Registers                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```mul ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Three Registers

| Test Case ID              | 50 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | MUL - Three Registers                     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```mul ra rb rc```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | Medium 2                                  |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Four Registers

| Test Case ID              | 50 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | MUL - Four Registers                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```mul ra rb rc rd```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 50 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | MUL - One Immediate                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```mul 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 50 - 6                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | MUL - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```mul ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Two Registers

| Test Case ID              | 50 - 7                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | MUL - One Immediate and Two Registers     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```mul ra rb 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### OR - Logical Or

#### One Register

| Test Case ID              | 51 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | OR - One Register                        |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```or ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.               |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 51 - 2                                         |
|---------------------------|-------------------------------------------|
| Test Case Name            | OR - Two Registers                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```or ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Three Registers

| Test Case ID              | 51 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | OR - Three Registers                     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```or ra rb rc```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.      |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | Medium 2                                  |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Four Registers

| Test Case ID              | 51 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | OR - Four Registers                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```or ra rb rc rd```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 51 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | OR - One Immediate                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```or 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 51 - 6                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | OR - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```or ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Two Registers

| Test Case ID              | 51 - 7                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | OR - One Immediate and Two Registers     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```or ra rb 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### ORI - Logical Or With Immediate

#### One Register

| Test Case ID              | 52 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | ORI - One Register                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```ori ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 52 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | ORI - Two Registers                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```ori ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Three Registers

| Test Case ID              | 52 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | ORI - Three Registers                    |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```ori ra rb rc```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Four Registers

| Test Case ID              | 52 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | ORI - Four Registers                     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```ori ra rb rc rd```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 52 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | ORI - One Immediate                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```ori 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.               |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 52 - 6                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | ORI - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```ori ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.      |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Two Registers

| Test Case ID              | 52 - 7                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | ORI - One Immediate and Two Registers    |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```ori ra rb 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.      |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | Medium 2                                  |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### POP - Pop Register From Stack

#### One Register

| Test Case ID              | 53 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | POP - One Register                        |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```pop ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.      |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 53 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | POP - Two Registers                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```pop ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 53 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | POP - One Immediate                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```pop 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.               |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 53 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | POP - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```pop ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### PUSH - Push Register From Stack

#### One Register

| Test Case ID              | 54 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | PUSH - One Register                        |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```push ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.      |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 54 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | PUSH - Two Registers                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```push ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 54 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | PUSH - One Immediate                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```push 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.               |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 54 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | PUSH - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```push ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### RET - Return From Subroutine

#### No Parameter

| Test Case ID              | 55 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | RET - No Parameter                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```ret```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Register

| Test Case ID              | 55 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | RET - One Register                        |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```ret ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 55 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | RET - One Immediate                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```ret 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Label

| Test Case ID              | 55 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | RET - One Label                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing on the first line ```ret label ``` and on the second ```label:```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.               |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### SET - Set Register To Immediate

#### One Register

| Test Case ID              | 56 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | SET - One Register                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```set ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 56 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | SET - Two Registers                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```set ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Three Registers

| Test Case ID              | 56 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | SET - Three Registers                    |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```set ra rb rc```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 56 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | SET - One Immediate                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```set 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 56 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | SET - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```set ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.      |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Two Registers

| Test Case ID              | 56 - 6                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | SET - One Immediate and Two Registers    |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```set ra rb 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.      |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### STR - Store With Direct Addressing

#### One Register

| Test Case ID              | 57 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | STR - One Register                        |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```str ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 57 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | STR - Two Registers                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```str ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Three Registers

| Test Case ID              | 57 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | STR - Three Registers                     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```str ra rb rc```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 57 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | STR - One Immediate                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```str 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 57 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | STR - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```str ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Two Registers

| Test Case ID              | 57 - 6                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | STR - One Immediate and Two Registers     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```str ra rb 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### STRI - Store With Direct Immediate Addressing

#### One Register

| Test Case ID              | 58 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | STRI - One Register                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```stri ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 58 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | STRI - Two Registers                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```stri ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Three Registers

| Test Case ID              | 58 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | STRI - Three Registers                    |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```stri ra rb rc```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 58 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | STRI - One Immediate                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```stri 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 58 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | STRI - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```stri ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.      |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Two Registers

| Test Case ID              | 58 - 6                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | STRI - One Immediate and Two Registers    |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```stri ra rb 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.      |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### STRP - Store With Indirect Addressing

#### One Register

| Test Case ID              | 59 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | STRP - One Register                        |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```strp ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 59 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | STRP - Two Registers                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```strp ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Three Registers

| Test Case ID              | 59 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | STRP - Three Registers                     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```strp ra rb rc```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 59 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | STRP - One Immediate                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```strp 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 59 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | STRP - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```strp ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Two Registers

| Test Case ID              | 59 - 6                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | STRP - One Immediate and Two Registers     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```strp ra rb 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### SUB - Substraction

#### One Register

| Test Case ID              | 60 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | SUB - One Register                        |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```sub ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 60 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | SUB - Two Registers                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```sub ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Three Registers

| Test Case ID              | 60 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | SUB - Three Registers                     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```sub ra rb rc```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | Medium 2                                  |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Four Registers

| Test Case ID              | 60 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | SUB - Four Registers                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```sub ra rb rc rd```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 60 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | SUB - One Immediate                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```sub 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 60 - 6                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | SUB - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```sub ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Two Registers

| Test Case ID              | 60 - 7                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | SUB - One Immediate and Two Registers     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```sub ra rb 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### SUBI - Substraction With Immediate

#### One Register

| Test Case ID              | 61 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | SUBI - One Register                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```subi ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 61 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | SUBI - Two Registers                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```subi ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Three Registers

| Test Case ID              | 61 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | SUBI - Three Registers                    |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```subi ra rb rc```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Four Registers

| Test Case ID              | 61 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | SUBI - Four Registers                     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```subi ra rb rc rd```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 61 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | SUBI - One Immediate                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```subi 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 61 - 6                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | SUBI - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```subi ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.      |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Two Registers

| Test Case ID              | 61 - 7                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | SUBI - One Immediate and Two Registers    |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```subi ra rb 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.      |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | Medium 2                                  |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### TEQ - Test If Equal

#### One Register

| Test Case ID              | 62 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TEQ - One Register                        |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```teq ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 62 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TEQ - Two Registers                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```teq ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.               |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Three Registers

| Test Case ID              | 62 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TEQ - Three Registers                     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```teq ra rb rc```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Four Registers

| Test Case ID              | 62 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TEQ - Four Registers                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```teq ra rb rc rd```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 62 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TEQ - One Immediate                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```teq 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 62 - 6                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TEQ - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```teq ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Two Registers

| Test Case ID              | 62 - 7                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TEQ - One Immediate and Two Registers     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```teq ra rb 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### TEQI - Test If Equal With Immediate

#### One Register

| Test Case ID              | 63 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TEQI - One Register                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```teqi ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 63 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TEQI - Two Registers                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```teqi ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Three Registers

| Test Case ID              | 63 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TEQI - Three Registers                    |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```teqi ra rb rc```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Four Registers

| Test Case ID              | 63 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TEQI - Four Registers                     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```teqi ra rb rc rd```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 63 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TEQI - One Immediate                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```teqi 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 63 - 6                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TEQI - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```teqi ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.               |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Two Registers

| Test Case ID              | 63 - 7                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TEQI - One Immediate and Two Registers    |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```teqi ra rb 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.      |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### TGE - Test If Greater Or Equal

#### One Register

| Test Case ID              | 64 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TGE - One Register                        |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tge ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 64 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TGE - Two Registers                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tge ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.               |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Three Registers

| Test Case ID              | 64 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TGE - Three Registers                     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tge ra rb rc```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Four Registers

| Test Case ID              | 64 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TGE - Four Registers                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tge ra rb rc rd```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 64 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TGE - One Immediate                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tge 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 64 - 6                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TGE - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tge ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Two Registers

| Test Case ID              | 64 - 7                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TGE - One Immediate and Two Registers     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tge ra rb 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### TGEI - Test If Greater Or Equal With Immediate

#### One Register

| Test Case ID              | 65 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TGEI - One Register                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tgei ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 65 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TGEI - Two Registers                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tgei ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Three Registers

| Test Case ID              | 65 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TGEI - Three Registers                    |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tgei ra rb rc```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Four Registers

| Test Case ID              | 65 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TGEI - Four Registers                     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tgei ra rb rc rd```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 65 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TGEI - One Immediate                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tgei 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 65 - 6                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TGEI - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tgei ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.               |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Two Registers

| Test Case ID              | 65 - 7                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TGEI - One Immediate and Two Registers    |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tgei ra rb 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.      |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### TGT - Test If Strictly Greater

#### One Register

| Test Case ID              | 66 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TGT - One Register                        |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tgt ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 66 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TGT - Two Registers                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tgt ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.               |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Three Registers

| Test Case ID              | 66 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TGT - Three Registers                     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tgt ra rb rc```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Four Registers

| Test Case ID              | 66 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TGT - Four Registers                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tgt ra rb rc rd```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 66 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TGT - One Immediate                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tgt 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 66 - 6                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TGT - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tgt ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Two Registers

| Test Case ID              | 66 - 7                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TGT - One Immediate and Two Registers     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tgt ra rb 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### TGTI - Test If Strictly Greater With Immediate

#### One Register

| Test Case ID              | 67 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TGTI - One Register                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tgti ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 67 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TGTI - Two Registers                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tgti ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Three Registers

| Test Case ID              | 67 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TGTI - Three Registers                    |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tgti ra rb rc```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Four Registers

| Test Case ID              | 67 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TGTI - Four Registers                     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tgti ra rb rc rd```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 67 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TGTI - One Immediate                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tgti 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 67 - 6                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TGTI - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tgti ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.               |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Two Registers

| Test Case ID              | 67 - 7                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TGTI - One Immediate and Two Registers    |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tgti ra rb 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.      |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### TLE - Test If Lower Or Equal

#### One Register

| Test Case ID              | 68 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TLE - One Register                        |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tle ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 68 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TLE - Two Registers                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tle ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.               |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Three Registers

| Test Case ID              | 68 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TLE - Three Registers                     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tle ra rb rc```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Four Registers

| Test Case ID              | 68 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TLE - Four Registers                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tle ra rb rc rd```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 68 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TLE - One Immediate                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tle 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 68 - 6                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TLE - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tle ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Two Registers

| Test Case ID              | 68 - 7                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TLE - One Immediate and Two Registers     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tle ra rb 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### TLEI - Test If Lower Or Equal With Immediate

#### One Register

| Test Case ID              | 69 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TLEI - One Register                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tlei ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 69 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TLEI - Two Registers                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tlei ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Three Registers

| Test Case ID              | 69 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TLEI - Three Registers                    |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tlei ra rb rc```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Four Registers

| Test Case ID              | 69 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TLEI - Four Registers                     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tlei ra rb rc rd```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 69 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TLEI - One Immediate                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tlei 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 69 - 6                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TLEI - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tlei ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.               |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Two Registers

| Test Case ID              | 69 - 7                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TLEI - One Immediate and Two Registers    |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tlei ra rb 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.      |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### TLT - Test If Strictly Lower

#### One Register

| Test Case ID              | 70 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TLT - One Register                        |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tlt ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 70 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TLT - Two Registers                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tlt ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.               |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Three Registers

| Test Case ID              | 70 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TLT - Three Registers                     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tlt ra rb rc```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Four Registers

| Test Case ID              | 70 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TLT - Four Registers                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tlt ra rb rc rd```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 70 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TLT - One Immediate                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tlt 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 70 - 6                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TLT - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tlt ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Two Registers

| Test Case ID              | 70 - 7                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TLT - One Immediate and Two Registers     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tlt ra rb 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### TLTI - Test If Strictly Lower With Immediate

#### One Register

| Test Case ID              | 71 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TLTI - One Register                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tlti ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 71 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TLTI - Two Registers                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tlti ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Three Registers

| Test Case ID              | 71 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TLTI - Three Registers                    |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tlti ra rb rc```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Four Registers

| Test Case ID              | 71 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TLTI - Four Registers                     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tlti ra rb rc rd```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 71 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TLTI - One Immediate                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tlti 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 71 - 6                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TLTI - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tlti ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.               |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Two Registers

| Test Case ID              | 71 - 7                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TLTI - One Immediate and Two Registers    |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tlti ra rb 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.      |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### TNE - Test If Not Equal

#### One Register

| Test Case ID              | 72 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TNE - One Register                        |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tne ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 72 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TNE - Two Registers                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tne ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.               |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Three Registers

| Test Case ID              | 72 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TNE - Three Registers                     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tne ra rb rc```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Four Registers

| Test Case ID              | 72 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TNE - Four Registers                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tne ra rb rc rd```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 72 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TNE - One Immediate                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tne 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 72 - 6                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TNE - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tne ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Two Registers

| Test Case ID              | 72 - 7                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TNE - One Immediate and Two Registers     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tne ra rb 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### TNEI - Test If Not Equal With Immediate

#### One Register

| Test Case ID              | 73 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TNEI - One Register                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tnei ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 73 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TNEI - Two Registers                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tnei ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Three Registers

| Test Case ID              | 73 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TNEI - Three Registers                    |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tnei ra rb rc```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Four Registers

| Test Case ID              | 73 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TNEI - Four Registers                     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tnei ra rb rc rd```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 73 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TNEI - One Immediate                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tnei 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 73 - 6                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TNEI - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tnei ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.               |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Two Registers

| Test Case ID              | 73 - 7                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | TNEI - One Immediate and Two Registers    |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```tnei ra rb 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.      |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### XCHG - Exchange Registers

#### One Register

| Test Case ID              | 74 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | XCHG - One Register                        |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```xchg ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 74 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | XCHG - Two Registers                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```xchg ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Three Registers

| Test Case ID              | 74 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | XCHG - Three Registers                     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```xchg ra rb rc```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 74 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | XCHG - One Immediate                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```xchg 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 74 - 6                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | XCHG - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```xchg ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Two Registers

| Test Case ID              | 74 - 7                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | XCHG - One Immediate and Two Registers     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```xchg ra rb 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### XOR - Logical Xor

#### One Register

| Test Case ID              | 75 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | XOR - One Register                        |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```xor ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.               |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 75 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | XOR - Two Registers                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```xor ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Three Registers

| Test Case ID              | 75 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | XOR - Three Registers                     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```xor ra rb rc```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.      |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | Medium 2                                  |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Four Registers

| Test Case ID              | 75 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | XOR - Four Registers                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```xor ra rb rc rd```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 75 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | XOR - One Immediate                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```xor 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 75 - 6                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | XOR - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```xor ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Two Registers

| Test Case ID              | 75 - 7                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | XOR - One Immediate and Two Registers     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```xor ra rb 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### XORI - Logical Xor With Immediate

#### One Register

| Test Case ID              | 76 - 1                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | XORI - One Register                       |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```xori ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Two Registers

| Test Case ID              | 76 - 2                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | XORI - Two Registers                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```xori ra rb```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Three Registers

| Test Case ID              | 76 - 3                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | XORI - Three Registers                    |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```xori ra rb rc```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.       |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### Four Registers

| Test Case ID              | 76 - 4                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | XORI - Four Registers                     |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```xori ra rb rc rd```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.                |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate

| Test Case ID              | 76 - 5                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | XORI - One Immediate                      |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```xori 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product sends an error.               |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Register

| Test Case ID              | 76 - 6                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | XORI - One Immediate and Register          |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```xori ra 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.      |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 3                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

#### One Immediate and Two Registers

| Test Case ID              | 76 - 7                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | XORI - One Immediate and Two Registers    |
| Test Case Description     | Check if it assemble. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.        |
| Test Case Steps           | 1. Create ```example.asm``` containing ```xori ra rb 1```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.       |
| Test Case Expected Result | The product runs without any errors.      |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | Medium 2                                  |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

## Test Cases Emulator

### Emulator: Compilation

| Test Case ID              | 77                                                                              |
|---------------------------|---------------------------------------------------------------------------------|
| Test case Name            | Emulator: Compilation                                                           |
| Test Case Description     | Verify if the file ```emulator.c``` could create ```emulator.exe``` and could be run without errors.                |
| Test Case Pre-conditions  | The product isn't running.                                                      |
| Test Case Steps           | 1. Open ```emulator.c``` in Visual Studio Code. <br> 2. Compile the file with GCC, and run it.      |
| Test Case Expected Result | The file runs without errors and you get another file named ```emulator.exe```. |
| Test Case Actual Result   | ---                                                                             |
| Test Case Status          | To Test                                                                         |
| Test Case Priority        | High 1                                                                          |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                             |

### Emulator: No parameter

| Test Case ID              | 78                                                                      |
|---------------------------|-------------------------------------------------------------------------|
| Test case Name            | Emulator: No parameter                                                  |
| Test Case Description     | Help the user to use the ```emulator.exe```.                            |
| Test Case Pre-conditions  | ```emulator.exe``` must be build.                                       |
| Test Case Steps           | 1. Type ```emulator.exe``` in the terminal. <br> 2. Press ```enter```.  |
| Test Case Expected Result | A help message should be sent.                                          |
| Test Case Actual Result   | ---                                                                     |
| Test Case Status          | To Test                                                                 |
| Test Case Priority        | Low 3                                                                   |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                     |

### Emulator: File not found

| Test Case ID              | 79                                                                                             |
|---------------------------|------------------------------------------------------------------------------------------------|
| Test case Name            | Emulator: File not found                                                                       |
| Test Case Description     | Search if the assembly file already exists or not.                                             |
| Test Case Pre-conditions  | ```emulator.exe``` must be build. <br> ```example.bin``` must not exist.                       |
| Test Case Steps           | 1. Type ```emulator.exe example.bin``` in the terminal. <br> 2. Press ```enter```.             |
| Test Case Expected Result | An error must be sent.                                                                         |
| Test Case Actual Result   | ---                                                                                            |
| Test Case Status          | To Test                                                                                        |
| Test Case Priority        | Medium 2                                                                                       |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                                            |

## File testing

### Separate color

| Test Case ID              | 80                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | Separate color                            |
| Test Case Description     | Verify if ```separate_color.asm``` comport any errors and return the expected result.|
| Test Case Pre-conditions  | ```assembler.exe``` must be build. <br> ```emulator.exe``` must be build. <br> Go to [testing](/documents/QA/testing/). <br> See if ```separate_color.asm``` exists.           |
| Test Case Steps           | 1. Type ```assembler.exe separate_color.asm separate_color.bin``` in the terminal. <br> 2. Press ```enter```. <br> 3. Type ```emulator.exe separate_color.bin > separate_color.txt```. <br> 4. Press ```enter```.       |
| Test Case Expected Result | The product create ```separate_color.txt``` and put the expected result in it.   |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | Medium 2                                  |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### Convert Hexa to Decimal

| Test Case ID              | 81                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | Convert Hexa to Decimal                   |
| Test Case Description     | Verify if ```hexa_to_decimal.asm``` comport any errors and return the expected result. |
| Test Case Pre-conditions  | ```assembler.exe``` must be build. <br> ```emulator.exe``` must be build. <br> Go to [testing](/documents/QA/testing/). <br> See if ```hexa_to_decimal.asm``` exists.           |
| Test Case Steps           | 1. Type ```assembler.exe hexa_to_decimal.asm hexa_to_decimal.bin``` in the terminal. <br> 2. Press ```enter```. <br> 3. Type ```emulator.exe hexa_to_decimal.bin > hexa_to_decimal.txt```. <br> 4. Press ```enter```.           |
| Test Case Expected Result | The product create ```hexa_to_decimal.exe``` and put the expected result in it. |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | Medium 2                                  |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### Temperature convertor

| Test Case ID              | 82                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | Temperature convertor                     |
| Test Case Description     | Verify if ```temperature_convertor.asm``` comport any errors and return the expected result.|
| Test Case Pre-conditions  | ```assembler.exe``` must be build. <br> ```emulator.exe``` must be build. <br> Go to [testing](/documents/QA/testing/). <br> See if ```temperature_convertor.asm``` exists.           |
| Test Case Steps           | 1. Type ```assembler.exe temperature_convertor.asm temperature_convertor.bin``` in the terminal. <br> 2. Press ```enter```. <br> 3. Type ```emulator.exe temperature_convertor.bin > temperature_convertor.txt```. <br> 4. Press ```enter```.       |
| Test Case Expected Result | The product create ```temperature_convertor.txt``` and put the expected result in it.   |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | Medium 2                                  |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### Randomizer

| Test Case ID              | 83                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | Randomizer                                |
| Test Case Description     | Verify if ```random_generator.asm``` comport any errors and return the expected result.|
| Test Case Pre-conditions  | ```assembler.exe``` must be build. <br> ```emulator.exe``` must be build. <br> Go to [testing](/documents/QA/testing/). <br> See if ```random_generator.asm``` exists.         |
| Test Case Steps           | 1. Type ```assembler.exe random_generator.asm random_generator.bin``` in the terminal. <br> 2. Press ```enter```. <br> 3. Type ```emulator.exe random_generator.bin > random_generator.txt```. <br> 4. Press ```enter```.       |
| Test Case Expected Result | The product create ```random_generator.txt``` and put the expected result in it.   |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | Medium 2                                  |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### Greatest Common Divisor

| Test Case ID              | 84                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | Greatest Common Divisor                   |
| Test Case Description     | Verify if ```greatest_common_divisor.asm``` comport any errors and return the expected result.|
| Test Case Pre-conditions  | ```assembler.exe``` must be build. <br> ```emulator.exe``` must be build. <br> Go to [testing](/documents/QA/testing/). <br> See if ```greatest_common_divisor.asm``` exists.         |
| Test Case Steps           | 1. Type ```assembler.exe greatest_common_divisor.asm greatest_common_divisor.bin``` in the terminal. <br> 2. Press ```enter```. <br> 3. Type ```emulator.exe greatest_common_divisor.bin > greatest_common_divisor.txt```. <br> 4. Press ```enter```.       |
| Test Case Expected Result | The product create ```greatest_common_divisor.txt``` and put the expected result in it.   |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | Medium 2                                  |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### Least Common Multiple

| Test Case ID              | 85                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | Least Common Multiple                     |
| Test Case Description     | Verify if ```least_common_multiple.asm``` comport any errors and return the expected result.|
| Test Case Pre-conditions  | ```assembler.exe``` must be build. <br> ```emulator.exe``` must be build. <br> Go to [testing](/documents/QA/testing/). <br> See if ```least_common_multiple.asm``` exists.         |
| Test Case Steps           | 1. Type ```assembler.exe least_common_multiple.asm least_common_multiple.bin``` in the terminal. <br> 2. Press ```enter```. <br> 3. Type ```emulator.exe least_common_multiple.bin > least_common_multiple.txt```. <br> 4. Press ```enter```.       |
| Test Case Expected Result | The product create ```least_common_multiple.txt``` and put the expected result in it.   |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | Medium 2                                  |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### Roll

| Test Case ID              | 86                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | Roll                                      |
| Test Case Description     | Verify if ```roll.asm``` comports any errors and return the expected result.|
| Test Case Pre-conditions  | ```assembler.exe``` must be build. <br> ```emulator.exe``` must be build. <br> Go to [testing](/documents/QA/testing/). <br> See if ```roll.asm``` exists.                                  |
| Test Case Steps           | 1. Type ```assembler.exe roll.asm roll.bin``` in the terminal. <br> 2. Press ```enter```. <br> 3. Type ```emulator.exe roll.bin > roll.txt```. <br> 4. Press ```enter```.       |
| Test Case Expected Result | The product create ```roll.txt``` and put the expected result in it.   |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | Medium 2                                  |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### Fibonacci

| Test Case ID              | 87                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | Fibonacci                                 |
| Test Case Description     | Verify if ```fibonacci.asm``` comport any errors and return the expected result.|
| Test Case Pre-conditions  | ```assembler.exe``` must be build. <br> ```emulator.exe``` must be build. <br> Go to [testing](/documents/QA/testing/). <br> See if ```fibonacci.asm``` exists.                             |
| Test Case Steps           | 1. Type ```assembler.exe fibonacci.asm fibonacci.bin``` in the terminal. <br> 2. Press ```enter```. <br> 3. Type ```emulator.exe fibonacci.bin > fibonacci.txt```. <br> 4. Press ```enter```.       |
| Test Case Expected Result | The product create ```fibonacci.txt``` and put the expected result in it.   |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | Medium 2                                  |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |