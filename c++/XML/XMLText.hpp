/**
 * \file XMLText.hpp
 * \brief XML text header file
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
#ifndef ONDALEAR_XML_XMLText_HPP
#define ONDALEAR_XML_XMLText_HPP



 
#include "core/CoreConfig.hpp"
#include "core/Text.hpp"



namespace ondalear {
namespace xml {

/**
 * @todo:  XMLText - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  XMLText - attributes/methods -  completeness/need/correctness
 * @todo:  XMLText - unit test completeness/need/correctness
 * @todo:  XMLText - doc - completeness/correctness
 */

/**
  * \class XMLText
  * \brief XMLText text facilities
  *  Defined for reuse and internationalization
  */



class CORE_API XMLText 
	: public Text {
	
public:
	/** @name public constructors */
	//@{
	static const XMLText& instance();
	//@}

	/** @name general */
	//@{
	virtual String implementationError(const String& errorDetail) const; 
	virtual String parserError(const String& errorDetail) const;
	virtual String nodeNotFound(const String& tagName) const;
	virtual String unsupportedParser(const String& parserType) const;
	//@}
	 
 
};


}//namespace xml
}//namespace ondalear




DECLARE_USING_TYPE(ondalear::xml,XMLText);


#endif //ONDALEAR_XML_XMLText_HPP
