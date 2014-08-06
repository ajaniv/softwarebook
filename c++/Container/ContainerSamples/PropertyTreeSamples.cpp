/**
 * \file PropertyTreeSamples.cpp
 * \brief PropertyTree    samples source file
 *
 *
 * PropertyTree is a container for managing properites; it is typically used for configuring application components where properties
 * are stored in files. The following samples focus on demonstrating key PropertyTree features including:
 * - Storeage and retieval of propertires from several kinds of files    including xml, json, ini.
 * - Import and export of property trees to/from files and streams.
 * - Conversion  to/from internal String storeage
 * - Merging of property trees
 *
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
#include <iostream>

#include "ContainerSamples.hpp"
#include "container/ContainerUtil.hpp"


namespace ondalear {
namespace samples {
namespace container {
/**
 * \fn propertyTreeSamples
 * \brief Demonstrate PropertyTree related features
 *
 */
void
propertyTreeSamples()
{
	/*
	 * Step 1: Import a property tree from a file where the file type is XML.
	 *         This allows configuration data to be retrieved at the application
	 *         or component level.
	 *         
	 */

	// Load the property tree from file and store its contents in PropertyTree. 
	// File processing errors result in BaseException or a derived class exception
	// being thrown. 

	PropertyTreeSharedPtr treePtr;
	
	//Expands to ContainerUtil::readPropertyTree("config.xml",FileType::XML )
	treePtr = ContainerUtil::readPropertyTree(); 

	//Memory  now has  the following properties, without the comments.
	/*
		<?xml version="1.0" encoding="utf-8"?>
		<!-- Logging configuration file -->
		<logger>
			<filename>logger.log</filename>
			<modules>
				<module>Finance</module>
				<module>Admin</module>
				<module>HR</module>
			</modules>
			<level>PriorityLevel::Debug</level>
			<format>
				<pretty>1</pretty> <!-- boolean -->
				<rows>10</rows>  <!-- int-->
				<precision>0.5</precision>  <!-- float-->
			</format>
		</logger>

	*/

	/*
	 * Step 2: Retrieve property data using path, key 
	 *         Note that the path and key can be combined into one lookup key,
	 *         but this may not be supported on all file types, or when
	 *         a key has a separator as part of its string.
	 *         
	 *     
	 */
	
	// Get filename and store it in logFileName variable. Note that 
	// we specify a path to the value using notation where keys 
	// are separated with dots (different separator may be used 
	// if keys themselves contain dots). If debug.filename key is 
	// not found, exception is thrown.
	
	try{
		String logFileName  = treePtr->get<String>("logger", "filename");
		std::cout << "logger.filename (expected logger.log): " << logFileName << std::endl;
	}
	catch(BaseException& ex){
		//should not see this error message
		std::cout << "failed to retrieve file name, detail: " << ex.what() << std::endl;
	}

	//Note that here the path and key have been combined; this approach may not
	//work for all the underlying implementations.
	try{
		String logFileName  = treePtr->get<String>("logger.filename");
		std::cout << "logger.filename (expected logger.log): " << logFileName << std::endl;
	}
	catch(BaseException& ex){
		//should not see this error message
		std::cout << "failed to retrieve file name, detail: " << ex.what() << std::endl;
	}
    
	// Get debug level and store it in debugLevel variable. This is 
	// another version of get method: if debug.level key is not 
	// found, it will return default value (specified by second 
	// parameter) instead of throwing.  
	String debugLevel =  treePtr->getOrDefault<String>("logger", "level",  "PriorityLevel::Info");
	std::cout << "logger.level (expected PriorityLevel::Debug ): " << debugLevel << std::endl;

	//Get a few other pieces of information from other parts of the xml tree,
	//and convert to the specified format

	Bool pretty = treePtr->getOrDefault<Bool>("logger.format", "pretty",  false);
	std::cout << "logger.format.pretty (expected 1 ): " << pretty << std::endl;
	
	Integer rows =  treePtr->getOrDefault<Integer>("logger.format", "rows",  5);
	std::cout << "logger.format.rows (expected 10 ): " << rows << std::endl;

	Real precision =  treePtr->getOrDefault<Real>("logger.format", "precision",  0.75);
	std::cout << "logger.format.precision (expected 0.5 ): " << precision << std::endl;

	//Iterate over a child tree
	try{
		PropertyTree child = treePtr->getTree("logger", "modules");
		for (PropertyTreeIterator iter = child.begin(); iter != child.end(); ++iter){
			std::cout << "key: " << iter.first() << " value : " << iter.get<String>() << std::endl;
		}
	}
	catch(BaseException& ex){
		//should not see this error message
		std::cout << "faiiled to chiild tree, detail: " << ex.what() << std::endl;
	}
 
	/*
	 * Step 3: Create a PropertyTree at run time
	 *     
	 */
	PropertyTree tree;

	tree.set<Integer>("root", "keyInteger", 1024);
	tree.set<String>("root", "keyString", "some string");
	tree.set<Bool>("root", "keyBool", true);
	tree.set<Real>("root", "keyFloat", 0.5);

	//export the property tree using  INI format
	std::stringstream myStream("");
	ContainerUtil::writePropertyTree(myStream, FileType::INI, tree);
	std::cout << "raw ini:"   << std::endl;
	std::cout <<  myStream.str() << std::endl;

	//export the property tree, nicely formatted to the file system, XML format
	ContainerUtil::writePropertyTree("dummy.xml", FileType::XML, tree);
}


} //namespace container
} //namespace samples
} //namespace ondalear