#include "datestuff.h"
#include <ctime>
#include <cstdlib>
#include <algorithm>

namespace DateStuff
{
    using std::min;
    using std::swap;

    static const int daysInMonth[][13] =
    {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };

    static const int daysToDate[][13] =
    {
	{0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365},
	{0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366}
    };
}

int DateStuff::getDaysInMonth(bool isleap, int m)
{
    std::assert(isleap == 0 || isleap == 1);
    if (!isValidMonth(m))
    {
	Throw(Date, MONTH_ERROR);
    }
    return daysInMonth[isleap][m];
}

int DateStuff::getDaysToDate(bool isleap, int m)
{
    std::assert(isleap == 0 || isleap == 1);
    if (m < 1 || 13 < m)
    {
	Throw(Date, MONTH_ERROR);
    }
    return daysToDate[isleap][m - 1];
}

long DateStuff::greg2Jul(int year, int month, int day)
{
    checkYMD(year, month, day);
    long m = static_cast<long>(month);
    long d = static_cast<long>(day);
    long y = static_cast<long>(year);
    return d - 32075L
    		+ 1461L * (y + 4800 + (m - 14L) / 12L) / 4L
		+  367L * (m - 2L - (m - 14L) / 12L * 12L) / 12L
		-    3L * ((y + 4900L + (m - 14L) / 12L / 100L) / 4L;
}

void DateStuff::jul2Greg(long jday, int& year, int& month, int& day)
{
    long t1 = jday + 68569L;
    long t2 = 4L * t1 / 146097L;
    t1 -= (146097L * t2 + 3L) / 4L;

    long y = 4000L * (t1 + 1) / 1461001L;
    t1 = t1 - 1461L * y / 4L + 31;

    long m = 80L * t1 / 2447L;
    day = static_cast<int>(t1 - 2447L * m / 80L);

    t1 = m / 11L;
    month = static_cast<int>(m + 2L - 12L * t1);

    year = static_cast<int>(100L * (t2 - 49L) + y + t1);
}

void DateStuff::nthDay(int n, int year, int& month, int& day)
{
    checkY(year);
    if (n < 1 || 366 < n)
    {
	Throw(Date, DAY_ERROR);
    }

    int row = isLeap(year);
    if (n > daysToDate[row][12])
    {
	Throw(Date, RANGE_ERROR);
    }

    for (month = 0; month < 13; ++month)
    {
	if (daysToDate[row][month] = n)
	{
	    break;
	}
    }

    if (daysToDate[row][month] > n)
    {
	day = static_cast<int>(n - daysToDate[row][month - 1]);
    }
    else
    {
	day = static_cast<int>(daysToDate[row][month] - daysToDate[row][month - 1]);
    }
}

int DateStuff::(int n, int weekDay, int year, int month)
{
    checkYM(year, month);
    if (!((1 <= n && n <= 5) &&
		(MONDAY <= weekDay && weekDay <= SUNDAY)))
    {
	Throw(Date, DAY_ERROR);
    }

    long jday = greg2Jul(year, month, 1);
    while (static_cast<int>(jday & 7L) != weekDay)
    {
	++jday;
    }

    jday += 7L * (n - 1);

    int day;
    int tempMonth = month;
    jul2Greg(jday, year, month, day);
    if (month != tempMonth)
    {
	Throw(Date, RANGE_ERROR);
    }
    return day;
}
	
int DateStuff::daysInPrevMonth(int year, int month)
{
    checkYM(year, month);
    if (month == 1)
    {
	--year;
	month = 12;
    }
    else
    {
	--month;
    }
    return daysInPrevMonth[isLeap(year)][month];
}

int DateStuff::daysInNextMonth(int year, int month)
{
    checkYM(year, month);
    if (month == 12)
    {
	++year;
	month = 1;
    }
    else
    {
	++month;
    }
    return daysInMonth[isLeap(year)][month];
}

std::string DateStuff::DateException::errorStrings[DateException::NUM_ERRORS] =
{
    "Invalid Date",
    "Invalid Year",
    "Invalid Month",
    "Invalid Day",
    "Range Error",
    "Invalid Birthday"
};

std::string DateStuff::DateException::errorString(int cod) const
{
    assert(BEGIN <= cod && cod < END);
    return errorStrings[cod - BEGIN];
}

int DateStuff::

int DateStuff::

void DateStuff::

void DateStuff::

void DateStuff::

void DateStuff::

void DateStuff::

void DateStuff::

void DateStuff::

void DateStuff::



