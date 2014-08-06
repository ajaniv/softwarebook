/**
 * \file DataDrivenCalendarTest.hpp
 * \brief Calendar data driven  test        header file
 *
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
#ifndef ONDALEAR_TEST_DataDrivenCalendarTest_HPP
#define ONDALEAR_TEST_DataDrivenCalendarTest_HPP

#include "core/CoreIncludes.hpp"

#include "test/Unittest.hpp"

#include "calendar/CalendarCache.hpp"
#include "calendar/BusinessCalendar.hpp"

#include "CalendarTestData.hpp"

namespace ondalear {
namespace test {
namespace calendar {






/**
  * \class DataDrivenCalendarTest
  * \brief Base Data Driven   unit test
  *
  */
	
class CORE_API DataDrivenCalendarTest
	: public Unittest {

 

protected:



	/** @name protected constructors */
	//@{
	DataDrivenCalendarTest();
	//@}

	/** @name accessors */
	//@{
	virtual const String& getTestDataFileName() const;
	virtual const String& getTestDataGrammarFileName() const;

	virtual const String& getCalendarDataFileName() const;
	virtual const String& getCalendarDataGrammarFileName() const;
	
	virtual void setTestDataGrammarFileName(const String& fileName) ; 
	virtual void setTestDataFileName(const String& fileName);

	virtual void setCalendarDataFileName(const String& fileName);
	virtual void setCalendarDataGrammarFileName(const String& fileName) ;
	
	//@}

	/** @name protected data  access */
	//@{
	const CalendarTestData& testDataForYear(const Year& year) ;
	virtual void loadTestData(const String grammarFileName, 
		const String& testDataFileName);
	virtual void loadCalendarData(const String grammarFileName, 
		const String& calendarDefinitionFileName);

	String getDefaultCalendarTestDataSchema(){
		return "calendars_test.xsd";
	}
	String getDefaultCalendarSchema(){
		return "calendar.xsd";
	}
	//@}
	 
	/** @name test execution and result comparison */
	//@{
	virtual void runCalendaTest(const BusinessCalendar& cal,
										    const Year& year, Bool doDataDump=false);
	virtual void runCalendaTest(const BusinessCalendar& cal,
		   const CalendarTestData& testData, Bool doDataDump=false) const;
	//@}

	virtual CalendarSharedPtr getCalendar(const String& calendarName); 
	virtual BusinessCalendarSharedPtr getBusinessCalendar(const String& calendarName);


private:

	CalendarCacheSharedPtr calendarCache;
	CalendarTestDataContainerSharedPtr testDataContainer;

	String testDataFileName;
	String testDataGrammarFileName;

	String calendarDataFileName;
	String calendarDataGrammarFileName;


};



} //namespace calendar
} //namespace test
} //namespace ondalear



#endif //ONDALEAR_TEST_DataDrivenCalendarTest_HPP

