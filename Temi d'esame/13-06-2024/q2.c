#include <stdio.h>
#include <string.h>

#define MAX_NATIONS 4

typedef struct{
    char name[50];
    int num;
} Nation;

void provenienze(FILE* my, Nation array[MAX_NATIONS]){
    char name[25], country[25];
    int flag=0;

    while (!feof(my)){
        fscanf(my, "%s %s", name, country);
        flag=0;

        for (int i = 0; i < MAX_NATIONS; i++){
            if(strcmp(array[i].name, country)==0){
                flag=1;
                array[i].num+=1;
            }
        }
        if (flag==0){
            for (int i = 0; i < MAX_NATIONS; i++){
                strcpy(array[i].name, country);
                array[i].num+=1; 
            }
            
        }
        
    }
    
}

int main(){
    FILE* my = fopen("invitati.txt", "r");
    Nation nazioni[MAX_NATIONS];

    provenienze(my, nazioni);
    for (int i = 0; i < MAX_NATIONS; i++){
        printf("Paese:%s\t Invitati:%d\n", nazioni[i].name, nazioni[i].num);
    }

}

//Brutto