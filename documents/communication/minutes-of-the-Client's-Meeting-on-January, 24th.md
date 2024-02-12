# Meeting minutes: Client, January 24th

The idea of a virtual processor is to allocate pieces of memory for each virtual component and interpret code using them as a real computer would do.

First, we have to invent our own assembly. x86 is one of the worst out there, we should go for something closer to ARM/PowerPC/MIPS/68000/RISC-V...
We should keep it as simple as possible, with the minimum number of instructions which is sufficient to do "useful things" since we will have to test it. We should go for a RISK architecture for sure.

Our program should first turn assembly (aka text) to machine code, then emulate this machine code. If it is too ambitious, we may directly interpret the assembly code.

We must stay close to reality in terms of how much time each instruction will take. For the client, the beauty of assembly is to be able to see how much time the program will take to run due to the regularity of how much time takes a clock cycle for each instruction. That being said, the program should still be fast. From this, we understood we should make benchmarking to check the execution times. 

We can assume that the host machine for our program is 64 bits, but the program needs to stay portable among the different OS (Linux, MacOS and Windows mainly). 32 bits is a good trade-off according to the client.

We have to choose which field of application we would choose to make our ASM (IOT, real-time app, embedded systems, ...).

8-bit doesn't make a lot of sense, 16-bit is quite limiting, and we can't really compete with 64-bit architectures.

We mustn't copy existing architectures, we have to create something new. (for instance, 'mov' doesn't really move and as such is a bad mnemonic).

We may use any version of C. (The client mentioned Zig's C cross-compiler)

The virtual terminal is just the fact that we can see the program printing text and getting inputs (using memory location read by the emulator, not with an instruction). It does not have to be another window created by the emulator and can simply be a regular terminal.

We must be mindful of the tradeoff between the size of the opcodes and the arguments (size of immediate values, labels, ...)

For the identifier of the opcode, 5 bits seems to be a good idea. We could, for instance, use the first bits to identify the category of instructions: 1 category could take only 1 or 2 other bits to define precisely which instruction it is. Overall, the opcodes could have variable lengths.

Having a 1:1 mapping between assembly instructions and machine code opcodes would be ideal.

We have to stay consistent in the order of source/destination for the instructions.

The assembly language should be convenient, while still being optimized. The 'cmpeq' and 'cmpge' instructions are not usual and should be dropped.

Documentation of the instructions should follow the usual pattern.

The 'call' instruction may be removed in favor of more general-purpose instructions for stack manipulation (call = push stack pointer + increment stack pointer + jump) if deemed useful.

We won't use macros. An instruction shouldn't be a result of a kind of assembly function in an assembly library.

We should really test our assembly language with a lot of programs to try the convenience and the optimization of our new assembly language to make it easy, and consistent.