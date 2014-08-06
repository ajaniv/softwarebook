/**
 * \file XercesUtil.hpp
 * \brief Xerces  util header file
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

#ifndef ONDALEAR_XML_XercesUtil_HPP
#define ONDALEAR_XML_XercesUtil_HPP

#include <xercesc/framework/XMLGrammarPoolImpl.hpp>

#include "core/CoreIncludes.hpp"


#include <xercesc/util/PlatformUtils.hpp>

namespace ondalear {
namespace xml {
namespace xercesimpl {

/**
  * \class XercessUtil
  * \brief Xerces  utilities
  *
  */

class CORE_API XercesUtil {
public:
	static void initialize();
	static void shutdown();

	/** @name schema */
	static xercesc::XMLGrammarPoolImpl* createGrammarPool();
	//@}
};

// 
/**
  * \class template<typename T> class DOMPtr
  * \brief RAII utility that releases a resource when it goes out of scope.
  *
  */
template<typename T>
class DOMPtr {
public:
    DOMPtr(T* t) : t_(t) { }
    ~DOMPtr( ) { t_->release( ); }
    T* operator->( ) const { return t_; }
	T* operator*() const { return t_;}
	T* get() const { return t_; }

private:
    // prohibit copying and assigning
    DOMPtr(const DOMPtr&);
    DOMPtr& operator=(const DOMPtr&);
    T* t_;
};


/**
  * \class XercesInitializer
  * \brief RAII utility that initializes the parser and frees resources
  *
  */

 
class CORE_API XercesInitializer {
public:
	XercesInitializer( ) { XercesUtil::initialize( ); }
	virtual ~XercesInitializer( ) { XercesUtil::shutdown( ); }
private:
    // Prohibit copying and assignment
    XercesInitializer(const XercesInitializer&);
    XercesInitializer& operator=(const XercesInitializer&);
};




} //namespace xercesimpl
} //namespace xml
} //namespace ondalear


DECLARE_USING_TYPE(ondalear::xml::xercesimpl, XercesInitializer);
DECLARE_USING_TYPE(ondalear::xml::xercesimpl, DOMPtr);
#endif //ONDALEAR_TEST_XercesStringUtil_HPP

