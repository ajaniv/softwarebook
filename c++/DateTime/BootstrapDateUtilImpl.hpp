/**
 * \file BootstrapDateUtilImpl.hpp 
 * \brief Miscellaneous private Date Implementation Utilities Inteface Definition
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

#ifndef ONDALEAR_DATETIME_BootstrapDateUtilImpl_HPP
#define ONDALEAR_DATETIME_BootstrapDateUtilImpl_HPP


#include "core/CoreIncludes.hpp"

namespace ondalear {
namespace datetime {

/**
  * @todo:  BootstrapDateUtilImpl - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  BootstrapDateUtilImpl - attributes/methods -  completeness/need/correctness
  * @todo:  BootstrapDateUtilImpl - unit test completeness/need/correctness
  * @todo:  BootstrapDateUtilImpl - doc - completeness/correctness
  */

/**
  * \class BootstrapDateUtilImpl
  * \brief Abstract class defining interfaces required for component bootstraping.
  *
  * Part of the PIMP pattern established.
  * @see BootstrapDateUtil
  */

class CORE_API BootstrapDateUtilImpl{
public:
	/** @name public constructors */
	//@{
	virtual ~BootstrapDateUtilImpl();
	//@}

	/** @name utilities */
	//@{
	virtual Integer year() const = 0 ;
	virtual Integer month() const = 0 ;
	virtual Integer dayOfMonth() const = 0 ;
	virtual Integer dayOfWeek() const = 0;
	virtual Integer dayOfYear() const = 0;
	virtual Bool isLeapYear(Integer year) const = 0;
	//@}

protected:

	/** @name public constructors */
	//@{
	BootstrapDateUtilImpl();
	BootstrapDateUtilImpl(const BootstrapDateUtilImpl& other);
	//@}

	//operators - general
	/** @name operators - general */
	//@{
	BootstrapDateUtilImpl& operator=(const BootstrapDateUtilImpl& rhs);
	//@}
};

} //namespace datetime
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::datetime, BootstrapDateUtilImpl);

#endif //ONDALEAR_DATETIME_BootstrapDateUtilImpl_HPP

