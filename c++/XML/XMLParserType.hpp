/**
 * \file XMLParserType.hpp
 * \brief XML Parser type   header file
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

#ifndef ONDALEAR_XML_XMLParserType_HPP
#define ONDALEAR_XML_XMLParserType_HPP


#include "core/CoreIncludes.hpp"
#include "core/Enum.hpp"
#include "core/EnumWrapper.hpp"
#include "core/CoreStream.hpp"



namespace ondalear {
namespace xml {


/**
 * @todo:  XMLParserType - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  XMLParserType - attributes/methods -  completeness/need/correctness
 * @todo:  XMLParserType - unit test completeness/need/correctness
 * @todo:  XMLParserType - doc - completeness/correctness
 */

/**
  * \class XMLParserType
  * \brief XML parser   types
  *
  */

class CORE_API XMLParserType
	: public Enum {

public:

	 
	typedef enum  { 
		SAX	  = 0,
		DOM   = 1,
		Default   = DOM
         
	} eXMLParserType;

	 


	/** @name Public utilities */
	//@{
	/** Return XMLParserType instance
      *
      * This methods implements the Singelton pattern.
	  * @return reference to singleton XMLParserType instance.
      */
	static const XMLParserType& instance();

	/** Convert XMLParserType::eXMLParserType to String
      *
      * Convenience wrapper function around utility methods
	  * @param unit The enum to be converted to String
	  * @return meaningful String representation of the enum (i.e. XMLParserType::eDOM)
      */
	virtual String toString(XMLParserType::eXMLParserType unit) const;


	/** Create XMLParserType::eXMLParserType from String
      *
      * Convenience wrapper function around utility methods.
	  * A BaseException is raised if an invalid argument is passed.
	  * @param stringRep The String to be converted to  XMLParserType::eXMLParserType
	  * @return XMLParserType::eXMLParserType
      */
	virtual XMLParserType::eXMLParserType fromString(const String& stringRep) const;
	//@}

protected:

	/** @name Protected constructors */
	//@{
	/** Create LoggerType
      *
      * @see instance
      */
	XMLParserType();
	//@}
};

/**
 * Declares XMLParserType convenience type from template
 */ 
DECLARE_ENUM(XMLParserType,XMLParserType::eXMLParserType);

} //namespace xml
} //namespace ondalear


/**
 * Makes XMLParserType accessible without ns qualification
 */ 
DECLARE_USING_TYPE(ondalear::xml,XMLParserType);

/**
 * Makes LoggerType accessible without ns qualification
 */ 
DECLARE_USING_TYPE(ondalear::xml,XMLParserType);

#endif //ONDALEAR_XML_XMLParserType_HPP
