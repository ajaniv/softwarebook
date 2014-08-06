/**
 * \file  OptionsConstants.hpp
 * \brief Options constants header file
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


#ifndef ONDALEAR_OPTIONS_OptionsConstants_HPP
#define ONDALEAR_OPTIONS_OptionsConstants_HPP


#include "core/CoreIncludes.hpp"

namespace ondalear {
namespace options {

/**
 * @todo:  OptionsConstants - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  OptionsConstants - attributes/methods -  completeness/need/correctness
 * @todo:  OptionsConstants - unit test completeness/need/correctness
 * @todo:  OptionsConstants - doc - completeness/correctness
 */

/**
  * \class OptionsConstants
  * \brief Options component constants definition
  *
  * Implemented as static methods to avoid cross platform 
  * and cross compiler implementation issues.
  * 
  */
class CORE_API OptionsConstants {

public:
	/** @name defaults */
	//@{
	static const String& defaultFactoryName();
	static const String& defaultGroupName();
	static const String& positionalArgName();
	static const String& dummyDefaultValue();
	 
	//@}
	static const Integer maxPositionalArgs = 64;
};

} //namespace options
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::options,OptionsConstants);

#endif //ONDALEAR_OPTIONS_OptionsConstants_HPP
