/**
 * \file ImplUtil.hpp
 * \brief Boost datetime misc implementation utilities header file
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

#ifndef ONDALEAR_DATETIME_ImplUtil_HPP
#define ONDALEAR_DATETIME_ImplUtil_HPP


#include "core/CoreIncludes.hpp"

#include "../Date.hpp"

#include "BoostDateImpl.hpp"
#include "BoostDate.hpp"

namespace ondalear {
namespace datetime {
namespace boostimpl {

 
/**
  * \class ImplUtil
  * \brief Misc boost date time implementation utilities
  *
  */
class CORE_API ImplUtil  {

public:
	static const BoostDateImpl& fromBase(const DateImpl& other) ;
	static const BoostDateImpl* fromBase(const DateImpl* other);
	static const BoostDate& fromBase(const Date& other) ;
	
};

} //namespace boostimpl
} //namespace datetime
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::datetime::boostimpl, ImplUtil);

#endif //ONDALEAR_DATETIME_ImplUtil_HPP


