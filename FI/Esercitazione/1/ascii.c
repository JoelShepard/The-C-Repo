#include <stdio.h>

char letter = 'z';

int main(){
    printf("%c\n", letter);
    printf("%u\n", letter); // equivalent number

    letter = letter - ('a'-'A');
    printf("capital letter: %c\n", letter);
}