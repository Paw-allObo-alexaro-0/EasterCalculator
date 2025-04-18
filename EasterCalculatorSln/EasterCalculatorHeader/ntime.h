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
}