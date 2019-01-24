#include "year.h"
#include <ctime>

DateStuff::Year::Year()
{
    time_t tval = time(0);
    struct tm* tmp = localtime(&tval);

    m_year = static_cast<int>(tmp->tm_year + 1900);
}

DateStuff::Year::Year(int y)
{
    m_year = y;
    if (!isEmpty() && !isValid())
    {
	Throw(YEAR_ERROR);
    }
}

DateStuff::Year::Year(const std::string& s)
{
    m_year = static_cast<int>(std::atoi(s.substr(0, 4).c_str()));
    if (!isEmpty() && !isValid())
    {
	Throw(YEAR_ERROR);
    }
}

DateStuff::addYears(int y)
{
    if (m_year > MAX_YEAR - y)
    {
	Throw(RANGE_ERROR);
    }
    m_year += y;
}

DateStuff::substractYears(int y)
{
    if (m_year < MIN_YEAR + y)
    {
	Throw(RANGE_ERROR);
    }
    m_year -= y;
}

DateStuff::age() const
{
    return ageBetween(Year());
}

DateStuff::endOfYear() const
{
    if (!isValid())
    {
	Throw(YEAR_ERROR);
    }
    return DateStuff::endOfYear(m_year);
}

