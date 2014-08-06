/**
 * \file BoostProprtyTreeFeatureTest.cpp
 * \brief Boost ProperyTree  feature test header file
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
#include "BoostPropertyTreeFeatureTest.hpp"
#include <boost/algorithm/string.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/lexical_cast.hpp>
#include <string>
#include <set>
#include <exception>
#include <iostream>

namespace ondalear {
namespace test {
namespace container {
namespace boostimpl {

static const String loggerSectionKey = "logger";
static const String subSectionKey = "debug";
static const String fileNameKey = "filename";
static const String levelKey = "level";
static const String modulesKey="modules.module";
static const String expectedFileName = "debug.log";
const int expectedLevel = 2;
static const String expectedModules = "Finance,Admin,HR";







struct DebugSettingsJSON
{
	std::string m_file;               // log filename
    int m_level;                      // debug level
    std::set<std::string> m_modules;  // modules where logging is enabled
    void load(const std::string &filename);
    void save(const std::string &filename);
};

void
DebugSettingsJSON::load(const std::string &filename)
{
	using boost::property_tree::ptree;
	int size;
    ptree rootPT;
	ptree::const_assoc_iterator it;

    read_json(filename, rootPT);
	write_json("dump.json", rootPT);

	String lookupKey;
	String value;

	it = rootPT.find(loggerSectionKey);
	size = rootPT.size();
	CPPUNIT_ASSERT(it != rootPT.not_found());
	CPPUNIT_ASSERT(loggerSectionKey== it->first);
	CPPUNIT_ASSERT(1 == size);

	ptree loggerPT = it->second;
	size = loggerPT.size();
	CPPUNIT_ASSERT(1 == size);

	it = loggerPT.find(subSectionKey);
	CPPUNIT_ASSERT(it != loggerPT.not_found());
	CPPUNIT_ASSERT(subSectionKey== it->first);

	ptree debugPT = it->second;
	size = loggerPT.size();
	CPPUNIT_ASSERT(1 == size);

	//filename
	lookupKey =  fileNameKey;
	it = debugPT.find(lookupKey);
	CPPUNIT_ASSERT(it != debugPT.not_found());

	value =  it->second.get_value<String>();
	m_file = boost::lexical_cast<std::string>(value);
	CPPUNIT_ASSERT(expectedFileName  == m_file);

	//level
	lookupKey = levelKey;
	it = debugPT.find(lookupKey);
	CPPUNIT_ASSERT(it != debugPT.not_found());
	value = it->second.get_value<String>();
	 
	m_level = boost::lexical_cast<int>(value);
	CPPUNIT_ASSERT(expectedLevel== m_level);
	
	//modules

	lookupKey = "modules";
	it = debugPT.find(lookupKey);
	CPPUNIT_ASSERT(it != debugPT.not_found());
	ptree modulesPT = it->second;;
	size = modulesPT.size();
	CPPUNIT_ASSERT(3 == size);

	
	ptree modulePT;
	for (ptree::const_iterator itModules = modulesPT.begin(); 
		itModules != modulesPT.end(); 
		++itModules)
	{
		modulePT = itModules->second;
		it = modulePT.find("module");
		CPPUNIT_ASSERT(it != modulePT.not_found());
		value = it->second.get_value<String>();
	}

	//another way of getting there
	BOOST_FOREACH(ptree::value_type &v, rootPT.get_child("logger.debug.modules"))
	{
		modulePT = v.second;
		it = modulePT.find("module");
		CPPUNIT_ASSERT(it != modulePT.not_found());
		value = it->second.get_value<String>();
		m_modules.insert(value);
		
	}
}

void
DebugSettingsJSON::save(const std::string &filename)
{
	using boost::property_tree::ptree;
    
	
	


	ptree debugPT;
	//file name
	debugPT.push_back(std::make_pair(fileNameKey, 
		expectedFileName));
 
	//logging level
	debugPT.push_back(std::make_pair(levelKey, 
		boost::lexical_cast<String>(expectedLevel)));

	//modules
	ptree modulesPT;
	BOOST_FOREACH(const std::string &name, m_modules)
        modulesPT.add("module", name);
	
	debugPT.push_back(std::make_pair("modules", 
		modulesPT));

	ptree loggerPT;
	loggerPT.push_back(std::make_pair(subSectionKey, debugPT));

	ptree rootPT;
	rootPT.push_back(std::make_pair(loggerSectionKey, loggerPT));

	write_json(filename, rootPT);
}

struct DebugSettingsIni
{
	

	std::string m_file;               // log filename
    int m_level;                      // debug level
    std::set<std::string> m_modules;  // modules where logging is enabled
    void load(const std::string &filename);
    void save(const std::string &filename);
};

void 
DebugSettingsIni::load(const std::string &filename)
{

    using boost::property_tree::ptree;
    ptree rootPT;
	ptree::const_assoc_iterator it ;

    read_ini(filename, rootPT);

	
	String lookupKey;
	String value;

	//get access to root
	it = rootPT.find(loggerSectionKey);
	CPPUNIT_ASSERT(it != rootPT.not_found());
	CPPUNIT_ASSERT(loggerSectionKey== it->first);

	ptree loggerPT = it->second;

	//do same another via get_child
	ptree childPT = rootPT.get_child(loggerSectionKey);
	CPPUNIT_ASSERT(loggerPT == childPT);

	//filename
	lookupKey = subSectionKey + "." + fileNameKey;
	it = loggerPT.find(lookupKey);
	CPPUNIT_ASSERT(it != rootPT.not_found());

	value =  it->second.get_value<String>();
	m_file = boost::lexical_cast<std::string>(value);
	CPPUNIT_ASSERT(expectedFileName  == m_file);

	//level
	lookupKey = subSectionKey + "." + levelKey;
	it = loggerPT.find(lookupKey);
	CPPUNIT_ASSERT(it != rootPT.not_found());
	value = it->second.get_value<String>();
	 
	m_level = boost::lexical_cast<int>(value);
	CPPUNIT_ASSERT(expectedLevel== m_level);

	//modules
	lookupKey = subSectionKey + "." + modulesKey;
	it = loggerPT.find(lookupKey);
	CPPUNIT_ASSERT(it != rootPT.not_found());
	value = it->second.get_value<String>();
	CPPUNIT_ASSERT(expectedModules== value);
	std::vector<std::string> strs;
	boost::split(strs, value, boost::is_any_of(","));
	BOOST_FOREACH( String  str, strs )
		m_modules.insert(str);


}


void
DebugSettingsIni::save(const std::string &filename)
{
    using boost::property_tree::ptree;
    ptree rootPT;
	ptree loggerPT;

	//file name
	loggerPT.push_back(std::make_pair(subSectionKey + "." + fileNameKey, 
		expectedFileName));
 
	//logging level
	loggerPT.push_back(std::make_pair(subSectionKey + "." + levelKey, 
		boost::lexical_cast<String>(expectedLevel)));

	//modules
	String modules;
 
	 
	for (std::set<std::string>::const_iterator it = m_modules.begin();
		it != m_modules.end();
		)
	{
		modules += *it;
		++it;
		if (it != m_modules.end())
			modules += ",";
 
	}
	 
	loggerPT.push_back(std::make_pair(subSectionKey + "." + modulesKey, 
		boost::lexical_cast<String>(modules)));
	
	//tree
	rootPT.push_back(std::make_pair(loggerSectionKey, loggerPT));
	write_ini(filename, rootPT);
}




struct DebugSettingsXml
{
    std::string m_file;               // log filename
    int m_level;                      // debug level
    std::set<std::string> m_modules;  // modules where logging is enabled
    void load(const std::string &filename);
    void save(const std::string &filename);
};

void
DebugSettingsXml::load(const std::string &filename)
{
	String key;
	String value;
    // Create empty property tree object
    using boost::property_tree::ptree;
    ptree pt;




    // Load XML file and put its contents in property tree. 
    // No namespace qualification is needed, because of Koenig 
    // lookup on the second argument. If reading fails, exception
    // is thrown.
    read_xml(filename, pt);


	for (ptree::iterator it = pt.begin(); it != pt.end(); ++it){
		key = it->first;
		ptree& p = it->second;
		value = p.data();
		Size sz = p.size();
		std::cout << "key: " << key << std::endl;
		std::cout << "value:" << value << std::endl;
		std::cout << "size: " << sz << std::endl;
		 
	}

    // Get filename and store it in m_file variable. Note that 
    // we specify a path to the value using notation where keys 
    // are separated with dots (different separator may be used 
    // if keys themselves contain dots). If debug.filename key is 
    // not found, exception is thrown.
    m_file = pt.get<std::string>("debug.filename");
    
    // Get debug level and store it in m_level variable. This is 
    // another version of get method: if debug.level key is not 
    // found, it will return default value (specified by second 
    // parameter) instead of throwing. Type of the value extracted 
    // is determined by type of second parameter, so we can simply 
    // write get(...) instead of get<int>(...).
    m_level = pt.get("debug.level", 0);

    // Iterate over debug.modules section and store all found 
    // modules in m_modules set. get_child() function returns a 
    // reference to child at specified path; if there is no such 
    // child, it throws. Property tree iterator can be used in 
    // the same way as standard container iterator. Category 
    // is bidirectional_iterator.
    BOOST_FOREACH(ptree::value_type &v, pt.get_child("debug.modules"))
		m_modules.insert(v.second.data());

}

void
DebugSettingsXml::save(const std::string &filename)
{

    // Create empty property tree object
    using boost::property_tree::ptree;
    ptree pt;

    // Put log filename in property tree
    pt.put("debug.filename", m_file);

    // Put debug level in property tree
    pt.put("debug.level", m_level);

    // Iterate over modules in set and put them in property
    // tree. Note that the add function places new key at the
    // end of list of keys. This is fine in most of the
    // situations. If you want to place item at some other
    // place (i.e. at front or somewhere in the middle),
    // this can be achieved using a combination of the insert
    // and put_value functions
    BOOST_FOREACH(const std::string &name, m_modules)
        pt.add("debug.modules.module", name);
    
    // Write property tree to XML file
    write_xml(filename, pt);

}


//public member functions
BoostPropertyTreeFeatureTest::BoostPropertyTreeFeatureTest()
{

}

void 
BoostPropertyTreeFeatureTest::test_features()
{
	using namespace boost::property_tree;
	const String keyString = "string";
	const String valueString = "3.14159";

	//1 Allocate a PropertyTree with String Key, String Data
	ptree pt;

	//2 Add String Data 
	pt.push_back(ptree::value_type(keyString, ptree(valueString)));

	ptree::const_assoc_iterator it = pt.find(keyString);
	CPPUNIT_ASSERT(it != pt.not_found());
	CPPUNIT_ASSERT(keyString == it->first);
	CPPUNIT_ASSERT(valueString == it->second.get_value<String>());
	CPPUNIT_ASSERT(valueString == pt.get<String>(keyString));


	//3) Add Double Data
	String keyDouble = "double";
	double valueDouble = 1.0;
	pt.put(keyDouble, valueDouble);
	CPPUNIT_ASSERT(valueDouble <= pt.get<double>(keyDouble));

	//4) Get default double data
	double valueDefault = 0.0; ;
	String keyDoubleNotFound = "doulbeNotFound";
	valueDefault = pt.get<double>(keyDoubleNotFound, valueDouble);
	CPPUNIT_ASSERT(valueDouble <= valueDefault);


	//5) Get missing key, should raise exception
	try{
		pt.get<double>(keyDoubleNotFound);
	}
	catch (std::exception& ex){
		std::cout << "caught expected exception: " << ex.what() << std::endl;
	}

	//6) read/writewrite xml structure to file
	DebugSettingsXml xds;
	xds.load("debug_settings.xml");
    xds.save("debug_settings_out.xml");

	//7) read/writewrite ini structure to file
	DebugSettingsIni  ids;
	ids.load("debug_settings.ini");
    ids.save("debug_settings_out.ini");


	//8) read/writewrite json structure to file
	DebugSettingsJSON  jds;
	jds.load("debug_settings.json");
    jds.save("debug_settings_out.json");
}


} //namespace boostimpl
} //namespace container
} //namespace test
} //namespace ondalear

