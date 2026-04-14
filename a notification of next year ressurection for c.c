#include <stdio.h>
#include <time.h>

// Define the structure
struct EasterDate {
    int day;
    int month;
    int year;
};

// Function to calculate Easter using the Meeus/Jones/Butcher algorithm
struct EasterDate calculateEaster(int year) {
    int a = year % 19;
    int b = year / 100;
    int c = year % 100;
    int d = b / 4;
    int e = b % 4;
    int f = (b + 8) / 25;
    int g = (b - f + 1) / 3;
    int h = (19 * a + b - d - g + 15) % 30;
    int i = c / 4;
    int k = c % 4;
    int l = (32 + 2 * e + 2 * i - h - k) % 7;
    int m = (a + 11 * h + 22 * l) / 451;
    
    int month = (h + l - 7 * m + 114) / 31;
    int day = ((h + l - 7 * m + 114) % 31) + 1;

    struct EasterDate result = {day, month, year};
    return result;
}

// Function to return month name as a constant string
const char* getMonthName(int m) {
    return (m == 3) ? "March" : "April";
}

int main() {
    // Get the current system time
    time_t t = time(NULL);
    struct tm *timePtr = localtime(&t);
    int currentYear = timePtr->tm_year + 1900;

    // Calculate dates
    struct EasterDate currentEaster = calculateEaster(currentYear);
    struct EasterDate nextEaster = calculateEaster(currentYear + 1);

    // Output results
    printf("This year (%d), Resurrection Sunday is: %s %d\n", 
            currentYear, getMonthName(currentEaster.month), currentEaster.day);
    
    printf("\n>>> Next Year Resurrection Sunday notification\n<<<\n\n");
    printf("The next Resurrection Sunday will be on: \n");
    printf("** %s %d, %d **\n", 
            getMonthName(nextEaster.month), nextEaster.day, nextEaster.year);

    return 0;
}