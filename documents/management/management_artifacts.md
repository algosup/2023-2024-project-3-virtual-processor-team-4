This document contains the main management artifacts:
- [List of tasks](https://algosup-my.sharepoint.com/:x:/p/benoit_dekeyn/ET3X56ZmAw1PpLeTLcSubvIB5y_Ylk7CU37q7dEQzBlDig?e=cXOKuN&nav=MTVfe0Q4MzdGRDRCLTJBNUItNDE3OC1CRjQ0LTk0RTE1MzhCRDAzQX0)
- [Tasks Management Board](https://trello.com/b/fyHkoXl9/virtual-processor-team-4)
- [RACI matrix](#raci-matrix)
- [Risks and Assumptions](#risks-and-assumptions)
- [Key Performance Indicators: Charts](https://algosup-my.sharepoint.com/:x:/p/benoit_dekeyn/ET3X56ZmAw1PpLeTLcSubvIB5y_Ylk7CU37q7dEQzBlDig?e=6n05sR&nav=MTVfezAwMDAwMDAwLTAwMDEtMDAwMC0wMDAwLTAwMDAwMDAwMDAwMH0) 
- [Key Performance Indicators: Data](https://algosup-my.sharepoint.com/:x:/p/benoit_dekeyn/ET3X56ZmAw1PpLeTLcSubvIB5y_Ylk7CU37q7dEQzBlDig?e=hhtu4A&nav=MTVfezQ3RjI0RTkyLUVFMDYtNDY1MS04MzE3LUM2Qjc4MzJERkU4Nn0)


# RACI matrix

The RACI matrix is as follows:

| Name                      | Project Manager | Program Manager | Technical Leader | Software Engineer | Quality Assurance | Client | Stakeholders |
| ------------------------- | --------------- | --------------- | ---------------- | ----------------- | ----------------- | ------ | ------------ |
| Project brief             | I               | I               | I                | I                 | I                 | A / R  | C            |
| Project charter           | A / R           | C / I           | C / I            | C / I             | C / I             | C      | C / I        |
| Schedule / Gantt chart    | A / R           | C / I           | C / I            | C / I             | C / I             |        | I            |
| Functional specifications | C               | A / R           | C                |                   | C / I             | C      | I            |
| Technical specifications  | C               | C               | A / R            | C                 | C / I             | C      | I            |
| Code                      |                 |                 | R                | A / R             |                   |        |              |
| Code review               | I               |                 | A / R            | R                 | R                 |        |              |
| Code documentation        |                 | I               | C                | A / R             | C / I             | I      |              |
| Usage instructions        |                 | I               | C                | A / R             | C / I             | I      |              |
| Testing plan              | I               | C               | C                | C                 | A / R             | I      |              |

Key:
| Letter | Name        | Description                                               |
| ------ | ----------- | --------------------------------------------------------- |
| R      | Responsible | Works on the task.                                        |
| A      | Accountable | Delegates and signs off. The one to be praised or blamed. |
| C      | Consulted   | Knowledgeable and asked about the task.                   |
| I      | Informed    | Told about the progress and changes.                      |
|        | -           | Not involved                                              |


# Risks and Assumptions

| ID   | Description                                                  | Impact                                                       | Impact | Likelihood | Strategy  | Solution                                                     |
| ---- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------ | ---------- | --------- | ------------------------------------------------------------ |
| 1    | Almost all the members of the team have never coded in C before | We will spend time on the development part                   | High   | High       | Sharing   | Have other members of the group help when necessary.         |
| 2    | There are a lot of important things to define in the functional specifications | The functional specifications may not be ready on time and are required for the rest of the project (due to the waterfall method) | High   | Medium     | Reduction | Start with the most simple and fundamental specifications and go to more detailed ones. |
| 6    | The last week is entirely dedicated to the oral presentation | We need to be efficient during project time and maybe work at home. | Medium | High       | Reminding | Remind well to everybody in the team that we don't have that much time for this project, above all at the end |
| 7    | As it is winter, health and transport issues are more likely to come up. | Team members may be late or even missing, possibly for multiple days. | Medium | High       | Sharing   | The work of missing members will either be shared with others, done later, or done remotely. |
