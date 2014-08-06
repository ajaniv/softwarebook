/**
 * \file BoostPropertyTreeImpl.cpp
 * \brief Boost Property Tree implementation source file
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

#include "BoostPropertyTreeImpl.hpp"


#include <boost/lexical_cast.hpp>
#include <boost/property_tree/xml_parser.hpp>

#include "core/CoreText.hpp"

namespace ondalear {
namespace container {
namespace boostimpl {

	

/*
 *
 * public constructors
 *
 */

BoostPropertyTreeImpl::BoostPropertyTreeImpl()
{
}

BoostPropertyTreeImpl::BoostPropertyTreeImpl (const BoostPropertyTreeImpl& other)
{
	init(other);
}


BoostPropertyTreeImpl::BoostPropertyTreeImpl(const BoostPropertyTreeRep& implRep)
	: 
	implRep(implRep)
{
}

BoostPropertyTreeImpl::~BoostPropertyTreeImpl()
{
}



/*
 *
 * public operators-general
 *
 */

BoostPropertyTreeImpl&
BoostPropertyTreeImpl::operator=(const BoostPropertyTreeImpl &other)
{
	if (this != &other){
		init(other);
	}
	return *this;
}

Bool
BoostPropertyTreeImpl::operator==(const PropertyTreeImpl& other) const
{
	const BoostPropertyTreeImpl& boostImpl = reference_cast<const BoostPropertyTreeImpl &, 
		const PropertyTreeImpl & >(other);
	return this->implRep == boostImpl.implRep;
}


/*
 *
 * public set value
 *
 */

void
BoostPropertyTreeImpl::setString(const String& key, const String& value)
{
	insertOrReplace(implRep, key, value);
}

void
BoostPropertyTreeImpl::setString(const String& path, const String& key, const String& value)
{

	BoostPropertyTreeRep* nodePT = findNode(implRep, path, false);
	if (nodePT != NULLPTR){
		insertOrReplace(*nodePT, key, value);
	}
	else{
		addChild(implRep, path, key, value);
	}

}

void
BoostPropertyTreeImpl::setTree(const String& key, const PropertyTreeImpl& value)
{
	const BoostPropertyTreeImpl& boostImpl = reference_cast<const BoostPropertyTreeImpl &, 
		const PropertyTreeImpl & >(value);
	insertOrReplace(implRep, key, boostImpl.implRep);
}

void
BoostPropertyTreeImpl::setTree(const String& path, const String& key, const PropertyTreeImpl& value)
{
	const BoostPropertyTreeImpl& boostImpl = reference_cast<const BoostPropertyTreeImpl &, 
		const PropertyTreeImpl & >(value);

	BoostPropertyTreeRep* nodePT = findNode(implRep, path, false);
	if (nodePT != NULLPTR){
		insertOrReplace(*nodePT, key, boostImpl.implRep);
	}
	else{
		 addChild(implRep, path, key,  boostImpl.implRep);
	}
}
/*
 *
 * public get value
 *
 */
String
BoostPropertyTreeImpl::getString(const String& key) const
{
	const BoostPropertyTreeRep* nodePT = findNode(implRep, key);
	return getStringValue(*nodePT);
}

String
BoostPropertyTreeImpl::getString(const String& path, const String& key) const
{
	String value;
	const BoostPropertyTreeRep* nodePT = findNode(implRep, path);
	if (nodePT != NULL) {
		const BoostPropertyTreeRep* childPT = findNode(*nodePT, key);

		value =  getStringValue(*childPT);
	}
	return value;
}

String
BoostPropertyTreeImpl::getStringOrDefault(const String& key, const String& defaultValue) const
{
	const BoostPropertyTreeRep* nodePT = findNode(implRep, key, false);
	return nodePT != NULLPTR ? getStringValue(*nodePT) : defaultValue;
}

String
BoostPropertyTreeImpl::getStringOrDefault(const String& path, const String& key, const String& defaultValue) const
{
	const BoostPropertyTreeRep*  nodePT = findNode(implRep, path,  false);
	if (nodePT != NULLPTR){
		const BoostPropertyTreeRep* childPT = findNode(*nodePT, key, false);
		if (childPT != NULLPTR)
			return getStringValue(*childPT);
	}
	return defaultValue;
}




PropertyTreeImpl*
BoostPropertyTreeImpl::getTree(const String& key) const
{
	return getTree(implRep, key);
}

PropertyTreeImpl*
BoostPropertyTreeImpl::getTree(const String& path, const String& key)
{
	BoostPropertyTreeImpl* impl = NULLPTR;
	const BoostPropertyTreeRep* nodePT = findNode(implRep, path);
	if (nodePT != NULLPTR)
		impl =  getTree(*nodePT, key);
	return impl;
	 
}
/*
 *
 * public utilities
 *
 */
Bool 
BoostPropertyTreeImpl::isEmpty() const
{
	return implRep.empty();
}


Size
BoostPropertyTreeImpl::size() const
{
	return implRep.size();
}

Size
BoostPropertyTreeImpl::size(const String& path) const
{
	const BoostPropertyTreeRep* node = findNode(implRep, path);
	return node->size();

}

