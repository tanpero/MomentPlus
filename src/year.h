#ifndef _SRC_YEAR_H_
#define _SRC_YEAR_H_

#include "datestuff.h"

namespace DateStuff
{
    class Year
    {
    public:
	Year();
	Year(int);
	Year(const std::string&);

	// Getter
	int getYear() const;

	// Comparing
	int compare(const Year& right) const;
	bool operator==(const Year& right) const;
	bool operator!=(const Year& right) const;
	bool operator<(const Year& right) const;
	bool operator>(const Year& right) const;
	bool operator<=(const Year& right) const;
	bool operator>=(const Year& right) const;

	// Computing
	int operator-(const Year& right) const;

	// Other operation
	virtual void addYears(int years);
	virtual void substractYears(int years);

	int yearsBetween(const Year& right) const;
	Duration ageBetween(const Year& right) const;
	Duration age() const;
	int endOfYear() const;

	std::string toString() const;
	bool isValid() const;
	bool isEmpty() const;

    protected:
	int m_year;
    };

    inline int Year::getYear() const
    {
	return m_year;
    }

    inline int Year::compare(const Year& right) const
    {
	return m_year - right.m_year;
    }

    inline bool Year::operator==(const Year& right) const
    {
	return compare(right) == 0;
    }

    inline bool Year::operator!=(const Year& right) const
    {
	return compare(right) != 0;
    }

    inline bool Year::operator<(const Year& right) const
    {
	return compare(right) < 0;
    }

    inline bool Year::operator>(const Year& right) const
    {
	return compare(right) > 0;
    }

    inline bool Year::operator<=(const Year& right) const
    {
	return compare(right) <= 0;
    }

    inline bool Year::operator>=(const Year& right) const
    {
	return compare(right) >= 0;
    }

    inline int Year::operator-(const Year& right) const
    {
	return compare(right);
    }

    inline Duration Year::ageBetween(const Year& right) const
    {
	return Duration(yearsBetween(right));
    }

    inline int Year::yearsBetween(const Year& right) const
    {
	int diff = static_cast<int>(right.m_year - m_year);
	return static_cast<int>(diff >= 0 ? diff : -diff);
    }

    inline bool Year::isValid() const
    {
	return MIN_YEAR <= m_year && m_year <= MAX_YEAR;
    }

    inline bool Year::isEmpty() const
    {
	return m_year == 0;
    }

    inline std::string Year::toString() const
    {
	return isEmpty() ? std::string()
			: DateStuff::toString(m_year, 0, 0);
    }

} // namespace DateStuff	

#endif // !_SRC_YEAR_H_

