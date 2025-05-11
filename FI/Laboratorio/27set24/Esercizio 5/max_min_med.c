#include <stdio.h>

int main() {

    int a, b, c, d, e, f, max, tmp, tmp2=0, min;
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

    tmp = a+b+c+d+e+f;

    while (tmp >= a && tmp >= b && tmp >= c && tmp >= d && tmp >= e && tmp >= f) {
        if (tmp == a || tmp == b || tmp == c || tmp == d || tmp == e || tmp == f) {
            max = tmp;
            }
        tmp--;
    }
    printf("il massimo è:%d\n", max);

    while (tmp2 <= a && tmp2 <= b && tmp2 <= c && tmp2 <= d && tmp2 <= e && tmp2 <= f) {
        if (tmp2 == a || tmp2 == b || tmp2 == c || tmp2 == d || tmp2 == e || tmp2 == f) {
            min = tmp2;
            }
        tmp2++;
    }
    printf("il minimo è:%d\n", min);
}