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
void print_list_reverse(List l);
int elem_data_check(List l, int val);

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
    while(l!=NULL){
		printf("%d->", (*l).data);
		print_list((*l).next);
    }
}

void print_list_reverse(List l){
    if (l==NULL) printf("|-");
	while(l!=NULL){
		print_list((*l).next);
    	printf("%d->", (*l).data);
    }
}

int elem_data_check(List l, int val){
    ElemList* cur = l;
    while(cur!=NULL && (*cur).data != val){
		cur = (*cur).next;
    }
    if((*cur).data == val) return 1;
    return 0;
}


int main(){
    List L;
    l = int_list();
}


