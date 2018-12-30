#ifndef DATE_H
#define DATE_H
#define FEL 0
#include <iostream>
namespace Ourdate {

// Leap checking function
inline bool isLeapYear( int year )
{
	if ( ( !( year % 4 ) && ( year % 100 ) ) || !( year % 400 ) )
		return true;
	else
		return false;
}

// Date storing structure
struct Datestruct {
		int day;
		int month;
		int year;
		unsigned long daysFrom16K; // Days past from 01.01.1600s
		
		Datestruct() {
			day = 0;
			year = 0;
			month = 0;
			daysFrom16K = 0;
		}
		
		Datestruct( int getDay, int getMonth, int getYear ) {
			day = getDay;
			year = getYear;
			month = getMonth;
			daysFrom16K = 0;
		}
};

// Date class
class Date {
	
private:
	Datestruct date;
	
	int daysFromCalc() {
		int locYear = date.year, locMonth = date.month, locDay = date.day;
		int stYear = 1600, stMonth = 1, stDay = 1;

		int ret = 0;
		int monthTemp = 0;

		while (stYear < locYear)
		{
			if (isLeapYear(stYear))
			{
				ret += 366;
			}
			else
			{
				ret += 365;
			}
			stYear++;
		}

		switch (locMonth) {
		case 1: { monthTemp = 0; break; }
		case 2: { monthTemp = 31; break; }
		case 3: { monthTemp = 59; break; }
		case 4: { monthTemp = 90; break; }
		case 5: { monthTemp = 120; break; }
		case 6: { monthTemp = 151; break; }
		case 7: { monthTemp = 181; break; }
		case 8: { monthTemp = 212; break; }
		case 9: { monthTemp = 243; break; }
		case 10: { monthTemp = 273; break; }
		case 11: { monthTemp = 304; break; }
		case 12: { monthTemp = 334; break; }
		}

		if ((isLeapYear(locYear)) && ((locMonth != 1) && (locMonth != 2)))
			monthTemp++;

		ret += monthTemp;
		
		ret += locDay;
		/*if (locDay == 0)
			ret++;*/
		return ret;
	}
	
	std::string dayToString( int arg ) {
	switch( arg ) {
		case 1: return "Sunday";
		case 2: return "Monday";
		case 3: return "Tuesday";
		case 4: return "Wednesday";
		case 5: return "Thursday";
		case 6: return "Friday";
		case 0: return "Saturday";
		}
	}
	
	int dayNumber( int d, int m, int yc, bool ly ) {
	
		int ret;
	
		int result = ( d + m + yc ) % 7 + 1;
		if (ly==true)
			if (result==0)
				ret = 6;
			else 	 
				ret = ( d + m + yc ) % 7 - 1;
		else 
			ret = ( d + m + yc ) % 7;
			
		return ret;
	}
	
	int monthCode( int m ) {
		if(m==2||m==3||m==11)
			m=4;
		else if (m == 1||m==10)
			m = 1;
		else if(m==4||m==7)
			m=0;
		else if(m==12||m==9)
			m=6;
		else if (m == 5)
			m = 2;
	 	else if(m==8)
			m =3;
		else if(m==6)
			m=5;
			
		return m;
	}
	
	int yearCode( int y ) {
		int  century=0;
	
		if((y/100)%4==0)
			century=6;
		if((y/100)%4==1)
			century=4;
		if((y/100)%4==2)
			century=2;
		if((y/100)%4==3)
			century=0;
		return ((century+y%100+(y%100)/4)%7);
	}

// Public members
public:
	// Constructors
	Date() {
		date.day = 1;
		date.month = 0;
		date.year = 0;
	}

	Date( int day, int month, int year ) {
		date.day = day;
		date.month = month;
		date.year = year;
		
		date.daysFrom16K = daysFromCalc();
	}
	
	Date( int daysFrom16K ) {
		date.day = 0;
		date.month = 0;
		date.year = 0;
	
		date.daysFrom16K = daysFrom16K;
	}

