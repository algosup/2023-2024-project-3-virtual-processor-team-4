# Virtual Processor - Project charter

## Table of content
- [Project definition](#project-definition)
- [Scope](#scope)
- [Stakeholders](#stakeholders)
- [Team members and responsibilities](#team-members-and-responsabilities)
- [Project Plan](#project-plan)
- [Milestones](#milestones)
- [Deliverables](#deliverables)
- [Budget](#budget)


## Project definition

The project involves creating a virtual processor in C and an interpreter to run an assembly language through that processor.

The client is ALGOSUP, the programming school we are part of, and our contact point is Franck JEANNIN, the school director.

## Scope

The project should be done in a portable C language, using only C standard libraries as external ones.

Also, we must choose the syntax, the mnemonics, and the working process of the new assembly language that the new virtual processor will use.

The client gave us the basic instructions we need to implement for this assembly language.



## Stakeholders

| Role   | Representative           | Expectation   |
| ------ | ------------------------ | ------------- |
| Client | Franck JEANNIN (ALGOSUP) | Final project |

## Team members and responsibilities

| Name              | Role              | Responsibilities                                             | Performance criteria                                         |
| ----------------- | ----------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Benoît DE KEYN  | Project Manager   | Report to stakeholders<br>Management (deadlines, budget, ...)<br>Task repartition<br>Risk management | Project delivered on time and budget<br>Good planning<br>Smooth running project |
| Léo CHARTIER    | Program Manager   | Design<br>Communication with client<br>Functional specifications<br>Risk management | Functional specifications                                    |
| Jason GROSSO    | Technical Leader  | Choose technical tools<br>Define interactions within the code<br>Review code<br>Technical specifications | Technical specifications                                     |
| Antoine PREVOST | Software Engineer | Write code<br>Fix bugs<br>Document the code                  | (Unit tests)<br>As few bugs in the code as possible          |
| Max BERNARD     | Software Engineer |                                                              |                                                              |
| Maxime THIZEAU  | Quality Assurance | Verify documents<br>Test the program<br>Confirm we match the client's needs<br>Overall quality of the project<br>Test plan | All bugs identified<br>Good team cohesion<br>Deliver a qualitative project |

## Project Plan

A meeting with the client will be organized in the early days. Further discussions will be made via emails/Slack messages and reports will be sent to the client.

The project will mainly use the Waterfall method as shown by the deliverables, but will also use SCRUM ideas to improve the quality of development.
The program will be split into multiple steps which will be incrementally implemented. This will also allow for fast testing iterations, leading to fewer bugs.

For all the files and documents for this project, a GitHub repository is created to allow easy access and collaboration in a centralized system.

The planning will consist of a Trello board where each task will have tags such as the priority, the kind of task, the members who work on it, and the deadlines. There will be some columns containing the remaining tasks by category, and 3 columns as "Doing", "To review" and "Done". An Excel board will deserve the KPI chart and data, and a weekly report will be available on GitHub. All these documents will be available through the readme.md of the repository.

## Milestones

| Date       | Time | Milestone                         |
| ---------- | ---- | --------------------------------- |
| 08/01/2024 | 9am  | Project acknowledgment            |
| 17/01/2024 | 9am  | Project start, as a team          |
| 30/01/2024 | 5pm  | Functional specification delivery |
| 09/02/2024 | 5pm  | Technical specification delivery  |
| 16/02/2024 | 5pm  | Test plan delivery                |
| 22/02/2024 | 5pm  | Working prototype delivery        |
| 23/02/2024 | 5pm  | Final product delivery            |
| 29/02/2024 | 9am  | Presentation pitch                |

## Deliverables

The main deliverable will be an executable file containing the virtual processor and the interpreter (being able to run an assembly file), and the documentation to use this assembly language.

The source files of the project and some examples of ASM files will be of course available on the GitHub repository as well as a Wiki.

Additionally, many documents will be provided to the client. Those include:
- Functional specifications
- Technical specifications
- Test plan
- Management planning & weekly reports

Finally, a presentation of our work will be done to the client in the form of a 15-minute presentation.

## Budget

Money: Free
Workforce: 6 team members
Worktime: 27 half days of 3h15 (at least)

Estimated total man-hours: 527 mh
