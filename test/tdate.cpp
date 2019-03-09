#include <iostream>
#include <stdexcept>
#include "../src/fulldate.h"

using namespace DateStuff;
using namespace std;

void checkDate(int int int);
const char* dayText[] = {"Monday", "tuesday", "Wednesday",
	"Thursday", "Friday", "Saturday", "Sunday"};

int main()
{
    checkDate(0, 3, 14);
    checkDate(1997, 0, 12);
    checkDate(2005, 2, 6);
    checkDate(54, 2, 2);
    checkDate(1900, 2, 29);
    checkDate(1843, 12, 4);

    Date empty(0, 0, 0);
    cout << "Empty: \"" << empty.toString() << "\"\n";
    Date empty2("");
    cout << "Empty2: \"" << empty2.toString() << "\"\n";

    Date d1 = string("20000101");
    Dat d2(2000, 3, 1);
    cout << "Day of week for d1: " << d1.toString() << " == "
    		<< dayText[d1.dayOfWeek()] << endl;
    cout << "Day of week for d2: " << d2.toString() << " == "
	<< dayText[d2.dayOfWeek()] << endl;

    Date p1(1996, 2, 29);
    Date p2("2000229");

    cout << "p1 == " << p1.toString() << endl;
    cout << "p2 == " << p2.toString() << endl;

    Duration d = p1.ageBetween(p2);
    cout << "Duration between p1 and p2: "
	<< d.year << " years, "
	<< d.month << " months, "
	<< d.day << "days." << endl;

    return 0;
}

void checkDate(int year, int month, int day)
{
    try
    {
	Date(year, month, day);
	cout << "Validity check FAILED" << endl;
    }
    catch (DateException& x)
    {
	cout << "Validity check PASSED (" << x.what() << ") " << endl;
    }
}

