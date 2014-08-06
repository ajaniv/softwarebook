/**
 * \file ConstrainingTypeImpl.hpp
 * \brief Interface definition for constraining type implementation header file.
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

#ifndef ONDALEAR_CONSTRAINED_ConstrainingTypeImpl_HPP
#define ONDALEAR_CONSTRAINED_ConstrainingTypeImpl_HPP


#include "core/CoreIncludes.hpp"

 


namespace ondalear {
namespace constrained {


/**
 * @todo:  ConstrainingTypeImpl - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  ConstrainingTypeImpl - attributes/methods -  completeness/need/correctness
 * @todo:  ConstrainingTypeImpl - unit test completeness/need/correctness
 * @todo:  ConstrainingTypeImpl - doc - completeness/correctness
 */

/**
  * \class ConstrainingTypeImpl
  * \brief Constraining type common implementation interface definition
  *
  * This class defines the minimal interface derived type implementations needs to implement
  */
class CORE_API ConstrainingTypeImpl{

public:
	/** @name public constructors */
	//@{
	virtual ~ConstrainingTypeImpl();
	//@}

	
	/** @name accessor - setters */
	//@{
	virtual void setUpperBoundExclusionFlag(Bool value) = 0;
	virtual void setLowerBoundExclusionFlag(Bool value) = 0;
	//@}

	/** @name accessor - getters */
	//@{
	virtual Bool isUpperBoundExcluded() const = 0;
	virtual Bool isLowerBoundExcluded() const = 0;
	//@}
	
	/** @name utilities */
	//@{
	virtual ConstrainingTypeImpl* clone() const = 0;
	//@}
	
	/** @name operators - general */
	//@{
	virtual Bool operator==(const ConstrainingTypeImpl& other) const = 0;
	virtual Bool operator!=(const ConstrainingTypeImpl& other) const = 0;
	
	virtual Bool operator<(const ConstrainingTypeImpl& other) const = 0;
    virtual Bool operator<=(const ConstrainingTypeImpl& other) const = 0 ;
     
    virtual Bool operator>(const ConstrainingTypeImpl& other) const = 0;
    virtual Bool operator>=(const ConstrainingTypeImpl& other) const = 0;
	//@}

protected:
	/** @name protected constructors */
	//@{
	ConstrainingTypeImpl();
	//@}
};

DECLARE_SHARED_POINTER(ConstrainingTypeImpl);
DECLARE_SCOPED_POINTER(ConstrainingTypeImpl);

} //namespace constrained
} //namespace ondalear

DECLARE_USING_ALL(ondalear::constrained,ConstrainingTypeImpl);


#endif //ONDALEAR_CONSTRAINED_ConstrainingTypeImpl_HPP