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

void DateStuff::

int DateStuff::

int DateStuff::

int DateStuff::

std::string DateStuff::

std::string DateStuff::

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



