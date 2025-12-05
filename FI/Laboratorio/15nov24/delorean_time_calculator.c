/* delorean_time_calculator.c - C source file. */

#include <stdio.h>

/* *
Struttura per rappresentare una data e ora completa
 */
typedef struct {
    int day;                              // Giorno del mese (1-31)
    int month;
    int year;                             // Anno (es. 1985, 2015)
    int hour;
    int min;
} data;


int year(data* dep, data* arr);
int month(data* dep, data* arr);
int day(data* dep, data* arr);
int hour(int* hour_dep, int* hour_arr, int* day_dep);
int min(int* min_dep, int* min_arr, int* hour_dep);
int compare_date(data dep, data arr);

int compare_date(data dep, data arr){

    if (dep.year < arr.year) return 1;
    if (dep.year > arr.year) return -1;

    // Confronto per mese (stesso anno)
    if (dep.month < arr.month) return 1;
    if (dep.month > arr.month) return -1;

    // Confronto per giorno (stesso mese)
    if (dep.day < arr.day) return 1;
    if (dep.day > arr.day) return -1;

    // Confronto per ora (stesso giorno)
    if (dep.hour < arr.hour) return 1;
    if (dep.hour > arr.hour) return -1;

    // Confronto per minuti (stessa ora)
    if (dep.min < arr.min) return 1;
    if (dep.min > arr.min) return -1;


    return 0;
}

int min(int* min_dep, int* min_arr, int* hour_dep){
    int simple_sum = *min_arr - *min_dep;
    
    // GESTIONE RIPORTO: se negativo, prende 60 minuti dall'ora precedente
    if (simple_sum < 0) {
        *hour_dep = *hour_dep + 1;
        simple_sum = simple_sum + 60;
    }
    return simple_sum;
}

int hour(int* hour_dep, int* hour_arr, int* day_dep){
    int simple_sum = *hour_arr - *hour_dep;
    
    // GESTIONE RIPORTO: se negativo, prende 24 ore dal giorno precedente
    if (simple_sum < 0) {
        *day_dep = *day_dep + 1;
        simple_sum = simple_sum + 24;
    }
    return simple_sum;
}

int day(data* dep, data* arr){
    int simple_sum = (*arr).day - (*dep).day;
    
    // GESTIONE RIPORTO: se negativo, prende giorni dal mese precedente
    if (simple_sum < 0) {
        (*dep).month = (*dep).month + 1;
        
        // MESI CON 30 GIORNI: aprile(4), giugno(6), settembre(9), novembre(11)
        if ((*dep).month == 11 || (*dep).month == 4 || (*dep).month == 6 || (*dep).month == 9) {
            simple_sum = simple_sum + 30;
        }
        
        // FEBBRAIO IN ANNO BISESTILE: 29 giorni
        if ((*dep).month == 2 && ((*dep).year % 4 == 0 && (*dep).year % 100 != 0) || ((*dep).year % 400 == 0)) {
            simple_sum = simple_sum + 29;
        }
        
        // FEBBRAIO IN ANNO NON BISESTILE: 28 giorni
        if ((*dep).month == 2 && !((*dep).year % 4 == 0 && (*dep).year % 100 != 0) || ((*dep).year % 400 == 0)) {
            simple_sum = simple_sum + 28;
        } else {
            // MESI CON 31 GIORNI: gennaio, marzo, maggio, luglio, agosto, ottobre, dicembre
            simple_sum = simple_sum + 31;
        }
    }
    return simple_sum;
}

int month(data* dep, data* arr){
    int simple_sum = (*arr).month - (*dep).month;
    
    // GESTIONE RIPORTO: se negativo, prende 12 mesi dall'anno precedente
    if (simple_sum < 0) {
        (*dep).year = (*dep).year + 1;
        simple_sum = simple_sum + 12;
    }
    return simple_sum;
}

int year(data* dep, data* arr){
    int simple_sum = (*arr).year - (*dep).year;
    
    // VALORE ASSOLUTO: converte sempre in positivo
    if (simple_sum < 0) {
        simple_sum = - simple_sum;
    }
    return simple_sum;
}

int main(){
    data dep_date, arr_date;
    
    printf("🚗⚡ DELOREAN TIME CALCULATOR ⚡🚗\n");
    printf("Insert the departure date in format: DD-MM-YYYY hh:mm\n");
    printf("(Es: 26-10-1985 01:20 per la famosa partenza di Marty): ");
    scanf("%d-%d-%d %d:%d", &dep_date.day, &dep_date.month, &dep_date.year, &dep_date.hour, &dep_date.min);
    
    printf("Insert the arrival date in format: DD-MM-YYYY hh:mm\n");
    printf("(Es: 21-10-2015 16:29 per il futuro): ");
    scanf("%d-%d-%d %d:%d", &arr_date.day, &arr_date.month, &arr_date.year, &arr_date.hour, &arr_date.min);

    if (compare_date(dep_date, arr_date) == 1) {

        int mm = min(&dep_date.min, &arr_date.min, &dep_date.hour);
        int h = hour(&dep_date.hour, &arr_date.hour, &dep_date.day);
        int d = day(&dep_date, &arr_date);
        int m = month(&dep_date, &arr_date);
        int y = year(&dep_date, &arr_date);
        printf("⚡ Grande Giove !!! ⚡\n");
        printf("Hai viaggiato per %d anni, %d mesi, %d giorni, %d ore e %d minuti AVANTI nel tempo.\n", y, m, d, h, mm);
        printf("🔮 Benvenuto nel futuro! 🔮\n");
        
    } else if (compare_date(dep_date, arr_date) == 0){

        printf("⚡ Grande Giove !!! ⚡\n");
        printf("Non hai viaggiato nel tempo - sei rimasto nello stesso momento!\n");
        printf("🕐 Il flusso temporale è stabile! 🕐\n");
        
    } else if (compare_date(dep_date, arr_date) == -1){

        int mm = min(&arr_date.min, &dep_date.min, &arr_date.hour);
        int h = hour(&arr_date.hour, &dep_date.hour, &arr_date.day);
        int d = day(&arr_date, &dep_date);
        int m = month(&arr_date, &dep_date);
        int y = year(&arr_date, &dep_date);
        printf("⚡ Grande Giove !!! ⚡\n");
        printf("Hai viaggiato per %d anni, %d mesi, %d giorni, %d ore e %d minuti INDIETRO nel tempo.\n", y, m, d, h, mm);
        printf("🤠 Attento a non incontrare te stesso! 🤠\n");
    }
    
    printf("\n🚗 Ricorda: dove stiamo andando, non servono... strade! 🚗\n");
    return 0;
}

/* 
Note tecniche:
- Il calcolo dei giorni per mese ha problemi di logica nella gestione dei casi
- La gestione degli anni bisestili è corretta ma potrebbe essere migliorata
- Le funzioni modificano i parametri di input, il che può causare confusione
- Sarebbe meglio utilizzare strutture dati separate per i calcoli
- Il formato di input potrebbe essere validato meglio
 */