	Datestruct daysToCalc() {
		int locDaysFrom16K = date.daysFrom16K;
		int yearTemp = 1600, monthTemp = 0, dayTemp = 0;

		int isLeap = 0;

		while (locDaysFrom16K >= 365)
		{
			if (isLeapYear(yearTemp))
			{
				locDaysFrom16K -= 366;
			}
			else
			{
				locDaysFrom16K -= 365;
			}
			yearTemp++;
		}
				
		if (isLeapYear(yearTemp))
			isLeap = 1;
		
		if (locDaysFrom16K > (273 + isLeap))
		{
			locDaysFrom16K -= (273 + isLeap);
			monthTemp += 9;

			if (locDaysFrom16K > (61 + isLeap))
			{
				locDaysFrom16K -= (61 + isLeap);
				monthTemp += 3;
			}
			else
				if (locDaysFrom16K > (31 + isLeap))
				{
					locDaysFrom16K -= (31 + isLeap);
					monthTemp += 2;
				}
				else
				{
					monthTemp += 1;
				}
		}
		else
			if (locDaysFrom16K > (181 + isLeap))
			{
				locDaysFrom16K -= (181 + isLeap);
				monthTemp += 6;

				if (locDaysFrom16K > (62 + isLeap))
				{
					locDaysFrom16K -= (62 + isLeap);
					monthTemp += 3;
				}
				else
					if (locDaysFrom16K > (31 + isLeap))
					{
						locDaysFrom16K -= (31 + isLeap);
						monthTemp += 2;
					}
					else
					{
						monthTemp += 1;
					}
			}
			else
				if (locDaysFrom16K > (90 + isLeap))
				{
					locDaysFrom16K -= (90 + isLeap);
					monthTemp += 3;

					if (locDaysFrom16K > (61 + isLeap))
					{
						locDaysFrom16K -= (61 + isLeap);
						monthTemp += 3;
					}
					else
						if (locDaysFrom16K > (30 + isLeap))
						{
							locDaysFrom16K -= (30 + isLeap);
							monthTemp += 2;
						}
						else
						{
							monthTemp += 1;
						}
				}
				else if (locDaysFrom16K > (59 + isLeap))
				{
					locDaysFrom16K -= (59 + isLeap);
					monthTemp += 3;
				}
				else
					if (locDaysFrom16K > (31))
					{
						locDaysFrom16K -= (31);
						monthTemp += 2;
					}
					else
						monthTemp++;
		
		dayTemp = locDaysFrom16K;
		
		/*if (dayTemp == 0)
			dayTemp = 31;*/

		Datestruct ret;

		ret.year = yearTemp;
		ret.month = monthTemp;
		ret.day = dayTemp;
		
		ret.daysFrom16K = date.daysFrom16K;

		return ret;
	}

	// Setters and Getters
	void setDate( Datestruct arg ) {
		date.day = arg.day;
		date.month = arg.month;
		date.year = arg.year;
		
		date.daysFrom16K = daysFromCalc();
	}
	
	int get16K() {
		return date.daysFrom16K;
	}

	// Other
	int calcWeekdayInt() {
	
		int yearcode = yearCode( date.year ); 
		int monthcode = monthCode( date.month );
		
		bool isleap = false;
		if ( ( ( !( date.year % 4 ) && ( date.year % 100 ) ) || !( date.year % 400 ) ) && ( date.month == 1 || date.month == 2 ) )
			isleap = true;
		
		return dayNumber( date.day, monthcode, yearcode, isleap );
	}

	std::string calcWeekday() {
		return dayToString( calcWeekdayInt() );
	}
	

	
	// Date arythmetic operations
	void increaseOnce()
	{
		date.daysFrom16K++;
		/*try {*/
			date = daysToCalc();
		/*}
		catch () {

		}*/
	}
	
	void decreaseOnce()
	{
		date.daysFrom16K--;
		date = daysToCalc();
		
	}
	
	void increaseBy( int arg )
	{
		date.daysFrom16K += arg;
		date = daysToCalc();
	}
	
	void decreaseBy( int arg )
	{
		date.daysFrom16K -= arg;
		date = daysToCalc();
	}
	
	int getYear() {
		return date.year;
	}

	int getMonth() {
		return date.month;
	}

	int getDay() {
		return date.day;
	}

};

// Input class
class Input {
	
private:
	Datestruct date;
	char inputString[10];
	//char *inputString;
	
	void enter(char *str) {
		//cin.getline(str,11);
		fgets(str, 11, stdin);
	}

