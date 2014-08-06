/**
 * \file StringUtil.hpp
 * \brief Miscellaneous string utilities header file
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


#ifndef ONDALEAR_CORE_StringUtil_HPP
#define ONDALEAR_CORE_StringUtil_HPP


#include <cstdarg>
 
#include "CoreConfig.hpp"
#include "CoreTypes.hpp"


namespace ondalear{
namespace core {


/**
 * @todo:  StringUtil - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  StringUtil - attributes/methods -  completeness/need/correctness
 * @todo:  StringUtil - unit test completeness/need/correctness
 * @todo:  StringUtil - doc - completeness/correctness
 */


/**
  * \class StringUtil
  * \brief Collection of additional string utilitiels
  */
class CORE_API StringUtil {
	
public:
	static String vsnprintf(const char* format, va_list args) ;
	static String sprintf(const char*, ...) ;
   
	static String fromUniversalId(const UniversalId& uid);

	static String fromInteger(Integer value);
	static Integer toInteger(const String& value);

	static String toUpper(const String& refString);
 
};

 



}//namespace core
}//namespace pimco

using ondalear::core::StringUtil;


#endif //ONDALEAR_CORE_StringUtil_HPP
