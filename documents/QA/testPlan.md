# Virtual processor - Test Plan

This project was requested by [ALGOSUP](https://algosup.com), a French computer science school.

The goal of the project is to create a virtual processor and an interpreter for running assembly code on 
that processor.
The assembly language will also be created and tailored by us.

<details>
<summary>Table of Contents</summary>

- [Test Plan](#test-plan)
    - [Test plan approval](#test-plan-approval)
    - [Glossary](#glossary)
    - [Introduction](#introduction)
        - [Overview](#overview)
        <!-- - [Targetted audiance](#target-audiance) -->
    - [Testing Strategy](#testing-strategy)
        - [QA team](#quality-assurance-team)
        - [testing scope](#testing-scope)
        - [testing type](#testing-type)
            - [... Test](#test)
            - [... Test](#test-1)
            - [... Test](#test-2)
    - [Test cases](#test-cases)
    - [Testing tools](#testing-tools)
        - [Hardware](#hardware)
        - [Software](#software)
    - [Test criteria](#test-criteria)
    - [Bug report](#bug-report)
    - [Testing schedule](#testing-schedule)
    - [Test deliverables](#test-deliverables)
    - [Conclusion and acknowledgements](#conclusion-and-acknowledgements)
    - [Sources](#sources)
    
</details>

## Test Plan approval

|Role             |Name               |Signature      |Date      |
|-----------------|-------------------|---------------|----------|
| Benoît DE KEYN  | Project Manager   |               |16/02/2024|
| Léo CHARTIER    | Program Manager   |               |16/02/2024|
| Jason GROSSO    | Tech Lead         |               |16/02/2024|
| Antoine PREVOST | Software Engineer |               |16/02/2024|
| Max BERNARD     | Software Engineer |               |16/02/2024|
| Maxime THIZEAU  | Quality Assurance |               |16/02/2024|

## Glossary

|Term|Definition|Source|
|----|----------|------|
|ALGOSUP|||
|Assembly language|||
|Compiler|||
|C language|||
|Github|||
|GNU Compiler Collection (GCC)|||
|Interpreter|||
|Linux|||
|MacOS|||
|Test case|||
|... Test|||
|... Test|||
|... Test|||
|Visual Studio Code|||
|Windows|||

## Introduction

### Overview

Our team was asked to create a virtual processor and an interprete to run assembly language previously created by our team on this same processor. The processor should be totally portable and written in C with standard libraries.

<!-- ### Targeted audiance -->

## Testing Strategy

### Quality Assurance team

The testing team will be composed by 5 Quality assurance member from 5 different teams:

- Serena BAVAROIS from the team 1 (Windows)
- Enzo GUILLOUCHE from the team 2 (Windows)
- Arthur LEMOINE from the team 3 (macOS)
- Maxime THIZEAU from the team 4 (Windows)
- Atifa AMIRI from the team 5 (Windows)

Having this lot of people will allow our teams to have an external point of view on our product and to define if we are on the good path or not. Moreover this association allow us to test our product with different operator system such as macOS and Windows. Finally it could helps us to create a better testing of the product.

### testing scope

### testing type

#### ... Test

#### ... Test

#### ... Test

## Test cases

This tablewill be used as an example for all of our test cases to test our product. We will create a test case for each test of our product and will define their priority.

| Test Case ID              | ID                                                                         |
|---------------------------|----------------------------------------------------------------------------|
| Test Case Name            | Name of the test case                                                      |
| Test Case Description     | Description of the test case                                               |
| Test Case Pre-conditions  | Requirements for the test                                                  |
| Test Case Steps           | Steps to go from the current state to the expected result                  |
| Test Case Expected Result | Result expected after following the steps                                  |
| Test Case Actual Result   | Actual result of the test (could differ from what's expected)              |
| Test Case Status          | Status of the test (To Test, Testing, Tested)                              |
| Test Case Priority        | Defines if a test is important or not. Using symbols : Low / Medium / High |
| Test Case Assigned To     | Name of the tester                                                         |

All the test cases will be stored in the markdown file ```testCases.md```

## Testing tools

### Hardware

All the tests will be done on different tools:

- [MacBook Air 2020](https://www.apple.com/fr/macbook-air-m1/)
  - 13.3 inch (2560 x 1600)
  - macOS Ventura 13.0
  - Apple M1 Chip

- [Lenovo Thinkbook 14](https://pcsupport.lenovo.com/us/en/products/laptops-and-netbooks/thinkbook-series/thinkbook-14-iil/20sl)
  - Windows 11 Pro
  - 14 inch (1920 x 1080)
  - Processor: Intel(R) Core(TM) i7-1065G7 CPU @ 1.30GHz
  - RAM: 16.0 GB
  - System type: 64-bit operating system, x64-based processor
  
<!-- - [ThinkPad E14 Gen 5](https://www.lenovo.com/fr/fr/p/laptops/thinkpad/thinkpade/thinkpad-e14-gen-5-(14-inch-intel)/len101t0064)
  - Windows 11 Pro
  - 14 inch (1920 x 1080)
  - Processor: 13th Gen Intel(R) Core(TM) i7-1355U, 1700 Mhz
  - RAM: 16.0 GB
  - System type: 64-bit operating system, x64-based processor -->

### Software

- [Visual Studio Code](https://code.visualstudio.com/) for the development of the game.
- [GitHub](https://github.com) for the version control and to track the defects.
- [Gcc](https://en.wikipedia.org/wiki/GNU_Compiler_Collection) for the compilation of the final product on [Windows](https://code.visualstudio.com/docs/cpp/config-mingw), [macOS](https://code.visualstudio.com/docs/cpp/config-clang-mac), [Linux](https://code.visualstudio.com/docs/cpp/config-linux).

## Test criteria

## Bug report

## Testing schedule

## Test deliverables

## Conclusion and acknowledgements



## Sources