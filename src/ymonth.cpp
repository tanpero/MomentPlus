#include "ymonth.h"
#include <ctime>

namespace DateStuff
{
    YMonth::YMonth()
    {
	time_t tval = time(0);
	struct tm *tmp = localtime(&tval);
	m_month = static_cast<int>(tmp->tm_mon + 1);
    }

    YMonth::YMonth(int y, int m) : Year(y)
    {
	m_month = m;
	if (!isEmpty() && !isValid())
	{
	    Throw(MONTH_ERROR);
	}
    }

    YMonth::YMonth(const std::string& s)
    	: Year(s)
    {
	m_month = static_cast<int>(std::atoi(s.substr(4, 2).c_str()));
	if (!isEmpty() && !isValid())
	{
	    Throw(MONTH_ERROR);
	}
    }

    Duration YMonth::age() const
    {
	return ageBetween(*this, YMonth());
    }

    int YMonth::endOfYear() const
    {
	if (!isValid())
	{
	    Throw(MONTH_ERROR);
	}
	return DateStuff::endOfYear(m_year);
    }

    int YMonth::endOfMonth() const
    {
	if (!isValid())
	{
	    Throw(MONTH_ERROR);
	}
	return DateStuff::endOfMonth(m_year, m_year);
    }

    int YMonth::daysInPrevMonth() const
    {
	if (!isValid())
	{
	    Throw(MONTH_ERROR);
	}
	return DateStuff::daysInPrevMonth(m_year, m_month);
    }

    int YMonth::daysInNextMonth() const
    {
	if (!isValid())
	{
	    Throw(MONTH_ERROR);
	}
	return DateStuff::daysInNextMonth(m_year, m_month);
    }

}; // namespace DateStuff


