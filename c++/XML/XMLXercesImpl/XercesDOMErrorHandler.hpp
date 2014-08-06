/**
 * \file XercesDOMErrorHandler.hpp
 * \brief Xerces DOM custom  error handler header file
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

#ifndef ONDALEAR_XML_XercesDOMErrorHandler_HPP
#define ONDALEAR_XML_XercesDOMErrorHandler_HPP

#include "core/CoreIncludes.hpp"




#include <xercesc/dom/DOMErrorHandler.hpp>
#include <xercesc/dom/DOMError.hpp>

namespace ondalear {
namespace xml {
namespace xercesimpl {

/**
 * @todo:  XercesDOMErrorHandler - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  XercesDOMErrorHandler - attributes/methods -  completeness/need/correctness
 * @todo:  XercesDOMErrorHandler - unit test completeness/need/correctness
 * @todo:  XercesDOMErrorHandler - doc - completeness/correctness
 * @todo:  XercesDOMErrorHandler - Handle relative date math
 */



/**
  * \class XercesDOMErrorHandler
  * \brief Xerces  DOM custom error handler
  *
  */

class CORE_API XercesDOMErrorHandler : 
	public xercesc::DOMErrorHandler {
public:
	/** @name public constructors */
	//@{

	 XercesDOMErrorHandler();
	 ~XercesDOMErrorHandler();
	 
	//@}

	/** @name error handling */
	//@{
    virtual bool handleError(const xercesc::DOMError& e);
    //@}

	/** @name public accessors */
	//@{
	virtual bool hasFailed() const ;
	virtual void reset() ;
	//@}

private:
	bool failed;
};


} //namespace xercesimpl
} //namespace xml
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::xml::xercesimpl,XercesDOMErrorHandler);

#endif //ONDALEAR_XML_XercesDOMErrorHandler_HPP

