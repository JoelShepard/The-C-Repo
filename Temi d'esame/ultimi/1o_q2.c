#include <stdio.h>

int itsfollowed(int a[], int x, int y, int dim, int flag){

    for (int i=0; i<dim; i++) {
        if(a[i]==x){
            flag=1;
        }
    }

    if (!flag){
        return -1;
    }

    if (dim == 0) {
        return 0;
    }

    if (*a == x && *(a+1)==y) {
        return 1+itsfollowed(a+1, x, y, dim-1, flag);
    } else {
        return 0+itsfollowed(a+1, x, y, dim-1, flag);
    }
}

int main(){
    int a[]={2,3,4,5,2,3,4,6,2,3};
    int dim = 10;

    printf("%d\n", itsfollowed(a, 7, 5, dim, 0));
}
