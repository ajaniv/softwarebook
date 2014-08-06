/**
 * \file PropertyTreeIteratorImpl.hpp
 * \brief Property Tree iterator  Implementation header file.
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


#ifndef ONDALEAR_CONTAINER_PropertyTreeIteratorImpl_HPP
#define ONDALEAR_CONTAINER_PropertyTreeIteratorImpl_HPP


#include "core/CoreIncludes.hpp"

 
 

namespace ondalear {
namespace container {



class PropertyTree;
/**
 * @todo:  PropertyTreeIteratorImpl - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  PropertyTreeIteratorImpl - attributes/methods -  completeness/need/correctness
 * @todo:  PropertyTreeIteratorImpl - unit test completeness/need/correctness
 * @todo:  PropertyTreeIteratorImpl - doc - completeness/correctness
 */


/**
 * \class PropertyTreeIteratorImpl
 * \brief Property Tree iterator  implementation interface definition
 *
 */

class CORE_API PropertyTreeIteratorImpl {

public:

	/** @name public constructors */
	//@{

	PropertyTreeIteratorImpl(const PropertyTreeIteratorImpl& other);
	virtual ~PropertyTreeIteratorImpl();

	//@}

	/** @name operators - general */
	//@{
	PropertyTreeIteratorImpl& operator=(const PropertyTreeIteratorImpl& other);
	virtual Bool operator==(const PropertyTreeIteratorImpl& other) const = 0;
	 
	//@}

	 
	/** @name iteration */
	//@{
	virtual void begin() = 0;
	virtual void end() = 0;
	virtual void advance() = 0;
	virtual void reset() = 0;

	virtual Size size() const = 0;
	virtual Size sizeCurrent() const = 0;
	virtual const String first() const = 0;
	virtual const String value() const = 0;
	virtual PropertyTree tree() const = 0;
	//@}
 

	//@}
protected:

	/** @name protected constructors */
	//@{

	PropertyTreeIteratorImpl();  
	
	//@}

private:

	/** @name private  utilities */
	//@{

	void init(const PropertyTreeIteratorImpl& other);
	//@}


	 
};



DECLARE_SHARED_POINTER(PropertyTreeIteratorImpl);
DECLARE_SCOPED_POINTER(PropertyTreeIteratorImpl);


} //namespace container
} //namespace ondalear


/**
 * Makes PropertyTreeIteratorImpl accessible without ns qualification
 */ 
DECLARE_USING_ALL(ondalear::container,PropertyTreeIteratorImpl);

#endif //ONDALEAR_CONTAINER_PropertyTreeIteratorImpl_HPP



