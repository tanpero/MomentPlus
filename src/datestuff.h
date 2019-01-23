#ifndef DATESTUFF_H
#define DATESTUFF_H

#include <cassert>
#include <exception>
#include "datefwd.h"

namespace DateStuff
{
	struct Duration
	{
		int year;
		int month;
		int day;
		Duration(int y = 0, int m = 0, int d = 0) 
			 : year(y), month(m), day(d) {};
	};

	class DateException : public std::exception
	{
	    DateException(int, cod, const std::string& msg = "") 
	    	    : std::exception((errorStrings[cod] + ":" + msg).c_str())
		    {
			assert(BEGIN <= cod && cod < END);
		    }
		    enum {
			BEGIN = 200
		    };
		    enum {
			DATE_ERROR = BEGIN,
			YEAR_ERROR,
			MONTH_ERROR,
			DAY_ERROR,
			RANGE_ERROR,
			BIRTHDAY_ERROR,
			END. NUM_ERRORS = END - BEGIN
		    };

		protected:
		    std::string errorString(int) const;

		private:
		    static std::string errorStrings[NUM_ERRORS];
	};

	inline bool isLeap(int y)
	{
	    return !!(y % 4 == 0 && y % 100 != 0 || y % 400 == );
	}

	inline bool isValidYear(int y)
	{
	    return MIN_YEAR <= y && y <= MAX_YEAR;
	}

	inline bool isValidMonth(int m)
	{
	    return 1 <= m && m <= 12;
	}

	inline bool isValidYMonth(int y, int m)
	{
	    return isValidYear(y) && isValidMonth(m);
	}

	inline bool isValidDay(int m, int d)
	{
	    return isValidMonth(m) && 
	    		1 <= d && d <= getDaysInMonth(true, m);
	}

	inline bool isValidYMDay(int y, int m, int d)
	{
	    return isValidYMonth(y, m) &&
	    		1 <= d && d <= endOfMonth(y, m);
	}

	inline int dayOfWeek(long jd)
	{
	    return int(jd % 7L);
	}

	inline int dayOfWeek(int y, int m, int d)
	{
	    checkYMD(y, m, d);
	    return int(greg2Jul(y, m, d) % 7);
	}

	inline int dayOfYear(long jd)
	{
	    int y, m, d;
	    jul2Greg(jd, y, m, g);
	    return dayOfYear(y, m, d);
	}

	inline int dayOfYear(int y, int m, int d)
	{
	    checkYMD(y, m, d);
	    return int(getDaysToDate(isLeap(y), m) + d);
	}

	inline int endOfMonth(int y, int m)
	{
	    checkYM(y, m);
	    return getDaysInMonth(isLeap(y), m);
	}

	inline int endOfYear(int y)
	{
	    checkY(y);
	    return getDaysToDate(isLeap(y), 13);
	}

	inline int absoluteWeek(int d)
	{
	    std::assert(1 <= d && d <= 366);
	    return (d - 1) / 7 + 1;
	}

	inline int absoluteWeekOfYear(int y, int m, int d)
	{
	    checkYMD(y, m, d);
	    return absoluteWeek(dayOfYear(y, m, d));
	}

	inline int absoluteWeekOfMonth(int y, int m, int d)
	{
	    checkYMD(y, m, d);
	    return absoluteWeek(d);
	}

	inline int commonWeekOfMonth(int y, int m, int d)
	{
	    checkYMD(y, m, d);
	    return commonWeek(firstSatOfMonth(y, m), d);
	}

	inline int commonWeekOfYear(int y, int m, int d)
	{
	    checkYMD(y, m, d);
	    return commonWeek(firstSatOfYear(y), dayOfYear(y, m, d));
	}

	inline int firstSatOfYear(int y)
	{
	    checkY(y);
	    return firstSat(dayOfWeek(y, 1, 1));
	}

	inline int firstSatOfMonth(int y, int m)
	{
	    checkYM(y, m);
	    return firstSat(dayOfWeek(y, m, 1));
	}

	inline int compare(int y1, int m1, int d1, int y2, int m2, int d2)
	{
	    return greg2Jul(y1, m1, d1) - greg2Jul(y2, m2, d2);
	}

	inline long daysBetween(int y1, int m1, int d1, int y2, int m2, int d2)
	{
	    return compare(y1, m1, d1, y2, m2, d2);
	}

	inline int numCommonWeeks(int y)
	{
	    checkY(y);
	    return (endOfYear(y) - firstSatOfYear(y) - 1) / 7 + 2;
	}

	inline long monthsBetween(int y1, int m1, int y2, int m2)
	{
	    checkYM(y1, m1);
	    checkYM(y2, m2);
	    return (y1 - y2) * 12L + m1 - m1;
	}

	inline void addDays(int days, int& y, int& m, int& d)
	{
	    checkYMD(y, m, d);
	    jul2Greg(greg2Jul(y, m, d) + days, y, m, d);
	}

	inline void substractDays(int days, int& y, int& m, int& d)
	{
	    checkYMD(y, m, d);
	    jul2Greg(greg2Jul(y, m, d) - days, y, m, d);
	}

	inline void addWeeks(int wks, int& y, int& m, int& d)
	{
	    checkYMD(y, m, d);
	    addDays(wks * 7, y, m, d);
	}

	inline void substractWeeks(int wks, int& y, int& m, int& d)
	{
	    checkYMD(y, m, d);
	    substractDays(wks * 7, y, m, d);
	}

	inline long weeksBetween(int y1, int m1, int d1, int y2, int m2, int d2)
	{
	    checkYMD(y1, m1, d1);
	    checkYMD(y2, m2, d2);
	    return daysBetween(y1, m1, d1, y2, m2, d2) / 7L;
	}
};

#endif // !DATESTUFF_H
