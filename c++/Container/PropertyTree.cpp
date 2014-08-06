/**
 * \file PropertyTree.cpp
 * \brief Property Tree  source file.
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



#include "PropertyTree.hpp"

#include "core/StringUtil.hpp"

#include "ContainerRegistry.hpp"
#include "PropertyTreeImpl.hpp"

namespace ondalear {
namespace container {

/*
 *
 * public constructors
 *
 */

PropertyTree::PropertyTree()
	:
	impl(ContainerRegistry::instance().getFactory()->createPropertyTreeImpl())
{
}

 


PropertyTree::PropertyTree (const PropertyTree& other)
{
	init(other);
}


PropertyTree::~PropertyTree()
{
}

 
/*
 *
 * public operators - general
 *
 */
PropertyTree&
PropertyTree::operator=(const PropertyTree &other)
{
	if (this != &other){
		init(other);
	}
	return *this;
}



Bool
PropertyTree::operator==(const PropertyTree& other) const
{
	return *this->impl == *other.impl;
}

Bool
PropertyTree::operator!=(const PropertyTree& other) const
{
	return ! (*this == other);
}

/*
 *
 * public public set value
 *
 */
	

void
PropertyTree::setString(const String& key, const String& value)
{
	impl->setString(key, value);
}

void
PropertyTree::setString(const String& path, const String& key, const String& value) 
{
	impl->setString(path, key, value);
}


void 
PropertyTree::setTree(const String& key, const PropertyTree& value)
{
	impl->setTree(key, *value.impl.get());
}

void
PropertyTree::setTree(const String& path, const String& key, const PropertyTree& value)
{
	impl->setTree(path, key, *value.impl.get());
}

/*
 *
 * public public get value
 *
 */

String
PropertyTree::getString(const String& key) const
{
	return impl->getString(key);
}

String
PropertyTree::getString(const String& path, const String& key) const 
{
	return impl->getString(path, key);
}

String
PropertyTree::getStringOrDefault(const String& key, const String& defaultValue) const 
{
	return impl->getStringOrDefault(key, defaultValue);
}

String
PropertyTree::getStringOrDefault(const String& path, const String& key, const String& defaultValue) const 
{
	return impl->getStringOrDefault(path, key, defaultValue);
}


PropertyTree
PropertyTree::getTree(const String& key) const
{

	PropertyTree tree;
	tree.impl.reset(impl->getTree(key));
	return tree;
}

PropertyTree
PropertyTree::getTree(const String& path, const String& key) const
{
	PropertyTree tree;
	tree.impl.reset(impl->getTree(path, key));
	return tree;
}
/*
 *
 * public public utilities
 *
 */


Bool
PropertyTree::isEmpty() const
{
	return impl->isEmpty();
}

Bool
PropertyTree::propertyExists(const String& key) const
{
	String defaultValue = ContainerConstants::dummyDefaultValue();
	String value =  getStringOrDefault(key, defaultValue);
	return value != defaultValue ? true : false;
}

Bool
PropertyTree::propertyExists(const String& path, const String& key) const
{
	String defaultValue = ContainerConstants::dummyDefaultValue();
	String value =  getStringOrDefault(path, key, defaultValue);
	return value != defaultValue ? true : false;

}

Size
PropertyTree::size() const
{
	return impl->size();
}


Size
PropertyTree::size(const String& path) const
{
	return impl->size(path);
}

void
PropertyTree::clear() 
{
	return impl->clear();
}

void
PropertyTree::clear(const String& path) 
{
	return impl->clear(path);
}

void
PropertyTree::remove(const String& key)
{
	impl->remove(key);
}

void
PropertyTree::remove(const String& path, const String& key)
{
	impl->remove(path, key);
}

/*
 *
 * public  iteration 
 */



const PropertyTreeIterator
PropertyTree::begin() const
{
	PropertyTreeIterator iter = ContainerRegistry::instance().getFactory()->createPropertyTreeIterator(*impl);
	return iter;
}



const PropertyTreeIterator
PropertyTree::end() const
{
	PropertyTreeIterator iter = ContainerRegistry::instance().getFactory()->createPropertyTreeIterator(*impl, true);
	return iter;
}



/*
 *
 * protected constructors 
 */

PropertyTree::PropertyTree(PropertyTreeImpl* impl)
	: impl(impl)
{
}

/*
 *
 * protected accessors
 */
PropertyTreeImplScopedPtr&
PropertyTree::getImpl()
{
	return impl;
}


const PropertyTreeImplScopedPtr&
PropertyTree::getImpl() const
{
	return impl;
}


/*
 *
 * private utilities
 *
 */
void
PropertyTree::init(const PropertyTree& other )
{
	const PropertyTreeImpl* otherImpl = other.impl.get();
	impl.reset(
		 ContainerRegistry::instance().getFactory()->createPropertyTreeImpl(*otherImpl)) ;
}


} //namespace container
} //namespace ondalear

