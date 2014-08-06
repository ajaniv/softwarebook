
/**
 * \file ConstrainingType.hpp
 * \brief Base template abstraction for constrained values header file
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
 
#ifndef ONDALEAR_CONSTRAINED_ConstrainingType_HPP
#define ONDALEAR_CONSTRAINED_ConstrainingType_HPP





#include "core/CoreIncludes.hpp"

namespace ondalear {
namespace constrained {

/**
 * @todo:  ConstrainingType - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  ConstrainingType - attributes/methods -  completeness/need/correctness
 * @todo:  ConstrainingType - unit test completeness/need/correctness
 * @todo:  ConstrainingType - doc - completeness/correctness
 * @todo:  ConstrainingType - design/impl - add search capability by query
 * @todo:  ConstrainingType - heavy implementation cost for separation of interface from implementation
 * @todo:  ConstrainingType - review protected attribute, determine whether alternative exists
 */


/**
  * \class ConstrainingType
  * \brief Template for a type which constrains underlying types
  *
  *  This abstraction is to be extended by derived template instantiation
  *  and defines the common interface required.
  */

template <
	typename UnderlyingType, 
	typename ImplType,
	typename ImplSmartPtr >

class CORE_API ConstrainingType {

public:
	 
	/** @name public constructors */
	//@{
	virtual ~ConstrainingType();
	//@}

	
	/** @name accessor - setters */
	//@{
	virtual void setValue(UnderlyingType value);
	virtual void setMin(UnderlyingType value);
	virtual void setMax(UnderlyingType value);
	virtual void setUpperBoundExclusionFlag(Bool value);
	virtual void setLowerBoundExclusionFlag(Bool value);
	//@}

	
	/** @name accessor - getters */
	//@{
	virtual UnderlyingType getValue() const;
	virtual UnderlyingType getMin() const;
	virtual UnderlyingType getMax() const;
	virtual Bool isUpperBoundExcluded() const;
	virtual Bool isLowerBoundExcluded() const;
	//@}

	
	/** @name operators - general */
	//@{
	ConstrainingType& operator=(const ConstrainingType& other);
	ConstrainingType& operator=(UnderlyingType value);

	Bool operator==(const ConstrainingType& other) const;
	Bool operator!=(const ConstrainingType& other) const;
	
	Bool operator<(const ConstrainingType& other) const;
    Bool operator<=(const ConstrainingType& other) const;
     
    Bool operator>(const ConstrainingType& other) const;
    Bool operator>=(const ConstrainingType& other) const;
	//@}

protected:
	 
	/** @name protected constructors */
	//@{
	ConstrainingType(ImplType* ptr);
	ConstrainingType(const ConstrainingType& other);
	//@}
	
	ImplSmartPtr impl;


private:
	//utililities
	/** @name utililities */
	//@{
	void init(const ConstrainingType& other);
	//@}
};

//public - constructor

template <typename UnderlyingType, typename ImplType, typename ImplSmartPtr>
ConstrainingType< UnderlyingType, ImplType, ImplSmartPtr >::~ConstrainingType()
{
}

//public - accessor


template <typename UnderlyingType, typename ImplType, typename ImplSmartPtr>
void
ConstrainingType< UnderlyingType, ImplType, ImplSmartPtr >::setValue(UnderlyingType value)
{
	impl->setValue(value);
}

template <typename UnderlyingType, typename ImplType, typename ImplSmartPtr>
void
ConstrainingType< UnderlyingType, ImplType, ImplSmartPtr >::setMin(UnderlyingType value)
{
	impl->setMin(value);
}

template <typename UnderlyingType, typename ImplType, typename ImplSmartPtr>
void
ConstrainingType< UnderlyingType, ImplType, ImplSmartPtr >::setMax(UnderlyingType value)
{
	impl->setMax(value);
}

template <typename UnderlyingType, typename ImplType, typename ImplSmartPtr>
void
ConstrainingType< UnderlyingType, ImplType, ImplSmartPtr >::setUpperBoundExclusionFlag(Bool value)
{
	impl->setUpperBoundExclusionFlag(value);
}

template <typename UnderlyingType, typename ImplType, typename ImplSmartPtr>
void
ConstrainingType< UnderlyingType, ImplType, ImplSmartPtr >::setLowerBoundExclusionFlag(Bool value)
{
	impl->setLowerBoundExclusionFlag(value);
}


template <typename UnderlyingType, typename ImplType, typename ImplSmartPtr>
UnderlyingType
ConstrainingType< UnderlyingType, ImplType, ImplSmartPtr >::getValue() const
{
	return impl->getValue();
}

