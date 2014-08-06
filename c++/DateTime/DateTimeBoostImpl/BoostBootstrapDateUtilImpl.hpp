/**
 * \file BoostBootstrapDateImplUtil.hpp
 * \brief Miscellaneous private Date Implementation Utilities Boost Implementation header file
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

#ifndef ONDALEAR_DATETIME_BoostBootstrapDateUtilImpl_HPP
#define ONDALEAR_DATETIME_BoostBootstrapDateUtilImpl_HPP


#include "core/CoreIncludes.hpp"

#include "../BootstrapDateUtilImpl.hpp"

namespace ondalear {
namespace datetime {
namespace boostimpl {

/**
  * \class BoostBootstrapDateUtilImpl
  * \brief Boost boostrap utilities implementation
  *
  */

class CORE_API BoostBootstrapDateUtilImpl 
	: public BootstrapDateUtilImpl{

public:
	/** @name public constructors */
	//@{
	
	BoostBootstrapDateUtilImpl();

	//@}

	/** @name utilities */
	//@{
	virtual Integer year() const  ;
	virtual Integer month() const  ;
	virtual Integer dayOfMonth() const  ;
	virtual Integer dayOfWeek() const  ;
	virtual Integer dayOfYear() const  ;
	virtual Bool isLeapYear(Integer year) const;

	//@}
	
};

} //namespace boostimpl 
} //namespace datetime
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::datetime::boostimpl,BoostBootstrapDateUtilImpl);

#endif //ONDALEAR_DATETIME_BoostBootstrapDateUtilImpl_HPP

