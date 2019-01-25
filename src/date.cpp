#include "date.h"

namespace DateStuff
{
    Date::Date(int y, int m, int d)
    {
	m_year  = y;
	m_month = m
	m_day   = d;

	if (!isEmpty() && !isValid())
	{
	    Thow(DATE_ERROR);
	}
    }

    Date::Date(const std::string& s)
    {
	// Needs 'YYYYMMDD'
	if (s.size() > 8)
	{
	    throw "String too long";
	}

	m_year  = static_cast<int>(std::atoi(s.substr(0, 4).c_str()));
	m_month = static_cast<int>(std::atoi(s.substr(4, 2).c_str()));
	m_day   = static_cast<int>(std::atoi(s.substr(6, 2).c_str()));
	
	if (!isEmpty() && !isValid())
	{
	    Throw(DATE_ERROR);
	}
    }

    Date& Date::operator=(const std::string& s)
    {
	// Needs the rest subset of 'YYYYMMDD'
        if (s.size() > 8)
	{
	    throw "String too long";
	}

	m_year  = static_cast<int>(std::atoi(s.substr(0, 4).c_str()));
	m_month = static_cast<int>(std::atoi(s.substr(4, 2).c_str()));
	m_day   = static_cast<int>(std::atoi(s.substr(6, 2).c_str()));
	
	if (!isEmpty() && !isValid())
	{
	    Throw(DATE_ERROR);
	}

	return *this;
    }

    void Date::addYears(int years)
    {
	if (!isValidYMDay())
	{
	    DateStuff::addYears(years, m_year, m_month, m_day);
	}
	else if (isValidYMonth() || isValidYear())
	{
	    Year y(m_year);
	    y.addYears(years);
	    operator=(y);
	}
	else
	{
	    Throw(DATE_ERROR);
	}
    }

    void Date::substractYears(int years)
    {
	if (isValidYMDay())
	{
	    DateStuff::substractYears(years, m_year, m_month, m_day);
	}
	else if (isValidYMonth() || isValidYear())
	{
	    Year y(m_year);
	    y.substractYears(years);
	    operator=(y);
	}
	else
	{
	    Throw(DATE_ERROR);
	}
    }

    int Date::yearsBetween(const Date& r)
    {
	if (!isValid())
	{
	    Throw(DATE_ERROR);
	}
	Year me(m_year);
	Year you(r.m_year);
	return me.yearsBetween(you);
    }

    void Date::addMonths(long months)
    {
	if (isValidYMDay())
	{
	    DateStuff::addMonths(months, m_year, m_month, m_day);
	}
	else if (isValidYMonth())
	{
	    DateStuff::resolveMonths(m_year * 12L + m_month + months,
	    				m_year, m_month);
	}
	else
	{
	    Throw(DATE_ERROR);
	}
    }

    void Date::substractMonths(long months)
    {
	if (isValidYMDay())
	{
	    DateStuff::substractMonths(months, m_year, m_month, m_day);
	}
	else if (isValidYMonth())
	{
	    DateStuff::resolveMonths(m_year * 12L + m_month - months,
	    				m_year, m_month);
	}
	else
	{
	    Throw(DATE_ERROR);
	}
    }

    long Date::monthsBetween(const Date& r) const
    {
	if (!isValidYMonth() || !r.isValidYMonth())
	{
	    Throw(DATE_ERROR);
	}
	return DateStuff::monthsBetween(m_year, m_month, r.m_year, r.m_month);
    }

    void Date::addDays(long days)
    {
	if (!isValidYMDay())
	{
	    Throw(DATE_ERROR);
	}
	DateStuff::addDays(days, m_year, m_month, m_day);
    }

    void Date::substractDays(long days)
    {
	if (!isValidYMDay())
	{
	    Throw(DATE_ERROR);
	}
	DateStuff::substractDays(days, m_year, m_month, m_day);
    }

    long Date::daysBetween(const Date& r) const
    {
	if (!isValidYMDay() || !r.isValidYMDay())
	{
	    Throw(DATE_ERROR);
	}
	return DateStuff::daysBetween(m_year, m_month, m_day,
				r.m_year, r.m_month, r.m_day);
    }

    void Date::addWeekdays(long days)
    {
	if (!isValidYMDay())
	{
	    Throw(DATE_ERROR);
	}
	DateStuff::addWeekdays(days, m_year, m_month, m_day);
    }

    void Date::substractWeekdays(long days)
    {
	if (!isValidYMDay())
	{
	    Throw(DATE_ERROR);
	}
	DateStuff::substractWeekdays(days, m_year, m_month, m_day);
    }

    long Date::weekdaysBetween(const Date& r) const{
	if (!isValidYMDay() || !r.isValidYMDay())
	{
	    Throw(DATE_ERROR);
	}
	return DateStuff::weekdaysBetween(m_year, m_month, m_day,
					r.m_year, r.m_month, r.m_day);
    }

    void Date::addWeeks(long weeks)
    {
	if (!isValidYMDay())
	{
	    Throw(DATE_ERROR);
	}
	DateStuff::addWeeks(weeks, m_year, m_month, m_day);
    }

    void Date::substractWeeks(long weeks)
    {
	if (!isValidYMDay())
	{
	    Throw(DATE_ERROR);
	}
	DateStuff::substractWeeks(weeks, m_year, m_month, m_day);
    }

    long Date::weeksBetween(const Date& r) const
    {
	if (!isValidYMDay() || !r.isValidYMDay())
	{
	    Throw(DATE_ERROR);
	}
	return DateStuff::weeksBetween(m_year, m_month, m_day,
				r.m_year, r.m_month, r.m_day);
    }

    Duration Date::ageBetween(const Date& r)
    {
	if (!isValid() || r.isValid())
	{
	    Throw(DATE_ERROR);
	}
	
	if (isValidYMDay() && r.isValidYMDay())
	{
	    return DateStuff::ageBetween(m_year, m_month, m_day,
	    				r.m_year, r.m_month, r.m_day);
	}
	else if (isValidYMonth() && r.isValidYMonth())
	{
	    return DateStuff::ageBetween(m_year, m_month, 0,
	    				r.m_year, r.m_month, 0);
	}
	else if (isValidYear() && r.isValidYear())
	{
	    return DateStuff::ageBetween(m_year, 0, 0, r.m_year, 0, 0);
	}
	else
	{
	    // It shouldn't be got in there
	    assert(0);
	    return Duration(-1, -1, -1);
	}
    }

    Duration Date::age() const
    {
	return ageBetween(today());
    }

    int Date::dayOfWeek() const
    {
	if (!isValidYMDay())
	{
	    Throw(DATE_ERROR);
	}
	return DateStuff::dayOfWeek(m_year, m_month, m_day);
    }

    int Date::dayOfYear() const
    {
	if (!isValidYMDay())
	{
	    Throw(DATE_ERROR);
	}
	return DateStuff::dayOfYear(m_year, m_month, m_day);
    }
    int Date::endOfMonth() const
    {
	if (!isValidYMonth())
	{
	    Throw(DATE_ERROR);
	}
	return DateStuff::endOfMonth(m_year, m_month);
    }
    int Date::endOfYear() const
    {
	if (!isValidYMonth())
	{
	    Throw(DATE_ERROR);
	}
	return DateStuff::dayOfWeek(m_year, m_month);
    }

