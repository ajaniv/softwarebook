/**
 * \file  ApplicationConstants.hpp
 * \brief Application constants header file
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


#ifndef ONDALEAR_APPLICATION_ApplicationConstants_HPP
#define ONDALEAR_APPLICATION_ApplicationConstants_HPP


#include "core/CoreIncludes.hpp"

namespace ondalear {
namespace application {

/**
 * @todo:  ApplicationConstants - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  ApplicationConstants - attributes/methods -  completeness/need/correctness
 * @todo:  ApplicationConstants - unit test completeness/need/correctness
 * @todo:  ApplicationConstants - doc - completeness/correctness
 */

/**
  * \class ContainerConstants
  * \brief Container component constants definition
  *
  * Implemented as static methods to avoid cross platform 
  * and cross compiler implementation issues.
  * 
  */
class CORE_API ApplicationConstants {

public:
	/** @name defaults */
	//@{
	static const String& defaultApplicationName();
	static const String& defaultApplicationVersion();
	static const String& defaultLoggingFileSinkName();

	//@}

	/** @name command line options */
	//@{
	static const String& mainOptionGroupName();

	static const String& helpOptionName();
	static const String& helpOptionShortName();
	static const String& helpOptionDescription();

	static const String& versionOptionName();
	static const String& versionOptionShortName();
	static const String& versionOptionDescription();

	static const String& configFileOptionName();
	static const String& configFileOptionShortName();
	static const String& configFileOptionDescription();

	static const String& configFileFormatOptionName();
	static const String& configFileFormatOptionShortName();
	static const String& configFileFormatOptionDescription();
	//@}

	/** @name exit status */
	//@{
	static const Integer success = 0;
	static const Integer failure = 1;
	//@}
};

} //namespace application
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::application,ApplicationConstants);

#endif //ONDALEAR_APPLICATION_ApplicationConstants_HPP
