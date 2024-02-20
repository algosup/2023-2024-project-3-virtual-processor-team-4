#include "./libs/utils.h"
#include "./libs/clock.h"
//#include "./libs/interpreter.h" //commented while interpreter is not blocking compilation
#include "./libs/v_processor.h"

//Prototypes
void testADD();


int main()
{
    testADD();
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
