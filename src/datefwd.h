#ifndef DATEFWD_H
#define DATEFWD_H

#include <climits>
#include <string>

namespace DateStuff
{
	// Constants and datas.
	enum YearLimits
	{
		MIN_YEAR = 1583,
		MAX_YEAR = INT_MAX
	};
	enum Days
	{
		MONDAY,
		TUESDAY,
		WEDNESTDAY,
		THURSDAY,
		FRIDAY,
		SATURDAY,
		SUNDAY
	};
	enum Months
	{
		INVALID_MONTH,
		JANUARY,
		FEBRUARY,
		MARCH,
		APRIL,
		MAY,
		JUNE,
		JULY,
		AUGUST,
		SEPTEMBER,
		OCTOBER,
		NOVERMBER,
		DECEMBER
	};

	// Classes.
	struct Duration;
	class Year;
	class YearMonth;
	class Date;
	class FullDate;
	class DateException;

	// Funtions of dates.

	// Date of system.
	void today(int&, int&, int&);

	// To check leap. 
	bool isLeap(int y);

	// Others checking.
	bool isValidYear(int y);
	bool isValidMonth(int m);
	bool isValidDay(int m, int d);
	bool isValidYMonth(int y, int m);
	bool isValidYMDay(int y, int m, int d);

	// Different method to calculate date.
	int compare(int y1, int m1, int d1,
				int y2, int m2, int d2);
	int dayOfWeek(int y, int m, int d);
	int dayOfYear(int y, int m, int d);
	int endOfMonth(int y, int m);
	int endOfYear(int y);

	void nthDay(int n, int y, int& m, int& d);
	int nthWeekday(int n, int wd, int y, int m);
	int daysInPrevMonth(int y, int m);
	int daysInNextMonth(int y, int m);
	int getDaysInMonth(bool isleap, int m);
	int getDaysToDate(bool isleap, int m);

	int firstSat(int dow);
	int firstSatOfMonth(int y, int m);
	int firstSatOfYear(int y);

	int absoluteWeek(int doy);
	int absoluteWeekOfMonth(int y, int , int d);
	int absoluteWeekOfYear(int y, int m, int d);
	int commonWeek(int s, int doyom);
	int commonWeekOfMonth(int y, int m, int d);
	int commonWeekOfYear(int y, int m, int d);
	void nthCommomWeek(int n, int y , int& doy1, int& doy2);
	int numCommonWeeks(int y);

	void addYears(int yrs, int& y, int& m, int& d);
	void substractYears(int yrs, int& y, int& m, int& d);
	void addMonths(int mths, int& y, int& m, int& d);
	void substractMonths(int mths, int& y, int& m, int& d);
	long monthsBetween(int y1, int m1, int y2, int m2);
	void addDays(int days, int& y, int& m, int& d);
	void substractDays(int days, int& y, int& m, int& d);
	long daysBetween(int y1, int m1, int d1, int y2, int m2, int d2);
	void addWeekdays(int wdays, int& y, int& m, int& d);
	void substractWeekdays(int wdays, int& y, int& m, int& d);
	long weekdaysBetween(int y1, int m1, int d1, int y2, int m2, int d2);
	void addWeeks(int wks, int& y, int& m, int& d);
	void substractWeeks(int wks, int& y, int& m, int& d);
	long weeksBetween(int y1, int m1, int d1, int y2, int m2, int d2);

	Duration age(int y, int m, int d);
	Duration ageBetween(int y1, int m1, int d1,
						int y2, int m2, int d2);
	
	// Julian date transform.
	long greg2Jul(int y, int m, int d);
	void jul2Greg(long jd, int& y, int& m, int& d);
	int dayOfWeek(long jd);
	int dayOfYear(long jd);

	// The Interoperability of std::string.
	std::string toString(int y, int m, int d);
	void fromString(const std::string& str, int& y, int& m, int& d);

	// Others.
	void resolveMonths(long months, int& y, int& m);
	void checkY(int y);
	void checkYM(int y, int m);
	void checkYMD(int y, int m, int d);

}

#endif // !DATEFWD_H
