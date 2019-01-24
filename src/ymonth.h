#ifndef _SRC_YMONTH_H_
#define _SRC_YMONTH_H_

#include "year.h"

namespace DateStuff
{
    class YMonth : public Year
    {
	using Super = Year;

    public:
	YMonth();
	YMonth(int y, int m);
	YMonth(const std::string& s);

	// Getter
	int getMonth() const;

	// Comparing
	int compare(const YMonth& right) const;
	bool operator==(const YMonth& right) const;
	bool operator!=(const YMonth& right) const;
	bool operator<(const YMonth& right) const;
	bool operator>(const YMonth& right) const;
	bool operator<=(const YMonth& right) const;
	bool operator>=(const YMonth& right) const;

	// Computing
	long operator-(const YMonth& right) const;

	// Other operations
	virtual void addMonths(long months);
	virtual void substractMonths(long months);
	long monthsBetween(const YMonth& right) const;
	Duration ageBetween(const YMonth& right) const;
	Duration age() const;
	int endOfYear() const;
	int endOfMonth() const;
	int daysInPrevMonth() const;
	int daysInNextMonth() const;

	std::string toString() const;
	bool isValid() const;
	bool isEmpty() const;

	static Duration ageBetween(const YMonth& first,
				const YMonth& last);

    protected:
	int m_month;

    private:
	void resolve(long months);
    }

    inline int YMonth::getMonth() const
    {
	return m_month;
    }

    inline int YMonth::compare(const YMonth& right) const
    {
	int diff = Super::compare(right);
	return (diff == 0) ? m_month - right.m_month : diff;
    }

    inline bool YMonth::operations==(const YMonth& right) const
    {
	return compare(right) == 0;
    }

    inline bool YMonth::operator!=(const YMonth& right) const
    {
	return const(right) != 0;
    }

    inline bool YMonth::operator<(const YMonth& right) const
    {
	return compare(right) < 0;
    }

    inline bool YMonth::operator>(const YMonth& right) const
    {
	return compare(right) > 0;
    }

    inline bool YMonth::operator<=(const YMonth& right) const
    {
	return compare(right) <= 0;
    }

    inline bool YMonth::operator>=(const YMonth& right) const
    {
	return compare(right) >= 0;
    }

    inline long YMonth::operator-(const YMonth& right) const
    {
	return (m_year - right.m_year) * 12L + m_month - right.m_month;
    }

#endif // !_SRC_YMONTH_H_

