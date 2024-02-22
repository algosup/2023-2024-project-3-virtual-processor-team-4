#include "./libs/utils.h"
//#include "./libs/clock.h"
#include "./libs/v_components.h"
#include "./libs/v_instructions.h"
#include "./libs/interpreter.h" //commented while interpreter is not blocking compilation


//Prototypes
void test_arithmetic_operations();
void test_logical_operations();
void test_instr_abs();
void test_logical_comaparisons();
void test_memory(void);
void test_stack(void);
void test_arithmetic_operations();
void test_Op_I();
void test_store_load_set();
void test_logic_op_immediate();
int test_load_bin();
void test_machinecode_to_bininstruction();
void execute_tests();



int main()
{   
    execute_tests();
    print_register(5, BIN);
    print_registers(HEX);
    print_memory(10, 50, BIN);

    return 0;
}



//TESTS

void execute_tests(){
    test_arithmetic_operations();
    test_logical_operations();
    test_instr_abs();
    test_logical_comaparisons();
    test_memory();
    test_stack();
    test_Op_I();
    test_store_load_set();
    test_logic_op_immediate();
    test_load_bin();
    test_machinecode_to_bininstruction();
}

void test_arithmetic_operations(){
    registerArr[0] = 5;
    registerArr[1] = 3;
    registerArr[4] = 10;

    //add 5 and 3, print 8

    binInstruction_t testADD;
    testADD.typeR.source2 = 0;
    testADD.typeR.source = 1;
    testADD.typeR.destination = 2;

    instr_add(testADD);

    //sub 8 and 5, print 3

    binInstruction_t testSUB;
    testSUB.typeR.source2 = 0;
    testSUB.typeR.source = 2;
    testSUB.typeR.destination = 3;

    instr_sub(testSUB);

    // mul 3 and 10, print 30

    binInstruction_t testMUL;
    testMUL.typeR.source2 = 3;
    testMUL.typeR.source = 4;
    testMUL.typeR.destination = 5;

    instr_mul(testMUL);

    // div 30 and 10, print 3

    binInstruction_t testDIV;
    testDIV.typeR.source2 = 4;
    testDIV.typeR.source = 5;
    testDIV.typeR.destination = 6;

    instr_div(testDIV);

    if (registerArr[6] != 3)
    {
        printf("Arithmetic operations test failed: Expected 3, got %d\n", registerArr[6]);
        return;
    }
    else
    {
        puts("Arithmetic operations test succeed");
    }
}

void test_logical_operations(){
    registerArr[0] = 2;
    registerArr[1] = 3;
    registerArr[2] = 15;
    registerArr[3] = 2;

    // or 2 and 3, get 3

    binInstruction_t testOR;
    testOR.typeR.source = 0;
    testOR.typeR.source2 = 1;
    testOR.typeR.destination = 4;

    // and 3 and 15, get 3

    binInstruction_t testAND;
    testAND.typeR.source = 4;
    testAND.typeR.source2 = 2;
    testAND.typeR.destination = 5;

    // xor 3 and 2, get 1

    binInstruction_t testXOR;
    testXOR.typeR.source = 5;
    testXOR.typeR.source2 = 3;
    testXOR.typeR.destination = 6;

    instr_or(testOR);
    instr_and(testAND);
    instr_xor(testXOR);

    if (registerArr[6] != 1){
        printf("Logical operations test failed: Expected 1, got %d\n", registerArr[6]);
        return;
    }else{
        puts("Logical operations test succeed");
    }
}

void test_instr_abs(){
    registerArr[0] = -1;

    // abs -1, get 1

    binInstruction_t testABS;
    testABS.typeR.source = 0;
    testABS.typeR.destination = 1;

    instr_abs(testABS);

    if (registerArr[1] != 1){
        printf("Absolute instruction test failed: Expected 1, got %d\n", registerArr[1]);
        return;
    }else{
        puts("Absolute instruction test succeed");
    }
}

