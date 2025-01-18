#include <stdio.h>
#include <strings.h>

char min_ch(char s[]){
    // Caso base: stringa vuota
    if (s[0] == '\0') {
        return '\0';
    }

    // Caso base: stringa di un carattere
    if (s[1] == '\0') {
        return s[0];
    }

    // Caso ricorsivo
    char min_resto = min_ch(s + 1);

    // Se il resto della stringa era vuoto, ritorna il carattere corrente
    if (min_resto == '\0') {
        return s[0];
    }

    // Ritorna il minimo tra il carattere corrente e il minimo del resto
    if (s[0] < min_resto) {
        return s[0];
    } else {
        return min_resto;
    }
}

int main(){
    char mystr[]="boh";
    printf("%c\n", min_ch(mystr));
}
