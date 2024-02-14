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

### Assembler compilation

| Test Case ID              | 1                                                                               |
|---------------------------|---------------------------------------------------------------------------------|
| Test case Name            | Assembler compilation                                                           |
| Test Case Description     | Verify if the assembly ```main.c``` could be run without errors.                |
| Test Case Pre-conditions  | The product isn't running.                                                      |
| Test Case Steps           | 1. Open ```main.c``` in Visual Studio Code. <br> 2. Run the file with GCC.      |
| Test Case Expected Result | The file run without errors and you get another file named ```assembler.exe```. |
| Test Case Actual Result   | ---                                                                             |
| Test Case Status          | To Test                                                                         |
| Test Case Priority        | High 1                                                                          |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                             |

### No parameter

| Test Case ID              | 2                                                                       |
|---------------------------|-------------------------------------------------------------------------|
| Test case Name            | No parameter                                                            |
| Test Case Description     | Help the user to use the ```assembler.exe```                            |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.                                      |
| Test Case Steps           | 1. Type ```assembler.exe``` in the terminal. <br> 2. Press ```enter```. |
| Test Case Expected Result | A help message should be sent.                                          |
| Test Case Actual Result   | ---                                                                     |
| Test Case Status          | To Test                                                                 |
| Test Case Priority        | Low 3                                                                   |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                     |

### One parameter

| Test Case ID              | 3                                                                                   |
|---------------------------|-------------------------------------------------------------------------------------|
| Test case Name            | One parameter                                                                       |
| Test Case Description     | Help the user to use the ```assembler.exe```                                        |
| Test Case Pre-conditions  | ```assembler.exe``` must be build. <br> ```example.asm``` must exist.               |
| Test Case Steps           | 1. Type ```assembler.exe example.asm``` in the terminal. <br> 2. Press ```enter```. |
| Test Case Expected Result | A help message should be sent but the product should run.                           |
| Test Case Actual Result   | ---                                                                                 |
| Test Case Status          | To Test                                                                             |
| Test Case Priority        | Low 3                                                                               |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                                 |

### File not found for the assembler

| Test Case ID              | 4                                                                                              |
|---------------------------|------------------------------------------------------------------------------------------------|
| Test case Name            | File not found for the assembler                                                               |
| Test Case Description     | Search if the assembly file already exist or not.                                              |
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
| Test Case Description     | Search if an error happens when invalid parameter.                                                                                                      |
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
| Test Case Steps           | 1. Create ```example.asm``` containing ```test rt ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```. |
| Test Case Expected Result | An error must be sent.                                                                                                                                       |
| Test Case Actual Result   | ---                                                                                                                                                          |
| Test Case Status          | To Test                                                                                                                                                      |
| Test Case Priority        | High 1                                                                                                                                                       |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                                                                                                          |

### Too much parameters

| Test Case ID              | 9                                                                                                                                                                  |
|---------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Test case Name            | Too much parameters                                                                                                                                                |
| Test Case Description     | Search if it contains too much parameters in a line.                                                                                                               |
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

### No immediate as second parameter

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

### No immediate as third parameter

| Test Case ID              | 16                                                                                                                                                            |
|---------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Test case Name            | No immediate as third parameter                                                                                                                                                 |
| Test Case Description     | Search if there is missing an immediate value as the the third parameter.                                                                                                                |
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
| Test Case Steps           | 1. Create ```example.asm``` containing ```jump next```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.  |
| Test Case Expected Result | An error must be sent.                                                                                                                                       |
| Test Case Actual Result   | ---                                                                                                                                                          |
| Test Case Status          | To Test                                                                                                                                                      |
| Test Case Priority        | High 1                                                                                                                                                       |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                                                                                                          |

<!-- ### Label Number

jump to over 8 million to test label number -->

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
| Test Case Steps           | 1. Create ```example.asm``` containing ```jump ra```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.  |
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
| Test Case Expected Result | The product should run without any error.                                                                                                                                   |
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
| Test Case Expected Result | The product should run without any error.                                                                                                                 |
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
| Test Case Expected Result | The product should run without any error.                                                                                                                  |
| Test Case Actual Result   | ---                                                                                                                                                        |
| Test Case Status          | To Test                                                                                                                                                    |
| Test Case Priority        | High 1                                                                                                                                                     |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                                                                                                        |

### Return carriage

| Test Case ID              | 26                                                                                                                                                             |
|---------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Test case Name            | Return carriage                                                                                                                                                |
| Test Case Description     | Check if the product can handle return carriage.                                                                                                               |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.                                                                                                                             |
| Test Case Steps           | 1. Create ```example.asm``` containing a return carriage. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.  |
| Test Case Expected Result | The product should run without any error.                                                                                                                      |
| Test Case Actual Result   | ---                                                                                                                                                            |
| Test Case Status          | To Test                                                                                                                                                        |
| Test Case Priority        | High 1                                                                                                                                                         |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                                                                                                            |

