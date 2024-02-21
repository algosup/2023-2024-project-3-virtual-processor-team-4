#include "./libs/utils.h"
//#include "./libs/clock.h"
#include "./libs/v_components.h"
#include "./libs/v_instructions.h"
#include "./libs/interpreter.h" //commented while interpreter is not blocking compilation

//Prototypes
void test_arithmetic_operations();
void test_memory(void);
void test_Op_I();
void test_store_load_set();
void test_logic_op_immediate();



int main()
{
    test_arithmetic_operations();
    test_memory();
    test_Op_I();
    test_store_load_set();
    test_logic_op_immediate();
    return 0;
}


//TESTS

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
        puts("Arithmetic operations test success");
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

void test_logic_op_immediate_1()
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