/**
 * \file datetime.i
 * \brief core swigh python interface file  
 */


/*
 * This file is part of OndALear  collection of open source components.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Copyright (C) 2008 Amnon Janiv <amnon.janiv@ondalear.com>
 *
 * Initial version: 2011-11-11
 * Author: Amnon Janiv <amnon.janiv@ondalear.com>
 */

/*
 * $Id:  $
 */
 
 
 %include core.i
 
 
 %inline %{
 
//Business Classes
#include "datetime/DateTimeConstants.hpp"
#include "datetime/Day.hpp"
#include "datetime/DayOfMonth.hpp"
#include "datetime/Year.hpp"
#include "datetime/Month.hpp"
#include "datetime/Days.hpp"
#include "datetime/Date.hpp"
#include "datetime/DateUtil.hpp"
#include "datetime/WeekDay.hpp"
#include "datetime/MonthWeek.hpp"
#include "datetime/HolidayDuration.hpp"

%}


%rename(ConstrainedIntegerImpl) ConstrainedInteger;
class ConstrainedInteger {

public:
	//constructors 
	 

	virtual ~ConstrainedInteger();
};

%rename(HolidayDurationImpl) HolidayDuration;
class   HolidayDuration :
	public ConstrainedInteger {

public:

	//constructors 
	HolidayDuration();
	
	//accessors
	%extend {
		virtual void setValue (const Integer value){
			self->setValue(value);
		}
		
		Integer getValue() const{
			return self->getValue();
		}
	}
	
};

%rename(DatePartImpl) DatePart;

class   DatePart{
public:


	//constructors
	virtual ~DatePart();

	//operators
	virtual Bool operator==(const DatePart& rhs) const;
	virtual Bool operator!=(const DatePart& rhs) const;
	
	virtual Bool operator<(const DatePart& rhs) const;
    virtual Bool operator<=(const DatePart& rhs) const;
     
    virtual Bool operator>(const DatePart& rhs) const;
    virtual Bool operator>=(const DatePart& rhs) const;
	

	//utilities
	virtual Integer asInteger() const;
	virtual void add(Integer increment);
	virtual void substract(Integer increment);

	virtual void setValue(Integer value);
	virtual Integer getValue() const;
	


};

%rename(WeekDayImpl) WeekDay;
class   WeekDay 
	: public Enum {

public:

	typedef enum 
	{ 
		Sunday    = 1,
        Monday    = 2,
        Tuesday   = 3,
        Wednesday = 4,
        Thursday  = 5,
        Friday    = 6,
        Saturday  = 7
	} eWeekDay;

	WeekDay();
	static const WeekDay& instance();
	virtual String toString(WeekDay::eWeekDay unit) const;
	virtual WeekDay::eWeekDay fromString(const String& stringRep) const;
	virtual WeekDay::eWeekDay fromPartialString(const String& stringRep) const;

	
};

%rename(MonthWeekImpl) MonthWeek ;
class   MonthWeek 
	: public Enum {

public:

	typedef enum 
	{ 
		First    = 1,
        Second   = 2,
        Third    = 3,
        Fourth   = 4,
        Fifth    = 5
         
	} eWeekOfMonth;

	 
	MonthWeek();
	static const MonthWeek& instance();
	virtual String toString(MonthWeek::eMonthWeek unit) const;
	virtual MonthWeek::eMonthWeek fromString(const String& stringRep) const;
	virtual MonthWeek::eMonthWeek fromPartialString(const String& stringRep) const;
	
};

%rename(DayImpl) Day;
class Day :
	public DatePart{

public:

	// utilities 
	virtual Integer daysBetween(const Day& other) const;
	

};


%rename(DayOfMonthImpl) DayOfMonth;
class DayOfMonth : 
	public Day{

public:
	
	//constructors 
	DayOfMonth(); 
	
	//operators - arithmetic 
	virtual DayOfMonth& operator+=(Integer increment);
	virtual DayOfMonth& operator-=(Integer value);
	
	%extend {
		static const Integer dayOfMonthMax(){
			return DateTimeConstants::dayOfMonthMax();
		}
		static const Integer dayOfMonthMin(){
			return DateTimeConstants::dayOfMonthMin();
		}
	 
	}

};

