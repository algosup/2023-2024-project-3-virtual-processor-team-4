# Virtual processor - Functional specifications

This project was requested by [ALGOSUP](https://algosup.com), a French computer science school.

The goal of the project is to create a virtual processor and an interpreter for running assembly code on 
that processor.
The assembly language will also be created and tailored by us.

<details>
<summary>Table of Contents</summary>

- [Stakeholders](#stakeholders)
  - [Project members](#project-members)
  - [Other stakeholders](#other-stakeholders)
- [Project scope](#project-scope)
- [Functional requirements](#functional-requirements)
- [Deliverables and milestones](#deliverables-and-milestones)
- [Personas and use cases](#personas-and-use-cases)
  - [Persona 1](#persona-1)
  - [Persona ...](#persona-)
- [Acceptance criteria](#acceptance-criteria)
- [Solution overview](#solution-overview)
  - [System architecture](#system-architecture)
  - [Instructions](#instructions)
  - [Usage](#usage)
- [Non-functional requirements](#non-functional-requirements)
  - [Performance](#performance)
  - [Scalability](#scalability)
  - [Portability](#portability)
  - [Usability](#usability)
- [Examples](#examples)
- [Timeline](#timeline)
- [Resources](#resources)
- [Risks and assumptions](#risks-and-assumptions)
- [Future improvements](#future-improvements)
- [Glossary](#glossary)
</summary></details>

## Stakeholders

### Project members

| Full name       | Occupation               | Links                                                             |
| --------------- | ------------------------ | ----------------------------------------------------------------- |
| Benoît DE KEYN  | Project manager          | [LinkedIn](https://linkedin.com/in/beno%C3%AEt-de-keyn-71611b293) |
| Léo CHARTIER    | Program manager          | [LinkedIn](https://linkedin.com/in/l%C3%A9o-chartier-367111221)   |
| Jason GROSSO    | Tech lead                | [LinkedIn](https://linkedin.com/in/jason-grosso-847b39251)        |
| Max BERNARD     | Senior software engineer | [LinkedIn](https://linkedin.com/in/max-bernard-b77680210)         |
| Antoine PREVOST | Junior software engineer | [LinkedIn](https://linkedin.com/in/antoine-prevost-dev)           |
| Maxime THIZEAU  | Quality assurance        | [LinkedIn](https://linkedin.com/in/maxime-thizeau-0b311a293)      |

### Other stakeholders

| Name           | Occupation                  | Links                          |
| -------------- | --------------------------- | ------------------------------ |
| Franck JEANNIN | Client (ALGOSUP's director) | [Website](https://algosup.com) |

## Project scope

We have multiple objectives for this project:
- Creation of an assembly language and [Instruction Set Architecture](#glossary) (defined further down in this document)
- Implementation of this ISA in the form of a [virtual processor](#glossary)
- Implementation of an interpreter to run code onto this virtual processor (in other words, encode the instructions of the CPU)
- Provision of sample assembly scripts that can be run by the interpreter

## Functional requirements

The instructions of the language must allow for the following actions:
- Data handling i.e. writing data between a register and
  - an immediate value (a constant),
  - another register,
  - the memory (RAM)
  - the virtual keyboard/display
- Calculations
  - The four basic mathematical operations (addition, subtraction, multiplication, division)
  - The four basic logical operations (not, and, or, xor)
- Branching
  - Comparison between registers and values
  - Conditional and unconditional jumping
  - Calling and returning from subroutines

The interpreter must be able to be compiled and run on any real computer architecture. No libraries outside of the standard ones should be used, and the libraries that are operating system-specific must have existing alternatives.

The interpreter must also detect syntactical errors such as invalid lines or invalid parameters. When those happen, the interpreter must stop the program and alert the user.

## Deliverables and milestones

| Date and time          | Deliverable              |
| ---------------------- | ------------------------ |
| 30 January 2023, 5 PM  | Functional specification |
| 9 February 2023, 5 PM  | Technical specification  |
| 16 February 2023, 5 PM | Test plan                |
| 23 February 2023, 5 PM | Final product            |

## Personas and use cases

<!-- TODO -->

### Persona 1

### Persona ...

## Acceptance criteria

The sample scripts -- which cover every instruction -- should be executed without any problem and their result should meet the expected output.

The program should be fail-safe with no segmentation fault, memory corruption, or other issue. In the event that those still happen, the program should catch them and alert the user of the error.

To ensure that the project is viable, all the specifications must be approved by the client and the program must also be tested by other teams (and potentially external people) to collect their feedback and improve the software.

## Solution overview

<!-- TODO -->

### System architecture

<!-- TODO -->

### Instructions

<!-- TODO -->

### Usage

<!-- TODO -->

## Non-functional requirements

### Performance
Since our language will be interpreted, our software must do so quite rapidly to not hinder the user experience.

### Scalability
In case the client decides to change their requirements, or if we realize that the current instruction set is insufficient, we must be able to easily update the way the instructions are run.

### Portability
As mentioned earlier, the software must run on any computer architecture which has a working C compiler.

### Usability
Although a debugger is not required, it might be useful for the developers to implement one for their own debugging needs.

## Examples

<!-- TODO -->

## Timeline

<!-- TODO -->

## Resources

Man-hours:
- 8 weeks
- 27 half-days (each of 3.5 hours)
- 567 manhours

Budget:
- None

## Risks and assumptions

<!-- TODO -->

## Future improvements

<!-- TODO -->

## Glossary

<!-- TODO -->

**Instruction Set Architecture (ISA)** \
An architecture defining how a microprocessor and its related components should work. It includes the instructions to run, the different registers, and memory partitioning among other things.
[Wikipedia](https://en.wikipedia.org/wiki/Instruction_set_architecture)

**Virtual processor** \

**Machine code** \

**Processor / Central Processing Unit (CPU)** \

**RAM** \

**Register** \