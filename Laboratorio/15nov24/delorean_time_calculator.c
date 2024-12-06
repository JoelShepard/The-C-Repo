#include <stdio.h>

typedef struct {
    int day;
    int month;
    int year;
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

    if (dep.month < arr.month) return 1;
    if (dep.month > arr.month) return -1;

    if (dep.day < arr.day) return 1;
    if (dep.day > arr.day) return -1;

    if (dep.hour < arr.hour) return 1;
    if (dep.hour > arr.hour) return -1;

    if (dep.min < arr.min) return 1;
    if (dep.min > arr.min) return -1;

    return 0;
}


int min(int* min_dep, int* min_arr, int* hour_dep){
    int simple_sum = *min_arr - *min_dep;
    if (simple_sum < 0) {
        *hour_dep = *hour_dep + 1;
        simple_sum = simple_sum + 60;
    }
    return simple_sum;
}

int hour(int* hour_dep, int* hour_arr, int* day_dep){
    int simple_sum = *hour_arr - *hour_dep;
    if (simple_sum < 0) {
        *day_dep = *day_dep + 1;
        simple_sum = simple_sum + 24;
    }
    return simple_sum;
}

int day(data* dep, data* arr){
    int simple_sum = (*arr).day - (*dep).day;
    if (simple_sum < 0) {
        (*dep).month = (*dep).month + 1;
        if ((*dep).month == 11 || (*dep).month == 4 || (*dep).month == 6 || (*dep).month == 9) {
            simple_sum = simple_sum + 30;
        }
        if ((*dep).month == 2 && ((*dep).year % 4 == 0 && (*dep).year % 100 != 0) || ((*dep).year % 400 == 0)) {
            simple_sum = simple_sum + 29;
        }
        if ((*dep).month == 2 && !((*dep).year % 4 == 0 && (*dep).year % 100 != 0) || ((*dep).year % 400 == 0)) {
            simple_sum = simple_sum + 28;
        } else {
            simple_sum = simple_sum + 31;
        }
    }
    return simple_sum;
}

int month(data* dep, data* arr){
    int simple_sum = (*arr).month - (*dep).month;
    if (simple_sum < 0) {
        (*dep).year = (*dep).year + 1;
        simple_sum = simple_sum + 12;
    }
    return simple_sum;
}

int year(data* dep, data* arr){
    int simple_sum = (*arr).year - (*dep).year;
    if (simple_sum < 0) {
        simple_sum = - simple_sum;
    }
    return simple_sum;
}

int main(){
    data dep_date, arr_date;
    printf("insert the date of departure in this format: DD-MM-YYYY hh:mm\n:");
    scanf("%d-%d-%d %d:%d", &dep_date.day, &dep_date.month, &dep_date.year, &dep_date.hour, &dep_date.min);
    printf("insert the date of arrival in this format: DD-MM-YYYY hh:mm\n:");
    scanf("%d-%d-%d %d:%d", &arr_date.day, &arr_date.month, &arr_date.year, &arr_date.hour, &arr_date.min);


    if (compare_date(dep_date, arr_date)==1) {
        int mm = min(&dep_date.min, &arr_date.min, &dep_date.hour);
        int h = hour(&dep_date.hour, &arr_date.hour, &dep_date.day);
        int d = day(&dep_date, &arr_date);
        int m = month(&dep_date, &arr_date);
        int y = year(&dep_date, &arr_date);
        printf("Grande Giove !!! Hai viaggiato per %d anni, %d mesi, %d giorni, %d ore e %d minuti avanti nel tempo.\n", y, m, d, h, mm);
    } else if (compare_date(dep_date, arr_date)==0){
        printf("Grande Giove !!! Non hai viaggiato");
    } else if (compare_date(dep_date, arr_date)==-1){
        int mm=min(&arr_date.min, &dep_date.min, &arr_date.hour);
        int h=hour(&arr_date.hour, &dep_date.hour, &arr_date.day);
        int d=day(&arr_date, &dep_date);
        int m=month(&arr_date, &dep_date);
        int y=year(&arr_date, &dep_date);
        printf("Grande Giove !!! Hai viaggiato per %d anni, %d mesi, %d giorni, %d ore e %d minuti indietro nel tempo.\n", y, m, d, h, mm);
    }
}
