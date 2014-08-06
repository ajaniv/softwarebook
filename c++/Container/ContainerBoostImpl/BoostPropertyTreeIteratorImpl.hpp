/**
 * \file BoostPropertyTreeIteratorImpl.hpp
 * \brief Boost property tree iterator abstraction header file
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


#ifndef ONDALEAR_CONTAINER_BoostPropertyTreeIteratorImpl_HPP
#define ONDALEAR_CONTAINER_BoostPropertyTreeIteratorImpl_HPP



#include "core/CoreIncludes.hpp"

#include "BoostContainerImplIncludes.hpp"

#include "../PropertyTreeIteratorImpl.hpp"

namespace ondalear {
namespace container {
namespace boostimpl {


/**
  * @todo:  BoostPropertyTreeIteratorImpl - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  BoostPropertyTreeIteratorImpl - attributes/methods -  completeness/need/correctness
  * @todo:  BoostPropertyTreeIteratorImpl - unit test completeness/need/correctness
  * @todo:  BoostPropertyTreeIteratorImpl - doc - completeness/correctness
  */

/**
  * \class BoostPropertyTreeIteratorImpl
  * \brief Boost proprty tree iterator 
  *
  */

class CORE_API BoostPropertyTreeIteratorImpl :
	public PropertyTreeIteratorImpl{
	

public:
	/** @name public constructors */
	//@{

	BoostPropertyTreeIteratorImpl();
	BoostPropertyTreeIteratorImpl(const BoostPropertyTreeRep& implRep);
	BoostPropertyTreeIteratorImpl(const BoostPropertyTreeIteratorImpl& other);
	//@}


	/** @name operators - general */
	//@{

	BoostPropertyTreeIteratorImpl& operator=(const BoostPropertyTreeIteratorImpl &other);
	virtual Bool operator==(const PropertyTreeIteratorImpl& other) const ;
	virtual Bool operator==(const BoostPropertyTreeIteratorImpl& other) const;

	//@}
	
	/** @name iteration */
	//@{
	virtual void begin();
	virtual void end();
	virtual void advance();
	virtual void reset();

	virtual Size size() const;
	virtual Size sizeCurrent() const;
	virtual const String first() const ;
	virtual const String value() const ;
	virtual PropertyTree tree() const;
	//@}
private:
	void init(const BoostPropertyTreeIteratorImpl& other);
	
	BoostPropertyTreeRep implRep;
	 
	int offset;

};



} //namespace boostimpl
} //namespace container
} //namespace ondalear


DECLARE_USING_TYPE(ondalear::container::boostimpl,BoostPropertyTreeIteratorImpl);

#endif //ONDALEAR_CONTAINER_BoostPropertyTreeIteratorImpl_HPP