%rename(MonthImpl) Month;
class Month 
	:  public DatePart{

public:

	
	Month();
	

	//operators 
	virtual Month& operator+=(Integer increment);
	virtual Month& operator-=(Integer increment);
	
    
	//utilities
	virtual Integer monthsBetween(const Month& month) const;
	
	%extend {
	static const Integer monthMax(){
		return DateTimeConstants::monthMax();
	}
	static const Integer monthMin(){
		return DateTimeConstants::monthMin();
	}
	 
	}

};

%rename(YearImpl) Year;
class Year 
	:	public DatePart{

public:

	Year();
  

	//operators
	virtual Year& operator+=(Integer increment);
	virtual Year& operator-=(Integer value);
	
	
	//utilities 
	virtual Bool isLeapYear() const;
	virtual Integer yearsBetween(const Year& year) const;
	
	%extend {
	static const Integer yearMax(){
		return DateTimeConstants::yearMax();
	}
	static const Integer yearMin(){
		return DateTimeConstants::yearMin();
	}
	 
	}

};

%rename(DaysImpl) Days;
class Days 
	:  public Day{

public:

	
	Days();
	

	//operators 
	virtual Days& operator+=(Integer increment);
	virtual Days& operator-=(Integer increment);
	
   
	%extend {
		static const Integer daysMax(){
			return DateTimeConstants::daysMax();
		}
		static const Integer daysMin(){
			return DateTimeConstants::daysMin();
		}
	 
	}
	

};


%rename(DateImpl) Date;

class Date {

public:
	//constructors 
	 
	Date();
	Date(const String& isoDate);// "20081201"
	Date(BigInteger ymd);  //20081201
	Date(const Year& year, const Month& month, const DayOfMonth& day);
	Date(Integer year, Integer month, Integer day);
	virtual ~Date();
	
	//utilities - general
	%extend {
		Date& copyFrom(const Date& rhs)
		{
			self->operator=(rhs);
			return *self;
		}
	}
	virtual		Integer daysBetween(const Date& other) const;
	virtual		BigInteger asInteger() const; /**< 20081201*/ 
	
	//utilities - year
	virtual		Integer yearAsInteger() const;
	virtual		Bool  isLeapYear() const;
	
	//utilities - month
	virtual		Integer monthAsInteger() const;
	virtual		Integer dayOfMonthAsInteger() const;
	
	%extend {
		String weekDayAsString()
		{
			WeekDay::eWeekDay day = self->weekDay();
			return WeekDay::instance().toString(day);
		}
	}

	//utilities - week
	virtual		Integer weekNumber() const;
	
	//utilities - day
	virtual		BigInteger modJulianDay() const;
	virtual		BigInteger julianDay() const;
	
	//operators
	Bool operator==(const Date& other) const;
	Bool operator!=(const Date& other) const;
	
	Bool operator<(const Date& other) const;
    Bool operator<=(const Date& other) const;
     
    Bool operator>(const Date& other) const;
    Bool operator>=(const Date& other) const;
	
	
	//operators - arithmetic - addition 
	Date& operator+=(BigInteger days);

	virtual void addDay(BigInteger days);
	virtual void addWeek(BigInteger weeks);
	virtual void addMonth(BigInteger months);
	virtual void addYear(BigInteger years);
	

	//operators - arithmetic - substraction  
	Date& operator-=(BigInteger days);
	

	virtual void subtractDay(BigInteger days);
	virtual void subtractWeek(BigInteger week);
	virtual void subtractMonth(BigInteger months);
	virtual void subtractYear(BigInteger years);

	%extend {
	static const Date& maxDate(){
		return DateUtil::maxDate();
	}
	static const Date& minDate(){
		return DateUtil::minDate();
	}
	 
	}
	
	
};



typedef std::set<Date> SetDate;
typedef std::vector<Date> VectorDate;
typedef std::set<WeekDay::eWeekDay> SetWeekDay;
typedef std::set<String> SetString;







