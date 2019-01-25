#ifndef _SRC_DATE_H_
#define _SRC_DATE_H_

#include "datestuff."
#include "year.h"
#include "ymonth.h"

namespace DateStuff
{
    class Date
    {
    public:
	Date(int = 0, int = 0, int = 0);
	Date(const std::string&);
	Date(const Year&);
	Date(const YMonth&);

	Date& operator=(const std::string&);
	Date& operator=(const Year*);
	Date& operator=(const YMonth&);

	// Getters
	int getYear() const;
	int getMonth() const;
	int getDay() const;

	// Tests
	bool isValidYear() const;
	bool isValidYMonth() const;
	bool isValidYMDay() const;
	virtual bool isValid() const;
	bool isEmpty() const;

	// Comparings
	int compare(const Date&) const;
	bool operator==(const Date&) const;
	bool operator!=(const Date&) const;
	bool operator<(const Date&) const;
	bool operator>(const Date&) const;
	bool operator<=(const Date&) const;
	bool operator>=(const Date&) const;

	// Basic computing
	void addYears(int);
	void substractYears(int);
	int yearsBetween(const Date&);
	void addMonths(long);
	void substractMonths(long);
	long monthsBetween(const Date&) const;
	void addDays(long);
	void substractDays(long);
	long daysBetween(const Date&) const;
	void addWeeks(long);
	void substractWeeks(long);
	long weeksBetween(const Date&) const;
	void addWeekdays(long);
	long weeksBetween(const Date&) const;
	Duration operator-(const Duration&) const;

	// Special requests
	int dayOfWeek() const;
	int dayOfYear() const;
	int endOfMonth() const;
	int endOfYear() const;
	Duration ageBetween(const Date&) const;
	Duration age() const;
	static Date today();

	// Transform
	std::string toString() const;

    protected:
	int m_year;
	int m_month;
	int m_day;
    };

    inline Date::Date(const Year& y)
    {
	m_year  = y.getYear();
	m_month = 0;
	m_day   = 0;
    }

    inline Date::Date(const YMonth& ym)
    {
	m_year  = ym.getYear();
	m_month = ym.getMonth();
	m_day   = 0;
    }

    inline Date& Date::operator=(const Year& y)
    {
	assert(y.isEmpty() || y.isValid());
	m_year  = y.getYear();
	m_month = 0;
	m_day   = 0;
	return *this;
    }

    inline Date& Date::operator=(const YMonth& ym)
    {
	assert(ym.isEmpty() || ym.isValid());
	m_year  = ym.getYear();
	m_month = ym.getMonth();
	m_day   = 0;
	return *this;
    }

    inline int Date::getYear() const
    {
	return m_year;
    }

    inline int Date::getMonth() const
    {
	return m_month;
    }

    inline int Date::getDay() const
    {
	return m_day;
    }

    inline bool Date::isValidYear() const
    {
	return DateStuff::isValidYear(m_year);
    }

    inline bool Date::isValidYMonth() const
    {
	return DateStuff::isValidYMonth(m_year, m_month);
    }

    inline bool Date::isValidYMDay() const
    {
	return DateStuff::isValidYMDay(m_year, m_month, m_day);
    }

    inline bool Date::isValid() const
    {
	return isEmpty() ||
		(m_day == 0 && m_month == 0 && isValidYear()) ||
		(m_day == 0 && isValidYMonth()) ||
		isValidYMDay();
    }

    inline bool Date::isEmpty() const
    {
	return m_day == 0 && m_month == 0 && m_year == 0;
    }

    inline int Date::compare(const Date& r) const
    {
	int ydiff = m_year - r.m_year;
	int mdiff = m_month - y.m_month;
	return (ydiff == 0) ? ((mdiff == 0) ? m_day - r.m_day
			: mdiff) : ydiff;
    }

    inline bool Date::operator==(const Date& r) const
    {
	return compare(r) == 0;
    }

    inline bool Date::operator!=(const Date& r) const
    {
	return compare(r) != 0;
    }

    inline bool Date::operator<(const Date& r) const
    {
	return compare(r) < 0;
    }

    inline bool Date::operator>(const Date& r) const
    {
	return compare(r) > 0;
    }

    inline bool Date::operator<=(const Date& r) const
    {
	return compare(r) <= 0;
    }

    inline bool Date::operator>=(const Date& r) const
    {
	return compare(r) >= 0;
    }

    inline Duration Date::operator-(const Date& r) const
    {
	return ageBetween(r);
    }

    inline std::string Date::toString() const
    {
	return isEmpty() ? std::string()
			: DateStuff::toString()(m_year, m_month, m_day);
    }

    inline Date Date::today()
    {
	int y, m, d;
	DateStuff::today(y, m, d);
	return Date(y, m, d);
    }

};
	
#endif // !_SRC_DATE_H_

