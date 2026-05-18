// q3.c - Distingui caratteri

#include <stdio.h>

int distingui(char s[], char up[], char low[]){
    int count = 0;
    
    if (*s == '\0'){
        return 0;
    }

    if (*s >= 'a' && *s <= 'z'){
        *low = *s;
        count += distingui(s+1, up, low+1);
        return count;
    }
    
    if (*s >= 'A' && *s <= 'Z') {
        *up = *s;
        count += distingui(s+1, up+1, low);
        return count;
    }
    
    else {
        count = distingui(s+1, up, low) + 1;
        return count;
    }
}

int main(){
    char s[] = "C4i1a5o?";
    char up[6];
    char low[6];

    printf("Caratteri non alfabetici: %d\n", distingui(s, up, low));
    
    return 0;
}
