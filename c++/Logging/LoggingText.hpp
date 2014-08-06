/**
 * \file LoggingText.hpp
 * \brief Logging text header file
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
#ifndef ONDALEAR_LOGGING_LoggingText_HPP
#define ONDALEAR_LOGGING_LoggingText_HPP



 
#include "core/CoreConfig.hpp"
#include "core/Text.hpp"



namespace ondalear {
namespace logging {

/**
 * @todo:  LoggingText - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  LoggingText - attributes/methods -  completeness/need/correctness
 * @todo:  LoggingText - unit test completeness/need/correctness
 * @todo:  LoggingText - doc - completeness/correctness
 */

/**
  * \class LoggingText
  * \brief Logging text facilities
  *  Defined for reuse and internationalization
  */



class CORE_API LoggingText 
	: public Text {
	
public:
	/** @name public constructors */
	//@{
	static const LoggingText& instance();
	//@}

	/** @name general */
	//@{
	virtual String implementationError(const String& errorDetail) const; 

	//@}
	 
 
};


}//namespace logging
}//namespace ondalear




DECLARE_USING_TYPE(ondalear::logging,LoggingText);


#endif //ONDALEAR_LOGGING_LoggingText_HPP