template <typename UnderlyingType, typename ImplType, typename ImplSmartPtr>
UnderlyingType
ConstrainingType< UnderlyingType, ImplType, ImplSmartPtr >::getMin() const
{
	return impl->getMin();
}

template <typename UnderlyingType, typename ImplType, typename ImplSmartPtr>
UnderlyingType
ConstrainingType< UnderlyingType, ImplType, ImplSmartPtr >::getMax() const
{
	return impl->getMax();
}

template <typename UnderlyingType, typename ImplType, typename ImplSmartPtr>
Bool
ConstrainingType< UnderlyingType, ImplType, ImplSmartPtr >::isUpperBoundExcluded() const
{
	return impl->isUpperBoundExcluded();
}

template <typename UnderlyingType, typename ImplType, typename ImplSmartPtr>
Bool
ConstrainingType< UnderlyingType, ImplType, ImplSmartPtr >::isLowerBoundExcluded() const
{
	return impl->isLowerBoundExcluded();
}


//operators - general
template <typename UnderlyingType, typename ImplType, typename ImplSmartPtr>
ConstrainingType < UnderlyingType, ImplType, ImplSmartPtr > &
ConstrainingType< UnderlyingType, ImplType, ImplSmartPtr >::operator=(
	const ConstrainingType< UnderlyingType, ImplType, ImplSmartPtr >& other)
{
	if (this != &other){
		init(other);
	}
	return *this;
}

template <typename UnderlyingType, typename ImplType, typename ImplSmartPtr>
ConstrainingType < UnderlyingType, ImplType, ImplSmartPtr > &
ConstrainingType< UnderlyingType, ImplType, ImplSmartPtr >::operator=(UnderlyingType value)
{
	impl->setValue(value);
	return *this;
}

template <typename UnderlyingType, typename ImplType, typename ImplSmartPtr>
Bool
ConstrainingType< UnderlyingType, ImplType, ImplSmartPtr >::operator==(const ConstrainingType< UnderlyingType, ImplType, ImplSmartPtr >& other) const
{
	return this == &other 
		? true
		: *this->impl == *other.impl;
	 
}

template <typename UnderlyingType, typename ImplType, typename ImplSmartPtr>
Bool
ConstrainingType< UnderlyingType, ImplType, ImplSmartPtr >::operator!=(const ConstrainingType< UnderlyingType, ImplType, ImplSmartPtr >& other) const
{
	return ! this->operator== (other);
}

template <typename UnderlyingType, typename ImplType, typename ImplSmartPtr>
Bool
ConstrainingType< UnderlyingType, ImplType, ImplSmartPtr >::operator<(const ConstrainingType< UnderlyingType, ImplType, ImplSmartPtr >& other) const
{
	return   *this->impl < *other.impl;
}

template <typename UnderlyingType, typename ImplType, typename ImplSmartPtr>
Bool
ConstrainingType< UnderlyingType, ImplType, ImplSmartPtr >::operator<=(const ConstrainingType< UnderlyingType, ImplType, ImplSmartPtr >& other) const
{
	return   *this->impl <= *other.impl;
}

template <typename UnderlyingType, typename ImplType, typename ImplSmartPtr>
Bool
ConstrainingType< UnderlyingType, ImplType, ImplSmartPtr >::operator>(const ConstrainingType< UnderlyingType, ImplType, ImplSmartPtr >& other) const
{
	return   *this->impl > *other.impl;
}

template <typename UnderlyingType, typename ImplType, typename ImplSmartPtr>
Bool
ConstrainingType< UnderlyingType, ImplType, ImplSmartPtr >::operator>=(const ConstrainingType< UnderlyingType, ImplType, ImplSmartPtr >& other) const
{
	return   *this->impl >= *other.impl;
}

//protected - constructor

template <typename UnderlyingType, typename ImplType, typename ImplSmartPtr>
ConstrainingType< UnderlyingType, ImplType, ImplSmartPtr >::ConstrainingType(ImplType* ptr)
	:
	impl(ptr)
{
}

template <typename UnderlyingType, typename ImplType, typename ImplSmartPtr>
ConstrainingType< UnderlyingType, ImplType, ImplSmartPtr >::ConstrainingType(const ConstrainingType& other)
	 
{
	init(other);
}


//private  - utilities
template <typename UnderlyingType, typename ImplType, typename ImplSmartPtr>
void
ConstrainingType< UnderlyingType, ImplType, ImplSmartPtr >::init(const ConstrainingType& other)
	 
{

	this->impl.reset(other.impl->clone());
	
}


} //namespace constrained
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::constrained,ConstrainingType);

#endif //ONDALEAR_CONSTRAINED_ConstrainingType_HPP
