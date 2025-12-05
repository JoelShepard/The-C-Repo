/* 1_cookies.c - C source file. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROW 1024  // Size massima per stringhe e buffer

/* *
Struttura per nodo di lista concatenata che contiene stringhe
 */
typedef struct my {
    char name[MAX_ROW];  // Contenuto del nodo (parola/frase)
    struct my* next;     // Puntatore al nodo successivo
} Node;

typedef Node* List;  // Alias per puntatore alla lista

FILE* open(char* filename){
    FILE* file = fopen(filename, "r");
    return file;
}

int open_check(FILE* file){
    if (file == NULL) return -1;
    else return 0;
}

int count_row(FILE* file){
    rewind(file);  // Torna all'inizio del file
    int count=0;
    char c;
    
    // Conta i characters di nuova linea
    while ((c = getc(file)) != EOF) {
        if (c == '\n'){
            count++;
        }
    }
    return count;
}

void create_nodes(Node** list, int n){
    *list = (Node*)malloc(sizeof(Node));
    Node* tmp = *list;

    // Crea n nodi concatenati
    for (int i=0; i<n; i++) {
        tmp->next = (Node*)malloc(sizeof(Node));
        tmp = tmp->next;
    }
    tmp->next = NULL;
}

void insert(List list, FILE* file){
    rewind(file);  // Torna all'inizio del file
    Node* tmp = list;
    char buffer[MAX_ROW];

    // Legge ogni row e la inserisce nel nodo corrente
    while (fgets(buffer, MAX_ROW, file) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0'; // Rimuove il character di nuova row
        strcpy(tmp->name, buffer);
        tmp = tmp->next;
    }
}

Node* search(List list, int n){
    Node* ptr = list;
    while (n!=0) {
        list = list->next;
        if (ptr != list) {
            ptr = ptr->next;
        }
        n--;
    }
    return ptr;
}

Node* sel(List list, int elem){

    int mynum = rand() % (elem + 1);
    Node* randptr = search(list, mynum);
    return randptr;
}

void insert_phrase(List list, char* str, int n){
    Node* ptr = search(list, n);
    strcpy(ptr->name, str);
}

void list_free(List* list){
    if (*list == NULL) {
        return;
    }
    Node* next = (*list)->next;
    free (*list);
    *list = NULL;
    list_free(&next);
}

void general_free(List* a, List* b, List* c, List* d, List* e){
    list_free(a);
    list_free(b);
    list_free(c);
    list_free(d);
    list_free(e);
}


int main(){
    FILE *azioni, *cose, *luoghi, *momenti;
    srand(time(NULL));


    azioni = open("azioni.txt");
    if (open_check(azioni) == -1){
        printf("Errore nell'apertura del file\n");
        return -1;
    }
    cose = open("cose.txt");
    if (open_check(cose) == -1){
        printf("Errore nell'apertura del file\n");
        return -1;
    }
    luoghi = open("luoghi.txt");
    if (open_check(luoghi) == -1){
        printf("Errore nell'apertura del file\n");
        return -1;
    }
    momenti = open("momenti.txt");
    if (open_check(momenti) == -1){
        printf("Errore nell'apertura del file\n");
        return -1;
    }


    List actions, things, places, moments;


    create_nodes(&actions, count_row(azioni));
    insert(actions, azioni);
    create_nodes(&things, count_row(cose));
    insert(things, cose);
    create_nodes(&places, count_row(luoghi));
    insert(places, luoghi);
    create_nodes(&moments, count_row(momenti));
    insert(moments, momenti);

    //save number of elements
    int elementi[4];
    elementi[0] = count_row(azioni);
    elementi[1] = count_row(cose);
    elementi[2] = count_row(luoghi);
    elementi[3] = count_row(momenti);

    // file closure
    fclose(azioni);
    fclose(cose);
    fclose(luoghi);
    fclose(momenti);


    int phrases;
    char buffer[MAX_ROW];
    int point;
    printf("Quante frasi vuoi generare: ");
    scanf("%d", &phrases);


    List frasi;
    create_nodes(&frasi, phrases);
    for (int i=0; i<phrases; i++) {
        point = snprintf(buffer, MAX_ROW, "%s ", sel(moments, elementi[3])->name);
        point += snprintf(buffer+point, MAX_ROW, "%s ", sel(actions, elementi[0])->name);
        point += snprintf(buffer+point, MAX_ROW, "%s ", sel(things, elementi[1])->name);
        point += snprintf(buffer+point, MAX_ROW, "%s ", sel(places, elementi[2])->name);
        insert_phrase(frasi, buffer, i);
        buffer[0]= '\0';
    }

    Node* tmp = frasi, *tmp2=frasi;
    for (int i=0; i<phrases; i++) {
        printf("%s\n", tmp->name);
        tmp = tmp->next;
    }


    FILE* file_frasi = fopen("frasi.txt", "w");
    if (file_frasi == NULL) {
        printf("Errore nella creazione del file frasi.txt");
    }
    for (int i=0; i<phrases; i++) {
        fprintf(file_frasi, "%s\n", tmp2->name);
        tmp2 = tmp2->next;
    }

    //free heap memory
    general_free(&actions, &things, &places, &moments, &frasi);
    return 0;
}