### Specific character in commentary

| Test Case ID              | 27                                                                                                                                                                                             |
|---------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Test case Name            | Specific character in commentary                                                                                                                                                               |
| Test Case Description     | Check if the product can handle specific characters in commentaries.                                                                                                                           |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.                                                                                                                                                             |
| Test Case Steps           | 1. Create ```example.asm``` containing a commentary with one or many specific characters. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.  |
| Test Case Expected Result | The product should run without any error.                                                                                                                                                      |
| Test Case Actual Result   | ---                                                                                                                                                                                            |
| Test Case Status          | To Test                                                                                                                                                                                        |
| Test Case Priority        | High 1                                                                                                                                                                                         |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                                                                                                                                            |

### Specific character out commentary

| Test Case ID              | 28                                                                                                                                                                                                |
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

| Test Case ID              | 29                                                                                                                                                            |
|---------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Test case Name            | Hexadecimal value                                                                                                                                             |
| Test Case Description     | Check if the product can handle hexadecimal value.                                                                                                            |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.                                                                                                                            |
| Test Case Steps           | 1. Create ```example.asm``` containing ```set ra xFF```. <br> 2. Type ```assembler.exe example.asm output.bin``` in the terminal. <br> 3. Press ```enter```.  |
| Test Case Expected Result | The product should run without any error.                                                                                                                     |
| Test Case Actual Result   | ---                                                                                                                                                           |
| Test Case Status          | To Test                                                                                                                                                       |
| Test Case Priority        | High 1                                                                                                                                                        |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                                                                                                           |


<!-- ## Run the product

| Test Case ID              | 1                                         |
|---------------------------|-------------------------------------------|
| Test Case Name            | Run the product                           |
| Test Case Description     | Verify that the product can be run        |
| Test Case Pre-conditions  | The product isn't running                 |
| Test Case Steps           | Run the file `main.c`                     |
| Test Case Expected Result | The product run without segmentation fault |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 1                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

## Search a file

| Test Case ID              | 2                                         |
|---------------------------|-------------------------------------------|
| Test Case Name            | Search a file                             |
| Test Case Description     | Verify if the file exist                  |
| Test Case Pre-conditions  | The product is running                    |
| Test Case Steps           | Enter any file name in the terminal       |
| Test Case Expected Result | The product sends an error text saying file not found |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 1                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

## Assemble a file

| Test Case ID              | 3                                         |
|---------------------------|-------------------------------------------|
| Test Case Name            | Assemble a file                           |
| Test Case Description     | Verify that the product can assemble a .asm file       |
| Test Case Pre-conditions  | The product is running <br> a file name `example.asm` is created and placed in the same file as `main.c`          |
| Test Case Steps           | Enter `example` in the terminal           |
| Test Case Expected Result | The product finds the file and creates a `.exe` file |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 1                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

## Find an error

| Test Case ID              | 4                                         |
|---------------------------|-------------------------------------------|
| Test Case Name            | Find an error                             |
| Test Case Description     | Verify if the `.asm` file comports any errors |
| Test Case Pre-conditions  | The product is running <br> a file name `example.asm` is created and placed in the same file as `main.c`         |
| Test Case Steps           | Enter `example` in the terminal           |
| Test Case Expected Result | The product send an error                 |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | High 1                                    |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       | -->

## File testing

### Separate color

| Test Case ID              | 30                                         |
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

| Test Case ID              | 31                                         |
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

| Test Case ID              | 32                                         |
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

| Test Case ID              | 33                                         |
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

| Test Case ID              | 34                                         |
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

| Test Case ID              | 35                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | Least Common Multiple                   |
| Test Case Description     | Verify if ```least_common_multiple.asm``` comport any errors and return the expected result.|
| Test Case Pre-conditions  | ```assembler.exe``` must be build. <br> ```emulator.exe``` must be build. <br> Go to [testing](/documents/QA/testing/). <br> See if ```least_common_multiple.asm``` exists.         |
| Test Case Steps           | 1. Type ```assembler.exe least_common_multiple.asm least_common_multiple.bin``` in the terminal. <br> 2. Press ```enter```. <br> 3. Type ```emulator.exe least_common_multiple.bin > least_common_multiple.txt```. <br> 4. Press ```enter```.       |
| Test Case Expected Result | The product create ```least_common_multiple.txt``` and put the expected result in it.   |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | Medium 2                                  |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

### Roll

| Test Case ID              | 36                                        |
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

| Test Case ID              | 37                                        |
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