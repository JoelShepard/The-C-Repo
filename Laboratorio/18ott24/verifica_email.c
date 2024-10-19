#include <stdio.h>
#include <string.h>

#define MAXLEN 30

int main(){
    char email[MAXLEN];
    int real_len=0, i=0, position_at=0, position_full_stop=0;

    fgets(email, MAXLEN, stdin);
    real_len= strlen(email);

    if (email[0] == '@'){
        printf("L'email non può iniziare con una @\n");
        return 0;
    }
    if (email[0] == '.'){
        printf("L'email non può iniziare con un .\n");
        return 0;
    }
    for (i = 0; i < real_len-1; i++){

        if (email[i] == '@'){
            position_at = i;
        }
        if (email[i] == '.'){
            position_full_stop = i;
            printf("full stop %d", position_full_stop);
        }
    }
    if (position_at == 0){
        printf("Formato non corretto. La @ non è presente\n");
        return 0;
    }
    if (position_full_stop == 0){
        printf("Formato non corretto. Non è presente nenache un .\n");
        return 0;
    }

    if (position_full_stop == position_at + 1)
    {
        printf("Formato non corretto. Il . non può essere subito dopo la @\n");
        return 0;
    }
    if (position_full_stop < position_at)
    {
        printf("Formato non corretto. Deve esserci almeno un . dopo la @\n");
        return 0;
    }
    
    
    printf("Formato email corretto :)\n");

    return 0;
}