#define NTIME

namespace ntime
{
	#ifdef NTIME_PRIVATE_CLASSES
		#if NTIME_PRIVATE_CLASSES == 1
			typedef ntime::time_private time;
		#else
			typedef ntime::time_public time;
		#endif
	#endif

	//classes
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

	//methods

	//for time_public
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


	//for time_private
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

	int time_private::set(unsigned short pyear, unsigned char pmonth, unsigned char pday, unsigned char phour, unsigned char pmin, unsigned char psec, unsigned short pmsec, unsigned short pmysec, unsigned short pnsec)
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
			return 0;
		}
		else
			return 1;
	}


	int time_private::set_nsec(unsigned short pnsec)
	{
		if(pnsec > 999 || pnsec < 0)
			return 1;
		else
			nsec = pnsec;
		return 0;
	}
	int time_private::set_mysec(unsigned short pmysec)
	{
		if(pmysec > 999 || pmysec < 0)
			return 1;
		else
			mysec = pmysec;
		return 0;
	}
	int time_private::set_msec(unsigned short pmsec)
	{
		if(pmsec > 999 || pmsec < 0)
			return 1;
		else
			msec = pmsec;
		return 0;
	}
	int time_private::set_sec(unsigned char psec)
	{
		if(psec > 59 || psec < 0)
			return 1;
		else
			sec = psec;
		return 0;
	}
	int time_private::set_min(unsigned char pmin)
	{
		if(pmin > 59 || pmin < 0)
			return 1;
		else
			min = pmin;
		return 0;
	}
	int time_private::set_hour(unsigned char phour)
	{
		if(phour > 23 || phour < 0)
			return 1;
		else
			hour = phour;
		return 0;
	}
	int time_private::set_day(unsigned char pday)
	{
		if(pday > 31 || pday < 1)
			return 1;
		else if(pday > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
			return 1;
		else if(pday > 29 && month == 2)
			return 1;
		else if(pday > 28 && month == 2 && ((year % 4 != 0) || (year % 100 == 0 && year % 400 != 0)))
			return 1;
		else
			day = pday;
		return 0;
	}
	int time_private::set_month(unsigned char pmonth)
	{
		if(pmonth > 12 || pmonth < 1)
			return 1;
		else
			month = pmonth;
		return 0;
	}
	int time_private::set_year(unsigned short pyear)
	{
		if(pyear < 0)
			return 1;
		else
			year = pyear;
		return 0;
	}

	unsigned short time_private::get_nsec()
	{
		return nsec;
	}
	unsigned short time_private::get_mysec()
	{
		return mysec;
	}
	unsigned short time_private::get_msec()
	{
		return msec;
	}
	unsigned char time_private::get_sec()
	{
		return sec;
	}
	unsigned char time_private::get_min()
	{
		return min;
	}
	unsigned char time_private::get_hour()
	{
		return hour;
	}
	unsigned char time_private::get_day()
	{
		return day;
	}
	unsigned char time_private::get_month()
	{
		return month;
	}
	unsigned short time_private::get_year()
	{
		return year;
	}
}