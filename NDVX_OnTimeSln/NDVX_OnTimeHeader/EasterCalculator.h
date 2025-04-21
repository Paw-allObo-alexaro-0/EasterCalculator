#include "ntime.h"
#define EASTER_CALCULATOR
#define NTIME_PIVATE_CLASSES 0

namespace time_calculator
{
	using namespace ntime;

	time_private calc_single_easter(signed short year)
	{
		int a = year % 19;
		int b = year % 4;
		int c = year % 7;
		int d = (19 * a + 24) % 30;
		int e = (2 * b + 4 * c + 6 * d + 5) % 7;

		time_private date(year, (unsigned char)d + e < 10 ? 3 : 4, (unsigned char)d + e < 10 ? d + e + 22 : d + e - 9);
		return date;
	}
	time_private* calc_easters(signed short* years, unsigned short count)
	{
		time_private* dates = new time_private[count];

		for (unsigned short i = 0; i < count; i++)
		{
			dates[i] = calc_single_easter(years[i]);
		}
		return dates;
	}
	time_private* calc_range_of_easters(signed short start_year, unsigned short end_year)
	{
		if (start_year > end_year)
			return nullptr;

		unsigned short count = end_year - start_year + 1;
		time_private* dates = new time_private[count];

		for (unsigned short i = 0; i < count; i++)
		{
			dates[i] = calc_single_easter(start_year + i);
		}
		return dates;
	}
}