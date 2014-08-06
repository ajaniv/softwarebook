/**
 * \file FileType.hpp
 * \brief File Type header file
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

#ifndef ONDALEAR_CORE_FileType_HPP
#define ONDALEAR_CORE_FileType_HPP


#include "CoreIncludes.hpp"
#include "Enum.hpp"
#include "EnumWrapper.hpp"
#include "CoreStream.hpp"




namespace ondalear {
namespace core {


/**
 * @todo:  FileType - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  FileType - attributes/methods -  completeness/need/correctness
 * @todo:  FileType - unit test completeness/need/correctness
 * @todo:  FileType - doc - completeness/correctness
 */

/**
  * \class FileType
  * \brief file type enum   
  *
  */

class CORE_API FileType
	: public Enum {

public:

	 
	typedef enum  { 
		
		XML     = 1,
		INI     = 2,
		JSON	= 3,
		Default = XML
         
	} eFileType;

	

	/** @name Public utilities */
	//@{
	/** Return FileType instance
      *
      * This methods implements the Singelton pattern.
	  * @return reference to singleton ContainerFileFormat instance.
      */
	static const FileType& instance();

	/** Convert FileType::eFileType to String
      *
      * Convenience wrapper function around utility methods
	  * @param unit The enum to be converted to String
	  * @return meaningful String representation of the enum (i.e. FileType::XML)
      */
	virtual String toString(FileType::eFileType unit) const;


	/** Create FileType::eFileType from String
      *
      * Convenience wrapper function around utility methods.
	  * A BaseException is raised if an invalid argument is passed.
	  * @param stringRep The String to be converted to  FileType::eFileType
	  * @return FileType::eFileType
      */
	virtual FileType::eFileType fromString(const String& stringRep) const;
	//@}

protected:
	/** @name Protected constructors */
	//@{
	/** Create ContainerFileFormat
      *
      * @see instance
      */
	FileType();
	//@}
 
};

/**
 * Declares FileType convenience type from template
 */ 
DECLARE_ENUM(FileType,FileType::eFileType);

} //namespace core
} //namespace ondalear

/**
 * Makes FileType accessible without ns qualification
 */ 
DECLARE_USING_TYPE(ondalear::core,FileType);

/**
 * Makes FileTypeEnum accessible without ns qualification
 */ 
DECLARE_USING_TYPE(ondalear::core,FileTypeEnum);


#endif //ONDALEAR_CORE_FileType_HPP
