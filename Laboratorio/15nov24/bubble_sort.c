#include <stdio.h>
#define N 3

int main(){
    int myarray1[N]={0}, myarray2[N]={0}, myarrayx2[2*N]={0}, i=0, k=0, tmp=0, j=0, swap1=0, swap2=0, iter1=0, iter2=0;

    //input
    printf("Inserisci i valori nel primo array:\n");
    for (i=0; i<N; i++) {
        scanf("%d", &myarray1[i]);
    }
    printf("Inserisci i valori nel secondo array:\n");
    for (i=0; i<N; i++) {
        scanf("%d", &myarray2[i]);
    }

    //bubble sort implementation
    for (j=0; j<N-1; j++) {
        for (i=0; i<N; i++) {
            iter1+=2;
            if(i+1 == N){continue;}
            if (myarray1[i] > myarray1[i+1]) {
                tmp=myarray1[i];
                myarray1[i]=myarray1[i+1];
                myarray1[i+1]=tmp;

                swap1+=1;
            }
        }
    }
    for (j=0; j<N-1; j++) {
        for (i=0; i<N; i++) {
            iter2+=1;
            if(i+1 == N){continue;}
            if (myarray2[i] > myarray2[i+1]) {
                tmp=myarray2[i];
                myarray2[i]=myarray2[i+1];
                myarray2[i+1]=tmp;

                swap2+=1;
            }
        }
    }

    //new array
    i = 0;
    j = 0;
    k = 0;
    while (i < N && j < N) {
        if (myarray1[i] <= myarray2[j]) {
            myarrayx2[k] = myarray1[i];
            i++;
        } else {
            myarrayx2[k] = myarray2[j];
            j++;
        }
        k++;
    }
    while (i < N) {
        myarrayx2[k] = myarray1[i];
        i++;
        k++;
    }
    while (j < N) {
        myarrayx2[k] = myarray2[j];
        j++;
        k++;
    }

    //stamp
    printf("Array 1 ordinato è:\n ");
    for (i=0; i<N; i++) {
        printf("%d ", myarray1[i]);
    }
    printf("\n");
    printf("Array 2 ordinato è:\n ");
    for (i=0; i<N; i++) {
        printf("%d ", myarray2[i]);
    }
    printf("\n");
    printf("La loro unione ordinata è:\n ");
    for (i=0; i<2*N; i++) {
        printf("%d ", myarrayx2[i]);
    }
    printf("\n");

    printf("Numero di swap effettuati\n - per ordinare Array 1: %d\n - per ordinare Array 2: %d\n", swap1, swap2);
    printf("Numero di controlli effettuati\n - per Array 1: %d\n - per Array 2: %d\n", iter1, iter2);
}
