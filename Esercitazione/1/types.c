#include <stdio.h>
#include <inttypes.h>

// global variables
int var=-154; // code type is C2
unsigned var2=5; // positive integer variable, flag is %u
// global vars occupies a piece of memory and it's r/w by every functions
// max limit of memory for variables = 4 bytes
// initialize vars is always good
// the dimension of the int type depends on the platform used

int8_t two_comp = 127; //equivalent to c2 [-128, 127]
uint8_t pos_int = 42; // equivalent to unsigned [0, 256]
//8_t means 1 byte

int32_t thirtytwo_bit= 355;

int main(){
    int var3; //local variables
    // the value of non declared variables depends on the assigned sector of memory
    printf("var: %d\n", var);
    printf("var2: %u\n", var2);
    printf("var hex: %04X\n", var); // var in hex code

    printf("%d\n", two_comp);
    two_comp = two_comp +1;
    // two_comp +=1; equivalent
    // two_comp++; equivalent
    printf("%d/n", two_comp); //overflow

    // bash:"man ascii", ascii table
    // ascii has 7bits but C compiler adds 1bit to reach 8bits
    // unicode better than ascii cause it's ascii + other

}