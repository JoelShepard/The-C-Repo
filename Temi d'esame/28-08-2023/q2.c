#include <stdio.h>

int strcmpRec(char s1[], char s2[]){
    if (*s1 == '\0' || *s1 == '\0') {
        return 0;
    }
    if (*s1 > *s2) {
        return 1+strcmpRec(s1+1, s2+1);
    }
    if (*s1 < *s2) {
        return -1+strcmpRec(s1+1, s2+1);
    }
    else {
        return 0+strcmpRec(s1+1, s2+1);
    }
}

int main(){
    char a[]= "gioele";
    char b[]="casa";

    int ris = strcmpRec(a, b);
    printf("%d", ris);
}

//First Try !!!
