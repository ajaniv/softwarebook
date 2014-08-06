/**
 * \file FileType.cpp
 * \brief File Type source file
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



#include "FileType.hpp"

namespace ondalear {
namespace core {



/**
 * \brief Enum string values. 
 * Used in the creation of enum/string mapping tables.
 * Order is important, and needs to match the order of 
 * the enum values.
 */
static String fileTypeStringValues[] =
	{
		STRINGIFY(FileType::XML),
		STRINGIFY(FileType::INI),
		STRINGIFY(FileType::JSON),
		STRINGIFY(FileType::Default)

	};

/**
 * \brief Enum integer  values.
 *  Using in the creation of enum/string mapping
 *  tables. Order is important, and needs to match the
 *  order of string values.
 */
static Integer  fileTypeEnumValues [] =  
	{
		FileType::XML,
		FileType::INI,   
		FileType::JSON,  
		FileType::Default  
	};




/*
 *
 * public utilities
 *
 */


const FileType&
FileType::instance()
{
	static FileType instance;
	return instance;
}


String
FileType::toString(FileType::eFileType unit) const
{
	return ondalear::core::toString<FileType,FileType::eFileType>(*this, unit);
}

FileType::eFileType
FileType::fromString(const String& stringRep) const
{
	return ondalear::core::fromString<FileType,FileType::eFileType>(*this, stringRep);
}

/*
 *
 * protected constructors
 *
 */

FileType::FileType ()
{
	registerKeys(fileTypeStringValues,
		fileTypeEnumValues, sizeof(fileTypeEnumValues)/sizeof(Integer));
	 
}



} //namespace container
} //namespace ondalear

