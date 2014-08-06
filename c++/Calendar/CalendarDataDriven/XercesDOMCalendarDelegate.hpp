/**
 * \file XercesDOMCalendarDelegate.hpp
 * \brief Calendar  xml    mapping  delegate header file
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

#ifndef ONDALEAR_CALENDAR_XercesDOMCalendarDelegate_HPP
#define ONDALEAR_CALENDAR_XercesDOMCalendarDelegate_HPP

#include <map>

#include "core/CoreIncludes.hpp"


#include "xml/XMLAppDelegate.hpp"
#include "xml/XMLHandlerImpl.hpp"



 
namespace ondalear {
namespace calendar {


class CORE_API XercesDOMCalendarDelegate 
	: public XMLAppDelegate{
public:

	/** @name constructors */
	//@{
	XercesDOMCalendarDelegate();
	//@}

	/** @name utilities */
	//@{
	virtual const ManagedObjectSharedPtr getObjectTree(XMLHandlerImpl* impl);
	//@}

};
 
DECLARE_SHARED_POINTER(XercesDOMCalendarDelegate);

} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,XercesDOMCalendarDelegate);

#endif //ONDALEAR_CALENDAR_XercesDOMCalendarDelegate_HPP