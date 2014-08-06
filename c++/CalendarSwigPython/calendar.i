/**
 * \file calendar.i
 * \brief Calendar swig python interface file  
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
%include datetime.i

%shared_ptr(Calendar)
%shared_ptr(BusinessCalendar)
%shared_ptr(CalendarRule)
%shared_ptr(WeekendRule)
%shared_ptr(DateRule)
%shared_ptr(SpecificDateRule)
%shared_ptr(MonthDayRule)
%shared_ptr(MonthWeekDayRule)
%shared_ptr(LastDayMonthRule)
%shared_ptr(FirstDayMonthRule)
%shared_ptr(DerivedRule)
%shared_ptr(DaysOffsetRule)
%shared_ptr(FirstDayAtOrBeforeRule)
%shared_ptr(CalendarCache)

%inline %{

//Business Classes
#include "calendar/CalendarRule.hpp"
#include "calendar/WeekendRule.hpp"
#include "calendar/DateRule.hpp"
#include "calendar/SpecificDateRule.hpp"
#include "calendar/MonthDayRule.hpp"
#include "calendar/MonthWeekDayRule.hpp"
#include "calendar/LastDayMonthRule.hpp"
#include "calendar/FirstDayMonthRule.hpp"
#include "calendar/DerivedRule.hpp"
#include "calendar/DaysOffsetRule.hpp"
#include "calendar/FirstDayAtOrBeforeRule.hpp"

#include "calendar/RuleContainerTypes.hpp"
#include "calendar/BusinessCalendar.hpp"
#include "calendar/data/DataLoader.hpp"
#include "calendar/CalendarCache.hpp"
%}







%rename(CalendarRuleImpl) CalendarRule;
typedef boost::shared_ptr<CalendarRule> CalendarRuleSharedPtr;
class CalendarRule{
public:

	//constructors 
	CalendarRule();
	virtual ~CalendarRule();

	%extend {
		static CalendarRuleSharedPtr createCalendarRuleSmartPtr(){
			CalendarRuleSharedPtr rulePtr (new CalendarRule());
			return rulePtr;
		}
	}
	
	//utilities
	%extend {
		CalendarRule& copyFrom(const CalendarRule& rhs)
		{
			self->operator=(rhs);
			return *self;
		}
		
		const String className() const 
		{
			String typeName = self->className();
			return typeName + "Impl";
		}
	}
	
	//operators
	Bool operator==(const CalendarRule& other);
	Bool operator!=(const CalendarRule& other);
	

	// mutators 
	 
	virtual void setRuleName(const String& name);
	virtual void setHolidayName(const String& name);
	virtual void setEnabledFlag(Bool value);
	virtual void setStartEffectiveDate(const Date& date);
	virtual void setEndEffectiveDate(const Date& date);
	

	//accessors 
	virtual const String& getRuleName() const;
	virtual const String& getHolidayName() const;
	virtual Bool  isEnabled() const;
	virtual Bool  getCanCalcWeekendFlag() const;
	virtual Bool  getCanCalcDateFlag() const;
	virtual const Date& getStartEffectiveDate() const;
	virtual const Date& getEndEffectiveDate() const;
	%extend {
		virtual Bool getEnabledFlag() const
		{
			 
			return self->isEnabled();
		}
	}
	 
};

typedef std::set<CalendarRuleSharedPtr, CalendarRuleSharedPtrLessThan> CalendarRules;

%rename(WeekendRuleImpl) WeekendRule;
typedef boost::shared_ptr<WeekendRule> WeekendRuleSharedPtr;

class   WeekendRule 
	: public CalendarRule {

public:

	//constructors
	WeekendRule();
	
	//operators
	Bool operator==(const WeekendRule& other);
	Bool operator!=(const WeekendRule& other);
	
	%extend {
		static WeekendRuleSharedPtr downCast(const CalendarRuleSharedPtr& rule)
		{
			WeekendRuleSharedPtr downCastRule = 
				boost::dynamic_pointer_cast<WeekendRule> (rule);
			return downCastRule;
		}
	 }
	 
	//accessors
	
	%extend {
		SetString weekendDaysAsStringSet()
		{
			const SetWeekDay& weekDays = self->getWeekendDays();
			SetString days;
			for (SetWeekDay::const_iterator iter = weekDays.begin();
				iter != weekDays.end(); ++iter) {
					days.insert(WeekDay::instance().toString(*iter));
			}
			 
			return days;
		}
	}
	 
	//structure
	%extend {
		virtual void addDay(const String& dayName)
		{
			self->addDay(WeekDay::instance().fromPartialString(dayName));
			 
		}
		virtual void removeDay(const String& dayName)
		{
			self->removeDay(WeekDay::instance().fromPartialString(dayName));
			 
		}
	}
	 
	//date calculation
	
	virtual SetDate weekendsForYear(const Year& year) const;
	%extend {
		virtual Bool isWeekend(const String& dayName) const
		{
			return self->isWeekend(WeekDay::instance().fromPartialString(dayName));
			 
		}
		virtual Bool isWeekendForYear(const Year& year, const String& dayName) const
		{
			return self->isWeekend(year, WeekDay::instance().fromPartialString(dayName));
		}
		 
	}
	 

	//utilities
	virtual Size size() const;
	virtual Bool isEmpty() const;

	virtual CalendarRule* clone() const;
	
	%extend {
		WeekendRule& copyFrom(const WeekendRule& rhs)
		{
			self->operator=(rhs);
			return *self;
		}
	}


};


%rename(DateRuleImpl) DateRule;
typedef boost::shared_ptr<DateRule> DateRuleSharedPtr;
class   DateRule
	: public CalendarRule {
public:

	//constructors
	DateRule();
	
	//operators
	Bool operator==(const DateRule& other);
	Bool operator!=(const DateRule& other);
	
	
	// accessors 
	
	virtual void setWeekendRule(const WeekendRuleSharedPtr& rule);
	virtual void setHolidayDuration(const HolidayDuration& duration);

	virtual void setIgnoreFridayMonthEndFlag(Bool value);
	virtual void setAddNextYearFlag(Bool value);
	virtual void setAddPriorYearFlag(Bool value);
	
	%extend {
		virtual void setWeekendAdjustment(const String& adjustmentName)
		{
			self->setWeekendAdjustment(WeekendAdjustment::instance().fromPartialString(adjustmentName));
			 
		}
		virtual String getWeekendAdjustment() const
		{
			WeekendAdjustment::eWeekendAdjustment adjustment = self->getWeekendAdjustment();
			return WeekendAdjustment::instance().toString(adjustment);
			 
		}
		
		SetString weekendDaysAsStringSet()
		{
			const SetWeekDay weekDays = self->weekendDays();
			SetString days;
			for (SetWeekDay::const_iterator iter = weekDays.begin();
				iter != weekDays.end(); ++iter) {
					days.insert(WeekDay::instance().toString(*iter));
			}
			 
			return days;
		}
	}

	// accessors getters
	
	virtual const WeekendRuleSharedPtr& getWeekendRule() const;
	
	virtual const HolidayDuration& getHolidayDuration() const;

	virtual const Bool getIgnoreFridayMonthEndFlag() const;
	virtual const Bool getAddNextYearFlag() const;
	virtual const Bool getAddPriorYearFlag() const;
	 
	 
	//date calculations 
	virtual SetDate calcDate(const Year& year) const;
	virtual Bool skipDate(const Date& date) const;
 
	//utilities  
	virtual void setExceptionsForYear(const Year& year, const SetDate& dates);
	virtual const SetDate getExceptionsForYear(const Year& year) const;
	
	%extend {
		DateRule& copyFrom(const DateRule& rhs)
		{
			self->operator=(rhs);
			return *self;
		}
	}
	 
};

%rename(SpecificDateRuleImpl) SpecificDateRule;
typedef boost::shared_ptr<SpecificDateRule> SpecificDateRuleSharedPtr;

class SpecificDateRule 
	: public DateRule{
public:

	 
	SpecificDateRule();
 
	//operators
	Bool operator==(const SpecificDateRule& other);
	Bool operator!=(const SpecificDateRule& other);
	%extend {
		SpecificDateRule& copyFrom(const SpecificDateRule& rhs)
		{
			self->operator=(rhs);
			return *self;
		}
		
		static SpecificDateRuleSharedPtr downCast(const CalendarRuleSharedPtr& rule)
		{
			SpecificDateRuleSharedPtr downCastRule = boost::dynamic_pointer_cast<SpecificDateRule> (rule);
			return downCastRule;
		}
	}
	
	//accessors
	virtual void setSpecifiedDate(const Date& date);
	virtual const Date& getSpecifiedDate() const;
	 
 
	virtual SetDate calcDate(const Year& year) const;
	
	

};


%rename(MonthDayRuleImpl) MonthDayRule;
typedef boost::shared_ptr<MonthDayRule> MonthDayRuleSharedPtr;

class MonthDayRule 
	: public DateRule{
public:

	 
	MonthDayRule();
 
	//operators
	Bool operator==(const MonthDayRule& other);
	Bool operator!=(const MonthDayRule& other);
	%extend {
		MonthDayRule& copyFrom(const MonthDayRule& rhs)
		{
			self->operator=(rhs);
			return *self;
		}
		
		static MonthDayRuleSharedPtr downCast(const CalendarRuleSharedPtr& rule)
		{
			MonthDayRuleSharedPtr downCastRule = boost::dynamic_pointer_cast<MonthDayRule> (rule);
			return downCastRule;
		}
	}
	
	//accessors
	 
 
	virtual void setMonth(const Month& month);
	virtual const Month& getMonth() const;
	
	virtual void setDayOfMonth (const DayOfMonth& dayOfMonth);
	virtual const DayOfMonth& getDayOfMonth() const;
	 
	 
 
	virtual SetDate calcDate(const Year& year) const;
	
	

};


%rename(MonthWeekDayRuleImpl) MonthWeekDayRule;
typedef boost::shared_ptr<MonthWeekDayRule> MonthWeekDayRuleSharedPtr;

class MonthWeekDayRule 
	: public DateRule{
public:

	 
	MonthWeekDayRule();
 
	//operators
	Bool operator==(const MonthWeekDayRule& other);
	Bool operator!=(const MonthWeekDayRule& other);
	%extend {
		MonthWeekDayRule& copyFrom(const MonthWeekDayRule& rhs)
		{
			self->operator=(rhs);
			return *self;
		}
		
		static MonthWeekDayRuleSharedPtr downCast(const CalendarRuleSharedPtr& rule)
		{
			MonthWeekDayRuleSharedPtr downCastRule = boost::dynamic_pointer_cast<MonthWeekDayRule> (rule);
			return downCastRule;
		}
	}
	
	//accessors
	 
 
	virtual void setMonth(const Month& month);
	virtual const Month& getMonth() const;
	

	%extend {
		void setMonthWeek(const String& weekName) 
		{
			self->setMonthWeek(MonthWeek::instance().fromPartialString(weekName));
		}
		String getMonthWeek() const
		{
			return MonthWeek::instance().toString(self->getMonthWeek());
		}
		
		void setWeekDay(const String& dayName) 
		{
			self->setWeekDay(WeekDay::instance().fromPartialString(dayName));
		}
		String getWeekDay() const
		{
			return WeekDay::instance().toString(self->getWeekDay());
		}
	}
	 
	 
	//calculations
	virtual SetDate calcDate(const Year& year) const;
	
	

};

%rename(LastDayMonthRuleImpl) LastDayMonthRule;
typedef boost::shared_ptr<LastDayMonthRule> LastDayMonthRuleSharedPtr;

class LastDayMonthRule 
	: public DateRule{
public:

	 
	LastDayMonthRule();
 
	//operators
	Bool operator==(const LastDayMonthRule& other);
	Bool operator!=(const LastDayMonthRule& other);
	%extend {
		LastDayMonthRule& copyFrom(const LastDayMonthRule& rhs)
		{
			self->operator=(rhs);
			return *self;
		}
		
		static LastDayMonthRuleSharedPtr downCast(const CalendarRuleSharedPtr& rule)
		{
			LastDayMonthRuleSharedPtr downCastRule = boost::dynamic_pointer_cast<LastDayMonthRule> (rule);
			return downCastRule;
		}
	}
	
	//accessors
	 
 
	virtual void setMonth(const Month& month);
	virtual const Month& getMonth() const;
	

	%extend {
		 
		void setWeekDay(const String& dayName) 
		{
			self->setWeekDay(WeekDay::instance().fromPartialString(dayName));
		}
		String getWeekDay() const
		{
			return WeekDay::instance().toString(self->getWeekDay());
		}
	}
	 
	 
	//calculations
	virtual SetDate calcDate(const Year& year) const;
	
	

};

%rename(FirstDayMonthRuleImpl) FirstDayMonthRule;
typedef boost::shared_ptr<FirstDayMonthRule> FirstDayMonthRuleSharedPtr;

class FirstDayMonthRule 
	: public DateRule{
public:

	 
	FirstDayMonthRule();
 
	//operators
	Bool operator==(const FirstDayMonthRule& other);
	Bool operator!=(const FirstDayMonthRule& other);
	%extend {
		FirstDayMonthRule& copyFrom(const FirstDayMonthRule& rhs)
		{
			self->operator=(rhs);
			return *self;
		}
		
		static FirstDayMonthRuleSharedPtr downCast(const CalendarRuleSharedPtr& rule)
		{
			FirstDayMonthRuleSharedPtr downCastRule = boost::dynamic_pointer_cast<FirstDayMonthRule> (rule);
			return downCastRule;
		}
	}
	
	//accessors
	 
 
	virtual void setMonth(const Month& month);
	virtual const Month& getMonth() const;
	

	%extend {
		 
		void setWeekDay(const String& dayName) 
		{
			self->setWeekDay(WeekDay::instance().fromPartialString(dayName));
		}
		String getWeekDay() const
		{
			return WeekDay::instance().toString(self->getWeekDay());
		}
	}
	 
	 
	//calculations
	virtual SetDate calcDate(const Year& year) const;
	
	

};

%rename(DerivedRuleImpl) DerivedRule;
typedef boost::shared_ptr<DerivedRule> DerivedRuleSharedPtr;

class DerivedRule 
	: public DateRule{
public:
	
	//constructors
	DerivedRule();
	
	//operators
	Bool operator==(const DerivedRule& other);
	Bool operator!=(const DerivedRule& other);
	%extend {
		DerivedRule& copyFrom(const DerivedRule& rhs)
		{
			self->operator=(rhs);
			return *self;
		}
	}
	
	virtual void setUnderlying (const DateRuleSharedPtr& underlying);
	virtual const DateRuleSharedPtr& getUnderlying() const;
	 
};


%rename(DaysOffsetRuleImpl) DaysOffsetRule;
typedef boost::shared_ptr<DaysOffsetRule> DaysOffsetRuleSharedPtr;

class DaysOffsetRule 
	: public DerivedRule{
public:

	 
	DaysOffsetRule();
 
	//operators
	Bool operator==(const DaysOffsetRule& other);
	Bool operator!=(const DaysOffsetRule& other);
	%extend {
		DaysOffsetRule& copyFrom(const DaysOffsetRule& rhs)
		{
			self->operator=(rhs);
			return *self;
		}
		
		static DaysOffsetRuleSharedPtr downCast(const CalendarRuleSharedPtr& rule)
		{
			DaysOffsetRuleSharedPtr downCastRule = boost::dynamic_pointer_cast<DaysOffsetRule> (rule);
			return downCastRule;
		}
	}
	
	//accessors
	 
 
	virtual void setOffset(const Days& days);
	virtual const Days& getOffset() const;
	
	//calculations
	virtual SetDate calcDate(const Year& year) const;
	
	

};


%rename(FirstDayAtOrBeforeRuleImpl) FirstDayAtOrBeforeRule;
typedef boost::shared_ptr<FirstDayAtOrBeforeRule> FirstDayAtOrBeforeRuleSharedPtr;

class FirstDayAtOrBeforeRule 
	: public DerivedRule{
public:

	 
	FirstDayAtOrBeforeRule();
 
	//operators
	Bool operator==(const FirstDayAtOrBeforeRule& other);
	Bool operator!=(const FirstDayAtOrBeforeRule& other);
	%extend {
		FirstDayAtOrBeforeRule& copyFrom(const FirstDayAtOrBeforeRule& rhs)
		{
			self->operator=(rhs);
			return *self;
		}
		
		static FirstDayAtOrBeforeRuleSharedPtr downCast(const CalendarRuleSharedPtr& rule)
		{
			FirstDayAtOrBeforeRuleSharedPtr downCastRule = boost::dynamic_pointer_cast<FirstDayAtOrBeforeRule> (rule);
			return downCastRule;
		}
		
		void setWeekDay(const String& dayName) 
		{
			self->setWeekDay(WeekDay::instance().fromPartialString(dayName));
		}
		String getWeekDay() const
		{
			return WeekDay::instance().toString(self->getWeekDay());
		}
	}
	
	virtual void setStartAtFlag (const Bool value);
	virtual const Bool getStartAtFlag() const;
	 
	 
	//calculations
	virtual SetDate calcDate(const Year& year) const;
	
	

};


%rename(CalendarImpl) Calendar;
typedef boost::shared_ptr<Calendar> CalendarSharedPtr;

class Calendar {
public:

	// constructors  
	Calendar();
	virtual ~Calendar();
	
	//operators  
	%extend {
		Calendar& copyFrom(const Calendar& rhs)
		{
			self->operator=(rhs);
			return *self;
		}
		
		const String className() const 
		{
			String typeName = self->className();
			return typeName + "Impl";
		}
		
	}
	Bool operator==(const Calendar& other);
	Bool operator!=(const Calendar& other);
	
	// accessors  
	virtual const String getCalendarName() const;
	virtual void setCalendarName(const String& name);
	
	/* structure  */ 
    virtual void addRule(const CalendarRuleSharedPtr& rule);
	virtual void removeRule(const String& ruleName);

	virtual const CalendarRule& findRule(const String& ruleName) const;
	%extend {
		CalendarRules rules()
		{
			CalendarRules rules;
			for (CalendarRules::const_iterator iter = self->beginRules();
				iter != self->endRules(); ++iter) {
					rules.insert(*iter);
			}
			return rules;
		}
	}
	 
	/* utilities  */ 
	virtual Bool isEmpty() const;
	virtual Size size() const;
	virtual Bool ruleExists(const String& ruleName) const;
	
};

