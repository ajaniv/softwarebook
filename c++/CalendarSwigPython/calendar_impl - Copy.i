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
%module calendar_impl

%include core.i
%include datetime.i

%shared_ptr(Calendar)
%shared_ptr(BusinessCalendar)
%shared_ptr(CalendarRule)
%shared_ptr(DateRule)
%shared_ptr(SpecificDateRule)
%shared_ptr(CalendarCache)





%inline %{


//static PyObject* pCalendarException; 

//Initialization classes

#include "constrained/BoostConstrainingTypeComponentManager.hpp"
#include "datetime/BoostDateTimeComponentManager.hpp"



//Business Classes

#include "calendar/CalendarRule.hpp"
#include "calendar/BusinessCalendar.hpp"
#include "calendar/DateRule.hpp"
#include "calendar/SpecificDateRule.hpp"
#include "calendar/data/DataLoader.hpp"
#include "calendar/CalendarCache.hpp"
%}








%init %{

 
   // pCalendarException = PyErr_NewException("_calendar_impl.CalendarException", NULL, NULL);
    //Py_INCREF(pCalendarException);
    //PyModule_AddObject(m, "CalendarException", pCalendarException);
 

	ondalear::logging::log4cppimpl::Log4cppComponentManager::bootstrap();
	ondalear::xml::xercesimpl::XercesComponentManager::bootstrap();
	ondalear::constrained::boostimpl::BoostConstrainingTypeComponentManager::bootstrap();
	ondalear::datetime::boostimpl::BoostDateTimeComponentManager::bootstrap();
	
	LoggingConfig config;
	config.setDefaults();
	LoggingConfigurator& configurator = LoggingConfigurator::instance();
	configurator.initialize();
	configurator.apply(config);
	
	XMLConfigurator::instance().initialize();
%}





//%pythoncode %{
  //  CalendarException = _calendar_impl.CalendarException
//%}


//%rename(CalendarRuleImpl) CalendarRule;
typedef boost::shared_ptr<CalendarRule> CalendarRuleSharedPtr;
class CalendarRule{
public:

	/* constructors */
	CalendarRule();  
	CalendarRule(const String& ruleName);  
	CalendarRule(const CalendarRule& other);
	virtual ~CalendarRule();

	%extend {
		static CalendarRuleSharedPtr createCalendarRuleSmartPtr(){
			CalendarRuleSharedPtr rulePtr (new CalendarRule());
			return rulePtr;
		}
	}
	
	/* operators  */
	%extend {
		CalendarRule& copyFrom(const CalendarRule& rhs)
		{
			self->operator=(rhs);
			return *self;
		}
	}
	Bool operator==(const CalendarRule& other);
	Bool operator!=(const CalendarRule& other);
	//@}

	/* mutators */
	 
	virtual void setRuleName(const String& name);
	virtual void setEnabledFlag(Bool value);
	virtual void setStartEffectiveDate(const Date& date);
	virtual void setEndEffectiveDate(const Date& date);
	

	/* accessors */
	 
	virtual const String& getRuleName() const;
	virtual Bool  isEnabled() const;
	virtual Bool  getCanCalcWeekendFlag() const;
	virtual Bool  getCanCalcDateFlag() const;
	virtual const Date& getStartEffectiveDate() const;
	virtual const Date& getEndEffectiveDate() const;
	 
};

%extend CalendarRule {
%pythoncode {
    rule_name = property(getRuleName, setRuleName)
	} 
}

typedef boost::shared_ptr<DateRule> DateRuleSharedPtr;
class   DateRule
	: public CalendarRule {
public:

	virtual void setIgnoreFridayMonthEndFlag(Bool value);
	 
};

typedef boost::shared_ptr<SpecificDateRule> SpecificDateRuleSharedPtr;
class SpecificDateRule 
	: public DateRule{
public:

	 
	SpecificDateRule();
 
	%extend {
		static SpecificDateRuleSharedPtr createSmartPtr(){
			SpecificDateRuleSharedPtr rulePtr (new SpecificDateRule());
			return rulePtr;
		}
	}
	virtual void setSpecifiedDate(const Date& date);
	virtual const Date& getSpecifiedDate() const;
	 
 
	virtual SetDate calcDate(const Year& year) const;

};


typedef boost::shared_ptr<Calendar> CalendarSharedPtr;
class Calendar {
public:

	/* constructors */
	Calendar();
	Calendar(const String& calendarName);
	Calendar(const Calendar& other);
	virtual ~Calendar();
	
	/* operators  */
	%extend {
		Calendar& copyFrom(const Calendar& rhs)
		{
			self->operator=(rhs);
			return *self;
		}
	}
	Bool operator==(const Calendar& other);
	Bool operator!=(const Calendar& other);
	
	/* accessors  */
	virtual const String getCalendarName() const;
	virtual void setCalendarName(const String& name);
	
	/* structure  */ 
	 
    virtual void addRule(const CalendarRuleSharedPtr& rule);
	virtual void removeRule(const String& ruleName);
	virtual CalendarRules::const_iterator beginRules() const;
	virtual CalendarRules::const_iterator endRules() const;
	virtual const CalendarRule& findRule(const String& ruleName) const;
	 
	/* utilities  */ 
	virtual Bool isEmpty() const;
	virtual Size size() const;
	virtual Bool ruleExists(const String& ruleName) const;
	
};

typedef boost::shared_ptr<BusinessCalendar> BusinessCalendarSharedPtr;
class  BusinessCalendar : public Calendar{
public:

	/* constructors */
	BusinessCalendar();
	BusinessCalendar(const String& name);
	BusinessCalendar(const BusinessCalendar& other);
	
	/* operators  */
	%extend {
		BusinessCalendar& copyFrom(const BusinessCalendar& rhs)
		{
			self->operator=(rhs);
			return *self;
		
		}
		static BusinessCalendarSharedPtr fromCalendar(const CalendarSharedPtr cal){
			BusinessCalendarSharedPtr busCal = boost::dynamic_pointer_cast<BusinessCalendar> (cal);;
			return busCal;
		}
	}
	
	virtual Bool isBusinessDay(const Date& date) const;
    virtual Bool isHoliday(const Date& date) const;

};

typedef boost::shared_ptr<CalendarCache> CalendarCacheSharedPtr;

class   CalendarCache {

public:

	 
	CalendarCache();
	 
 
	virtual const String getCacheName() const;
	virtual void setCacheName(const String& name);
 

	/** @name public structure  */ 
	//@{
    virtual void add(const CalendarSharedPtr& calendar);
	 
	virtual void remove(const String& calendarName);
 
	virtual const CalendarSharedPtr find(const String& calendarName) const;
	
	//@}

	/** @name public utilities  */ 
	//@{
	virtual Bool isEmpty() const;
	virtual Size size() const;

	virtual Bool calendarExists(const String& calendarName) const;
	 
	virtual void merge(const CalendarCache& other);
	//@}

  
};

class   DataLoader {
	 

public:
	
	
	 
	static  const CalendarCacheSharedPtr loadFromXml(const String& grammarFile,
		const String& xmlFile);
	
	 

};

%exception; 
namespace std {
   
   %template(DoubleVector) vector<double>;
   %template(SetDate) set<Date>;
}


