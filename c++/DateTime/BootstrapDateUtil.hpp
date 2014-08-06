/**
 * \file BootstrapDateUtil.hpp
 * \brief Miscellaneous private Date Implementation Utilities
 *
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



#ifndef ONDALEAR_DATETIME_BootstrapDateUtil_HPP
#define ONDALEAR_DATETIME_BootstrapDateUtil_HPP


#include "core/CoreIncludes.hpp"

namespace ondalear {
namespace datetime {

/**
  * @todo:  Class - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  Class - attributes/methods -  completeness/need/correctness
  * @todo:  Class - unit test completeness/need/correctness
  * @todo:  Class - doc - completeness/correctness
  */

class BootstrapDateUtilImpl;

/**
  * \class BootstrapDateUtil
  * \brief Implementation utilities required for component/class initialization
  *
  * 
  */

class CORE_API BootstrapDateUtil{
public:
	
	/** @name public constructors */
	//@{
	virtual ~BootstrapDateUtil();
	static const BootstrapDateUtil& instance();
	//@}

	/** @name utilities */
	//@{
	virtual Integer year() const;
	virtual Integer month() const;
	virtual Integer dayOfMonth() const;
	virtual Integer dayOfWeek() const;
	virtual Integer dayOfYear() const;
	virtual Bool isLeapYear(Integer year) const;
	//@}

	
protected:
	/** @name protected constructors */
	//@{
	BootstrapDateUtil();
	//@}

private:
	
	boost::shared_ptr< BootstrapDateUtilImpl> impl;

};

} //namespace datetime
} //namespace ondalear

using ondalear::datetime::BootstrapDateUtil;

#endif //ONDALEAR_DATETIME_BootstrapDateUtilL_HPP
