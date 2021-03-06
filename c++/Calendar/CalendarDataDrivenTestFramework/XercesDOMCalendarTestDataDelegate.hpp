/**
 * \file XercesDOMCalendarTestDataDelegate.hpp
 * \brief Calendar test data    mapping  delegate header file
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

#ifndef ONDALEAR_TEST_XercesDOMCalendarTestDataDelegate_HPP
#define ONDALEAR_TEST_XercesDOMCalendarTestDataDelegate_HPP

#include <map>

#include "core/CoreIncludes.hpp"


#include "xml/XMLAppDelegate.hpp"
#include "xml/XMLHandlerImpl.hpp"


#include "CalendarTestData.hpp"
 
namespace ondalear {
namespace test {
namespace calendar {


class CORE_API XercesDOMCalendarTestDataDelegate 
	: public XMLAppDelegate{
public:

	/** @name constructors */
	//@{
	XercesDOMCalendarTestDataDelegate();
	//@}

	/** @name utilities */
	//@{
	virtual const ManagedObjectSharedPtr getObjectTree(XMLHandlerImpl* impl);
	//@}

};
 


} //namespace calendar
} //namespace test
} //namespace ondalear



#endif //ONDALEAR_TEST_XercesDOMCalendarTestDataDelegate_HPP