#include "../src/datestuff.h"
#include <iostream>

const char* dayText[] = {"Monday", "Tuesday", "wednesday",
	"Thursday", "Friday", "Saturday", "Sunday"};
int main()
{
    using namespace DateStuff;
    using namespace std;
    
    int year = 1997;
    int month = 4;
    int day = 1;

    cout.setf(ios::boolalpha);
    cout << "Date: " << month << '/' << day << '/' << year << endl;
    cout << "Leap year? " << isLeap(year) << endl;
    
    return 0;
}

