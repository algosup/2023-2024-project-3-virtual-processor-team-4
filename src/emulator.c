#include "./libs/utils.h"
#include "./libs/clock.h"
//#include "./libs/interpreter.h" //commented while interpreter is not blocking compilation
#include "./libs/v_processor.h"

//Prototypes
void testADD();
void test_memory(void);


int main()
{
    testADD();
    test_memory();
    return 0;
}


//exemple
void testADD(){
    //add 5 and 3, print 8

    registerArr[0] = 5;
    registerArr[1] = 3;

    binInstruction_t testADD;
    testADD.typeR.source2 = 0;
    testADD.typeR.source = 1;
    testADD.typeR.destination = 2;

    add(testADD);

    printf("%d\n", registerArr[2]);
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
