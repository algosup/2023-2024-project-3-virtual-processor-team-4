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
            - [In-scope](#in-scope)
            - [Out-of-scope](#out-of-scope)
        - [testing type](#testing-type)
            - [Smoke testing](#smoke-testing)
            - [Unit testing](#unit-testing)
            - [Agile testing](#agile-testing)
    - [Test cases](#test-cases)
    - [Testing tools](#testing-tools)
        - [Hardware](#hardware)
        - [Software](#software)
    - [Test criteria](#test-criteria)
        - [Suspension criteria](#suspension-criteria)
        - [Entry criteria](#entry-criteria)
        - [Exit criteria](#exit-criteria)
    - [Bug report](#bug-report)
    - [Testing schedule and estimation](#testing-schedule-and-estimation)
        - [Tasks time estimation](#tasks-time-estimation)
        - [Tasks schedule](#tasks-schedule)
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
|Agile testing|A software development practice that promotes frequent, automated testing of new code as it is completed and stipulates that defects should be fixed as soon as they are found.|[Informatica](https://www.informatica.com/in/services-and-training/glossary-of-terms/agile-testing-definition.html#:~:text=Agile%20testing%20is%20a%20software,soon%20as%20they%20are%20found.)|
|Assembler|A program that changes computer instructions into machine code (= a set of numbers that gives instructions to a computer).|[Cambridge Dictionary](https://dictionary.cambridge.org/fr/dictionnaire/anglais/assembler)|
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
|Smoke testing|A software testing method that is used to determine if a new software build is ready for the next testing phase. This testing method determines if the most crucial functions of a program work but does not delve into finer details.|[TechTarget](https://www.techtarget.com/searchsoftwarequality/definition/smoke-testing#:~:text=Smoke%20testing%2C%20also%20called%20build,not%20delve%20into%20finer%20details.)|
|Unit testing|A software testing method by which individual units of source code—sets of one or more computer program modules together with associated control data, usage procedures, and operating procedures—are tested to determine whether they are fit for use.|[Wikipedia](https://en.wikipedia.org/wiki/Unit_testing)|
|Visual Studio Code|Visual Studio Code, also commonly referred to as VS Code, is a source-code editor developed by Microsoft for Windows, Linux and macOS. Features include support for debugging, syntax highlighting, intelligent code completion, snippets, code refactoring, and embedded Git.|[Wikipedia](https://en.wikipedia.org/wiki/Visual_Studio_Code)|
|Windows|Microsoft Windows is a group of several proprietary graphical operating system families developed and marketed by Microsoft. Each family caters to a certain sector of the computing industry.|[Wikipedia](https://en.wikipedia.org/wiki/Microsoft_Windows)|

## Introduction

### Overview

Our team was asked to create a virtual processor and an interpreter to run assembly language previously created by our team on this same processor. The processor should be totally portable and written in C with standard libraries.

<!-- ### Targeted audiance -->

## Testing Strategy

As a quality assurance I need to test the quality of the code produce by the sofware engineer team but also the quality of the documentation.

**code testing strategy**

Our testing strategy will be based on three different testing types. At first we will use [smoke testing](#smoke-testing) to see basics functionnalities. Then we will use some [unit tests](#unit-testing) to see in more detail if the code run as expected. We will also use some [agile testing](#agile-testing) to test the code before each push on GitHub.

**documentation testing strategy**

As for the documentation, I will principaly do the test as soon as a new version is released or updated but majoritarly test before the release date of them.

### Quality Assurance team

The testing team will be composed by 5 Quality assurance member from 5 different teams:

- Serena BAVAROIS from the team 1 (Windows)
- Enzo GUILLOUCHE from the team 2 (Windows)
- Arthur LEMOINE from the team 3 (macOS)
- Maxime THIZEAU from the team 4 (Windows)
- Atifa AMIRI from the team 5 (Windows)

Having this lot of people will allow our teams to have an external point of view on our product and to define if we are on the good path or not. Moreover this association allow us to test our product with different operator system such as macOS and Windows. Finally it could helps us to create a better testing of the product.

### testing scope

Testing will focus on assembly instruction and the assembler.

#### In-scope

- Assembly instruction
  - all the instructions defined in the ```functional_specification.md``` should function as intended.
- Assembler
  - Absence of significant bug
  - Should run properly
  - Should compile the files
  - Should interprete asm files
- Documentation
  - Spelling accuracy
  - Typographical errors
  - naming conventions

#### Out-of-Scope

- font details
- interupt instruction
<!-- TODO
- ... -->

### testing type

#### Smoke testing

The quality assurance is going to use a smoke testing strategy for the assembler, like this he would be sure that it works as intended by doing some easy test each time he ran the code.

#### Unit testing

The quality assurance will also use Unit tests for all the particular instruction in the assembly language createdby the team. It will also be used to assure that some function in the assembler work as intended.

#### Agile testing

Finally, the quality assurance will use an agile testing strategy. This means that he should be really reactive each time of a version is pushedon the repository and to test them.

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
  
- [ThinkPad E14 Gen 5](https://www.lenovo.com/fr/fr/p/laptops/thinkpad/thinkpade/thinkpad-e14-gen-5-(14-inch-intel)/len101t0064)
  - Windows 11 Pro
  - 14 inch (1920 x 1080)
  - Processor: 13th Gen Intel(R) Core(TM) i7-1355U, 1700 Mhz
  - RAM: 16.0 GB
  - System type: 64-bit operating system, x64-based processor

### Software

- [Visual Studio Code](https://code.visualstudio.com/) for the development of the game.
- [GitHub](https://github.com) for the version control and to track the defects.
- [Gcc](https://en.wikipedia.org/wiki/GNU_Compiler_Collection) for the compilation of the final product on [Windows](https://code.visualstudio.com/docs/cpp/config-mingw), [macOS](https://code.visualstudio.com/docs/cpp/config-clang-mac), [Linux](https://code.visualstudio.com/docs/cpp/config-linux).

## Test criteria

### Suspension criteria

When a test is done if a suspension criteria is reach we stop the folllowing test and the development team as well as the quality assurance team will work together until the issue met was fixed. This method will allow us to take issues oneby one and to not create program with existing issue in it. It would avoid to generate more issues.

### Entry criteria

The entry criterias are the criteria needed to the well being of the test and to esure to proceed them in the better environment possible. \
The three main criterias are:
- Be sure to proceed tests on a valid version of the code.
- Be sure to have the unit tests required
- Be sure that the environment is correctly set for the tests

### Exit criteria

The exit criterias are should specify the requirements to complete before the end of the testing phase. \
These criterias are:
- We need to have at least 80% of success rate.
- We need to have no critical or high severity defects during the tests.
- All the little and medium severity issues should be reported.

## Bug report

**Github issues report**

To provide a better bug report I chose to create a bug report template that we can apply on github issues. It allows the people that found a bug to report it quickly and effectively with the main information needed. \
Here is a picture of the template:

![Bug report high](/documents/pictures/bug_report_high.png)
![Bug report low](/documents/pictures/bug_report_low.png)

**Labels**

I also provide labels to my team, permitting us to have a better comprehension of the bug just with the title and the labels. There are 15 of then:

|Label|Description|
|:-----:|-----------|
|![Bug Label](/documents/pictures/bug_label.png)|Something isn't working|
|![Critical Label](/documents/pictures/critical_label.png)|Critical Priority|
|![Dev Label](/documents/pictures/dev_label.png)|Use for Dev|
|![Documentation Label](/documents/pictures/documentation_label.png)|Improvements or additions to documentation|
|![Duplicate Label](/documents/pictures/duplicate_label.png)|This issue or pull request already exists|
|![Enhancement Label](/documents/pictures/enhancement_label.png)|New feature or request|
|![Good first issue Label](/documents/pictures/good_first_issue_label.png)|Good for newcomers|
|![Help wanted Label](/documents/pictures/help_wanted_label.png)|Extra attention is needed|
|![High Label](/documents/pictures/high_label.png)|High Priority|
|![Invalid Label](/documents/pictures/invalid_label.png)|This doesn't seem right|
|![Low Label](/documents/pictures/low_label.png)|Low Priority|
|![medium Label](/documents/pictures/medium_label.png)|Medium Priority|
|![Question Label](/documents/pictures/question_label.png)|Further information is requested|
|![Test case Label](/documents/pictures/test_case_label.png)|Use for test case|
|![Wontfix Label](/documents/pictures/wontfix_label.png)|This will not be worked on|

## Testing schedule and estimation

### Tasks time estimation

|Task|Duration|
|----|--------|
|Requirement specification documentation review|5 hours|
|Test plan writing|20 hours|
|Test cases creation|10 hours|
|Assembly testing|15 hours|
|Quality assurance meeting|4 hours|
|Test case execution|20 hours|
|GitHub initialization|2 hours|
|Bug reports|12 hours|
|Bug data report|6 hours|

All the duration define here are only an estimation! It could take more or less time according to the advancement of the tasks, the extra hours outside the school or even if the test cases doesn't occur any errors or issues.

### Tasks schedule

|Task|Start date|End date|
|----|----------|--------|
|GitHub initialization|01/22/24|01/22/24|
|Test plan writing|01/22/24|02/16/24|
|Test cases creation|01/22/24|02/16/24|
|Assembly testing|01/22/24|01/30/24|
|Functional specification review|01/29/24|01/30/24|
|Quality assurance meeting|01/29/24|01/29/24|
|Functional specification review|02/08/24|02/09/24|
|Test case execution|01/30/24|02/23/24|
|Bug reports|01/30/24|02/23/24|
|Bug data report|01/30/24|02/23/24|

## Test deliverables

- **Test plan:** It will define how the tests should be done and the strategy choosen.
- **Test cases:** It will contain all the test that will be done to see if the product is functional.
- **Bug reports:** Each will contain a report about a bug found during the test sessions.
- **Bug data report:** It will allow to see all of the reports in one place.

## Conclusion and acknowledgements

The testing part of a project is oneof the most important one. If the quality isn't assured then the product would not work as intended, that is why this part is such an important one.

We would thank all the member of the team who works in this project.
We would thank the other quality assurance that we work with, our product would have been less good without their help.

<!-- TODO -->

We would also thank our teacher, [], that teach us the fundamental of a good test plan and of the quality assurance role.

We would also thank the previous project quality assurance who help us by giving us hint.

Finally, we would than [ALGOSUP] for this project and this opportunity to develop our skills once again.

## Sources

- [Cambridge Dictionary](https://dictionary.cambridge.org/)
- [Github](https://github.com/)
- [Informatica](https://www.informatica.com/eng.html)
- [TechTarget](https://www.techtarget.com/)
- [Wikipedia](https://en.wikipedia.org/wiki/Main_Page)