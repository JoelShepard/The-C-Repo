/* giorno_nascita.c - C source file. */

#include <stdio.h>

/* *
Function principale che implementa l'algoritmo di Zeller
 */
int main(){
    int day=0, month=0, year=0;
    int year_ok=0, month_ok=0, day_ok=0;
    int day_week=0, century_year=0, century=0;    // Variabili per algoritmo Zeller

    printf("input your birth date in this format: day month year \n");
    scanf("%d %d %d", &day, &month, &year);
    
    // L'algoritmo funziona solo dopo l'adozione del calendario gregoriano
    if (year > 1582) {
        year_ok = 1;
    }
    
    if (1 <= month && month <= 12) {
        month_ok = 1;
    }
    
    if (month_ok) {
        if (month == 2) {
            // Febbraio: gestione anni bisestili
            int leap_year = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
            if ((leap_year && day >= 1 && day <= 29) ||
                (!leap_year && day >= 1 && day <= 28)) {
                day_ok = 1;
            }
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11) {
            // Mesi con 30 giorni
            if (day >= 1 && day <= 30) {
                day_ok = 1;
            }
        }
        else {
            // Mesi con 31 giorni
            if (day >= 1 && day <= 31) {
                day_ok = 1;
            }
        }
    }
    
    if (year_ok == 0) {
        printf("The year is not compatible with the algorithm\n");
        return 1;
    }
    if (month_ok == 0) {
        printf("The month is not valid\n");
        return 1;
    }
    if (day_ok == 0 && month_ok == 1) {
        printf("The day is not valid\n");
        return 1;
    }
    
    // Gennaio e febbraio sono trattati come mesi 13 e 14 dell'anno precedente
    if (month == 1 || month == 2) {
        month += 12;
        year--;
    }
    
    century_year = year % 100;            // Ultime due cifre dell'anno
    century = (year - century_year) / 100; // Prime cifre dell'anno (secolo)
    
    // Formula: h = (q + ⌊26(m+1)/10⌋ + K + ⌊K/4⌋ + ⌊J/4⌋ - 2J) mod 7
    day_week = (day + ((26*(month+1))/10) + century_year + (century_year/4) + (century/4) - 2*century) % 7;

    // 0=Sabato, 1=Domenica, 2=Lunedì, 3=Martedì, 4=Mercoledì, 5=Giovedì, 6=Venerdì
    switch(day_week) {
        case 0:
            printf("The day of the week is Saturday\n");
            break;
        case 1:
            printf("The day of the week is Sunday\n");
            break;
        case 2:
            printf("The day of the week is Monday\n");
            break;
        case 3:
            printf("The day of the week is Tuesday\n");
            break;
        case 4:
            printf("The day of the week is Wednesday\n");
            break;
        case 5:
            printf("The day of the week is Thursday\n");
            break;
        case 6:
            printf("The day of the week is Friday\n");
            break;
    }

    return 0;
}
