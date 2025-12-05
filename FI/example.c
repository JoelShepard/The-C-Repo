#include <stdio.h>

/* Separates uppercase and lowercase letters from string. Returns count of non-alphabetic chars. */
int distingui(char s[], char up[], char low[]) {
    if (*s == '\0') {
        return 0;
    }

    char c = *s;

    if (c >= 'A' && c <= 'Z') {
        *up = c;
        return distingui(s + 1, up + 1, low);
    } else if (c >= 'a' && c <= 'z') {
        *low = c;
        return distingui(s + 1, up, low + 1);
    } else {
        return 1 + distingui(s + 1, up, low);
    }
}

int main(void) {
    char s[] = "2Ew?jm7y9TR£";
    char low[5], up[5];

    distingui(s, up, low);

    for (int i = 0; i < 5; i++)
        printf("%c ", up[i]);

    for (int i = 0; i < 5; i++)
        printf("%c ", low[i]);

    return 0;
}
