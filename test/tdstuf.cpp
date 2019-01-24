#include "../src/datestuff.h"
#include <iostream>

static const char* dayText[] = {"Monday", "Tuesday", "wednesday",
	"Thursday", "Friday", "Saturday", "Sunday"};
int main()
{
    using namespace DateStuff;
    using namespace std;
    
    int year = 2019;
    int month = 1;
    int day = 24;

    cout.setf(ios::boolalpha);
    cout << "Date: " << month << '/' << day << '/' << year << endl;
    cout << "Leap year? " << isLeap(year) << endl;
    
    cout << "Day of week: " << dayText[dayOfWeek(year, month, day)] << endl;    cout << "Day of year: " << dayOfYear(year, month, day) << endl;
    cout << "Days in month: " << endOfMonth(year, month) << endl;
    cout << "Days in previous month: " << daysInPrevMonth(year, month) << endl;
    cout << "Days in next month: " << daysInNextMonth(year, month) << endl;
    cout << "3rd Saturday of month: " << nthWeekday(3, SATURDAY, year, month) << endl;
    
    long jday = greg2Jul(year, month, day);
    cout << "Julian day number: " << jday << endl;

    return 0;
}

