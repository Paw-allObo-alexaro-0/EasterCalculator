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



	class time_private
	{
	private:
		unsigned short nsec;
		unsigned short mysec;
		unsigned short msec;
		unsigned char sec;
		unsigned char min;
		unsigned char hour;
		unsigned char day;
		unsigned char month;
		unsigned short year;
	public:
		time_private();
		time_private(unsigned short pyear, unsigned char pmonth, unsigned char pday, unsigned char phour, unsigned char pmin, unsigned char psec, unsigned short pmsec, unsigned short pmysec, unsigned short pnsec);
		time_private(unsigned short pyear, unsigned char pmonth, unsigned char pday, unsigned char phour, unsigned char pmin, unsigned char psec);
		time_private(unsigned short pyear, unsigned char pmonth, unsigned char pday);
		time_private(unsigned char phour, unsigned char pmin, unsigned char psec, unsigned short pmsec, unsigned short pmysec, unsigned short pnsec);
		time_private(unsigned char phour, unsigned char pmin, unsigned char psec);
		time_private(unsigned char phour, unsigned char pmin);
		int set(unsigned short pyear, unsigned char pmonth, unsigned char pday, unsigned char phour, unsigned char pmin, unsigned char psec, unsigned short pmsec, unsigned short pmysec, unsigned short pnsec);
		int set_nsec(unsigned short pnsec);
		int set_mysec(unsigned short pmysec);
		int set_msec(unsigned short pmsec);
		int set_sec(unsigned char psec);
		int set_min(unsigned char pmin);
		int set_hour(unsigned char phour);
		int set_day(unsigned char pday);
		int set_month(unsigned char pmonth);
		int set_year(unsigned short pyear);
		unsigned short get_nsec();
		unsigned short get_mysec();
		unsigned short get_msec();
		unsigned char get_sec();
		unsigned char get_min();
		unsigned char get_hour();
		unsigned char get_day();
		unsigned char get_month();
		unsigned short get_year();
	};
	time_private::time_private()
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
	time_private::time_private(unsigned short pyear, unsigned char pmonth, unsigned char pday, unsigned char phour, unsigned char pmin, unsigned char psec, unsigned short pmsec, unsigned short pmysec, unsigned short pnsec)
	{
		time_public temp;
		temp.nsec = pnsec;
		temp.mysec = pmysec;
		temp.msec = pmsec;
		temp.sec = psec;
		temp.min = pmin;
		temp.hour = phour;
		temp.day = pday;
		temp.month = pmonth;
		temp.year = pyear;
		if (!temp.check())
		{
			nsec = pnsec;
			mysec = pmysec;
			msec = pmsec;
			sec = psec;
			min = pmin;
			hour = phour;
			day = pday;
			month = pmonth;
			year = pyear;
		}
		else
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
	}
	time_private::time_private(unsigned short pyear, unsigned char pmonth, unsigned char pday, unsigned char phour, unsigned char pmin, unsigned char psec)
	{
		nsec = 0;
		mysec = 0;
		msec = 0;

		time_public temp;
		temp.nsec = nsec;
		temp.mysec = mysec;
		temp.msec = msec;
		temp.sec = psec;
		temp.min = pmin;
		temp.hour = phour;
		temp.day = pday;
		temp.month = pmonth;
		temp.year = pyear;
		if (!temp.check())
		{
			sec = psec;
			min = pmin;
			hour = phour;
			day = pday;
			month = pmonth;
			year = pyear;
		}
		else
		{
			sec = 0;
			min = 0;
			hour = 0;
			day = 1;
			month = 1;
			year = 0;
		}
	}
	time_private::time_private(unsigned short pyear, unsigned char pmonth, unsigned char pday)
	{
		nsec = 0;
		mysec = 0;
		msec = 0;
		sec = 0;
		min = 0;
		hour = 0;

		time_public temp;
		temp.nsec = nsec;
		temp.mysec = mysec;
		temp.msec = msec;
		temp.sec = sec;
		temp.min = min;
		temp.hour = hour;
		temp.day = pday;
		temp.month = pmonth;
		temp.year = pyear;
		if (!temp.check())
		{
			day = pday;
			month = pmonth;
			year = pyear;
		}
		else
		{
			day = 1;
			month = 1;
			year = 0;
		}
	}
	time_private::time_private(unsigned char phour, unsigned char pmin, unsigned char psec, unsigned short pmsec, unsigned short pmysec, unsigned short pnsec)
	{
		nsec = pnsec;
		mysec = pmysec;
		msec = pmsec;
		day = 1;
		month = 1;
		year = 0;

		time_public temp;
		temp.nsec = nsec;
		temp.mysec = mysec;
		temp.msec = msec;
		temp.sec = psec;
		temp.min = pmin;
		temp.hour = phour;
		temp.day = day;
		temp.month = month;
		temp.year = year;
		if (!temp.check())
		{
			hour = phour;
			min = pmin;
			sec = psec;
			msec = pmsec;
			mysec = pmysec;
			nsec = pnsec;
		}
		else
		{
			hour = 0;
			min = 0;
			sec = 0;
			msec = 0;
			mysec = 0;
			nsec = 0;
		}
	}
	time_private::time_private(unsigned char phour, unsigned char pmin, unsigned char psec)
	{
		nsec = 0;
		mysec = 0;
		msec = 0;
		day = 1;
		month = 1;
		year = 0;

		time_public temp;
		temp.nsec = nsec;
		temp.mysec = mysec;
		temp.msec = msec;
		temp.sec = psec;
		temp.min = pmin;
		temp.hour = phour;
		temp.day = day;
		temp.month = month;
		temp.year = year;
		if (!temp.check())
		{
			hour = phour;
			min = pmin;
			sec = psec;
			msec = 0;
			mysec = 0;
			nsec = 0;
		}
		else
		{
			hour = 0;
			min = 0;
			sec = 0;
			msec = 0;
			mysec = 0;
			nsec = 0;
		}
	}
	time_private::time_private(unsigned char phour, unsigned char pmin)
	{
		nsec = 0;
		mysec = 0;
		msec = 0;
		sec = 0;
		day = 1;
		month = 1;
		year = 0;

		time_public temp;
		temp.nsec = nsec;
		temp.mysec = mysec;
		temp.msec = msec;
		temp.sec = sec;
		temp.min = pmin;
		temp.hour = phour;
		temp.day = day;
		temp.month = month;
		temp.year = year;
		if (!temp.check())
		{
			hour = phour;
			min = pmin;
			msec = 0;
			mysec = 0;
			nsec = 0;
			sec = 0;
		}
		else
		{
			hour = 0;
			min = 0;
			msec = 0;
			mysec = 0;
			nsec = 0;
			sec = 0;
		}
	}
}