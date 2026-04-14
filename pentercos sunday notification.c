#include <stdio.h>
#include <stdbool.h>

bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getDaysInMonth(int month, int year) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeap(year)) {
        return 29;
    }
    return days[month - 1];
}

void addDays(int *day, int *month, int *year, int daysToAdd) {
    *day += daysToAdd;
    while (*day > getDaysInMonth(*month, *year)) {
        *day -= getDaysInMonth(*month, *year);
        (*month)++;
        if (*month > 12) {
            *month = 1;
            (*year)++;
        }
    }
    while (*day <= 0) {
        (*month)--;
        if (*month < 1) {
            *month = 12;
            (*year)--;
        }
        *day += getDaysInMonth(*month, *year);
    }
}

int main() {
    int day, month, year;

    printf("Enter Easter date (day month year): \n");
    if (scanf("%d %d %d", &day, &month, &year) != 3) {
        printf("Invalid input.\n");
        return 1;
    }

    int pDay = day, pMonth = month, pYear = year;
    addDays(&pDay, &pMonth, &pYear, 49);

    int wDay = pDay, wMonth = pMonth, wYear = pYear;
    addDays(&wDay, &wMonth, &wYear, -7);

    printf("Pentecost week starts on: %d / %d / %d\n", wDay, wMonth, wYear);
    printf("Pentecost Sunday is on: %d / %d / %d\n", pDay, pMonth, pYear);

    return 0;
}