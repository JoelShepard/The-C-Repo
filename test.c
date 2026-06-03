#include <stdio.h>
int main(void) {
    char foo[] = "iuuqt;00u/nf0,UZtDhE:KLgZ2OU[l";
    for (int j = 0; j < 30; j++) foo[j]--;
    printf("%s\n", foo);
}
