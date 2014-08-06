/**
 * \file BoostPropertyTreeImpl.hpp
 * \brief Boost Property Tree implementation header file
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


#ifndef ONDALEAR_CONTAINER_BoostPropertyTreeImpl_HPP
#define ONDALEAR_CONTAINER_BoostPropertyTreeImpl_HPP

#include <boost/lexical_cast.hpp>
#if defined (_MSC_VER)
#pragma warning(disable:4996)
#include <boost/property_tree/ptree.hpp>
#else
#include <boost/property_tree/ptree.hpp>
#endif


#include "core/CoreIncludes.hpp"


#include "../PropertyTreeImpl.hpp"
#include "../ContainerConstants.hpp"



namespace ondalear {
namespace container {
namespace boostimpl {

/**
  * @todo:  BoostPropertyTreeImpl - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  BoostPropertyTreeImpl - attributes/methods -  completeness/need/correctness
  * @todo:  BoostPropertyTreeImpl - unit test completeness/need/correctness
  * @todo:  BoostPropertyTreeImpl - doc - completeness/correctness
  * @todo:  BoostPropertyTreeImpl - Force an exception to happen, enusre proper recovery
  * @todo:  BoostPropertyTreeImpl - asses impact of introducing dependency on boost lexical cast
  */



typedef boost::property_tree::ptree BoostPropertyTreeRep;

/**
  * \class BoostPropertyTreeImpl
  * \brief Boost Property Tree  implementation
  *
  */


class CORE_API BoostPropertyTreeImpl : 
	public PropertyTreeImpl{

public:
	/** @name public constructors */
	//@{

	BoostPropertyTreeImpl();
	BoostPropertyTreeImpl(const BoostPropertyTreeImpl& other);
	BoostPropertyTreeImpl(const BoostPropertyTreeRep& implRep);

	~BoostPropertyTreeImpl();
	 
	//@}

 


	 
	/** @name public operators general */
	//@{
	BoostPropertyTreeImpl& operator=(const BoostPropertyTreeImpl& other);

	virtual Bool operator==(const PropertyTreeImpl& other) const;
	//@}

	/** @name public set value */
	//@{

	virtual void setString(const String& key, const String& value);
	virtual void setString(const String& path, const String& key, const String& value);

	virtual void setTree(const String& key, const PropertyTreeImpl& value);
	virtual void setTree(const String& path, const String& key, const PropertyTreeImpl& value);
	
	template <typename T>  void set(const String& key, const T& value);
	template <typename T>  void set(const String& path, const String& key, const T& value);

	//@}

	/** @name public get value */
	//@{

	virtual String getString(const String& key) const;
	virtual String getString(const String& path, const String& key) const;
	virtual String getStringOrDefault(const String& key, const String& defaultValue) const;
	virtual String getStringOrDefault(const String& path, const String& key, const String& defaultValue) const;

	virtual PropertyTreeImpl* getTree(const String& key) const;
	virtual PropertyTreeImpl* getTree(const String& path, const String& key );


	template <typename T>  T get(const String& key) const;
	template <typename T>  T get(const String& path, const String& key) const;
	template <typename T>  T getOrDefault(const String& key, const T& defaultValue) const;
	template <typename T>  T getOrDefault(const String& path, const String& key, const T& defaultValue) const;
	
	//@}

	/** @name public utilities */
	//@{
	virtual Bool isEmpty() const;

	virtual Size size() const;
	virtual Size size(const String& path) const;

	virtual void clear() ;
	virtual void clear(const String& path) ;

	virtual void remove(const String& key);
	virtual void remove(const String& path, const String& key);

	virtual void writeTo(const String& fileName) const;
	//@}

	/** @name public accessor */
	//@{
	BoostPropertyTreeRep& getImplRep();
	const BoostPropertyTreeRep& getImplRep() const;
	//@}

protected:

	/** @name protected utilities */
	//@{
	 
	virtual BoostPropertyTreeRep* findNode(BoostPropertyTreeRep& root, const String& path, 
								bool throwWhenMissing=true) ;

	virtual const BoostPropertyTreeRep* findNode(const BoostPropertyTreeRep& root, const String& path, 
								bool throwWhenMissing=true) const ;

	virtual String getStringValue(const BoostPropertyTreeRep& tree) const;

	virtual void removeKey(BoostPropertyTreeRep& node, const String& key);

	virtual void insertOrReplace(BoostPropertyTreeRep& tree, const String& key, const String& value);
	virtual void insertOrReplace(BoostPropertyTreeRep& tree, const String& key, const BoostPropertyTreeRep& value);
	virtual void addChild(BoostPropertyTreeRep& tree, const String& path, const String& key, const String& value);
	virtual void addChild(BoostPropertyTreeRep& tree, const String& path, const String& key, const BoostPropertyTreeRep& value);
	virtual BoostPropertyTreeImpl* getTree(const BoostPropertyTreeRep& tree, const String& key) const;


	//@}
private:
	/** @name private constructors */
	//@{

	void init (const BoostPropertyTreeImpl& other);
	//@}


	BoostPropertyTreeRep implRep;
	

	
};

DECLARE_SHARED_POINTER(BoostPropertyTreeImpl);
DECLARE_SCOPED_POINTER(BoostPropertyTreeImpl);


template <typename T>  
inline void 
BoostPropertyTreeImpl::set(const String& key, const T& value)
{
	setString(key, boost::lexical_cast<String>(value));
}

template <typename T>
inline void 
BoostPropertyTreeImpl::set(const String& path, const String& key, const T& value)
{
	setString(path, key, boost::lexical_cast<String>(value));
}

template <typename T>  
inline T 
BoostPropertyTreeImpl::get(const String& key) const
{
	String value = getString(key);
	return boost::lexical_cast<T>(value);
}

template <typename T>  
inline T 
BoostPropertyTreeImpl::getOrDefault(const String& key, const T& defaultValue) const
{
	String dummyDefault = ContainerConstants::dummyDefaultValue();
	String strValue = getStringOrDefault(key, dummyDefault);
	
	return strValue  != dummyDefault ? boost::lexical_cast<T>(strValue) : defaultValue;
}


template <typename T>  
inline T 
BoostPropertyTreeImpl::get(const String& path, const String& key) const
{
	String value = getString(path, key);
	return boost::lexical_cast<T>(value);
}


template <typename T>  
inline T 
BoostPropertyTreeImpl::getOrDefault(const String& path, const String& key, const T& defaultValue) const
{
	String dummyDefault = ContainerConstants::dummyDefaultValue();
	String strValue = getStringOrDefault(path, key, dummyDefault);
	return strValue  != dummyDefault ? boost::lexical_cast<T>(strValue) : defaultValue;
}


} //namespace boostimpl
} //namespace container
} //namespace ondalear


DECLARE_USING_ALL(ondalear::container::boostimpl,BoostPropertyTreeImpl);

#endif //ONDALEAR_CONTAINER_BoostPropertyTreeImpl_HPP
