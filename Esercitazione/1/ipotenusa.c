#include <stdio.h>
#include <math.h>

int main(){
    //vars
    double c1=0.0,c2=0.0,i=0.0;
    // input
    printf("primo cateto: ");
    scanf("%lf\n", &c1);

    printf("secondo cateto: ");
    scanf("%lf", &c2);

    //compute
    i = sqrt(c1*c1+c2*c2);

    printf("%lf", i);
    return 0;
}