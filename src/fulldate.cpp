#include "fulldate.h"

namespace DateStuff
{
    FullDate::FullDate(const string& s)
    {
	DateStuff::fromString(s, m_year, m_month, m_day);
	if (!isEmpty() && !isValidYMDay())
	{
	    Throw(DATE_ERROR);
	}
    }

    FullDate::FullDate(int year, int month, int day)
    {
	m_year  = year;
	m_month = month;
	m_day   = day;
	if (!isEmpty && !isValidYMDay()
	{
	    Throw(DATE_ERROR);
	}
    }

    FullDate::FullDate(const Date& d)
    {
	m_year  = d.getYear();
	m_month = d.getMonth();
	m_day   = d.getDay();
	assert(isValid());
    }

}; // namespace DateStuff

