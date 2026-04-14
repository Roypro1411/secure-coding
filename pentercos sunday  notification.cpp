#include <iostream>

using namespace std;
void addDays(int &day, int &month, int &year, int daysToAdd){
int daysInMonth[ ]={31, 28, 31, 30, 31, 30, 31, 31, 30 ,31, 30, 31};
if((year % 4 == 0 && year % 100 != 0 )  || year % 400 == 0)
    daysInMonth[1] = 29;
day += daysToAdd;
while (day > daysInMonth[ month - 1])
{
    day -= daysInMonth[ month - 1];
    month++;
    if ( month > 12) {
        month = 1;
        year++;
        }
}
}
int main()
{
    int day, month, year;
    cout<<" enter Easter date (day month year): " << endl;
    cin>> day >> month >> year ;
    int pDay = day, pMonth = month , pYear = year;
    addDays( pDay, pMonth, pYear, 49);
    int wDay = pDay, wMonth = pMonth, wYear = pYear;
    addDays(wDay, wMonth, wYear, -7);
    cout <<" Pentecost week starts on: "<< wDay << " / " << wMonth << " / " << wYear  << endl;
    cout<<" Pentecost Sunday is on: "<< pDay <<" / " << pMonth << "/ "<< pYear <<endl;
return 0;
}
