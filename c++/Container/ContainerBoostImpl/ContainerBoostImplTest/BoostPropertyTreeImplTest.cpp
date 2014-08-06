/**
 * \file BoostProprtyTreeImpl.cpp
 * \brief Boost ProperyTree  Impl   test source file
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
#include "BoostPropertyTreeImplTest.hpp"


namespace ondalear {
namespace test {
namespace container {
namespace boostimpl {




//public member functions
BoostPropertyTreeImplTest::BoostPropertyTreeImplTest()
{

}

void 
BoostPropertyTreeImplTest::test_lifecycle()
{
	//test: BoostPropertyTreeImpl::BoostPropertyTreeImpl();
	//test: BoostPropertyTreeImpl::~BoostPropertyTreeImpl();
	BoostPropertyTreeImpl impl;
	CPPUNIT_ASSERT(true == impl.isEmpty());
}



void 
BoostPropertyTreeImplTest::test_value_string()
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
	
	String obtainedValue;

	BoostPropertyTreeImpl impl;

	//test:: BoostPropertyTreeImpl::virtual void setString(const String& key, const String& value);
	impl.setString(key, valueRoot);

	//test:: BoostPropertyTreeImpl::virtual String getString(const String& key) const;
	obtainedValue = impl.getString(key);

	CPPUNIT_ASSERT(valueRoot == obtainedValue);
	CPPUNIT_ASSERT(false == impl.isEmpty());
	CPPUNIT_ASSERT(1 == impl.size());

	impl.setString(key, valueRoot); //make sure not being appended
	CPPUNIT_ASSERT(valueRoot == impl.getString(key));
	CPPUNIT_ASSERT(1 == impl.size());

	try {
		obtainedValue = impl.getString(invalidKey);
	}
	catch (BaseException& ex)
	{
		std::cout << std::endl;
		std::cout << "Caught expected exception (invalid key) " << ex.what() << std::endl;
	}

	//test:: BoostPropertyTreeImpl::virtual String getStringOrDefault(const String& key, const String& defaulValue) const;

	const String defaultValue = "defaultValue";
	obtainedValue = impl.getStringOrDefault(key, defaultValue);
	CPPUNIT_ASSERT(valueRoot == obtainedValue);
	
	obtainedValue = impl.getStringOrDefault(invalidKey, defaultValue);
	CPPUNIT_ASSERT(defaultValue == obtainedValue);


	//test:: BoostPropertyTreeImpl::virtual void setString(const String& path, const String& key, const String& value);
	impl.setString(levelOnePath, key, valueLevelOne);
	CPPUNIT_ASSERT(2 == impl.size());
	CPPUNIT_ASSERT(1 == impl.size(levelOnePath));

	impl.setString(levelTwoPath, key, valueLevelTwo);
	
	CPPUNIT_ASSERT(2 == impl.size());
	CPPUNIT_ASSERT(2 == impl.size(levelOnePath));
	CPPUNIT_ASSERT(1 == impl.size(levelTwoPath));
	
	//check and ensure no dups/append rather then replace
	impl.setString(levelOnePath, key, valueLevelOne);
	impl.setString(levelTwoPath, key, valueLevelTwo);
	
	CPPUNIT_ASSERT(2 == impl.size());
	CPPUNIT_ASSERT(2 == impl.size(levelOnePath));
	CPPUNIT_ASSERT(1 == impl.size(levelTwoPath));

	//test:: BoostPropertyTreeImpl::virtual String getString(const String& path, const String& key) const;
	obtainedValue = impl.getString(levelOnePath, key);
	CPPUNIT_ASSERT(obtainedValue == valueLevelOne);
	
	obtainedValue = impl.getString(levelTwoPath, key);
	CPPUNIT_ASSERT(obtainedValue == valueLevelTwo);

	
	//test:: BoostPropertyTreeImpl::virtual String getStringOrDefault(const String& path, const String& key, const String& defaulValue) const;

	obtainedValue = impl.getStringOrDefault(levelOnePath, key, defaultValue);
	CPPUNIT_ASSERT(obtainedValue == valueLevelOne);

	obtainedValue = impl.getStringOrDefault(levelTwoPath, key, defaultValue);
	CPPUNIT_ASSERT(obtainedValue == valueLevelTwo);

	obtainedValue = impl.getStringOrDefault(invalidPath, key, defaultValue);
	CPPUNIT_ASSERT(defaultValue == obtainedValue);

	obtainedValue = impl.getStringOrDefault(levelTwoPath, invalidKey, defaultValue);
	CPPUNIT_ASSERT(defaultValue == obtainedValue);

	//wrapup
	impl.writeTo(fileName);

	impl.clear();
	CPPUNIT_ASSERT(0 == impl.size());
}

void 
BoostPropertyTreeImplTest::test_value_template_integer()
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

	BoostPropertyTreeImpl impl;

	//test:: BoostPropertyTreeImpl::template <typename T>  void set(const String& key, const T& value);
	impl.set<Integer>(key, valueRoot);

	//test:: BoostPropertyTreeImpl::template <typename T>  T get(const String& key) const
	obtainedValue = impl.get<Integer>(key);
	CPPUNIT_ASSERT(obtainedValue == valueRoot);



	try {
		obtainedValue = impl.get<Integer>(invalidKey);
	}
	catch (BaseException& ex)
	{
		std::cout << std::endl;
		std::cout << "Caught expected exception (invalid key) " << ex.what() << std::endl;
	}

	//test:: BoostPropertyTreeImpl::template <typename T>  T getOrDefault(const String& key, const T& defaultValue) const;

	obtainedValue = impl.getOrDefault<Integer>(key, defaultValue);
	CPPUNIT_ASSERT(valueRoot == obtainedValue);
	
	obtainedValue = impl.getOrDefault<Integer>(invalidKey, defaultValue);
	CPPUNIT_ASSERT(defaultValue == obtainedValue);

	//test:: BoostPropertyTreeImpl::template <typename T>  void set(const String& path, const String& key, const T& value);

	impl.set<Integer>(levelOnePath, key, valueLevelOne);
	CPPUNIT_ASSERT(2 == impl.size());
	CPPUNIT_ASSERT(1 == impl.size(levelOnePath));

	impl.set<Integer>(levelTwoPath, key, valueLevelTwo);
	
	CPPUNIT_ASSERT(2 == impl.size());
	CPPUNIT_ASSERT(2 == impl.size(levelOnePath));
	CPPUNIT_ASSERT(1 == impl.size(levelTwoPath));

	//test:: BoostPropertyTreeImpl::template <typename T>  T get(const String& path, const String& key) const;
	obtainedValue = impl.get<Integer>(levelOnePath, key);
	CPPUNIT_ASSERT(obtainedValue == valueLevelOne);
	obtainedValue = impl.get<Integer>(levelTwoPath, key);
	CPPUNIT_ASSERT(obtainedValue == valueLevelTwo);

	//test:: BoostPropertyTreeImpl::template <typename T>  T getOrDefault(const String& path, const String& key, const T& defaultValue) const;

	obtainedValue = impl.getOrDefault<Integer>(levelOnePath, key, defaultValue);
	CPPUNIT_ASSERT(obtainedValue == valueLevelOne);

	obtainedValue = impl.getOrDefault<Integer>(levelTwoPath, key, defaultValue);
	CPPUNIT_ASSERT(obtainedValue == valueLevelTwo);
	
	obtainedValue = impl.getOrDefault<Integer>(invalidPath, key, defaultValue);
	CPPUNIT_ASSERT(defaultValue == obtainedValue);

	obtainedValue = impl.getOrDefault<Integer>(levelTwoPath, invalidKey, defaultValue);
	CPPUNIT_ASSERT(defaultValue == obtainedValue);

	//wrapup
	impl.writeTo(fileName);

	impl.clear();
	CPPUNIT_ASSERT(0 == impl.size());
}

void 
BoostPropertyTreeImplTest::test_value_template_bool()
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

	BoostPropertyTreeImpl impl;

	//test:: BoostPropertyTreeImpl::template <typename T>  void set(const String& key, const T& value);
	impl.set<Bool>(key, valueRoot);

	//test:: BoostPropertyTreeImpl::template <typename T>  T get(const String& key) const
	obtainedValue = impl.get<Bool>(key);
	CPPUNIT_ASSERT(obtainedValue == valueRoot);

	try {
		obtainedValue = impl.get<Bool>(invalidKey);
	}
	catch (BaseException& ex)
	{
		std::cout << std::endl;
		std::cout << "Caught expected exception (invalid key) " << ex.what() << std::endl;
	}

	//test:: BoostPropertyTreeImpl::template <typename T>  T getOrDefault(const String& key, const T& defaultValue) const;

	obtainedValue = impl.getOrDefault<Bool>(key, defaultValue);
	CPPUNIT_ASSERT(valueRoot == obtainedValue);
	
	obtainedValue = impl.getOrDefault<Bool>(invalidKey, defaultValue);
	CPPUNIT_ASSERT(defaultValue == obtainedValue);

	//test:: BoostPropertyTreeImpl::template <typename T>  void set(const String& path, const String& key, const T& value);

	impl.set<Integer>(levelOnePath, key, valueLevelOne);
	CPPUNIT_ASSERT(2 == impl.size());
	CPPUNIT_ASSERT(1 == impl.size(levelOnePath));

	impl.set<Integer>(levelTwoPath, key, valueLevelTwo);
	
	CPPUNIT_ASSERT(2 == impl.size());
	CPPUNIT_ASSERT(2 == impl.size(levelOnePath));
	CPPUNIT_ASSERT(1 == impl.size(levelTwoPath));

	//test:: BoostPropertyTreeImpl::template <typename T>  T get(const String& path, const String& key) const;
	obtainedValue = impl.get<Bool>(levelOnePath, key);
	CPPUNIT_ASSERT(obtainedValue == valueLevelOne);
	obtainedValue = impl.get<Bool>(levelTwoPath, key);
	CPPUNIT_ASSERT(obtainedValue == valueLevelTwo);

	//test:: BoostPropertyTreeImpl::template <typename T>  T getOrDefault(const String& path, const String& key, const T& defaultValue) const;

	obtainedValue = impl.getOrDefault<Bool>(levelOnePath, key, defaultValue);
	CPPUNIT_ASSERT(obtainedValue == valueLevelOne);

	obtainedValue = impl.getOrDefault<Bool>(levelTwoPath, key, defaultValue);
	CPPUNIT_ASSERT(obtainedValue == valueLevelTwo);
	
	obtainedValue = impl.getOrDefault<Bool>(invalidPath, key, defaultValue);
	CPPUNIT_ASSERT(defaultValue == obtainedValue);

	obtainedValue = impl.getOrDefault<Bool>(levelTwoPath, invalidKey, defaultValue);
	CPPUNIT_ASSERT(defaultValue == obtainedValue);

	//wrapup
	impl.writeTo(fileName);

	impl.clear();
	CPPUNIT_ASSERT(0 == impl.size());
}

void 
BoostPropertyTreeImplTest::test_operator_general()
{
	const String key1 = "key1";
	const String key2 = "key2";
	const Integer value1 = 1;
	const Integer value2 = 2;

	//test: BoostPropertyTreeImpl::BoostPropertyTreeImpl& operator=(const BoostPropertyTreeImpl& other);

	//test: BoostPropertyTreeImpl::virtual Bool operator==(const PropertyTreeImpl& other) const;
	BoostPropertyTreeImpl impl1;
	BoostPropertyTreeImpl impl2;
	CPPUNIT_ASSERT(impl1 == impl2);

	impl1.set<Integer>(key1, value1);
	impl1.set<Integer>(key2, value2);
	CPPUNIT_ASSERT(2 == impl1.size());

	impl2 = impl1;
	CPPUNIT_ASSERT(impl1 == impl2);
	CPPUNIT_ASSERT(value1 == impl2.get<Integer>(key1));
	CPPUNIT_ASSERT(value2 == impl2.get<Integer>(key2));
}

void 
BoostPropertyTreeImplTest::test_util()
{

	const String fileName = "util.txt";
	const String key1 = "key1";
	const String key2 = "key2";
	const String path = "child";
	const Integer value1 = 1;
	const Integer value2 = 2;

	BoostPropertyTreeImpl impl;
	//test: BoostPropertyTreeImpl::virtual Bool isEmpty() const;
	CPPUNIT_ASSERT(true == impl.isEmpty());

	//test: BoostPropertyTreeImpl::virtual Size size() const;
	impl.set<Integer>(key1, value1);
	impl.set<Integer>(key2, value2);
	CPPUNIT_ASSERT(2 == impl.size());

	impl.set<Integer>(path, key1, value1);

	impl.set<Integer>(path, key2, value2);


	CPPUNIT_ASSERT(3 == impl.size());


	//test: BoostPropertyTreeImpl::virtual Size size(const String& path) const;
	CPPUNIT_ASSERT(value1 == impl.get<Integer>(path, key1));
	CPPUNIT_ASSERT(value2 == impl.get<Integer>(path, key2));


	CPPUNIT_ASSERT(2 == impl.size(path));


	//test: BoostPropertyTreeImpl::virtual void clear(const String& path) ;
	impl.clear(path);
	CPPUNIT_ASSERT(0 == impl.size(path));
	
	//test: BoostPropertyTreeImpl::virtual void clear() ;
	impl.clear();
	CPPUNIT_ASSERT(0 == impl.size());
	


	//test: BoostPropertyTreeImpl::virtual void remove(const String& key);

	impl.set<Integer>(key1, value1);
	impl.set<Integer>(key2, value2);
	CPPUNIT_ASSERT(2 == impl.size());

	impl.set<Integer>(path, key1, value1);
	impl.set<Integer>(path, key2, value2);

	CPPUNIT_ASSERT(3 == impl.size());
	CPPUNIT_ASSERT(2 == impl.size(path));

	impl.remove(key1);
	Size sz = impl.size();
	CPPUNIT_ASSERT(2 == impl.size());

	impl.remove(key2);
	CPPUNIT_ASSERT(1 == impl.size());

	//test: BoostPropertyTreeImpl::virtual void remove(const String& path, const String& key);
	impl.remove(path, key1);
	CPPUNIT_ASSERT(1 == impl.size(path));
	CPPUNIT_ASSERT(1 == impl.size());
	impl.remove(path, key2);
	CPPUNIT_ASSERT(0 == impl.size(path));
	impl.remove(path);
	CPPUNIT_ASSERT(0 == impl.size());
}

void 
BoostPropertyTreeImplTest::test_value_tree()
{
	const String fileName = "tree.txt";
	const String key1 = "key1";
	const String key2 = "key2";
	const String key3 = "key3";
	const String path = "child";
	const Integer value1 = 1;
	const Integer value2 = 2;

	BoostPropertyTreeImpl parent;
	parent.set<Integer>(key1, value1);
	parent.set<Integer>(key2, value2);
	parent.set<Integer>(path, key1, value1);
	parent.set<Integer>(path, key2, value2);

	BoostPropertyTreeImpl child = parent;

	//test: PropertyTreeImpl::virtual void setTree(const String& key, const PropertyTreeImpl& value);
	parent.setTree(key3, child);
	CPPUNIT_ASSERT(4 == parent.size());

	//test: PropertyTreeImpl::virtual PropertyTreeImpl* getTree(const String& key) const;
	PropertyTreeImplScopedPtr  implPtr1(parent.getTree(key3));
	CPPUNIT_ASSERT(3 == implPtr1->size());
	CPPUNIT_ASSERT(2 == implPtr1->size(path));

	//test: PropertyTreeImpl::virtual void setTree(const String& path, const String& key, const PropertyTreeImpl& value);

	parent.setTree(path, key3, child);
 
	//test: PropertyTreeImpl::virtual PropertyTreeImpl* getTree(const String& key, const String& path);
	PropertyTreeImplScopedPtr  implPtr2(parent.getTree(path, key3));
	Size sz = implPtr2->size();

	CPPUNIT_ASSERT(3 == implPtr2->size());
	CPPUNIT_ASSERT(2 == implPtr2->size(path));

		//wrapup
	parent.writeTo(fileName);

	parent.clear();
	CPPUNIT_ASSERT(0 == parent.size());
}

} //namespace boostimpl
} //namespace container
} //namespace test
} //namespace ondalear

