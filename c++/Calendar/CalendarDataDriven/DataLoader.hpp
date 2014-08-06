/**
 * \file DataLoader.hpp
 * \brief Calendar    data loader   header file
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

#ifndef ONDALEAR_CALENDAR_DataLoader_HPP
#define ONDALEAR_CALENDAR_DataLoader_HPP



#include "core/CoreIncludes.hpp"

#include "calendar/CalendarCache.hpp"

 
namespace ondalear {
namespace calendar {


class CORE_API DataLoader {
	 

public:
	
	
	/** @name public utilities */
	//@{
	static  const CalendarCacheSharedPtr loadFromXmlFile(const String& grammarFile,
		const String& xmlFile);
	
	//@}

 
	 

};


} //namespace calendar
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::calendar,DataLoader);

#endif //ONDALEAR_CALENDAR_DataLoader_HPP