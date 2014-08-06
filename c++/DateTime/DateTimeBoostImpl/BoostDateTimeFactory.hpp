/**
 * \file BoostDateTimeFactory.hpp
 * \brief Abstraction for creation of datetime implementation specific classes header file
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


#ifndef ONDALEAR_DATETIME_BoostDateTimeFactory_HPP
#define ONDALEAR_DATETIME_BoostDateTimeFactory_HPP



#include "core/CoreIncludes.hpp"

#include "../DateTimeFactory.hpp"



namespace ondalear {
namespace datetime {
namespace boostimpl {


/**
  * \class BoostDateTimeFactory
  * \brief Creation of boost dattime objects
  *
  */

class CORE_API BoostDateTimeFactory: 
	public DateTimeFactory{

public:
	/** @name public constructors */
	//@{

	BoostDateTimeFactory();
	 
	//@}
	 
	/** @name instance creation */
	//@{

	virtual BootstrapDateUtilImpl* createBootstrapDateUtilImpl() ;

	virtual DateImpl* createDateImpl();
	virtual DateImpl* createDateImpl(const DateImpl& other);
	virtual DateImpl* createDateImpl(Integer year, Integer month, Integer day);
	virtual DateImpl* createDateImpl(const String& isoDate);
	virtual DateImpl* createDateImpl(BigInteger ymd);
	
	virtual Date createDateFromDelimitedString(const String& dateString);

	virtual Date createLocal();
	virtual Date createUTC();



	//@}

	/** @name conversions */
	//@{

	virtual String toString(const Date& date)   const;
	virtual String toISOString(const Date& date)    const;
	virtual String toDelemetedISOString(const Date& date)  const;

	//@}
};

DECLARE_SHARED_POINTER(BoostDateTimeFactory);

} //namespace boostimpl
} //namespace datetime
} //namespace ondalear


DECLARE_USING_DEFAULT(ondalear::datetime::boostimpl,BoostDateTimeFactory);

#endif //ONDALEAR_DATETIME_BoostDateTimeFactory_HPP
