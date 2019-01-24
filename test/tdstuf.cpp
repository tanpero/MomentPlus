#include "../src/datestuff.h"
#include <iostream>
#include <ctime>

static const char* dayText[] = {"Monday", "Tuesday", "wednesday",
	"Thursday", "Friday", "Saturday", "Sunday"};
int main()
{
    using namespace DateStuff;
    using namespace std;
    
    struct tm *now;
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

    int year2, month2, day2;
    jul2Greg(jday + 100, year2, month2, day2);
    cout << "100 days from now: " << month2 << '/' << day2 << '/'
		<< year2 << endl;

    return 0;
}

