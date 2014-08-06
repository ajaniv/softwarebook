/**
 * \file ApplicationText.hpp
 * \brief Application text header file
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
#ifndef ONDALEAR_APPLICATION_ApplicationText_HPP
#define ONDALEAR_APPLICATION_ApplicationText_HPP



 
#include "core/CoreConfig.hpp"
#include "core/Text.hpp"



namespace ondalear {
namespace application {

/**
 * @todo:  ApplicationText - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  ApplicationText - attributes/methods -  completeness/need/correctness
 * @todo:  ApplicationText - unit test completeness/need/correctness
 * @todo:  ApplicationText - doc - completeness/correctness
 */

/**
  * \class ApplicationText
  * \brief Application text facilities
  *  Defined for reuse and internationalization
  */



class CORE_API ApplicationText 
	: public Text {
	
public:
	/** @name public constructors */
	//@{
	static const ApplicationText& instance();
	//@}

	/** @name general */
	//@{
	virtual String loggingInitialized() const; 
	virtual String applicationStartWork() const;
	virtual String applicationEndWork() const;
	virtual String applicationExiting(Integer resultCode) const;
	virtual String usageMessage(const String& appName) const;
	virtual String versionMessage(const String& appName, const String& version) const;
	virtual String loggingPriorityChanged(const String& newLevel) const;
	virtual String loggingSinkAdded(const String& sinkType, const String& sinkName) const;
	virtual String loggerPriorityChanged(const String& loggerName, const String& priority) const;

	//@}
	 
 
};


}//namespace application
}//namespace ondalear




DECLARE_USING_TYPE(ondalear::application,ApplicationText);


#endif //ONDALEAR_APPLICATION_ApplicationText_HPP
