#include <stdio.h>

void order(int a[], int b[], int size_a, int size_b, int c[]) {
    if (size_a == 0 && size_b == 0) {
        return;
    }

    if (size_a == 0) {
        *c = *b;
        order(a, b+1, size_a, size_b-1, c+1);
        return;
    }

    if (size_b == 0) {
        *c = *a;
        order(a+1, b, size_a-1, size_b, c+1);
        return;
    }

    if (*a < *b) {
        *c = *a;
        order(a+1, b, size_a-1, size_b, c+1);
    } else {
        *c = *b;
        order(a, b+1, size_a, size_b-1, c+1);
    }
}

int main(){
    int a[]={1,2};
    int b[]={3,5,9,11,14};
    int c[7]={0};

    order(a, b, 2, 5, c);
    for (int i=0; i<7; i++) {
        printf("%d ", c[i]);
    }
}