	int dayCheck() {
	
		int retDay=0;
		int max=31; // Maximum days in month

		int locMonth = date.month;
		
		if ( ( ( inputString[FEL+0] >= '0' ) && ( inputString[FEL+0] <= '9' ) ) && ( ( inputString[FEL+1] >= '0' ) && ( inputString[FEL+1] <= '9' ) ) && ((inputString[FEL+2] == '.') || (inputString[FEL+2] == '/')))
			retDay = ( inputString[FEL+0] - '0' ) * 10 + ( inputString[FEL+1] - '0' );
		else
			return 0;
		
		switch (locMonth) // Month checking
                    {
                        case 1: { max=31; break; }
                        case 2: { if ( isLeapYear( date.year ) ) max=29; else max=28; break; }
                        case 3: { max=31; break; }
                        case 4: { max=30; break; }
                        case 5: { max=31; break; }
                        case 6: { max=30; break; }
                        case 7: { max=31; break; }
                        case 8: { max=31; break; }
                        case 9: { max=30; break; }
                        case 10: { max=31; break; }
                        case 11: { max=30; break; }
                        case 12: { max=31; break; }
						default: max = 31;
                    }
		
		if ((retDay <= 0) || (retDay > max))
			return 0;
		
		return retDay;
	}

	int monthCheck() {

		int retMonth = 0;
		
		if ( ( ( inputString[FEL+3] >= '0' ) && ( inputString[FEL + 3] <= '9' ) ) && ( ( inputString[FEL + 4] >= '0' ) && ( inputString[FEL + 4] <= '9' ) ) && ( ( inputString[FEL + 5] == '.' ) || ( inputString[FEL + 5] == '/' ) ) )
			retMonth = ( inputString[FEL + 3] - '0' ) * 10 + ( inputString[FEL + 4] - '0' );
		else
			return 0;
		
		if ( ( retMonth > 0 ) && ( retMonth <= 12 ) )
			return retMonth;
		else
			return 0;
	}

	int yearCheck() {

		int retYear = 0;
		
		for (int i = 6; i <= 9; i++) {
			if (!((i == 8) || (i == 9)))
			{
				if ((inputString[FEL + i] >= '0') && (inputString[FEL + i] <= '9'))
					retYear = retYear * 10 + (inputString[FEL + i] - '0');
				else
					return 0;
			} else
				if ((inputString[FEL + i] >= '0') && (inputString[FEL + i] <= '9'))
					retYear = retYear * 10 + (inputString[FEL + i] - '0');


		}
				
		if ((retYear >= 1600) || ((retYear >= 1) && (retYear <= 99)))
		{
			if ((retYear >= 1) && (retYear <= 99))
				return retYear + 2000;
			else
				return retYear;
		}
		else
			return 0;
	}
	
public:
	Input(const char* arg) {
		//inputString = new char[size];
		for ( int i = 0; i < 10; i++ )
			inputString[i] = arg[i+1];
	}
	
	/*~Input() {
		delete inputString;
	}*/

	bool checkDate() {
		if ( ( yearCheck() > 0 ) && ( monthCheck() > 0 ) ) {
			date.year = yearCheck();
			date.month = monthCheck();
		}
		else
			return false;

		int temp = dayCheck();

		if (temp > 0)
			date.day = temp;
		else
			return false;
		date.daysFrom16K = 0;
		return true;
			
	}

	int nCheck() {

		int retN = 0;

		for (int i = 0; i <= 4; i++) {

			if ((inputString[FEL + i] >= '0') && (inputString[FEL + i] <= '9'))
				retN = retN * 10 + (inputString[FEL + i] - '0');
			else
				if (i = 0)
					return 0;
				else
					break;
		}

		return retN;
	}

	// Setters and Getters
	Datestruct getDate() {
		Datestruct ret;
		
		ret.day = date.day;
		ret.year = date.year;
		ret.month = date.month;
		ret.daysFrom16K = date.daysFrom16K;
		
		return ret;
	}

	int getYear() {
		return date.year;
	}

	int getMonth() {
		return date.month;
	}

	int getDay() {
		return date.day;
	}

	std::string getString()
	{
		return inputString;
	}
};

}

#endif