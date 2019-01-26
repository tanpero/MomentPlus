#ifndef _SRC_FULLDATE_H_
#define _SRC_FULLDATE_H_

#include "date.h"

namespace DateStuff
{
    class FullDate : public Date
    {
    public:
	FullDate();
	FullDate(const std::string&);
	FullDate(int, int, int);
	FullDate(const Date&);

	bool isValid() const;
	long toJul() const;
    };

    inline FullDate::FullDate()
    {
	DateStuff::today(m_year, m_month, m_day);
    }

    inline bool FullDate::isValid() const
    {
	return isEmpty() || DateStuff::isValidYMDay(m_year, m_month, m_day);
    }

    inline long FullDate::toJul() const
    {
	return greg2Jul(m_year, m_month, m_day);
    }

}; // namespace DateStuff

#endif // !_SRC_FULLDATE_H_

