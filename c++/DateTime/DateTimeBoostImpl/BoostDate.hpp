/**
 * \file  BoostDate.hpp
 * \brief Boost Date Abstraction header file
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

#ifndef ONDALEAR_DATETIME_BoostDate_HPP
#define ONDALEAR_DATETIME_BoostDate_HPP


#include "core/CoreIncludes.hpp"
#include "BoostIncludes.hpp"

#include "../Date.hpp"

namespace ondalear {
namespace datetime {
namespace boostimpl {

class BoostDateImpl;

/**
  * \class BoostDate
  * \brief Implementation of the Date abstraction using boost
  *
  */

class CORE_API BoostDate 
	: public Date{

public:
	/** @name public constructors */
	//@{

	 BoostDate(BoostDateImpl* dateImpl);

	 BoostDate(const Date& other);

	 //@}
	 
	/** @name utility */
	//@{

	 const boost::gregorian::date& dateRep() const;

	 //@}

protected:

	
	/** @name  accessor */

	//@{
	const BoostDateImpl* getImpl() const;
	//@}
};

} //namespace boostimpl
} //namespace datetime
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::datetime::boostimpl,BoostDate);

#endif //ONDALEAR_DATETIME_BoostDate_HPP

