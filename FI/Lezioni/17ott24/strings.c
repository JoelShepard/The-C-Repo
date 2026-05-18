// strings.c - Operazioni su stringhe e array 2D

#include <stdio.h>
#include <string.h>

#define DIM 15

int main(){
    char str1[]="Hello World";
    char str2[DIM];
    
    // fgets dopo scanf lascia \n nel buffer
    fgets(str2, DIM, stdin);
    printf("%s", str2);
    
    printf("%s", strncpy(str2, str1, 6));

    int a[20][30];
    
    a[14][23] = 1231231;
    a[0][0] = 12082005;
    
    printf("%d %d", a[0][0], a[14][23]);
}

// Le stringhe in C sono array di char con terminatore '\0'