%rename(BusinessCalendarImpl) BusinessCalendar;
typedef boost::shared_ptr<BusinessCalendar> BusinessCalendarSharedPtr;
class  BusinessCalendar : public Calendar{
public:

	/* constructors */
	BusinessCalendar();
	
	
	/* operators  */
	%extend {
		BusinessCalendar& copyFrom(const BusinessCalendar& rhs)
		{
			self->operator=(rhs);
			return *self;
		
		}
		static BusinessCalendarSharedPtr downCast(const CalendarSharedPtr cal){
			BusinessCalendarSharedPtr busCal = boost::dynamic_pointer_cast<BusinessCalendar> (cal);;
			return busCal;
		}
	}
	
	//Business Dates
	virtual Bool isBusinessDay(const Date& date) const;
    virtual Bool isHoliday(const Date& date) const;
    

    virtual Bool isEndOfMonth(const Date& date) const;
	virtual Date endOfMonth(const Date& date) const;

	
	%extend {
		virtual Bool isWeekend(const String& dayName) const
		{
			return self->isWeekend(WeekDay::instance().fromPartialString(dayName));
			 
		}
		virtual Bool isWeekendForYear(const Date& refDate, const String& dayName) const
		{
			return self->isWeekend(refDate, WeekDay::instance().fromPartialString(dayName));
		}
		virtual Bool isWeekendForDate(const Date& date) const
		{
			return self->isWeekend(date);
		}
	 
		 
	}
	
