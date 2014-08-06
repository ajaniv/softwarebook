/**
 * \file PropertyTreeIterator.hpp
 * \brief Property Tree Iterator  header file.
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


#ifndef ONDALEAR_CONTAINER_PropertyTreeIterator_HPP
#define ONDALEAR_CONTAINER_PropertyTreeIterator_HPP


#include <boost/lexical_cast.hpp>

#include "core/CoreIncludes.hpp"



namespace ondalear {
namespace container {


class PropertyTree;
	
/**
 * @todo:  PropertyTreeIterator - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  PropertyTreeIterator - attributes/methods -  completeness/need/correctness
 * @todo:  PropertyTreeIterator - unit test completeness/need/correctness
 * @todo:  PropertyTreeIterator - doc - completeness/correctness

 */
DECLARE_SCOPED_POINTER(PropertyTreeIteratorImpl);

/**
 * \class PropertyTreeIterator
 * \brief Property Tree Iterator 
 *
 */



class CORE_API PropertyTreeIterator {

public:

	/** @name public constructors */
	//@{

	PropertyTreeIterator();
	PropertyTreeIterator (const PropertyTreeIterator& other);

	virtual ~PropertyTreeIterator();

	//@}

	/** @name operators - general */
	//@{

	PropertyTreeIterator& operator=(const PropertyTreeIterator &other);
	Bool operator==(const PropertyTreeIterator& other) const;
	Bool operator!=(const PropertyTreeIterator& other) const;

	//@}

	/** @name iteration */
	//@{
	virtual void begin();
	virtual void end();
	virtual void reset();

	PropertyTreeIterator& operator++();
    PropertyTreeIterator operator++(int dummy);

	virtual Size size() const;
	virtual Size sizeCurrent() const;
	
	virtual const String first() const;
	virtual const String value() const;
	template <typename T>  T get() const;

	virtual PropertyTree tree() const;


	//@}
protected:

	/** @name protected constructors */
	//@{

	PropertyTreeIterator(PropertyTreeIteratorImpl* impl); 
	
	//@}
	 
	/** @name protected accessors */
	//@{
	PropertyTreeIteratorImplScopedPtr& getImpl();
	const PropertyTreeIteratorImplScopedPtr& getImpl() const;
	//@}

	
private:

	/** @name private utilities */
	//@{

	void init(const PropertyTreeIterator& other);

	//@}

	PropertyTreeIteratorImplScopedPtr impl;
	
};



template <typename T>  
inline T 
PropertyTreeIterator::get() const
{
	String strValue = value();
	return boost::lexical_cast<T>(strValue);
}


} //namespace container
} //namespace ondalear



DECLARE_USING_TYPE(ondalear::container,PropertyTreeIterator);

#endif //ONDALEAR_CONTAINER_PropertyTreeIterator_HPP



