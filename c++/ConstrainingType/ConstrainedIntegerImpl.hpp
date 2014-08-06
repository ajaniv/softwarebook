/**
 * \file ConstrainedIntegerImpl.hpp
 * \brief  Constraining an underlying Integer type interface definition  header file
 *
 * In line with the PIMPL design pattern, this class defined interface required
 * by the implementations.  ConstrainingInteger delegates to it.
 * @see ConstrainedInteger
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

#ifndef ONDALEAR_CONSTRAINED_ConstrainedIntegerImpl_HPP
#define ONDALEAR_CONSTRAINED_ConstrainedIntegerImpl_HPP




#include "core/CoreIncludes.hpp"

#include "ConstrainingTypeImpl.hpp"

namespace ondalear {
namespace constrained {


/**
  * @todo:  ConstrainedIntegerImpl - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  ConstrainedIntegerImpl - attributes/methods -  completeness/need/correctness
  * @todo:  ConstrainedIntegerImpl - unit test completeness/need/correctness
  * @todo:  ConstrainedIntegerImpl - doc - completeness/correctness
  */

/**
  * \class ConstrainedIntegerImpl
  * \brief Constraining an Integer implemenntation interface definition
  *
  * This abstract class defines the interface that specific Integer
  * constraining classes are required to implement.
  */

class CORE_API ConstrainedIntegerImpl 
	: public ConstrainingTypeImpl{

public:

	/** @name public constructors */
	//@{
	virtual ~ConstrainedIntegerImpl();
	//@}

	/** @name accessor - setters */
	//@{
	virtual void setValue(Integer value) = 0;
	virtual void setMin(Integer value) = 0;
	virtual void setMax(Integer value) = 0;
	//@}

	/** @name accessor - getters */
	//@{
	virtual Integer getValue() const = 0;
	virtual Integer getMin() const = 0;
	virtual Integer getMax() const = 0;

	virtual ConstrainedIntegerImpl* clone() const = 0;
	//@}

	
	/** @name operators - general */
	//@{

	virtual Bool operator==(const ConstrainingTypeImpl& other) const = 0;
	virtual Bool operator!=(const ConstrainingTypeImpl& other) const = 0;
	
	virtual Bool operator<(const ConstrainingTypeImpl& other) const = 0;
    virtual Bool operator<=(const ConstrainingTypeImpl& other) const = 0 ;
     
    virtual Bool operator>(const ConstrainingTypeImpl& other) const  = 0;
    virtual Bool operator>=(const ConstrainingTypeImpl& other) const = 0;
	//@}

protected:
	/** @name protected constructors */
	//@{
	ConstrainedIntegerImpl();
	//@}
};

DECLARE_SHARED_POINTER(ConstrainedIntegerImpl);
DECLARE_SCOPED_POINTER(ConstrainedIntegerImpl);

} //namespace constrained
} //namespace ondalear


DECLARE_USING_ALL(ondalear::constrained, ConstrainedIntegerImpl);

#endif //ONDALEAR_CONSTRAINED_ConstrainedIntegerImpl_HPP
