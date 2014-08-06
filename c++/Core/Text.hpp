/**
 * \file Text.hpp
 * \brief Abstraction for text internationalization header file
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

#ifndef ONDALEAR_CORE_Text_HPP
#define ONDALEAR_CORE_Text_HPP



 
#include "CoreConfig.hpp"
#include "CoreTypes.hpp"
#include "CoreMacros.hpp"

namespace ondalear{
namespace core {

/**
 * @todo:  Text - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  Text - attributes/methods -  completeness/need/correctness
 * @todo:  Text - unit test completeness/need/correctness
 * @todo:  Text - doc - completeness/correctness
 */

/**
  * \class Text
  * \brief Abstraction for supporting text internationalization
  *
  * While it supports the interfaces required to support internationalization
  * binding to a specifc implementation is required.
  */

class CORE_API Text {
	
public:
	/** @name public constructors */
	//@{
	Text(const Text& other);
	virtual ~Text();
	//@}

	/** @name operators - general */
	//@{
	Text& operator=(const Text& rhs);
	//@}

	/** @name utilities */
	//@{
	virtual String getText(const char* format, ...) const;
    //@}

protected:
	 
	/** @name protected constructors */
	//@{
	Text ();
	//@}
	
};

 

}//namespace core
}//namespace pimco



DECLARE_USING_TYPE(ondalear::core,Text);


#endif //ONDALEAR_CORE_BaseException_HPP
