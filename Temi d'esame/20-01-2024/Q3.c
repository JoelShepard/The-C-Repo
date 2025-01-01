#include <stdio.h>

char min_ch(char s[]) {
  if (s[0] == '\0') { // Caso base: stringa vuota
    return '\0';
  } else if (s[1] == '\0') { // Caso base: stringa di lunghezza 1
    return s[0];
  } else {
    // Caso ricorsivo: confronta il primo carattere con il minimo del resto della stringa
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
