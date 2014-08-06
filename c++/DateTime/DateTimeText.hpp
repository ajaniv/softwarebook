/**
 * \file DateTimeText.hpp
 * \brief Date time text header file
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
#ifndef ONDALEAR_DATETIME_DateTimeText_HPP
#define ONDALEAR_DATETIME_DateTimeText_HPP



 
#include "core/CoreIncludes.hpp"
#include "core/Text.hpp"



namespace ondalear {
namespace datetime {

/**
 * @todo:  DateTimeText - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  DateTimeText - attributes/methods -  completeness/need/correctness
 * @todo:  DateTimeText - unit test completeness/need/correctness
 * @todo:  DateTimeText - doc - completeness/correctness
 */

/**
  * \class DateTimeText
  * \brief Date time text facilities
  *  Defined for reuse and internationalization
  */



class CORE_API DateTimeText 
	: public Text {
	
public:
	/** @name public constructors */
	//@{
	static const DateTimeText& instance();
	//@}

	/** @name validation */
	//@{
	virtual String invalidDateString(const String& date, const String& errorDetail) const; 
	virtual String invalidDateArgs(Integer year, Integer month, Integer day, const String& errorDetail) const;
	virtual String dateCreationFailure(const String& errorDetail) const;
	virtual String invalidDatePeriod(const String& start, const String& end) const;

	//@}
	 

	/** @name conversion */
	//@{
	virtual String toStringConversionFailure(Integer year, Integer month, Integer day, const String& errorDetail) const;
	//@}
};


}//namespace datetime
}//namespace ondalear




DECLARE_USING_TYPE(ondalear::datetime,DateTimeText);


#endif //ONDALEAR_CORE_DateTimeText_HPP
