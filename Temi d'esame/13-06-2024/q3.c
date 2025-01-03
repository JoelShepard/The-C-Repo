// C'ero quasi. Allenati di più sul ragionamento ricorsivo. La return deve passare il tipo della funzione. le chiamate ricorsive falle su una variabile fuori dalla return per non confonderti.
#include <stdio.h>

int distingui(char s[], char up[], char low[]){
    int count=0;
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
    char s[]="C4i1a5o?", up[6], low[6];

    printf("%d", distingui(s, up, low));
}
