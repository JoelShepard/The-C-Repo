/* Q3.c - C source file. */
#include <stdio.h>

char min_ch(char s[]) {
  if (s[0] == '\0') {
    return '\0';
  } else if (s[1] == '\0') {
    return s[0];
  } else {
    // Case ricorsivo: confronta il primo character con il minimo del resto della string
    char minimo = s[0];
    char resto_minimo = min_ch(s + 1);
    if (resto_minimo < minimo) {
      minimo = resto_minimo;
    }
    return minimo;
  }
}

int main() {
  char s[] = "gioele";
  char minimo = min_ch(s);
  printf("Il carattere minimo nella stringa \"%s\" è '%c'\n", s, minimo);
  return 0;
}
