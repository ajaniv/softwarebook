/**
 * \file XercesDOMCalendarMapping.hpp
 * \brief Calendar  xml    mapping    header file
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

#ifndef ONDALEAR_CALENDAR_XercesDOMCalendarMapping_HPP
#define ONDALEAR_CALENDAR_XercesDOMCalendarMapping_HPP

 

#include "xml/XercesDOMUtil.hpp"

 
namespace ondalear {
namespace calendar {


void handleCalendarCreation(xercesc::DOMElement* ruleDefinition, void* arg);
 


} //namespace calendar
} //namespace ondalear



#endif //ONDALEAR_CALENDAR_XercesDOMCalendarMapping_HPP