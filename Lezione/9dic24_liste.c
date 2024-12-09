#include<stdlib.h>


typedef struct EL {
    int data;
    struct EL* next;
} ElemList;

typedef ElemList* List;

List int_list();
int list_void_check(List l);
int list_dim(List l);
int rec_list_dim(Lit l);
void print_list(List l);

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

int rec_list_dim(List l){
    if (L == NULL){
        return 0;
    }
    return 1 + rec_list_dim((*l).next);
}

void print_list(List l){
    if (l==NULL) printf("-|");
    printf("%d->", (*l).data);
    print_list((*l).next);
}

int main(){
    List L;
    l = int_list();
}


