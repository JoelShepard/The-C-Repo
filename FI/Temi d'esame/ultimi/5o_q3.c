// 5o_q3.c - Carattere minimo ricorsivo

#include <stdio.h>
#include <strings.h>

char min_ch(char s[]){
    if (s[0] == '\0') {
        return '\0';
    }

    if (s[1] == '\0') {
        return s[0];
    }

    char min_resto = min_ch(s + 1);

    if (min_resto == '\0') {
        return s[0];
    }

    if (s[0] < min_resto) {
        return s[0];
    } else {
        return min_resto;
    }
}

int main(){
    char mystr[]="boh";
    
    char risultato = min_ch(mystr);
    printf("Carattere minimo in \"%s\": %c\n", mystr, risultato);
    
    return 0;
}
