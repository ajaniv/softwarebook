/**
 * \file CoreText.hpp
 * \brief Core component text messages header file
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

#ifndef ONDALEAR_CORE_CoreText_HPP
#define ONDALEAR_CORE_CoreText_HPP

 
#include "CoreConfig.hpp"
#include "Text.hpp"



namespace ondalear{
namespace core {


/**
 * @todo:  CoreText - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  CoreText - attributes/methods -  completeness/need/correctness
 * @todo:  CoreText - unit test completeness/need/correctness
 * @todo:  CoreText - doc - completeness/correctness
 */

/**
  * \class CoreText
  * \brief Core component text messages
  *
  *  Desiged with a view to support internationalization of text
  */

class CORE_API CoreText 
	: public Text {
	
public:
	/** @name public constructors */
	//@{
	static const CoreText& instance();
	//@}
	 
	/** @name misc */
	//@{
	virtual String reviewImplementation() const; 
	virtual String reviewImplementation(const String& errorDetail) const; 
	virtual String invalidObjectComparison() const;
	//@}

	/** @name object */
	//@{
	virtual String objectNotFound(const UniversalId& uid) const;
	virtual String objectNotFound(const String& objectName) const;
	virtual String objectNotFound(const String& objectName, const String& errorDetail) const;
	virtual String objectNotFound(BigInteger objectId) const;
	virtual String objectExists(const UniversalId& uid) const;
	virtual String multipleInstances(const String& instanceName, const String& instanceVersion) const;
	virtual String objectRemovalError(const String& objectName, const String& errorDetail) const;
	virtual String objectNotConfigured(const String& objectName, const String& errorDetail) const;
	virtual String objectIsInactive(const String& objectName) const;
	//@}

	/** @name file access */
	//@{
	virtual String fileAccessError(const String& fileName, const String& errorDetail) const;
	virtual String streamAccessError(const String& errorDetail) const;
	//@}

	/** @name options */
	//@{
	virtual String invalidOption(const String& option) const;
	virtual String missingOption(const String& option) const;
	//@}

	/** @name memory */
	//@{
	virtual String dynamicCastFailure() const;
	//@}


	/** @name conversion */
	//@{
	virtual String conversionFailure(const String& errorDetail) const;
	virtual String conversionFailure(const String& value, const String& errorDetail) const;
	//@}

	/** @name validaton */
	//@{
	virtual String assertionFailure(const char* expr) const;
	virtual String assertionFailure(const char* expr, const String& message) const;
	//@}
};

 



}//namespace core
}//namespace ondalear

DECLARE_USING_TYPE(ondalear::core,CoreText);


#endif //ONDALEAR_CORE_CoreText_HPP