void
BoostPropertyTreeImpl::clear() 
{
	implRep.clear();
}

void
BoostPropertyTreeImpl::clear(const String& path) 
{
	BoostPropertyTreeRep* node = findNode(implRep, path);
	node->clear();
}
 
void
BoostPropertyTreeImpl::remove(const String& key)
{
	//confirm key  exists within tree node
	BoostPropertyTreeRep* node =  findNode(implRep, key);
	//remove from tree node
	removeKey(implRep, key);
}

void
BoostPropertyTreeImpl::remove(const String& path, const String& key)
{
	//confirm  path existings
	BoostPropertyTreeRep* node = findNode(implRep, path);
	//find key within path
	BoostPropertyTreeRep* child = findNode(*node, key);

	removeKey(*node, key);

	
}

/*
 *
 * public  accessors for this package only
 *
 */
BoostPropertyTreeRep&
BoostPropertyTreeImpl::getImplRep()
{
	return implRep;
}

const BoostPropertyTreeRep&
BoostPropertyTreeImpl::getImplRep() const
{
	return implRep;
}



//For debugging only

void
BoostPropertyTreeImpl::writeTo(const String& fileName) const
{
	boost::property_tree::write_xml(fileName, implRep);
}

/*
 *
 * protected utilities
 *
 */
BoostPropertyTreeRep*
BoostPropertyTreeImpl::findNode(BoostPropertyTreeRep& root,
								const String& path,
								bool throwWhenMissing) 
{
	 
	BoostPropertyTreeRep* treePtr = NULLPTR;
	 
	try {
		BoostPropertyTreeRep& tree = root.get_child(path);
		treePtr = &tree;
	}
	catch (boost::property_tree::ptree_bad_path& ex){
		if (throwWhenMissing)
			THROW_MSG(CoreText::instance().objectNotFound(path, ex.what()));
	}
	catch (std::exception& )
	{
		THROW_MSG(CoreText::instance().objectNotFound(path));
	}

	return treePtr;
	
}


const BoostPropertyTreeRep*
BoostPropertyTreeImpl::findNode(const BoostPropertyTreeRep& root,
								const String& path,
								bool throwWhenMissing) const
{

	try {
		const BoostPropertyTreeRep& tree = root.get_child(path);
		const BoostPropertyTreeRep* treePtr = &tree;
		return treePtr;
	}
	catch (boost::property_tree::ptree_bad_path& ex){
		if (throwWhenMissing)
			THROW_MSG(CoreText::instance().objectNotFound(path, ex.what()));
	}
	catch (std::exception& )
	{
		THROW_MSG(CoreText::instance().objectNotFound(path));
	}

	return NULLPTR;
	
}



String
BoostPropertyTreeImpl::getStringValue(const BoostPropertyTreeRep& tree) const
{
	String value = tree.get_value<String>();
	return value;
}

 


void
BoostPropertyTreeImpl::removeKey(BoostPropertyTreeRep& node, const String& key)
{
	try {
		node.erase(key);
	}
	catch (std::exception& ex)
	{
		THROW_MSG(CoreText::instance().objectRemovalError(key, ex.what()));
	}
}

void
BoostPropertyTreeImpl::insertOrReplace(BoostPropertyTreeRep& tree,
									   const String& key, 
									   const String& value)
{
	BoostPropertyTreeRep* nodePT = findNode(tree, key, false);
	if (nodePT == NULLPTR)
		tree.push_back(std::make_pair(key, value));
	else
		nodePT->put_value(value);
}

void
BoostPropertyTreeImpl::insertOrReplace(BoostPropertyTreeRep& tree,
									   const String& key, 
									   const BoostPropertyTreeRep& value)
{
	BoostPropertyTreeRep* nodePT = findNode(tree, key, false);
	if (nodePT == NULLPTR)
		tree.push_back(std::make_pair(key, value));
	else
		nodePT->put_child(key, value);
}


void
BoostPropertyTreeImpl::addChild(
								BoostPropertyTreeRep& tree,
								const String& path,
								const String& key, 
								const String& value)
{
	BoostPropertyTreeRep childPT;
	childPT.push_back(std::make_pair(key, value));	
	tree.put_child(path, childPT);
}

void
BoostPropertyTreeImpl::addChild(
								BoostPropertyTreeRep& tree,
								const String& path,
								const String& key, 
								const BoostPropertyTreeRep& value)
{
	BoostPropertyTreeRep childPT;
	childPT.push_back(std::make_pair(key, value));	
	tree.put_child(path, childPT);
}

BoostPropertyTreeImpl*
BoostPropertyTreeImpl::getTree(const BoostPropertyTreeRep& tree, const String& key) const
{
	BoostPropertyTreeImpl* impl = NULLPTR;
	const BoostPropertyTreeRep*  nodePT = findNode(tree, key);
	if (nodePT != NULLPTR){
		impl = new BoostPropertyTreeImpl();
		impl->implRep = *nodePT;
	}
	return impl;
}
/*
 *
 * private utilities
 *
 */
void
BoostPropertyTreeImpl::init(const BoostPropertyTreeImpl& other )
{
	this->implRep = other.implRep;
}
} //namespace boostimpl
} //namespace container
} //namespace ondalear