// types.c - Dimostrazione tipi di dati e overflow

#include <stdio.h>
#include <inttypes.h>

int var=-154;
unsigned var2=5;

int8_t two_comp = 127;
uint8_t pos_int = 42;

int32_t thirtytwo_bit= 355;

int main(){
    int var3;
    
    printf("var: %d\n", var);
    printf("var2: %u\n", var2);
    printf("var hex: %04X\n", var);

    printf("%d\n", two_comp);
    two_comp = two_comp +1;
    printf("%d/n", two_comp);           // Overflow: 127 -> -128
}
