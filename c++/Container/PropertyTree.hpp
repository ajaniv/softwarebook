/**
 * \file PropertyTree.hpp
 * \brief Property Tree  header file.
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


#ifndef ONDALEAR_CONTAINER_PropertyTree_HPP
#define ONDALEAR_CONTAINER_PropertyTree_HPP

#include <boost/lexical_cast.hpp>

#include "core/CoreIncludes.hpp"
#include "core/CoreText.hpp"

#include "ContainerConstants.hpp"

#include "PropertyTreeIterator.hpp"


namespace ondalear {
namespace container {



	
/**
 * @todo:  PropertyTree - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  PropertyTree - design/imple -  tight coupling with boost lexical cast
 * @todo:  PropertyTree - attributes/methods -  completeness/need/correctness
 * @todo:  PropertyTree - unit test completeness/need/correctness
 * @todo:  PropertyTree - doc - completeness/correctness

 */
DECLARE_SCOPED_POINTER(PropertyTreeImpl);

/**
 * \class PropertyTree
 * \brief A container which manages properties typically used to configure components/applications
 *
 */



class CORE_API PropertyTree {

public:

	/** @name public constructors */
	//@{

	PropertyTree();
	PropertyTree (const PropertyTree& other);

	virtual ~PropertyTree();

	//@}

	/** @name operators - general */
	//@{

	PropertyTree& operator=(const PropertyTree &other);
	Bool operator==(const PropertyTree& other) const;
	Bool operator!=(const PropertyTree& other) const;

	//@}

	/** @name public set value */
	//@{

	virtual void setString(const String& key, const String& value);
	virtual void setString(const String& path, const String& key, const String& value);

	virtual void setTree(const String& key, const PropertyTree& value);
	virtual void setTree(const String& path, const String& key, const PropertyTree& value);


	
	template <typename T>  void set(const String& key, const T& value);
	template <typename T>  void set(const String& path, const String& key, const T& value);

	//@}

	/** @name public get value */
	//@{

	virtual String getString(const String& key) const;
	virtual String getString(const String& path, const String& key) const;
	virtual String getStringOrDefault(const String& key, const String& defaultValue) const;
	virtual String getStringOrDefault(const String& path, const String& key, const String& defaultValue) const;

	virtual PropertyTree getTree(const String& key) const;
	virtual PropertyTree getTree(const String& path, const String& key) const;

	template <typename T>  T get(const String& key) const;
	template <typename T>  T get(const String& path, const String& key) const;
	template <typename T>  T getOrDefault(const String& key, const T& defaultValue) const;
	template <typename T>  T getOrDefault(const String& path, const String& key, const T& defaultValue) const;
	
	//@}
	
	/** @name public utilities */
	//@{

	virtual Bool propertyExists(const String& key) const;
	virtual Bool propertyExists(const String& path, const String& key) const;

	virtual Bool isEmpty() const;

	virtual Size size() const;
	virtual Size size(const String& path) const;

	virtual void clear() ;
	virtual void clear(const String& path) ;

	virtual void remove(const String& key);
	virtual void remove(const String& path, const String& key);


	//@}

	/** @name iteration */
	//@{

	virtual const PropertyTreeIterator begin() const;


	virtual const PropertyTreeIterator end() const;
	//@}
protected:

	/** @name protected constructors */
	//@{

	PropertyTree(PropertyTreeImpl* impl); 
	
	//@}
	 
	/** @name protected accessors */
	//@{
	PropertyTreeImplScopedPtr& getImpl();
	const PropertyTreeImplScopedPtr& getImpl() const;
	//@}

	
private:

	/** @name private utilities */
	//@{

	void init(const PropertyTree& other);

	//@}

	PropertyTreeImplScopedPtr impl;
	
};


DECLARE_SHARED_POINTER(PropertyTree);



template <typename T>  
inline void 
PropertyTree::set(const String& key, const T& value)
{
	try{
		setString(key, boost::lexical_cast<String>(value));
	}
	catch (std::exception& ex) {
		THROW_MSG(CoreText::instance().conversionFailure(ex.what()));
	}
}

template <typename T>
inline void 
PropertyTree::set(const String& path, const String& key, const T& value)
{
	try{
		setString(path, key, boost::lexical_cast<String>(value));
	}
	catch (std::exception& ex) {
		THROW_MSG(CoreText::instance().conversionFailure(ex.what()));
	}
}

template <typename T>  
inline T 
PropertyTree::get(const String& key) const
{
	String strValue = getString(key);
	try {

		T typedValue =  boost::lexical_cast<T>(strValue);
		return typedValue;
	}
	catch (std::exception& ex) {
		THROW_MSG(CoreText::instance().conversionFailure(ex.what()));
	}
}

template <typename T>  
inline T 
PropertyTree::getOrDefault(const String& key, const T& defaultValue) const
{
	String dummyDefault = ContainerConstants::dummyDefaultValue();
	String strValue = getStringOrDefault(key, dummyDefault);
	
	
	try {
		T typedValue = strValue  != dummyDefault ? boost::lexical_cast<T>(strValue) : defaultValue;
		return typedValue;
	}
	catch (std::exception& ex) {
		THROW_MSG(CoreText::instance().conversionFailure(ex.what()));
	}
}


template <typename T>  
inline T 
PropertyTree::get(const String& path, const String& key) const
{
	String strValue = getString(path, key);
	
	try{
		T typedValue = boost::lexical_cast<T>(strValue);
		return typedValue;
	}
	catch (std::exception& ex) {
		THROW_MSG(CoreText::instance().conversionFailure(ex.what()));
	}
}


template <typename T>  
inline T 
PropertyTree::getOrDefault(const String& path, const String& key, const T& defaultValue) const
{
	String dummyDefault = ContainerConstants::dummyDefaultValue();
	String strValue = getStringOrDefault(path, key, dummyDefault);
	
	try{
		T typedValue = strValue  != dummyDefault ? boost::lexical_cast<T>(strValue) : defaultValue;
		return typedValue;
	}
	catch (std::exception& ex) {
		THROW_MSG(CoreText::instance().conversionFailure(ex.what()));
	}
}


} //namespace container
} //namespace ondalear



DECLARE_USING_DEFAULT(ondalear::container,PropertyTree);

#endif //ONDALEAR_CONTAINER_PropertyTree_HPP



