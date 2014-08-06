/**
 * \file CoreText.cpp
 * \brief Core component text messages source file
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
#include "CoreText.hpp"

#include "StringUtil.hpp"



namespace ondalear {
namespace core {

//constructors
const CoreText& 
CoreText::instance()
{
	static const CoreText instance;
	return instance;
}


/*
 * 
 * public - misc	
 *
 */

String 
CoreText::reviewImplementation() const
{
	return getText("Implementation requires review");
}

String 
CoreText::reviewImplementation(const String& errorDetail) const
{
	return getText("Implementation requires review; detail: %s", 
		errorDetail.c_str());
}

String
CoreText::invalidObjectComparison() const
{
	return getText("Invalid object comparison");
}

String 
CoreText::objectNotFound(const UniversalId& uid) const
{
	return getText("Object (%s) not found", StringUtil::fromUniversalId(uid));
}


String 
CoreText::objectNotFound(const String& objectName) const
{
	return getText("Object (%s) not found", objectName.c_str());
}

String
CoreText::objectNotFound(const String& objectName, const String& errorDetail) const
{
	return getText("Object (%s) not found; detail: %s", objectName.c_str(), errorDetail.c_str());
}

String
CoreText::objectRemovalError(const String& objectName, const String& errorDetail) const
{
	return getText("Object (%s) removal error; detail: %s", objectName.c_str(), errorDetail.c_str());
}

String
CoreText::objectNotConfigured(const String& objectName, const String& errorDetail) const
{
	return getText("Object (%s) configuration error; detail: %s", objectName.c_str(), errorDetail.c_str());
}


String 
CoreText::objectNotFound(BigInteger objectId) const
{
	return getText("Object (%ld) not found", objectId);
}

String 
CoreText::objectExists(const UniversalId& uid) const
{
	return getText("Key (%s) exists", StringUtil::fromUniversalId(uid));
}

String
CoreText::objectIsInactive(const String& objectName) const
{
	return getText("Object (%s) is inactive", objectName.c_str());
}

String
CoreText::multipleInstances(const String& instanceName,
						  const String& instanceVersion) const
{
	return getText("Multiple object instances found with name ( %s ) and version( %s )", 
		instanceName.c_str(),
		instanceVersion.c_str());
}

String
CoreText::dynamicCastFailure() const
{
	return getText("dynamic cast failure");
}


/*
 *
 *   file access
 *
 */

String
CoreText::fileAccessError(const String& fileName, const String& errorDetail) const
{
	return getText("File (%s) access error; detail: %s", fileName.c_str(), errorDetail.c_str());
}

String
CoreText::streamAccessError(const String& errorDetail) const
{
	return getText("Stream  access error; detail: %s", errorDetail.c_str());
}


/*
 *
 *   options
 *
 */

String
CoreText::invalidOption(const String& option) const
{
	return getText("Unsupported option (%s) ", option.c_str());
}


String
CoreText::missingOption(const String& option) const
{
	return getText("Missing option (%s) ", option.c_str());
}


/*
 *
 * Conversion
 *
 */

String
CoreText::conversionFailure(const String& errorDetail) const
{
	return getText("Conversion failure details (%s)",	errorDetail.c_str());
}

String
CoreText::conversionFailure(const String& value , const String& errorDetail) const
{
	return getText("Conversion failure for(%s)  details (%s)",	value.c_str(), errorDetail.c_str());
}


/*
 *
 * Validation
 *
 */

String
CoreText::assertionFailure(const char* expr) const
{
	return getText("Assertion failure (%s)", expr);
}

String
CoreText::assertionFailure(const char* expr, const String& message) const
{
	return getText("Assertion failure (%s); details (%s)",	expr, message.c_str());
}



} //namespace core
} //namespace ondalear

