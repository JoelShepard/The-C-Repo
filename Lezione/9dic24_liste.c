#include<stdlib.h>


typedef struct EL {
    int data;
    struct EL* next;
} ElemList;

typedef ElemList* List;

List int_list();
int list_void_check(List l);
int list_dim(List l);

List int_list(){
    return NULL;
}

int list_void_check(List l){
	if (l == NULL) return 1;
    return 0;
}

int list_dim(List l){
    int count=0;
    while ((*l).next != NULL){
		l=(*l).next;
        count++;
    }
    return count;
}

int main(){
    List L;
    l = int_list();
}


