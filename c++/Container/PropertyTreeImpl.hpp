/**
 * \file PropertyTreeImpl.hpp
 * \brief Property Tree Implementation header file.
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


#ifndef ONDALEAR_CONTAINER_PropertyTreeImpl_HPP
#define ONDALEAR_CONTAINER_PropertyTreeImpl_HPP


#include "core/CoreIncludes.hpp"

namespace ondalear {
namespace container {



	
/**
 * @todo:  PropertyTreeImpl - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  PropertyTreeImpl - attributes/methods -  completeness/need/correctness
 * @todo:  PropertyTreeImpl - unit test completeness/need/correctness
 * @todo:  PropertyTreeImpl - doc - completeness/correctness
 */


/**
 * \class PropertyTreeImpl
 * \brief PropertyTree implementation interface definition
 *
 */

class CORE_API PropertyTreeImpl {

public:

	/** @name public constructors */
	//@{

	 
	virtual ~PropertyTreeImpl();

	//@}

	/** @name operators - general */
	//@{

	virtual Bool operator==(const PropertyTreeImpl& other) const = 0;
	//@}

	/** @name public set value */
	//@{

	virtual void setString(const String& key, const String& value) = 0;
	virtual void setString(const String& path, const String& key, const String& value) = 0;

	virtual void setTree(const String& key, const PropertyTreeImpl& value) = 0;
	virtual void setTree(const String& path, const String& key, const PropertyTreeImpl& value) = 0;

	//@}

	/** @name public get value */
	//@{

	virtual String getString(const String& key) const = 0;
	virtual String getString(const String& path, const String& key) const = 0;
	virtual String getStringOrDefault(const String& key, const String& defaultValue) const = 0;
	virtual String getStringOrDefault(const String& path, const String& key, const String& defaultValue) const = 0;

	virtual PropertyTreeImpl* getTree(const String& key) const = 0;
	virtual PropertyTreeImpl* getTree(const String& key, const String& path) = 0;
	
	//@}

	/** @name public accessor */
	//@{
	virtual void setPathSeparator(const String& separator);
	virtual const String& getPathSeparator() const;
	//@}

 	/** @name public utilities */
	//@{
	virtual Bool isEmpty() const = 0;

	virtual Size size() const = 0;
	virtual Size size(const String& path) const = 0;

	virtual void clear() = 0;
	virtual void clear(const String& path) = 0 ;

	virtual void remove(const String& key) = 0;
	virtual void remove(const String& path, const String& key) = 0;

	virtual void writeTo(const String& fileName) const = 0;
	//@}

protected:

	/** @name protected constructors */
	//@{

	PropertyTreeImpl();/**< empty constructor*/  
	
	//@}

private:

	/** @name private constructors */
	//@{
	PropertyTreeImpl& operator=(const PropertyTreeImpl& other);
	PropertyTreeImpl(const PropertyTreeImpl& other);
	//@}
 	String pathSeparator;
	 
};



DECLARE_SHARED_POINTER(PropertyTreeImpl);
DECLARE_SCOPED_POINTER(PropertyTreeImpl);


} //namespace container
} //namespace ondalear


/**
 * Makes PropertyTreeImpl accessible without ns qualification
 */ 
DECLARE_USING_ALL(ondalear::container,PropertyTreeImpl);

#endif //ONDALEAR_CONTAINER_PropertyTreeImpl_HPP