	//structure  
    virtual void addRule(const CalendarRuleSharedPtr& rule);
	virtual void removeRule(const String& ruleName);
	virtual BusinessCalendar add(const BusinessCalendar& other) const;
	
	
	//utilities 
	virtual Calendar* clone() const;
	virtual SetDate businessDays(const Date& from, const Date& to) const;
    virtual SetDate holidays(const Date& from, const Date& to) const;
	virtual SetDate weekends(const Date& from, const Date& to) const;
	
	virtual SetDate holidaysAndWeekends(const Date& from, const Date& to) const;
	virtual SetDate holidaysForYear(const Year& year) const;
	%extend {
		virtual SetDate weekendsForYear(const Year& year) const
		{
			return self->weekends(year);
			 
		}
	}
	


};

%rename(CalendarCacheImpl) CalendarCache;
typedef boost::shared_ptr<CalendarCache> CalendarCacheSharedPtr;

class   CalendarCache {

public:

	 
	CalendarCache();
	 
 
	virtual const String getCacheName() const;
	virtual void setCacheName(const String& name);
 

	//structure 
    virtual void add(const CalendarSharedPtr& calendar);
	virtual void remove(const String& calendarName);
	virtual const CalendarSharedPtr find(const String& calendarName) const;
	
	

	//utilities
	virtual Bool isEmpty() const;
	virtual Size size() const;
	virtual Bool calendarExists(const String& calendarName) const;
	virtual void merge(const CalendarCache& other);
	
	virtual CalendarMap::const_iterator begin() const;
	virtual CalendarMap::const_iterator end() const;
	%extend {
		SetString calendarNames()
		{
			CalendarMap::const_iterator iter;
			SetString names;
			for (iter = self->begin(); iter != self->end(); ++iter){
				names.insert(iter->first);
			}
			return names;
		}
	}

  
};

%rename(DataLoaderImpl) DataLoader;
class   DataLoader {
	 

public:
	
	
	 
	static  const CalendarCacheSharedPtr loadFromXmlFile(const String& grammarFile,
		const String& xmlFile);
	
	 

};



