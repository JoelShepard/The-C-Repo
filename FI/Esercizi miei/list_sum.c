// list_sum.c - Manipolazione liste concatenate

#include <stdlib.h>
#include <stdio.h>

typedef struct nd{
    int val;
    struct nd* next;
}Node;

typedef Node* List;

void sumbytwo(List my){
    List prev = my;
    List curr = my->next;
    int tmp=0;
    
    while (curr->next!=NULL) {
        if (prev != my) {
            curr->val+=prev->val;
        }
        curr = curr->next;
        prev = prev->next;
    }
}

int main(){
    List head = malloc(sizeof(Node));
    head->val = 0;

    List curr = head;
    for(int i = 1; i <= 4; i++) {
        curr->next = malloc(sizeof(Node));
        curr->next->val = i;
        curr->next->next = NULL;
        curr = curr->next;
    }

    printf("Original list: ");
    curr = head;
    while(curr != NULL) {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");

    sumbytwo(head);

    printf("Modified list: ");
    curr = head;
    while(curr != NULL) {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");

    curr = head;
    while(curr != NULL) {
        List tmp = curr;
        curr = curr->next;
        free(tmp);
    }

    return 0;
}
