#include <stdio.h>

int main() {

    int a, b, c, d, e, f;
    float media;

    printf("Scegli valori interi positivi: ");
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);
    scanf("%d", &e);
    scanf("%d", &f);


    if(a <= 0 || b <= 0 || c <= 0 || d <= 0 || e <= 0 || f <= 0) {
        printf("\nI valori inseriti devono essere degli interi positivi\n");
        return 0;
        }

    media = (a + b + c + d + e + f) / 6.0f;
    printf("\nla media è:%f\n", media);

}

// da finire massimo e minimo