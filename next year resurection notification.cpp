incl#ude <iostream>
#include <string>
#include <ctime>
using namespace std;
struct EasterDate {
    int day;
    int month;
    int year;
};

EasterDate calculateEaster(int year) {
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

    return {day, month, year};
}

std::string getMonthName(int m) {
    return (m == 3) ? "March" : "April";
}

int main() {
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    int currentYear = timePtr->tm_year + 1900;

    EasterDate currentEaster = calculateEaster(currentYear);
    EasterDate nextEaster = calculateEaster(currentYear + 1);

    cout << "This year (" << currentYear << "), Resurrection Sunday is: " 
              << getMonthName(currentEaster.month) << " " << currentEaster.day << std::endl;
    
    cout << "\n>>> Next Year Resurrection Sunday notification\n<<<" << std::endl;
    cout << "The next Resurrection Sunday will be on: " << std::endl;
    cout << "** " << getMonthName(nextEaster.month) << " " << nextEaster.day << ", " << nextEaster.year << " **" << std::endl;

    return 0;
}