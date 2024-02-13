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
| Test Case Steps           | 1. Open ```main.c``` in Visual Studio Code. 2. Run the file with GCC.           |
| Test Case Expected Result | The file run without errors and you get another file named ```assembler.exe```. |
| Test Case Actual Result   | ---                                                                             |
| Test Case Status          | To Test                                                                         |
| Test Case Priority        | High 1                                                                          |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                             |

### No parameter

| Test Case ID              | 2                                                                  |
|---------------------------|--------------------------------------------------------------------|
| Test case Name            | No parameter                                                       |
| Test Case Description     | Help the user to use the ```assembler.exe```                       |
| Test Case Pre-conditions  | ```assembler.exe``` must be build.                                 |
| Test Case Steps           | 1. Type ```assembler.exe``` in the terminal. 2. Press ```enter```. |
| Test Case Expected Result | A help message should be sent.                                     |
| Test Case Actual Result   | ---                                                                |
| Test Case Status          | To Test                                                            |
| Test Case Priority        | Low 3                                                              |
| Test Case Assigned To     | QA (Maxime THIZEAU)                                                |

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
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

## Separate color

| Test Case ID              | 5                                         |
|---------------------------|-------------------------------------------|
| Test Case Name            | Separate color                            |
| Test Case Description     | Verify if `separate_color.asm` comport any errors |
| Test Case Pre-conditions  | The product is running <br> go to [testing](/documents/QA/testing/) <br> see if `separate_color.asm` exist           |
| Test Case Steps           | Copy the file named `separate_color.asm` <br> paste it in the same file as `main.c` <br> enter `separate_color` in the terminal           |
| Test Case Expected Result | The product create `separate_color.exe`   |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | Medium 2                                  |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

## Convert Hexa to Decimal

| Test Case ID              | 6                                         |
|---------------------------|-------------------------------------------|
| Test Case Name            | Convert Hexa to Decimal                   |
| Test Case Description     | Verify if `hexa_to_decimal.asm` comport any errors |
| Test Case Pre-conditions  | The product is running <br> go to [testing](/documents/QA/testing/) <br> see if `hexa_to_decimal.asm` exist           |
| Test Case Steps           | Copy the file named `hexa_to_decimal.asm` <br> paste it in the same file as `main.c` <br> enter `hexa_to_decimal` in the terminal           |
| Test Case Expected Result | The product create `hexa_to_decimal.exe`  |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | Medium 2                                  |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

## Temperature convertor

| Test Case ID              | 7                                         |
|---------------------------|-------------------------------------------|
| Test Case Name            | Temperature convertor                     |
| Test Case Description     | Verify if `temperature_convertor.asm` comport any errors |
| Test Case Pre-conditions  | The product is running <br> go to [testing](/documents/QA/testing/) <br> see if `temperature_convertor.asm` exist           |
| Test Case Steps           | Copy the file named `temperature_convertor.asm` <br> paste it in the same file as `main.c` <br> enter `temperature_convertor` in the terminal           |
| Test Case Expected Result | The product create `temperature_convertor.exe`  |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | Medium 2                                  |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

## Randomizer

| Test Case ID              | 8                                         |
|---------------------------|-------------------------------------------|
| Test Case Name            | Randomizer                                |
| Test Case Description     | Verify if `random_generator.asm` comport any errors |
| Test Case Pre-conditions  | The product is running <br> go to [testing](/documents/QA/testing/) <br> see if `random_generator.asm` exist         |
| Test Case Steps           | Copy the file named `random_generator.asm` <br> paste it in the same file as `main.c` <br> enter `random_generator` in the terminal           |
| Test Case Expected Result | The product create `random_generator.exe` |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | Medium 2                                  |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

## Greatest Common Divisor

| Test Case ID              | 9                                         |
|---------------------------|-------------------------------------------|
| Test Case Name            | Greatest Common Divisor                   |
| Test Case Description     | Verify if `greatest_common_divisor.asm` comport any errors |
| Test Case Pre-conditions  | The product is running <br> go to [testing](/documents/QA/testing/) <br> see if `greatest_common_divisor.asm` exist         |
| Test Case Steps           | Copy the file named `greatest_common_divisor.asm` <br> paste it in the same file as `main.c` <br> enter `greatest_common_divisor` in the terminal           |
| Test Case Expected Result | The product create `greatest_common_divisor.exe` |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | Medium 2                                  |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

## Least Common Multiple

| Test Case ID              | 10                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | Least Common Multiple                   |
| Test Case Description     | Verify if `least_common_multiple.asm` comport any errors |
| Test Case Pre-conditions  | The product is running <br> go to [testing](/documents/QA/testing/) <br> see if `least_common_multiple.asm` exist         |
| Test Case Steps           | Copy the file named `least_common_multiple.asm` <br> paste it in the same file as `main.c` <br> enter `least_common_multiple` in the terminal           |
| Test Case Expected Result | The product create `least_common_multiple.exe` |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | Medium 2                                  |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

## Roll

| Test Case ID              | 11                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | Roll                                      |
| Test Case Description     | Verify if `roll.asm` comports any errors   |
| Test Case Pre-conditions  | The product is running <br> go to [testing](/documents/QA/testing/) <br> see if `roll.asm` exist                                  |
| Test Case Steps           | Copy the file named `roll.asm` <br> paste it in the same file as `main.c` <br> enter `roll` in the terminal                      |
| Test Case Expected Result | The product create `roll.exe`             |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | Medium 2                                  |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       |

## Fibonacci

| Test Case ID              | 12                                        |
|---------------------------|-------------------------------------------|
| Test Case Name            | Fibonacci                                 |
| Test Case Description     | Verify if `fibonacci.asm` comport any errors|
| Test Case Pre-conditions  | The product is running <br> go to [testing](/documents/QA/testing/) <br> see if `fibonacci.asm` exist                             |
| Test Case Steps           | Copy the file named `fibonacci.asm` <br> paste it in the same file as `main.c` <br> enter `fibonacci` in the terminal            |
| Test Case Expected Result | The product create `fibonacci.exe`        |
| Test Case Actual Result   | ---                                       |
| Test Case Status          | To Test                                   |
| Test Case Priority        | Medium 2                                  |
| Test Case Assigned To     | QA (Maxime THIZEAU)                       | -->