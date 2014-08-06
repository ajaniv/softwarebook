/**
 * \file DatePeriodSamples.cpp
 * \brief Date period usage samples source file
 *
 * A DatePeriod defines a date range on a time line with from/to dates.
 * The following samples focus on demonstrating key date period  features including:
 * - Creation of DatePeriod, including defaulting
 * - Defintion of a date range
 * - Date period utilities including validation, extending, contracting, shifting, intersection
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

#include <iostream>

#include "datetime/DatePeriod.hpp"

namespace ondalear {
namespace samples {
namespace datetime {

 
/* 
 * datePeriodSamples
 * Demonstrate date period related features
 *
 */
void
datePeriodSamples()
{
	/*
	 * Explore various ways of creation date periods
	 */
	Date refStart(20091225); //ISO date format
	Date refEnd(20101225);  //ISO date format
	Date today;  //defaults to today's date

	//Default initialization, range is from/to today
	DatePeriod period1;
	ASSERT(today == period1.getStart());
	ASSERT(today == period1.getEnd());

	//Copy constructor
	DatePeriod period2(period1);
	 
	//speficyfing date ranges (const Date& startDate, const Date& endDate)
	DatePeriod period3(refStart, refEnd);
 
	//specifying the period length in days to define its end
	DatePeriod period4(refStart, 365);
	ASSERT(refEnd == period4.getEnd());

	DatePeriod period5(refStart, Days(365));
	ASSERT(refEnd == period5.getEnd());

	//specifying the period length using a relative date specification (i.e. 1Y)
	DatePeriod period6(refStart, DateSpec("1Y"));
	ASSERT(refEnd == period6.getEnd());


	/*
	 * Excercise the accessor functionality
	 */
	DatePeriod period7;
	period7.setStart(refStart);
	ASSERT(refStart == period7.getStart());

	period7.setEnd(refEnd);
	ASSERT(refEnd == period7.getEnd());

	period7.update(refStart, refEnd);

	

	/*
	 * Explore date period general operators
	 */


	//operator = 
	DatePeriod assignA(Date(20101224), Date(20101231));
	DatePeriod assignB;
	assignB = assignA;
	 
	//operator == 
	ASSERT(assignA == assignB);

	//operator !=
	DatePeriod notEqual;
	ASSERT(assignA != notEqual);
	
	//operator < 
	DatePeriod lessThanA (Date(20101224), Date(20101231));
	DatePeriod lessThanB (Date(20111224), Date(20111231));
	ASSERT(lessThanA < lessThanB);

	//operator <= 
	ASSERT(lessThanA <= lessThanA);
	ASSERT(lessThanA < lessThanB);
     
	//operator > 
	ASSERT(lessThanB > lessThanA);

	//operator >= 
	ASSERT(lessThanA >= lessThanA);
	ASSERT(lessThanB > lessThanA);



	/*
	 * Explore utilities
	 */


	//Check for validity
	 
	Date startDate(20080228);
	Date endDate(20080229);

	ASSERT(true == DatePeriod::isValid(startDate, endDate));
	ASSERT(true == DatePeriod::isValid(startDate, startDate));
	ASSERT(false == DatePeriod::isValid(endDate, startDate));
	
	//Date period length
	DatePeriod lenPeriod;
	ASSERT(0 == lenPeriod.length());
	lenPeriod.setEnd(today + Days(1));
	ASSERT(1 == lenPeriod.length());

	//Check for proper  initialization.
	DatePeriod initPeriod;
	ASSERT(true == initPeriod.isEmpty());
	initPeriod.setEnd(Date() + Days(1));
	ASSERT(false == initPeriod.isEmpty());

	//Shift the start  and  end points in 'parallel' either to the left or right of the timeline
	DatePeriod shiftPeriod (Date(20101226), Date(20101228));
	shiftPeriod.shift(1);
	ASSERT(Date(20101227) == shiftPeriod.getStart());
	ASSERT(Date(20101229) == shiftPeriod.getEnd());

	//Extend the period by shifting the start to the left, the end to the right, in the timeline
	DatePeriod extendPeriod (Date(20101226), Date(20101228));
	extendPeriod.extend(1);
	ASSERT(Date(20101225) == extendPeriod.getStart());
	ASSERT(Date(20101229) == extendPeriod.getEnd());

	//Shrink by moving the start to the right, the end to the left, in the time line
	DatePeriod shrinkPeriod (Date(20101226), Date(20101228));
	shrinkPeriod.shrink(1);
	ASSERT(Date(20101227) == shrinkPeriod.getStart());
	ASSERT(Date(20101227) == shrinkPeriod.getEnd());

	//merge two date periods, which overlap
	DatePeriod mergePeriod1 (Date(20101226), Date(20101228));
	DatePeriod mergePeriod2 (Date(20101227), Date(20101229));
	DatePeriod mergePeriod3 = mergePeriod1.merge(mergePeriod2);

	ASSERT(Date(20101226) == mergePeriod3.getStart());
	ASSERT(Date(20101229) == mergePeriod3.getEnd())


	//merge two periods which do not overlap
	DatePeriod spanPeriod1 (Date(20101226), Date(20101228));
	DatePeriod spanPeriod2 (Date(20101228), Date(20101229));
	DatePeriod spanPeriod3 = spanPeriod1.span(spanPeriod2);
	ASSERT(Date(20101226) == spanPeriod3.getStart());
	ASSERT(Date(20101229) == spanPeriod3.getEnd());


	//Check if a date is within  period
	DatePeriod period20 (Date(20101228), Date(20101228));
	 
	ASSERT(false == period20.contains(Date(20101228)) );
	period20.setEnd(20101229);
	 
	ASSERT(true == period20.contains(Date(20101228)));
 
	
	//Check for intersection
 
	DatePeriod datePeriod21 (Date(20101228), Date(20101229));
	DatePeriod datePeriod22 (Date(20101228), Date(20101230));
 
	 
	//Derive period of intersection
	DatePeriod intersection  = datePeriod21.intersection(datePeriod22);
	ASSERT(Date( 20101228) == intersection.getStart());
	ASSERT(Date( 20101229) == intersection.getEnd());



	//Determine if two periods are adjacent
 
	DatePeriod adjacentPeriodA (Date(20101228), Date(20101230));
	DatePeriod adjacentPeriodB (Date(20101230), Date(20101231));
 
	ASSERT(true == adjacentPeriodA.isAdjacent(adjacentPeriodB));


	//Determine if two date periods intersect
	 
	DatePeriod intersectPeriodB (Date(20101228), Date(20101229));
	DatePeriod intersectPeriodC (Date(20101228), Date(20101230));
	 
	//intersects
	ASSERT(true == intersectPeriodB.intersects(intersectPeriodC));

	//check if after
	DatePeriod afterPeriod (Date(20101228), Date(20101229));
	 
	ASSERT(true == afterPeriod.isAfter(20101227));

	//check if before
	DatePeriod beforePeriod (Date(20101228), Date(20101229));
	ASSERT(true == beforePeriod.isBefore(20101230));


}



} //namespace datetime
} //namespace samples
} //namespace ondalear