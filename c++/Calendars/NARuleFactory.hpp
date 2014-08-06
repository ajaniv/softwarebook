/**
 * \file NARuleFactory.hpp
 * \brief North America rule factory abstraction header file  
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

#ifndef ONDALEAR_CALENDAR_NARuleFactory_HPP
#define ONDALEAR_CALENDAR_NARuleFactory_HPP



#include "core/CoreIncludes.hpp"

#include "RuleFactory.hpp"
#include "calendar/CalendarRule.hpp"


namespace ondalear {
namespace calendar {

/**
 * @todo:  NARuleFactory - design/imple -  completeness/need/correctness/performance/memory

 * @todo:  NARuleFactory - attributes/methods -  completeness/need/correctness
 * @todo:  NARuleFactory - unit test completeness/need/correctness
 * @todo:  NARuleFactory - doc - completeness/correctness
 */

/**
  * \class NARuleFactory 
  * \brief North America rule  factory  to facilitate regional rule construction by  code
  *
  * Facilitates calendar construction with helper methods for rule creation.  Designed
  * to allow code reuse among calendar construction if and when it is required to be done
  * using code rather than data, and when calendar reuse does not make sense.
  */ 
class CORE_API  NARuleFactory
	: public RuleFactory{
	 

public:
	/** @name public constructor  */ 
	//@{
	NARuleFactory();
	//@}

	/** @name public rule creation utilities  */ 
	//@{
	

	
	virtual const DateRuleSharedPtr laborDay() const;
	
	 

	//@}
};

DECLARE_SHARED_POINTER(NARuleFactory);

} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,NARuleFactory);

#endif //ONDALEAR_CALENDAR_NARuleFactory_HPP