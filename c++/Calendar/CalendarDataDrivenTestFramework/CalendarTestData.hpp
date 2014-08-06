/**
 * \file CalendarTestData.hpp
 * \brief Test data for    calendar        header file
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
#ifndef ONDALEAR_TEST_CalendarTestData_HPP
#define ONDALEAR_TEST_CalendarTestData_HPP

#include "core/CoreIncludes.hpp"
#include "core/ManagedObject.hpp"

#include "test/Unittest.hpp"

#include "datetime/DateTimeContainerTypes.hpp"


namespace ondalear {
namespace test {
namespace calendar {



struct DateData{
	String name;
	Date date;
};

typedef std::vector <DateData> VectorDateData;

void dumpData(const VectorDateData& refHolidays, const VectorDate& resultHolidays);

/**
  * \struct CalendarTestData
  * \brief Base abstraction    calendar test data
  *
  */

struct CORE_API CalendarTestData{
	CalendarTestData(){};
	CalendarTestData( const Year& year, const SetDate& holidays, const Date& weekDay,
		const Date& weekendDay1, const Date& weekendDay2);
	
	virtual const Year& getYear() const { return this->year;} 
	virtual void  setYear(const Year& year) { this->year = year; }

	virtual const VectorDateData& getHolidays() const { return this->holidays; }
	virtual void  setHolidays(const VectorDateData& holidays) { this->holidays = holidays;}

	virtual const VectorDateData& getWeekDays() const { return this->weekDays; }
	virtual void  setWeekDays(const VectorDateData& weekDays) { this->weekDays = weekDays;}

	virtual const VectorDateData& getWeekEnds() const { return this->weekEnds; }
	virtual void  setWeekEnds(const VectorDateData& weekEnds) { this->weekEnds = weekEnds;}

	virtual const Date&  getWeekDay()     const { return this->weekDays[0].date; }
	virtual const Date&  getWeekendDay1() const { return this->getWeekEnds()[0].date; }
	virtual const Date&  getWeekendDay2() const { return this->getWeekEnds()[1].date; }
	 

	String name;
	Year year;
	 

	VectorDateData weekDays;
	VectorDateData weekEnds;
	VectorDateData holidays;

};







typedef boost::shared_ptr<CalendarTestData> CalendarTestDataSharedPtr;

typedef std::map<Year, CalendarTestDataSharedPtr> HolidayTestDataMap;

typedef boost::shared_ptr<HolidayTestDataMap> HolidayTestDataMapSharedPtr;


class CORE_API CalendarTestDataContainer : public ManagedObject {
public:
	CalendarTestDataContainer() {}
	CalendarTestDataContainer(const HolidayTestDataMapSharedPtr& testData) : testData(testData) {}
	const HolidayTestDataMapSharedPtr& getTestData() const {return testData;}
	void setTestData(const HolidayTestDataMapSharedPtr& testData) {this->testData = testData;}
private:
	HolidayTestDataMapSharedPtr testData;
};

DECLARE_SHARED_POINTER(CalendarTestDataContainer);




} //namespace calendar
} //namespace test
} //namespace ondalear



#endif //ONDALEAR_TEST_HolidayCalendarTestData_HPP

