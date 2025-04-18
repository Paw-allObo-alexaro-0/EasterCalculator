#define NTIME

namespace ntime
{
	class time_public
	{
		public:
			unsigned short nsec;
			unsigned short mysec;
			unsigned short msec;
			unsigned char sec;
			unsigned char min;
			unsigned char hour;
			unsigned char day;
			unsigned char month;
			unsigned short year;
			time_public(void);
			int check();
	};
	time_public::time_public()
	{
		nsec = 0;
		mysec = 0;
		msec = 0;
		sec = 0;
		min = 0;
		hour = 0;
		day = 1;
		month = 1;
		year = 0;
	}
	int time_public::check()
	{
		if(month > 12 || month < 1)
			return 2;
		if(day > 31 || day < 1)
			return 3;
		else if(day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
			return 3;
		else if(day > 29 && month == 2)
			return 3;
		else if(day > 28 && month == 2 && ((year % 4 != 0) || (year % 100 == 0 && year % 400 != 0)))
			return 3;
		if(hour > 23 || hour < 0)
			return 4;
		if(min > 59 || min < 0)
			return 5;
		if(sec > 59 || sec < 0)
			return 6;
		if(msec > 999 || msec < 0)
			return 7;
		if(mysec > 999 || mysec < 0)
			return 8;
		if(nsec > 999 || nsec < 0)
			return 9;
		return 0;
	}
}