#include <stdio.h>
#include <stdlib.h>

typedef struct ls {
    int firstindex;
    int lastindex;
    struct ls* next;
} Node;

Node* create() {
    Node* tmp = malloc(sizeof(Node));
    if (tmp == NULL) {
        return NULL;
    }
    tmp->next = NULL;
    return tmp;
}

Node* ArrayPartToList(int my[], int n, int sum) {
    if (n <= 0) {
        return NULL;
    }

    Node* list = NULL;
    Node* prev = NULL;
    Node* current = NULL;

    for (int i = 0; i < n; i++) {
        if (i < n-1) {  // Check pairs
            int j = i + 1;
            int tmpsum = my[i] + my[j];
            
            current = create();
            if (current == NULL) {
                // Gestione errore di allocazione
                // TODO: liberare la lista precedente
                return NULL;
            }

            if (tmpsum == sum) {
                current->firstindex = i;
                current->lastindex = j;
            } else if (tmpsum > sum) {
                current->firstindex = i;
                current->lastindex = i;
            } else {  // tmpsum < sum
                current->firstindex = i;
                current->lastindex = i;
            }

            if (list == NULL) {
                list = current;
            } else {
                prev->next = current;
            }
            prev = current;
        } else {  // Handle last element
            current = create();
            if (current == NULL) {
                // Gestione errore di allocazione
                // TODO: liberare la lista precedente
                return NULL;
            }
            current->firstindex = i;
            current->lastindex = i;
            
            if (list == NULL) {
                list = current;
            } else {
                prev->next = current;
            }
        }
    }

    return list;
}

int main(){
    int my[]={1, 5, 8, 10, 2};
    int sum = 10;

    Node* result = ArrayPartToList(my, 5, sum);
    printf("%d", result->next->lastindex);
}
