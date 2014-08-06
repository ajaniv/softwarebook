/**
 * \file BoostProprtyTreeFileHandlerImplTest.hpp
 * \brief Boost ProperyTree  file handler impl test header file
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
#include "BoostPropertyTreeFileHandlerImplTest.hpp"
#include <boost/foreach.hpp>

namespace ondalear {
namespace test {
namespace container {
namespace boostimpl {


//public member functions
BoostPropertyTreeFileHandlerImplTest::BoostPropertyTreeFileHandlerImplTest()
{

}

void 
BoostPropertyTreeFileHandlerImplTest::test_lifecycle()
{
	//test: BoostPropertyTreeFileHandlerImpl::BoostPropertyTreeFileHandlerImpl(const String& fileName, ContainerFileFormat::eContainerFileFormat fileFormat);  
	BoostPropertyTreeFileHandlerImpl impl1;

	//test: BoostPropertyTreeFileHandlerImpl::BoostPropertyTreeFileHandlerImpl(const BoostPropertyTreeFileHandlerImpl& other);
	BoostPropertyTreeFileHandlerImpl impl2(impl1);

}

void
BoostPropertyTreeFileHandlerImplTest::test_file()
{
	const String xmlInputFileName("debug_settings.xml");
	const String xmlOutputFileName("config.xml");

	const String iniInputFileName("debug_settings.ini");
	const String iniOutputFileName("config.ini");


	const String jsonInputFileName("debug_settings.json");
	const String jsonOutputFileName("config.json");

	PropertyTreeSharedPtr ptr;

	//test: BoostPropertyTreeFileHandlerImpl::virtual PropertyTreeSharedPtr read();
	//test: BoostPropertyTreeFileHandlerImpl::virtual void write(const PropertyTree& tree);
	//XML
	BoostPropertyTreeFileHandlerImpl implXML;
	 
	
	std::stringstream ssxml("");

	 

	ptr = implXML.readFrom(xmlInputFileName,FileType::XML );
	CPPUNIT_ASSERT(1 == ptr->size());//comments are striped

	implXML.writeTo (xmlOutputFileName, FileType::XML , *ptr);
	implXML.writeTo(ssxml, FileType::XML , *ptr);
	ptr = implXML.readFrom(ssxml, FileType::XML );
	CPPUNIT_ASSERT(1 == ptr->size());//comments are striped





	//INI

	BoostPropertyTreeFileHandlerImpl implINI;
	std::stringstream ssini("");
	ptr = implINI.readFrom(iniInputFileName, FileType::INI);
	CPPUNIT_ASSERT(1 == ptr->size()); //comments are striped

	implINI.writeTo(ssini, FileType::INI , *ptr);
	
	ptr = implXML.readFrom(ssini, FileType::INI );
	CPPUNIT_ASSERT(1 == ptr->size());//comments are striped

	implINI.writeTo (iniOutputFileName, FileType::INI, *ptr);

	//JSON
	BoostPropertyTreeFileHandlerImpl implJSON;
	std::stringstream ssjson("");
	ptr = implJSON.readFrom(jsonInputFileName, FileType::JSON);
	CPPUNIT_ASSERT(1 == ptr->size()); //comments are striped

	implJSON.writeTo(ssjson, FileType::JSON , *ptr);
	
	ptr = implJSON.readFrom(ssjson, FileType::JSON );
	CPPUNIT_ASSERT(1 == ptr->size());//comments are striped

	implJSON.writeTo (jsonOutputFileName, FileType::JSON, *ptr);



	PropertyTree tree;
	BoostPropertyTreeFileHandlerImpl dynamicImpl;
	tree.set<Integer>("root", "keyInteger", 1024);
	tree.set<String>("root", "keyString", "some string");
	tree.set<Bool>("root", "keyBool", true);
	tree.set<Real>("root", "keyFloat", 0.5);

	//export the property tree, nicely formatted to the file system, XML format
	std::stringstream myStream("");
	dynamicImpl.writeTo(myStream, FileType::INI, tree);
	std::cout << "raw ini " << myStream.str() << std::endl;

	//export the property tree, nicely formatted to the file system, XML format
	dynamicImpl.writeTo("dummy.xml", FileType::XML, tree);

}
} //namespace boostimpl
} //namespace container
} //namespace test
} //namespace ondalear

