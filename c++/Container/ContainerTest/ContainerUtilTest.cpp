/**
 * \file ContainerUtilTest.cpp
 * \brief Container util test  unit test source file
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
#include "ContainerUtilTest.hpp"



namespace ondalear {
namespace test {
namespace container {



//public member functions
ContainerUtilTest::ContainerUtilTest()
{

}

void
ContainerUtilTest::test_import_export()
{
	
	//test: ContainerUtil::static PropertyTreeSharedPtr readPropertyTree();
	//test: ContainerUtil::static PropertyTreeSharedPtr readPropertyTree(const String& fileName);
	//test: ContainerUtil::static PropertyTreeSharedPtr readPropertyTree(const String& fileName, FileType::eFileType fileType );
	
	
	//test: ContainerUtil::static void  writePropertyTree(const PropertyTree& tree);
	//test: ContainerUtil::static void  writePropertyTree(const String& fileName, const PropertyTree& tree);
	//test: ContainerUtil::static void  writePropertyTree(const String& fileName, FileType::eFileType fileType, const PropertyTree& tree);


	//test: ContainerUtil::static PropertyTreeSharedPtr readPropertyTree(std::istream& inputStream, FileType::eFileType fileType );
	//test: ContainerUtil::static void  writePropertyTree(std::ostream& outputStream, FileType::eFileType fileType, const PropertyTree& tree);

	const String xmlInputFileName("debug_settings.xml");
	const String xmlOutputFileName("config.xml");

	const String iniInputFileName("debug_settings.ini");
	const String iniOutputFileName("config.ini");


	const String jsonInputFileName("debug_settings.json");
	const String jsonOutputFileName("config.json");

	PropertyTreeSharedPtr ptr;


	//XML
	 
	std::stringstream ssxml("");

	ptr = ContainerUtil::readPropertyTree(xmlInputFileName,FileType::XML );
	CPPUNIT_ASSERT(1 == ptr->size());//comments are striped

	ContainerUtil::writePropertyTree (xmlOutputFileName, FileType::XML , *ptr);
	ContainerUtil::writePropertyTree(ssxml, FileType::XML , *ptr);
	ptr = ContainerUtil::readPropertyTree(ssxml, FileType::XML );
	CPPUNIT_ASSERT(1 == ptr->size());//comments are striped



	//INI

	
	std::stringstream ssini("");
	ptr = ContainerUtil::readPropertyTree(iniInputFileName, FileType::INI);
	CPPUNIT_ASSERT(1 == ptr->size()); //comments are striped

	ContainerUtil::writePropertyTree(ssini, FileType::INI , *ptr);
	
	ptr = ContainerUtil::readPropertyTree(ssini, FileType::INI );
	CPPUNIT_ASSERT(1 == ptr->size());//comments are striped

	ContainerUtil::writePropertyTree (iniOutputFileName, FileType::INI, *ptr);

	//JSON

	std::stringstream ssjson("");
	ptr = ContainerUtil::readPropertyTree(jsonInputFileName, FileType::JSON);
	CPPUNIT_ASSERT(1 == ptr->size()); //comments are striped

	ContainerUtil::writePropertyTree(ssjson, FileType::JSON , *ptr);
	
	ptr = ContainerUtil::readPropertyTree(ssjson, FileType::JSON );
	CPPUNIT_ASSERT(1 == ptr->size());//comments are striped

	ContainerUtil::writePropertyTree(jsonOutputFileName, FileType::JSON, *ptr);


	//test: ContainerUtil::static PropertyTreeSharedPtr readPropertyTree();
	std::stringstream defaultss("");
	ptr = ContainerUtil::readPropertyTree();
	CPPUNIT_ASSERT(1 == ptr->size());//comments are striped
	ContainerUtil::writePropertyTree(defaultss, FileType::XML , *ptr);
	std::cout << "Input xml,output raw XML: " << defaultss.str() << std::endl;

}



} //namespace container
} //namespace test
} //namespace ondalear

