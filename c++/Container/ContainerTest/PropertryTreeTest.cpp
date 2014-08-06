/**
 * \file PropertyTreeTest.cpp
 * \brief PropertyTree unit test source file
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
#include "PropertyTreeTest.hpp"



namespace ondalear {
namespace test {
namespace container {



//public member functions
PropertyTreeTest::PropertyTreeTest()
{

}

void
PropertyTreeTest::test_lifecycle()
{
	
	//test: PropertyTree::PropertyTree();
	PropertyTree tree1;
	CPPUNIT_ASSERT(0 == tree1.size());

	//test: PropertyTree::PropertyTree (const PropertyTree& other);
	PropertyTree tree2(tree1);
	CPPUNIT_ASSERT(0 == tree2.size());

	//test: PropertyTree::virtual ~PropertyTree();

}

//Note: returning by value by design
PropertyTree
PropertyTreeTest::buildPropertyTree()
{
	
	const String key = "goodKey";
	const String levelOnePath = "levelOnePath";
	const String levelTwoPath = levelOnePath + "." + "levelTwoPath";
	const String valueRoot = "valueRoot";
	const String valueLevelOne = "valueLevelOne";
	const String valueLevelTwo = "valueLevelTwo";

	PropertyTree tree;

	tree.set<String>(key, valueRoot);
	tree.set<String>(levelOnePath, key, valueLevelOne);
	tree.set<String>(levelTwoPath, key, valueLevelTwo);

	return tree;
}

void 
PropertyTreeTest::test_value_string()
{
	const String fileName = "String.txt";
	const String invalidKey = "invalidKey";
	const String invalidPath = "badone.badtwo.badthree";
	const String key = "goodKey";
	const String levelOnePath = "levelOnePath";
	const String levelTwoPath = levelOnePath + "." + "levelTwoPath";
	const String valueRoot = "valueRoot";
	const String valueLevelOne = "valueLevelOne";
	const String valueLevelTwo = "valueLevelTwo";
	const String defaultValue = "defaultValue";
	String obtainedValue;

	PropertyTree tree;

	//test:: BoostPropertyTreeImpl::virtual void setString(const String& key, const String& value);
	tree.setString(key, valueRoot);

	//test:: BoostPropertyTreeImpl::virtual String getString(const String& key) const;
	obtainedValue = tree.getString(key);

	CPPUNIT_ASSERT(valueRoot == obtainedValue);
	CPPUNIT_ASSERT(false == tree.isEmpty());
	CPPUNIT_ASSERT(1 == tree.size());

	try {
		obtainedValue = tree.getString(invalidKey);
	}
	catch (BaseException& ex)
	{
		std::cout << std::endl;
		std::cout << "Caught expected exception (invalid key) " << ex.what() << std::endl;
	}

	//test:: BoostPropertyTreeImpl::virtual String getStringOrDefault(const String& key, const String& defaulValue) const;

	
	obtainedValue = tree.getStringOrDefault(key, defaultValue);
	CPPUNIT_ASSERT(valueRoot == obtainedValue);
	
	obtainedValue = tree.getStringOrDefault(invalidKey, defaultValue);
	CPPUNIT_ASSERT(defaultValue == obtainedValue);


	//test:: BoostPropertyTreeImpl::virtual void setString(const String& path, const String& key, const String& value);
	tree.setString(levelOnePath, key, valueLevelOne);
	CPPUNIT_ASSERT(2 == tree.size());
	CPPUNIT_ASSERT(1 == tree.size(levelOnePath));

	tree.setString(levelTwoPath, key, valueLevelTwo);
	
	CPPUNIT_ASSERT(2 == tree.size());
	CPPUNIT_ASSERT(2 == tree.size(levelOnePath));
	CPPUNIT_ASSERT(1 == tree.size(levelTwoPath));
	
	
	//test:: BoostPropertyTreeImpl::virtual String getString(const String& path, const String& key) const;
	obtainedValue = tree.getString(levelOnePath, key);
	CPPUNIT_ASSERT(obtainedValue == valueLevelOne);
	
	obtainedValue = tree.getString(levelTwoPath, key);
	CPPUNIT_ASSERT(obtainedValue == valueLevelTwo);


	try {
		obtainedValue = tree.getString(invalidPath, key);
	}
	catch (BaseException& ex)
	{
		std::cout << "Caught expected exception (invalid key) " << ex.what() << std::endl;
	}
	 
	try {
		obtainedValue = tree.getString(levelTwoPath, invalidKey);
	}
	catch (BaseException& ex)
	{
		std::cout << "Caught expected exception (invalid key) " << ex.what() << std::endl;
	}
	 

	
	//test:: BoostPropertyTreeImpl::virtual String getStringOrDefault(const String& path, const String& key, const String& defaulValue) const;

	obtainedValue = tree.getStringOrDefault(levelOnePath, key, defaultValue);
	CPPUNIT_ASSERT(obtainedValue == valueLevelOne);

	obtainedValue = tree.getStringOrDefault(levelTwoPath, key, defaultValue);
	CPPUNIT_ASSERT(obtainedValue == valueLevelTwo);

	obtainedValue = tree.getStringOrDefault(invalidPath, key, defaultValue);
	CPPUNIT_ASSERT(defaultValue == obtainedValue);

	obtainedValue = tree.getStringOrDefault(levelTwoPath, invalidKey, defaultValue);
	CPPUNIT_ASSERT(defaultValue == obtainedValue);

	 

	tree.clear();
	CPPUNIT_ASSERT(0 == tree.size());
}

void 
PropertyTreeTest::test_operator_general()
{
	const String key = "goodKey";
	const String levelOnePath = "levelOnePath";
	const String levelTwoPath = levelOnePath + "." + "levelTwoPath";
	const String valueRoot = "valueRoot";
	const String valueLevelOne = "valueLevelOne";
	const String valueLevelTwo = "valueLevelTwo";

	String obtainedValue;
	PropertyTree tree1 = buildPropertyTree();
	CPPUNIT_ASSERT(2 == tree1.size());
	PropertyTree tree2;
	CPPUNIT_ASSERT(0 == tree2.size());

	//test: PropertyTree::Bool operator!=(const PropertyTree& other) const;
	CPPUNIT_ASSERT(tree1 != tree2);

	//test: PropertyTree::PropertyTree& operator=(const PropertyTree &other);
	tree2  = tree1;
	//test: PropertyTree::Bool operator==(const PropertyTree& other) const;
	CPPUNIT_ASSERT(tree1 == tree2);
	CPPUNIT_ASSERT(2 == tree2.size());

	obtainedValue = tree2.get<String>(key);
	CPPUNIT_ASSERT(valueRoot == obtainedValue);

	obtainedValue = tree2.get<String>(levelOnePath, key);
	CPPUNIT_ASSERT(obtainedValue == valueLevelOne);
	
	obtainedValue = tree2.get<String>(levelTwoPath, key);
	CPPUNIT_ASSERT(obtainedValue == valueLevelTwo);
}

void 
PropertyTreeTest::test_value_template_integer()
{
	const String fileName = "Integer.txt";
	const String invalidKey = "invalidKey";
	const String invalidPath = "badone.badtwo.badthree";
	const String key = "goodKey";
	const String levelOnePath = "levelOnePath";
	const String levelTwoPath = levelOnePath + "." + "levelTwoPath";
	const Integer valueRoot = 1024;
	const Integer valueLevelOne = 2048;
	const Integer valueLevelTwo = 4096;
	const Integer defaultValue = 12;
	Integer obtainedValue;

	PropertyTree tree;

	//test:: BoostPropertyTreeImpl::template <typename T>  void set(const String& key, const T& value);
	tree.set<Integer>(key, valueRoot);

	//test:: BoostPropertyTreeImpl::template <typename T>  T get(const String& key) const
	obtainedValue = tree.get<Integer>(key);
	CPPUNIT_ASSERT(obtainedValue == valueRoot);



	try {
		obtainedValue = tree.get<Integer>(invalidKey);
	}
	catch (BaseException& ex)
	{
		std::cout << std::endl;
		std::cout << "Caught expected exception (invalid key) " << ex.what() << std::endl;
	}

	//test:: BoostPropertyTreeImpl::template <typename T>  T getOrDefault(const String& key, const T& defaultValue) const;

	obtainedValue = tree.getOrDefault<Integer>(key, defaultValue);
	CPPUNIT_ASSERT(valueRoot == obtainedValue);
	
	obtainedValue = tree.getOrDefault<Integer>(invalidKey, defaultValue);
	CPPUNIT_ASSERT(defaultValue == obtainedValue);

	//test:: BoostPropertyTreeImpl::template <typename T>  void set(const String& path, const String& key, const T& value);

	tree.set<Integer>(levelOnePath, key, valueLevelOne);
	CPPUNIT_ASSERT(2 == tree.size());
	CPPUNIT_ASSERT(1 == tree.size(levelOnePath));

	tree.set<Integer>(levelTwoPath, key, valueLevelTwo);
	
	CPPUNIT_ASSERT(2 == tree.size());
	CPPUNIT_ASSERT(2 == tree.size(levelOnePath));
	CPPUNIT_ASSERT(1 == tree.size(levelTwoPath));

	//test:: BoostPropertyTreeImpl::template <typename T>  T get(const String& path, const String& key) const;
	obtainedValue = tree.get<Integer>(levelOnePath, key);
	CPPUNIT_ASSERT(obtainedValue == valueLevelOne);
	obtainedValue = tree.get<Integer>(levelTwoPath, key);
	CPPUNIT_ASSERT(obtainedValue == valueLevelTwo);

	//test:: BoostPropertyTreeImpl::template <typename T>  T getOrDefault(const String& path, const String& key, const T& defaultValue) const;

	obtainedValue = tree.getOrDefault<Integer>(levelOnePath, key, defaultValue);
	CPPUNIT_ASSERT(obtainedValue == valueLevelOne);

	obtainedValue = tree.getOrDefault<Integer>(levelTwoPath, key, defaultValue);
	CPPUNIT_ASSERT(obtainedValue == valueLevelTwo);
	
	obtainedValue = tree.getOrDefault<Integer>(invalidPath, key, defaultValue);
	CPPUNIT_ASSERT(defaultValue == obtainedValue);

	obtainedValue = tree.getOrDefault<Integer>(levelTwoPath, invalidKey, defaultValue);
	CPPUNIT_ASSERT(defaultValue == obtainedValue);

	 

	tree.clear();
	CPPUNIT_ASSERT(0 == tree.size());
}

void 
PropertyTreeTest::test_value_template_bool()
{
	const String fileName = "Bool.txt";
	const String invalidKey = "invalidKey";
	const String invalidPath = "badone.badtwo.badthree";
	const String key = "goodKey";
	const String levelOnePath = "levelOnePath";
	const String levelTwoPath = levelOnePath + "." + "levelTwoPath";
	const Bool valueRoot = true;
	const Bool valueLevelOne = false;
	const Bool valueLevelTwo = true;
	const Bool defaultValue = false;
	Bool obtainedValue;

	PropertyTree tree;

	//test:: BoostPropertyTreeImpl::template <typename T>  void set(const String& key, const T& value);
	tree.set<Bool>(key, valueRoot);

	//test:: BoostPropertyTreeImpl::template <typename T>  T get(const String& key) const
	obtainedValue = tree.get<Bool>(key);
	CPPUNIT_ASSERT(obtainedValue == valueRoot);

	try {
		obtainedValue = tree.get<Bool>(invalidKey);
	}
	catch (BaseException& ex)
	{
		std::cout << std::endl;
		std::cout << "Caught expected exception (invalid key) " << ex.what() << std::endl;
	}

	//test:: BoostPropertyTreeImpl::template <typename T>  T getOrDefault(const String& key, const T& defaultValue) const;

	obtainedValue = tree.getOrDefault<Bool>(key, defaultValue);
	CPPUNIT_ASSERT(valueRoot == obtainedValue);
	
	obtainedValue = tree.getOrDefault<Bool>(invalidKey, defaultValue);
	CPPUNIT_ASSERT(defaultValue == obtainedValue);

	//test:: BoostPropertyTreeImpl::template <typename T>  void set(const String& path, const String& key, const T& value);

	tree.set<Bool>(levelOnePath, key, valueLevelOne);
	CPPUNIT_ASSERT(2 == tree.size());
	CPPUNIT_ASSERT(1 == tree.size(levelOnePath));

	tree.set<Bool>(levelTwoPath, key, valueLevelTwo);
	
	CPPUNIT_ASSERT(2 == tree.size());
	CPPUNIT_ASSERT(2 == tree.size(levelOnePath));
	CPPUNIT_ASSERT(1 == tree.size(levelTwoPath));

	//test:: BoostPropertyTreeImpl::template <typename T>  T get(const String& path, const String& key) const;
	obtainedValue = tree.get<Bool>(levelOnePath, key);
	CPPUNIT_ASSERT(obtainedValue == valueLevelOne);
	obtainedValue = tree.get<Bool>(levelTwoPath, key);
	CPPUNIT_ASSERT(obtainedValue == valueLevelTwo);

	//test:: BoostPropertyTreeImpl::template <typename T>  T getOrDefault(const String& path, const String& key, const T& defaultValue) const;

	obtainedValue = tree.getOrDefault<Bool>(levelOnePath, key, defaultValue);
	CPPUNIT_ASSERT(obtainedValue == valueLevelOne);

	obtainedValue = tree.getOrDefault<Bool>(levelTwoPath, key, defaultValue);
	CPPUNIT_ASSERT(obtainedValue == valueLevelTwo);
	
	obtainedValue = tree.getOrDefault<Bool>(invalidPath, key, defaultValue);
	CPPUNIT_ASSERT(defaultValue == obtainedValue);

	obtainedValue = tree.getOrDefault<Bool>(levelTwoPath, invalidKey, defaultValue);
	CPPUNIT_ASSERT(defaultValue == obtainedValue);

	 

	tree.clear();
	CPPUNIT_ASSERT(0 == tree.size());
}


void 
PropertyTreeTest::test_value_template_string()
{
	const String fileName = "StringTemplate.txt";
	const String invalidKey = "invalidKey";
	const String invalidPath = "badone.badtwo.badthree";
	const String key = "goodKey";
	const String levelOnePath = "levelOnePath";
	const String levelTwoPath = levelOnePath + "." + "levelTwoPath";
	const String valueRoot = "valueRoot";
	const String valueLevelOne = "valueLevelOne";
	const String valueLevelTwo = "valueLevelTwo";
	const String defaultValue = "defaultValue";

	String obtainedValue;

	PropertyTree tree;

	//test:: BoostPropertyTreeImpl::template <typename T>  void set(const String& key, const T& value);
	tree.set<String>(key, valueRoot);

	//test:: BoostPropertyTreeImpl::template <typename T>  T get(const String& key) const
	obtainedValue = tree.get<String>(key);
	CPPUNIT_ASSERT(obtainedValue == valueRoot);

	try {
		obtainedValue = tree.get<String>(invalidKey);
	}
	catch (BaseException& ex)
	{
		std::cout << std::endl;
		std::cout << "Caught expected exception (invalid key) " << ex.what() << std::endl;
	}

	//test:: BoostPropertyTreeImpl::template <typename T>  T getOrDefault(const String& key, const T& defaultValue) const;

	obtainedValue = tree.getOrDefault<String>(key, defaultValue);
	CPPUNIT_ASSERT(valueRoot == obtainedValue);
	
	obtainedValue = tree.getOrDefault<String>(invalidKey, defaultValue);
	CPPUNIT_ASSERT(defaultValue == obtainedValue);

	//test:: BoostPropertyTreeImpl::template <typename T>  void set(const String& path, const String& key, const T& value);

	tree.set<String>(levelOnePath, key, valueLevelOne);
	CPPUNIT_ASSERT(2 == tree.size());
	CPPUNIT_ASSERT(1 == tree.size(levelOnePath));

	tree.set<String>(levelTwoPath, key, valueLevelTwo);
	
	CPPUNIT_ASSERT(2 == tree.size());
	CPPUNIT_ASSERT(2 == tree.size(levelOnePath));
	CPPUNIT_ASSERT(1 == tree.size(levelTwoPath));

	//test:: BoostPropertyTreeImpl::template <typename T>  T get(const String& path, const String& key) const;
	obtainedValue = tree.get<String>(levelOnePath, key);
	CPPUNIT_ASSERT(obtainedValue == valueLevelOne);
	obtainedValue = tree.get<String>(levelTwoPath, key);
	CPPUNIT_ASSERT(obtainedValue == valueLevelTwo);

	//test:: BoostPropertyTreeImpl::template <typename T>  T getOrDefault(const String& path, const String& key, const T& defaultValue) const;

	obtainedValue = tree.getOrDefault<String>(levelOnePath, key, defaultValue);
	CPPUNIT_ASSERT(obtainedValue == valueLevelOne);

	obtainedValue = tree.getOrDefault<String>(levelTwoPath, key, defaultValue);
	CPPUNIT_ASSERT(obtainedValue == valueLevelTwo);
	
	obtainedValue = tree.getOrDefault<String>(invalidPath, key, defaultValue);
	CPPUNIT_ASSERT(defaultValue == obtainedValue);

	obtainedValue = tree.getOrDefault<String>(levelTwoPath, invalidKey, defaultValue);
	CPPUNIT_ASSERT(defaultValue == obtainedValue);

	 

	tree.clear();
	CPPUNIT_ASSERT(0 == tree.size());
}

void 
PropertyTreeTest::test_util()
{

	 
	const String key1 = "key1";
	const String key2 = "key2";
	const String path = "child";
	const Integer value1 = 1;
	const Integer value2 = 2;

	PropertyTree tree;
	//test: BoostPropertyTreeImpl::virtual Bool isEmpty() const;
	CPPUNIT_ASSERT(true == tree.isEmpty());

	//test: BoostPropertyTreeImpl::virtual Size size() const;
	tree.set<Integer>(key1, value1);
	tree.set<Integer>(key2, value2);
	CPPUNIT_ASSERT(2 == tree.size());
	CPPUNIT_ASSERT(true == tree.propertyExists(key1));
	CPPUNIT_ASSERT(true == tree.propertyExists(key2));

	tree.set<Integer>(path, key1, value1);
	tree.set<Integer>(path, key2, value2);
	CPPUNIT_ASSERT(true == tree.propertyExists(path, key1));
	CPPUNIT_ASSERT(true == tree.propertyExists(path, key2));
	CPPUNIT_ASSERT(true == tree.propertyExists(path));

	CPPUNIT_ASSERT(3 == tree.size());


	//test: BoostPropertyTreeImpl::virtual Size size(const String& path) const;
	CPPUNIT_ASSERT(value1 == tree.get<Integer>(path, key1));
	CPPUNIT_ASSERT(value2 == tree.get<Integer>(path, key2));


	CPPUNIT_ASSERT(2 == tree.size(path));


	//test: BoostPropertyTreeImpl::virtual void clear(const String& path) ;
	tree.clear(path);
	CPPUNIT_ASSERT(0 == tree.size(path));
	
	//test: BoostPropertyTreeImpl::virtual void clear() ;
	tree.clear();
	CPPUNIT_ASSERT(0 == tree.size());
	


	//test: BoostPropertyTreeImpl::virtual void remove(const String& key);

	tree.set<Integer>(key1, value1);
	tree.set<Integer>(key2, value2);
	CPPUNIT_ASSERT(2 == tree.size());

	tree.set<Integer>(path, key1, value1);
	tree.set<Integer>(path, key2, value2);

	CPPUNIT_ASSERT(3 == tree.size());
	CPPUNIT_ASSERT(2 == tree.size(path));

	tree.remove(key1);
	Size sz = tree.size();
	CPPUNIT_ASSERT(2 == tree.size());

	tree.remove(key2);
	CPPUNIT_ASSERT(1 == tree.size());

	CPPUNIT_ASSERT(false == tree.propertyExists(key1));
	CPPUNIT_ASSERT(false == tree.propertyExists(key2));

	//test: BoostPropertyTreeImpl::virtual void remove(const String& path, const String& key);
	tree.remove(path, key1);
	CPPUNIT_ASSERT(1 == tree.size(path));
	CPPUNIT_ASSERT(1 == tree.size());
	tree.remove(path, key2);
	CPPUNIT_ASSERT(0 == tree.size(path));
	CPPUNIT_ASSERT(false == tree.propertyExists(path, key1));
	CPPUNIT_ASSERT(false == tree.propertyExists(path, key2));
	CPPUNIT_ASSERT(true == tree.propertyExists(path));
	tree.remove(path);
	CPPUNIT_ASSERT(false == tree.propertyExists(path));
	CPPUNIT_ASSERT(0 == tree.size());
}

void 
PropertyTreeTest::test_value_tree()
{
	const String fileName = "tree.txt";
	const String key1 = "key1";
	const String key2 = "key2";
	const String key3 = "key3";
	const String path = "child";
	const Integer value1 = 1;
	const Integer value2 = 2;

	PropertyTree parent;
	parent.set<Integer>(key1, value1);
	parent.set<Integer>(key2, value2);
	parent.set<Integer>(path, key1, value1);
	parent.set<Integer>(path, key2, value2);

	PropertyTree child = parent;

	//test: PropertyTreeImpl::virtual void setTree(const String& key, const PropertyTreeImpl& value);
	parent.setTree(key3, child);
	CPPUNIT_ASSERT(4 == parent.size());

	//test: PropertyTreeImpl::virtual PropertyTreeImpl* getTree(const String& key) const;
	PropertyTree  tree1 = parent.getTree(key3);
	CPPUNIT_ASSERT(3 == tree1.size());
	CPPUNIT_ASSERT(2 == tree1.size(path));

	//test: PropertyTreeImpl::virtual void setTree(const String& path, const String& key, const PropertyTreeImpl& value);

	parent.setTree(path, key3, child);
 
	//test: PropertyTreeImpl::virtual PropertyTreeImpl* getTree(const String& key, const String& path);
	PropertyTree  tree2 = parent.getTree(path, key3);
	 

	CPPUNIT_ASSERT(3 == tree2.size());
	CPPUNIT_ASSERT(2 == tree2.size(path));

 

	parent.clear();
	CPPUNIT_ASSERT(0 == parent.size());
}


void
PropertyTreeTest::test_iteration()
{
	PropertyTreeIterator beginIterator;
	PropertyTreeIterator endIterator;
	PropertyTree parent;
	PropertyTree child;

	beginIterator = parent.begin();
	endIterator = parent.end();
	CPPUNIT_ASSERT(0 == beginIterator.size());
	CPPUNIT_ASSERT(0 == beginIterator.sizeCurrent());

	CPPUNIT_ASSERT(beginIterator == endIterator);
	for (PropertyTreeIterator iter1 = parent.begin(); iter1 != parent.end();
		++iter1){
			std::cout << "should not see this line" << std::endl;
	}

	String key;
	String value;

	const String key1 = "key1";
	const String key2 = "key2";
	const String key3 = "key3";
	const String path = "child";
	const Integer value1 = 1;
	const Integer value2 = 2;

	parent.set<Integer>(key1, value1);
	parent.set<Integer>(key2, value2);
	parent.set<Integer>(path, key1, value1);
	parent.set<Integer>(path, key2, value2);

	

	beginIterator.reset();
	endIterator.reset();

	CPPUNIT_ASSERT(0 == beginIterator.size());
	CPPUNIT_ASSERT(3 == parent.begin().size());

	//Note: this can be made into a recursive test by checking for empty value

	for (PropertyTreeIterator iter2 = parent.begin(); iter2 != parent.end();
		++iter2){
			key = iter2.first();
			value = iter2.value();
			std::cout << "parent key: " << key
				<< " parent string value: " << value << std::endl;
			if (value != ""){
				std::cout << "value as Integer: " << iter2.get<Integer>() << std::endl;
				CPPUNIT_ASSERT(0 == iter2.sizeCurrent());
			}
			else {
				CPPUNIT_ASSERT(2 == iter2.sizeCurrent());
				child = parent.getTree(iter2.first());
				for (PropertyTreeIterator iter3 = child.begin(); 
					iter3 != child.end(); ++iter3){
						CPPUNIT_ASSERT(0 == iter3.sizeCurrent());
						std::cout << "child key: " << iter3.first() << " child int value: " << iter3.get<Integer>() << std::endl;
				}
			}
	}
	

}
} //namespace container
} //namespace test
} //namespace ondalear

