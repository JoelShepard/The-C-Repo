#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 20

char looser_name[LEN];

typedef struct{
    int serv;
    int pul;
    int pos;
} voto;
typedef struct{
    char name[LEN];
    float score;
} hscore;

float voto_hotel(char myhfilename[]);
char* incubo(char index[]);


float voto_hotel(char myhfilename[]){
    float avgserv, avgpul, avgpos, tot;
    int sum=0, people=0;
    char buffer[1024], let;
    FILE*myhotel = fopen(myhfilename, "r");

    if (myhotel == NULL) {
        printf("Errore. Il file non si apre");
    }

    while ((let = fgetc(myhotel)) != EOF) {
        if (let == '\n') {
            people++;
        }
    }
    people = people-1;
    rewind(myhotel);

    voto* myvoti = malloc(sizeof(voto)*(people));

    //input
    fgets(buffer, sizeof(buffer), myhotel);
    for (int i = 0; i<people; i++) {
        fscanf(myhotel, "%d %d %d\n", &myvoti[i].serv, &myvoti[i].pul, &myvoti[i].pos);
    }
    fclose(myhotel);

    //medie
    for (int i=0; i<people; i++) {
        sum = sum + myvoti[i].serv;
    }
    avgserv = (float) sum / people;
    sum = 0;
    for (int i=0; i<people; i++) {
        sum = sum + myvoti[i].pul;
    }
    avgpul = (float) sum / people;
    sum = 0;
    for (int i=0; i<people; i++) {
        sum = sum + myvoti[i].pos;
    }
    avgpos = (float) sum / people;
    sum = 0;

    tot = avgserv + avgpul + avgpos;

    free(myvoti);
    return tot;
}


char* incubo(char index[]){

    FILE*myindex = fopen(index, "r");
    char let, tmp_name[LEN];
    int rows=0, l=0, m=0;
    float tmp;

    while ((let = fgetc(myindex)) != EOF) {
        if (let == '\n') {
            rows++;
        }
    }
    rewind(myindex);


    hscore* hotel = malloc(sizeof(hscore)*(rows));

    for (int i=0; i<rows; i++) {
        fscanf(myindex, "%s\n", hotel[i].name);
    }
    for (int i=0; i<rows; i++) {
        hotel[i].score = voto_hotel(hotel[i].name);
    }

    //printf("%.2f", hotel[3].score);
    //printf(" %s\n", hotel[3].name);

    //order the array
    for (int i=0; i<rows-1; i++){
        for (int j=0; j<rows-i-1; j++){
            if(hotel[j].score > hotel[j+1].score){
                tmp = hotel[j].score;
                hotel[j].score = hotel[j+1].score;
                hotel[j+1].score = tmp;
                strcpy(tmp_name, hotel[j].name);
                strcpy(hotel[j].name, hotel[j+1].name);
                strcpy(hotel[j+1].name, tmp_name);
            }
        }
    }

    strcpy(looser_name, hotel[0].name);
    free(hotel);

    return looser_name;
}


int main(int argc, char* argv[]){
    if (argc == 2){
        printf("L'Hotel da incubo tra quelli indicati è: %s\nIl suo voto complessivo è stato di %.2f\n", strtok(incubo(argv[1]), "."), voto_hotel(incubo(argv[1])));
        return 0;
    } else {
        printf("Argomenti inseriri non validi");
        return 0;
    }
}
