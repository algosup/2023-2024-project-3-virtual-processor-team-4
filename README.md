# The Project

This project is a student project provided by ALGOSUP, based in Vierzon. ( → see the [**call for tender**](/documents/.data/call_for_tender_2023-2024_project_3_virtual_processor.pdf))
The objective is to build a virtual processor and its components in C and to create our assembly language to interact with it.

The definition of the project is available in the [Project Charter](https://github.com/algosup/2023-2024-project-3-virtual-processor-team-4/blob/main/documents/project_charter.md)

<hr>

# The Members

|Name|Role|Image|Link|
| ------------------------- | --------------------------------- | -------------------- | --------------------------------------------------------------------------------------------------- |
| Benoît DE KEYN | Project Manager   | <img src="https://avatars.githubusercontent.com/u/146000855" width="100px"> | [Benoît\'s Github Profile](https://github.com/benoitdekeyn-algosup) |
| Léo CHARTIER    | Program Manager   | <img src="https://avatars.githubusercontent.com/u/91249751" width="100px"> | [Léo\'s Github Profile](https://github.com/leo-chartier) |
| Jason GROSSO    | Tech Lead         | <img src="https://avatars.githubusercontent.com/u/114397870" width="100px"> | [Jason\'s Github Profile](https://github.com/jasonGROSSO) |
| Antoine PREVOST | Software Engineer | <img src="https://avatars.githubusercontent.com/u/81081224" width="100px"> | [Antoine\'s Github Profile](https://github.com/TechXplorerFR) |
| Max BERNARD     | Software Engineer | <img src="https://avatars.githubusercontent.com/u/80251657?" width="100px"> | [Max\'s Github Profile](https://github.com/maxbernard3) |
| Maxime THIZEAU  | Quality Assurance | <img src="https://avatars.githubusercontent.com/u/145995586" width="100px"> | [Maxime\'s Github Profile](https://github.com/MaximeTAlgosup) |

<hr>

# The Manual

## Download

Just download the code of the project [from the last release](https://github.com/algosup/2023-2024-project-3-virtual-processor-team-4/releases) or directly [the zip of the main code](https://github.com/algosup/2023-2024-project-3-virtual-processor-team-4/archive/refs/heads/main.zip).
Then, unzip it, and follow the instructions below ↓

## Content of the release

In the release, the folder named 'src' contains all the code of the project.
You can find here the libraries folder and three files.c :

- **assembler.c** : program reading an assembly file (.asm) to generate a machine code file (.bin)
- **emulator.c** : program reading the machine code file (.bin) to execute the instructions through the virtual processor.
- **test_emulator.c** : a test file which runs tests on all the emulator functions.
- **libs/**
   - **utils.h** : structures and tools used in both emulator and assembler programs
   - **clock.h** : !not used! functions relative to the clock implementation to have a regular execution of the instructions.
   - **preprocessor.h** : functions relatives to the reading of the assembly file, detecting synthetical and semantical errors: decode the .asm file and gives all the read instructions to the assembler part. 
   - **assembler.h** : functions relatives to the encoding part . It take the instructions given by the preprocessor, to build the machine code (.bin) file containing all the instructions in binary.
   - **v_components.h** : functions to allocate the space in memory and create files that emulate the virtual component of the virtual processor architecture. It contains also the reading, writing and printing functions of the components' content.
   - **v_instructions.h** : functions which execute the assembly instructions using the virtual components.

## How to run an assembly file
The prerequisite is a compilator to compile .c files to executable files. We used **gcc compiler** for the entire project. So you have to refer to an online tutorial to install gcc on your machine.

### Windows

Copy your assembly file in the 'src' folder. Examples of assembly files are available [here](https://github.com/algosup/2023-2024-project-3-virtual-processor-team-4/tree/main/documents/QA/testing) and the documentation for our [assembly language](https://github.com/algosup/2023-2024-project-3-virtual-processor-team-4/blob/main/documents/functional/appendix_a_instruction_set_manual.pdf) an₫ [processor architecture](https://github.com/algosup/2023-2024-project-3-virtual-processor-team-4/blob/main/documents/functional/functional_specification.md#system-architecture) are available in the [functional folder](https://github.com/algosup/2023-2024-project-3-virtual-processor-team-4/tree/main/documents/functional) of the GitHub repository).

Open a terminal, and place you in the folder 'src'
```cd "C:/Users/.../src"```

Compile assembler.c :
```gcc assembler.c -o assembler```

Compile emulator.c :
```gcc emulator.c -o emulator```

Run the assembler with your assembly file:
```assembler.exe path_to_your_file.asm ```	Here the .bin file will be created in the same folder as the .asm file.
OR
```assembler.exe path_to_your_file.asm path_to_your_destination_folder ```	Here the .bin file will be created in the destination folder.

Run the emulator with the generated machine code file:
```emulator.exe path_to_your_file.bin```
However, as there is no way to see print in the terminal with the assembly code, you can use the following command to see the content of the registers at the end of the execution:
```emulator.exe -d path_to_your_file.bin``` //execute the machine code and then print the registers through the 'debug' option.

### Linux

Adapt the command to place you in the right folder and then,
adapt the code above replacing '.exe' extensions with '.o' extension 

### MacOS

Adapt the command to place you in the right folder and then,
adapt the code above replacing xxx.exe with ./xxx to execute the executable

<hr>

# Related documents

- [Functional specifications](https://github.com/algosup/2023-2024-project-3-virtual-processor-team-4/blob/main/documents/functional/functional_specification.md)
- [Technical specifications](https://github.com/algosup/2023-2024-project-3-virtual-processor-team-4/blob/main/documents/technical/technical_specification.md)
- [Test Plan](https://github.com/algosup/2023-2024-project-3-virtual-processor-team-4/blob/main/documents/QA/test_plan.md)
- [KPIs](https://algosup-my.sharepoint.com/:x:/p/benoit_dekeyn/ET3X56ZmAw1PpLeTLcSubvIBwjEooiU8LSl_ZvGzSR8ylA?e=STmP8k)
- [Management artifacts](https://github.com/algosup/2023-2024-project-3-virtual-processor-team-4/blob/main/documents/management/management_artifacts.md)
- [Weekly Report](https://github.com/algosup/2023-2024-project-3-virtual-processor-team-4/blob/main/documents/management/weekly_report/cumulative.md)

<hr>

# Dates

- We started the project on Wednesday, January 17th, 2024

- The deadline for the project is Friday, February 23rd

- Date of the last official update of the project: 23/02/2024

<hr>

# License

This project is under the [MIT License](LICENSE).

<hr>
<img src="documents/.data/pictures/algosup_logo.png" width="750px">