// in progress
void test_logical_comaparisons(){
    registerArr[0] = 40;
    registerArr[1] = 20;
    registerArr[2] = 20;

    // test 20 < 40, get 1

    binInstruction_t testTLT;
    testTLT.typeR.source = 1;
    testTLT.typeR.source2 = 0;
    testTLT.typeR.destination = 3;

    // test 20 <= 20, get 1

    binInstruction_t testTLE;
    testTLE.typeR.source = 1;
    testTLE.typeR.source = 2;
    testTLE.typeR.destination = 4;

    // test 40 > 20, get 1

    binInstruction_t testTGT;
    testTGT.typeR.source = 0;
    testTGT.typeR.source2 = 1;
    testTGT.typeR.destination = 5;

    // test 1 >= 1, get 1

    binInstruction_t testTGE;
    testTGE.typeR.source = 3;
    testTGE.typeR.source2 = 4;
    testTGE.typeR.destination = 6;

    // test 1 == 1; get 1

    binInstruction_t testTEQ;
    testTEQ.typeR.source = 5;
    testTEQ.typeR.source2 = 6;
    testTEQ.typeR.destination = 7;

    // test 1 != 40, get 1

    binInstruction_t testTNE;
    testTNE.typeR.source = 7;
    testTNE.typeR.source2 = 0;
    testTEQ.typeR.destination = 8;

    instr_tlt(testTLT);
    instr_tle(testTLE);
    instr_tgt(testTGT);
    instr_tge(testTGE);
    instr_teq(testTEQ);
    instr_tne(testTNE);

    if (registerArr[8] != 1){
        printf("Tesing logical comparison test failed: Expected 1, got %d\n", registerArr[8]);
        return;
    }else{
        puts("Testing logical comparison test succeed");
    }
}

void test_memory(void)
{
    uint32_t address = 0x01234567;
    uint32_t expected = 0x89abcdef;

    // Initialize
    init_memory();

    // Write a value in memory
    set_memory_32(address, expected);

    // Clear the pages
    load_page_memory(0);
    load_page_memory(1);
    load_page_memory(2);
    load_page_memory(3);

    // Read the value back
    uint32_t actual = read_memory_32(address);

    if (actual != expected)
    {
        printf("Memory test failed: Expected %08x, got %08x\n", expected, actual);
    }
    else
    {
        puts("Memory test success");
    }
}

void test_stack(void)
{
    init_memory();

    uint32_t value1 = 5, value2 = 7, value3 = 13;
    uint8_t source1 = 0, source2 = 1, source3 = 2;
    uint8_t destination1 = 10, destination2 = 11, destination3 = 12;

    registerArr[source1] = value1;
    registerArr[source2] = value2;
    registerArr[source3] = value3;

    binInstruction_t push1 = {.typeR = {.source = source1}};
    instr_push(push1);
    binInstruction_t push2 = {.typeR = {.source = source2}};
    instr_push(push2);
    binInstruction_t pop2 = {.typeR = {.destination = destination2}};
    instr_pop(pop2);
    binInstruction_t push3 = {.typeR = {.source = source3}};
    instr_push(push3);
    binInstruction_t pop3 = {.typeR = {.destination = destination3}};
    instr_pop(pop3);
    binInstruction_t pop1 = {.typeR = {.destination = destination1}};
    instr_pop(pop1);

    if (
        registerArr[destination1] != value1 ||
        registerArr[destination2] != value2 ||
        registerArr[destination3] != value3
    )
    {
        printf(
            "Stack test failed:\nExpected (%d, %d, %d), got (%d, %d, %d)\n",
            value1, value2, value3,
            registerArr[destination1], registerArr[destination2], registerArr[destination3]
        );
    }
    else
    {
        puts("Stack test success");
    }
}

void test_Op_I(){

    registerArr[0] = 5;

    binInstruction_t testOpI;
    testOpI.typeI.source = 0;
    testOpI.typeI.immediate = 3;
    testOpI.typeI.destination = 2;

    // test the addi instruction, add the immediate 3 to a 5 in a register
    instr_addi(testOpI);
    printf("expected result: '8', got: %d \n", registerArr[2]);

    // test the subi instruction, substact the immediate 3 to a 5 in a register
    instr_subi(testOpI);
    printf("expected result: '2', got: %d \n", registerArr[2]);
}


void test_store_load_set()
{
    registerArr[0] = 3;

    binInstruction_t testSls;
    testSls.typeI.source = 0;
    testSls.typeI.immediate = 6;
    testSls.typeI.destination = 1;

    // test the stri instruction, store a 6 in a register
    instr_stri(testSls);
    printf("expected result: '6', got: %d \n", registerArr[1]);

    // test the ldi instruction, load a 6 from a register
    instr_ldi(testSls);
    printf("expected result: '6', got: %d \n", registerArr[1]);

    // test the set instruction, change the set the value of a register to 6
    instr_set(testSls);
    printf("expected result: '6', got: %d \n", registerArr[0]);
}

