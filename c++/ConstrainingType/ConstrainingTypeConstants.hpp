/**
 * \file ConstrainingTypeConstants.hpp
 * \brief Constraining type constants definition header file
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
#ifndef ONDALEAR_CONSTRAINED_ConstrainingTypeConstants_HPP
#define ONDALEAR_CONSTRAINED_ConstrainingTypeConstants_HPP


#include "core/CoreIncludes.hpp"




namespace ondalear {
namespace constrained {

/**
 * @todo:  constrained::ConstrainingTypeConstants - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  constrained::ConstrainingTypeConstants - attributes/methods -  completeness/need/correctness
 * @todo:  constrained::ConstrainingTypeConstants - unit test completeness/need/correctness
 * @todo:  constrained::ConstrainingTypeConstants - doc - completeness/correctness
 */

/**
  * \class ConstrainingTypeConstants
  * \brief Constraining type implementation independent constants access methods
  *
  * 
  */
	
class CORE_API ConstrainingTypeConstants {

public:
	/** @name factory */
	//@{
	static const String& defaultFactoryName();
	//@}
	
};

} //namespace constrained
} //namespace ondalear


DECLARE_USING_TYPE(ondalear::constrained,ConstrainingTypeConstants);

#endif //ONDALEAR_CONSTRAINED_ConstrainingTypeConstants_HPP
