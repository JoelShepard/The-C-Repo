// ipotenusa.c - Calcolo ipotenusa triangolo rettangolo

#include <stdio.h>
#include <math.h>

int main(){
    double c1=0.0, c2=0.0, i=0.0;
    
    printf("primo cateto: ");
    scanf("%lf\n", &c1);

    printf("secondo cateto: ");
    scanf("%lf", &c2);

    i = sqrt(c1*c1+c2*c2);

    printf("%lf", i);
    
    return 0;
}
