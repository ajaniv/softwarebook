/**
 * \file XMLUtil.hpp
 * \brief XML util header file.
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


#ifndef ONDALEAR_XML_XMLUtil_HPP
#define ONDALEAR_XML_XMLUtil_HPP


#include "core/CoreIncludes.hpp"

 


namespace ondalear {
namespace xml {



	
/**
 * @todo:  XMLUtil - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  XMLUtil - attributes/methods -  completeness/need/correctness
 * @todo:  XMLUtil - unit test completeness/need/correctness
 * @todo:  XMLUtil - doc - completeness/correctness
 */
 

/**
 * \class XMLInitializer
 * \brief XML facilities initialization, shutdown
 *
 */

class CORE_API XMLInitializer {
public:
	XMLInitializer();
	virtual ~XMLInitializer();
private:
    // Prohibit copying and assignment
    XMLInitializer(const XMLInitializer&);
    XMLInitializer& operator=(const XMLInitializer&);
};


} //namespace xml
} //namespace ondalear



DECLARE_USING_TYPE(ondalear::xml,XMLInitializer);

#endif //ONDALEAR_XML_XMLUtil_HPP



