/**
 * \file BoostConstrainedIntegerImpl.hpp
 * \brief Boost implemenatation of ConstrainedIntger header file
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

#ifndef ONDALEAR_CONSTRAINED_BoostConstrainedIntegerImpl_HPP
#define ONDALEAR_CONSTRAINED_BoostConstrainedIntegerImpl_HPP




#include "core/CoreIncludes.hpp"

#include "BoostIncludes.hpp"

#include "constrained/ConstrainedIntegerImpl.hpp"



namespace ondalear {
namespace constrained {
namespace boostimpl {

/**
  * @todo:  Class - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  Class - attributes/methods -  completeness/need/correctness
  * @todo:  Class - unit test completeness/need/correctness
  * @todo:  Class - doc - completeness/correctness
  */

/**
  * \class BoostConstrainedIntegerImpl
  * \brief Boost ContainedInteger implementation
  *
  * @see boost::contained_value
  * 
  */


class CORE_API BoostConstrainedIntegerImpl 
	: public ConstrainedIntegerImpl{

public:

	//constructors
	
	BoostConstrainedIntegerImpl();
	BoostConstrainedIntegerImpl(const BoostConstrainedIntegerImpl& other );
	BoostConstrainedIntegerImpl(Integer value, Integer min, Integer max, 
		Bool lowerBoundsExclusionFlag=false,
		Bool upperBoundExclusionFlag=false);
	
	virtual ~BoostConstrainedIntegerImpl();

	//accessors
	virtual void setValue(Integer value);
	virtual void setMin(Integer value);
	virtual void setMax(Integer value);
	virtual void setUpperBoundExclusionFlag(Bool value);
	virtual void setLowerBoundExclusionFlag(Bool value);
	
	virtual Integer getValue() const;
	virtual Integer getMin() const;
	virtual Integer getMax() const;
	virtual Bool isUpperBoundExcluded() const;
	virtual Bool isLowerBoundExcluded() const;

	
	//operators general
	virtual Bool operator==(const ConstrainingTypeImpl& other) const;
	virtual Bool operator!=(const ConstrainingTypeImpl& other) const;
	
	virtual Bool operator<(const ConstrainingTypeImpl& other)  const;
    virtual Bool operator<=(const ConstrainingTypeImpl& other) const;
     
    virtual Bool operator>(const ConstrainingTypeImpl& other) const ;
    virtual Bool operator>=(const ConstrainingTypeImpl& other) const;

	//utilities
	ConstrainedIntegerImpl* clone() const; 

	virtual void reset(Integer value, Integer min, Integer max, 
		Bool lowerBoundExclusionFlag, Bool upperBoundExclusionFlag);

protected:

	//utilities	
	virtual const BoostConstrainedIntegerImpl&
		fromBase(const ConstrainingTypeImpl & other) const;

private:
	//utilities
	void init(const BoostConstrainedIntegerImpl& other);

	//typedef boost::constrained_value::bounded<int>::type BoostConstrainedInteger;

	
    typedef 
		boost::constrained_value::bounded<
            Integer,
            Integer,
            Integer,
			boost::constrained_value::throw_exception<>,
            bool,
            bool,
            std::less<Integer>
        >::type BoostConstrainedInteger;




	BoostConstrainedInteger implRep;


};

DECLARE_SHARED_POINTER(BoostConstrainedIntegerImpl);
DECLARE_SCOPED_POINTER(BoostConstrainedIntegerImpl);

} //namespace boostimpl
} //namespace constrained
} //namespace ondalear


DECLARE_USING_ALL(ondalear::constrained::boostimpl, BoostConstrainedIntegerImpl);

#endif //ONDALEAR_CONSTRAINED_BoostConstrainedIntegerImpl_HPP
