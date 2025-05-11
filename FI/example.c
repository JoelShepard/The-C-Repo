#include <stdio.h>

int distingui(char s[], char up[], char low[]) {
    if (*s == '\0') {
        return 0; // Caso base: stringa vuota
    }

    char c = *s;
    if (c >= 'A' && c <= 'Z') { // Carattere maiuscolo
        *up = c;
        return distingui(s + 1, up + 1, low);
    } else if (c >= 'a' && c <= 'z') { // Carattere minuscolo
        *low = c;
        return distingui(s + 1, up, low + 1);
    } else { // Carattere non alfabetico
        return 1 + distingui(s + 1, up, low);
    }
}

int main(){

    char s[] = "2Ew?jm7y9TR£";
    char low[5], up[5];

    distingui(s, up, low);

    for (int i=0; i<5; i++) {
        printf("%c ", up[i]);
    }
    for (int i=0; i<5; i++) {
        printf("%c ", low[i]);
    }
}
