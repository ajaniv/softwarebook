/**
 * \file DateTimeFactory.hpp
 * \brief Abstraction for creation of implementation specific classes header file 
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

#ifndef ONDALEAR_DATETIME_DateTimeFactory_HPP
#define ONDALEAR_DATETIME_DateTimeFactory_HPP



#include "core/CoreIncludes.hpp"
#include "core/ComponentFactory.hpp"



namespace ondalear {
namespace datetime {

/**
  * @todo:  DateTimeFactory - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  DateTimeFactory - attributes/methods -  completeness/need/correctness
  * @todo:  DateTimeFactory - unit test completeness/need/correctness
  * @todo:  DateTimeFactory - doc - completeness/correctness
  */


class BootstrapDateUtilImpl;
class DateImpl;
class Date;

/**
  * \class DatetimeFactory
  * \brief Abstraction for the creation of implementation specific instances
  *
  */

class CORE_API DateTimeFactory 
	: public ComponentFactory{

public:

	/** @name instance creation */
	//@{
	virtual BootstrapDateUtilImpl* createBootstrapDateUtilImpl() = 0;
	virtual DateImpl* createDateImpl() = 0;
	virtual DateImpl* createDateImpl(const DateImpl& other)  = 0;
	virtual DateImpl* createDateImpl(Integer year, Integer month, Integer day)  = 0;
	virtual DateImpl* createDateImpl(const String& isoDate) = 0;
	virtual DateImpl* createDateImpl(BigInteger ymd) = 0;

	virtual Date createDateFromDelimitedString(const String& dateString) = 0;
	virtual Date createLocal() = 0;
	virtual Date createUTC() = 0;
	 //@}

	//
	/** @name conversions */
	//@{
	virtual String toString(const Date& date) const = 0 ;
	virtual String toISOString(const Date& date) const = 0  ;
	virtual String toDelemetedISOString(const Date& date) const = 0 ;
	//@}

protected:
	/** @name protected constructors */
	//@{
	DateTimeFactory(const String& factoryName, const String& factoryVersion);
	DateTimeFactory();
	//@}

};

 
DECLARE_SHARED_POINTER(DateTimeFactory);

} //namespace datetime
} //namespace ondalear


DECLARE_USING_DEFAULT(ondalear::datetime,DateTimeFactory);



#endif //ONDALEAR_DATETIME_DateTimeFactory_HPP
