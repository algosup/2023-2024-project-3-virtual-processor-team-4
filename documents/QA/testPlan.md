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
|Assembly language|In computer programming, assembly language is any low-level programming language with a very strong correspondence between the instructions in the language and the architecture's machine code instructions|[Wikipedia](https://en.wikipedia.org/wiki/Assembly_language)|
|Compiler|In computing, a compiler is a computer program that translates computer code written in one programming language (the source language) into another language (the target language).|[Wikipedia](https://en.wikipedia.org/wiki/Compiler)|
|C language|C is a general-purpose computer programming language. C is commonly used on computer architectures that range from the largest supercomputers to the smallest microcontrollers and embedded systems.|[Wikipedia](https://en.wikipedia.org/wiki/C_(programming_language))|
|Github|GitHub, Inc. is an AI-powered developer platform that allows developers to create, store, manage and share their code.|[Wikipedia](https://en.wikipedia.org/wiki/GitHub)|
|Github Issues|GitHub Issues are items you can create in a repository to plan, discuss and track work. Issues are simple to create and flexible to suit a variety of scenarios. You can use issues to track work, give or receive feedback, collaborate on ideas or tasks, and efficiently communicate with others.|[Github](https://docs.github.com/en/issues/tracking-your-work-with-issues/about-issues)|
|GNU Compiler Collection (GCC)|The GNU Compiler Collection (GCC) is an optimizing compiler produced by the GNU Project supporting various programming languages, hardware architectures and operating systems.|[Wikipedia](https://en.wikipedia.org/wiki/GNU_Compiler_Collection)|
|Interpreter|In computer science, an interpreter is a computer program that directly executes instructions written in a programming or scripting language, without requiring them previously to have been compiled into a machine language program.|[Wikipedia](https://en.wikipedia.org/wiki/Interpreter_(computing))|
|Linux|Linux is a family of open-source Unix-like operating systems based on the Linux kernel, an operating system kernel first released on September 17, 1991, by Linus Torvalds.|[Wikipedia](https://en.wikipedia.org/wiki/Linux)|
|MacOS|MacOS, originally Mac OS X, previously shortened as OS X, is an operating system developed and marketed by Apple Inc.|[Wikipedia](https://en.wikipedia.org/wiki/MacOS)|
|Test case|In software engineering, a test case is a specification of the inputs, execution conditions, testing procedure, and expected results that define a single test to be executed to achieve a particular software testing objective, such as to exercise a particular program path or to verify compliance with a specific requirement.|[Wikipedia](https://en.wikipedia.org/wiki/Test_case)|
|... Test|||
|... Test|||
|... Test|||
|Visual Studio Code|Visual Studio Code, also commonly referred to as VS Code, is a source-code editor developed by Microsoft for Windows, Linux and macOS. Features include support for debugging, syntax highlighting, intelligent code completion, snippets, code refactoring, and embedded Git.|[Wikipedia](https://en.wikipedia.org/wiki/Visual_Studio_Code)|
|Windows|Microsoft Windows is a group of several proprietary graphical operating system families developed and marketed by Microsoft. Each family caters to a certain sector of the computing industry.|[Wikipedia](https://en.wikipedia.org/wiki/Microsoft_Windows)|

## Introduction

### Overview

Our team was asked to create a virtual processor and an interpreter to run assembly language previously created by our team on this same processor. The processor should be totally portable and written in C with standard libraries.

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

This table will be used as an example for all of our test cases to test our product. We will create a test case for each test of our product and will define their priority.

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

**Github issues report**

To provide a better bug report I chose to create a bug report template that we can apply on github issues. It allows the people that found a bug to report it quickly and effectively with the main information needed. \
Here is a picture of the template:

![Bug report high](..\pictures\bug_report_high.png)
![Bug report low](..\pictures\bug_report_low.png)

**Labels**

I also provide to my team labels, permitting us to have a better comprehension of the bug just with the title and the labels. There are 15 of then:

|Label|Description|
|:-----:|-----------|
|![Bug Label](..\pictures\bug_label.png)|Something isn't working|
|![Critical Label](..\pictures\critical_label.png)|Critical Priority|
|![Dev Label](..\pictures\dev_label.png)|Use for Dev|
|![Documentation Label](..\pictures\documentation_label.png)|Improvements or additions to documentation|
|![Duplicate Label](..\pictures\duplicate_label.png)|This issue or pull request already exists|
|![Enhancement Label](..\pictures\enhancement_label.png)|New feature or request|
|![Good first issue Label](..\pictures\good_first_issue_label.png)|Good for newcomers|
|![Help wanted Label](..\pictures\help_wanted_label.png)|Extra attention is needed|
|![High Label](..\pictures\high_label.png)|High Priority|
|![Invalid Label](..\pictures\invalid_label.png)|This doesn't seem right|
|![Low Label](..\pictures\low_label.png)|Low Priority|
|![medium Label](..\pictures\medium_label.png)|Medium Priority|
|![Question Label](..\pictures\question_label.png)|Further information is requested|
|![Test case Label](..\pictures\test_case_label.png)|Use for test case|
|![Wontfix Label](..\pictures\wontfix_label.png)|This will not be worked on|

## Testing schedule

## Test deliverables

## Conclusion and acknowledgements



## Sources