#include <stdio.h>
#include <string.h>

void modify(char** str);

int main(){
    char *s= "Io sono bello e ";
    modify(&s);
}

void modify(char** str){
    strcat(*str, "Ciaooo");
}
