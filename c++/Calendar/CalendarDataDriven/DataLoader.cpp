/**
 * \file DataLoader.cpp
 * \brief Calendar    data loader   source file
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
#include "DataLoader.hpp"

#include "logging/LoggingMacros.hpp"

#include "xml/XMLHandler.hpp"

#include "calendar/data/XercesDOMCalendarDelegate.hpp"

#include "CalendarContainer.hpp"

namespace ondalear {
namespace calendar {

const CalendarCacheSharedPtr
DataLoader::loadFromXmlFile(const String& grammarFileName,
		const String& calendarDefinitionFileName)
{
	CalendarCacheSharedPtr calCache;
	try {
		XMLHandler xmlHandler(XMLParserType::DOM);

		xmlHandler.loadGrammar(grammarFileName);
		xmlHandler.parse(calendarDefinitionFileName);

		XercesDOMCalendarDelegate xmlHelper;
		ManagedObjectSharedPtr root = xmlHandler.getObjectTree(&xmlHelper);
		CalendarContainerSharedPtr calContainer = 
			CHECKED_SHARED_POINTER_CAST(CalendarContainer, ManagedObject, root );

		const CalendarMapSharedPtr  calMap = calContainer->getCalendarMap();
		calCache.reset((new CalendarCache()));

		calCache->add(calMap->begin(), calMap->end());
	}
	catch (BaseException& ex){
		//Key entry point, including from SWIG, want to make sure the
		//error is logged
		ERROR("details: %s", ex.details().c_str());
		throw;
	}
	return calCache;
}


} //namespace calendar
} //namespace ondalear
