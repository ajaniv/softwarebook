/**
 * \file ConstrainingTypeText.hpp
 * \brief Constraining type text messages header file
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
#ifndef ONDALEAR_CONSTRAINED_ConstrainingTypeText_HPP
#define ONDALEAR_CONSTRAINED_ConstrainingTypeText_HPP



 
#include "core/CoreIncludes.hpp"
#include "core/Text.hpp"


namespace ondalear{
namespace constrained {

/**
 * @todo:  ConstrainingTypeText - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  ConstrainingTypeText - attributes/methods -  completeness/need/correctness
 * @todo:  ConstrainingTypeText - unit test completeness/need/correctness
 * @todo:  ConstrainingTypeText - doc - completeness/correctness
 */

/**
  * \class ConstrainingTypeText
  * \brief Common constraining type text messages 
  *
  */

class CORE_API ConstrainingTypeText
	: public Text {
	
public:
	/** @name public constructors */
	//@{
	static const ConstrainingTypeText& instance();
	//@}

	/** @name text processing */
	//@{
	virtual String constraintViolation(Integer value, Integer minValue, Integer maxValue, 
		const char* extraText) const;
	//@}
};

 



}//namespace constrained
}//namespace pimco

using ondalear::constrained::ConstrainingTypeText;


#endif //ONDALEAR_CONSTRAINED_ConstrainingTypeText_HPP