void test_logic_op_immediate()
{
    registerArr[0] = 5;
    registerArr[2] = 5;
    
    binInstruction_t testLogicI;
    testLogicI.typeI.source = 0;
    testLogicI.typeI.immediate = 7;
    testLogicI.typeI.destination = 1;

    instr_ori(testLogicI);
    printf("expected '1', got %d \n", registerArr[1]);

    instr_andi(testLogicI);
    printf("expected'0', got %d \n", registerArr[1]);

    instr_xori(testLogicI);
    printf("expected result: '1', got %d \n", registerArr[1]);
}

int test_load_bin(){
    FILE *file = fopen("./test.bin", "wb");
    if (file == NULL) {
        perror("Error opening file\n");
        return GENERIC_ERROR;
    }
    uint8_t array[8] = {8, 11, 13, 14, 2, 31, 4, 5};
    int size = 8;
    size_t written = fwrite(array, sizeof(uint8_t), size, file);
    fclose(file);

    init_memory();
    load_bin_to_mem("./test.bin");
    load_page_memory(1);
    load_page_memory(2);
    load_page_memory(3);
    load_page_memory(4);

    FILE *fileMem = fopen("./test.bin", "rb");
    if (fileMem == NULL) {
        perror("Error opening file\n");
        return GENERIC_ERROR;
    }

    uint8_t outputArray[8]; 
    fread(outputArray, 1, 8, fileMem);
    fclose(fileMem);

    bool error = false;
    for (int i = 0; i < 8; i++)
    {
        if(outputArray[i] != array[i]){
            error = true;
            printf("test_load_bin: expected result %d, got %d\n", outputArray[i], array[i]);
        }
    }
    
    if(!error){
        printf("test_load_bin: succesful\n");
    }else{
        printf("test_load_bin: failed\n");
    }
}

void test_machinecode_to_bininstruction(){
    bool error;

    uint8_t setRb[4] = {0b01011100, 0b00000000, 0b00000000, 0b00100001};
    binInstruction_t instr0;
    machinecode_to_bininstruction(setRb, &instr0);

    if(instr0.type != I){
        error = true;
        printf("test_machinecode_to_bininstruction 0: type expected %d but got %d\n", I, instr0.type);
    }else{
        if(instr0.typeI.destination != 1){
            error = true;
            printf("test_machinecode_to_bininstruction 0: destination expected %d but got %d\n", 1, instr0.typeI.destination);
        }
        if(instr0.typeI.immediate != 0){
            error = true;
            printf("test_machinecode_to_bininstruction 0: immediate expected %d but got %d\n", 0, instr0.typeI.immediate);
        }
        if(instr0.typeI.source != 1){
            error = true;
            printf("test_machinecode_to_bininstruction 0: source expected %d but got %d\n", 1, instr0.typeI.source);
        }
        if(instr0.typeI.opcode != SET){
            error = true;
            printf("test_machinecode_to_bininstruction 0: opcode expected %d but got %d\n", SET, instr0.typeI.opcode);
        }
    }
    

    uint8_t divZero[4] = {0b00000110, 0b00000000, 0b00000100, 0b00100001};
    binInstruction_t instr1;
    machinecode_to_bininstruction(divZero, &instr1);

    if(instr1.type != R){
        error = true;
        printf("test_machinecode_to_bininstruction 1: type expected %d but got %d\n", R, instr1.type);
    }else{
        if(instr1.typeR.destination != 1){
            error = true;
            printf("test_machinecode_to_bininstruction 1: destination expected %d but got %d\n", 1, instr1.typeR.destination);
        }
        if(instr1.typeR.source2 != 1){
            error = true;
            printf("test_machinecode_to_bininstruction 1: source2 expected %d but got %d\n", 1, instr1.typeR.source2);
        }
        if(instr1.typeR.source != 1){
            error = true;
            printf("test_machinecode_to_bininstruction 1: source expected %d but got %d\n", 1, instr1.typeR.source);
        }
        if(instr1.typeR.opcode != DIV){
            error = true;
            printf("test_machinecode_to_bininstruction 1: opcode expected %d but got %d\n", DIV, instr1.typeR.opcode);
        }
    }

    if(!error){
        printf("test_machinecode_to_bininstruction: succesful\n");
    }else{
        printf("test_machinecode_to_bininstruction: failed\n");
    }
}