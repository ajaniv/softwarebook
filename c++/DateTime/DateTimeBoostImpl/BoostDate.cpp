/**
 * \file  BoostDate.hpp
 * \brief Boost Date Abstraction source file
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



 
#include "BoostDate.hpp"

#include "BoostDateImpl.hpp"

#include "ImplUtil.hpp"

namespace ondalear {
namespace datetime {
namespace boostimpl {

/*
 *
 * public - constructor
 *
 */
BoostDate::BoostDate(BoostDateImpl* dateImpl)
	:
	Date(dateImpl)
{
}

BoostDate::BoostDate(const Date& other)
	:
	Date(other)
{
}

/*
 *
 * public - utility
 *
 */

const boost::gregorian::date&
BoostDate::dateRep() const
{
	return getImpl()->getDateRep();
}



/*
 *
 * protected - accessor
 *
 */
const BoostDateImpl* 
BoostDate::getImpl() const
{
	return ImplUtil::fromBase(impl.get());
	 

}
} //namespace boostimpl
} //namespace datetime
} //namespace ondalear
