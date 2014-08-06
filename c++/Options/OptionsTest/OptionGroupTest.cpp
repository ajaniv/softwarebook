/**
 * \file OptionGroupTest.cpp
 * \brief OptionGroup unit test source file
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
#include "OptionGroupTest.hpp"
#include "options/OptionsConstants.hpp"


namespace ondalear {
namespace test {
namespace options {



//public member functions
OptionGroupTest::OptionGroupTest()
{

}

void
OptionGroupTest::test_lifecycle()
{
	const String groupName("MainGroup");
	//test: OptionGrup::OptionGroup();
	OptionGroup group1;
	CPPUNIT_ASSERT(OptionsConstants::defaultGroupName() == group1.getName());
	CPPUNIT_ASSERT(0 == group1.sizeOptions());
	CPPUNIT_ASSERT(0 == group1.sizeGroups());

	//test: OptionGrup::OptionGroup(const String& name);
	OptionGroup group2(groupName);
	CPPUNIT_ASSERT(groupName  ==  group2.getName() );
	CPPUNIT_ASSERT(0 == group2.sizeOptions());
	CPPUNIT_ASSERT(0 == group2.sizeGroups());

	//test: OptionGrup::OptionGroup (const OptionGroup& other);
	OptionGroup group3(group2);
	CPPUNIT_ASSERT(groupName  == group3.getName()  );
	CPPUNIT_ASSERT(0 == group3.sizeOptions());
	CPPUNIT_ASSERT(0 == group3.sizeGroups());
	//test: OptionGrup::virtual ~OptionGroup();
	 
}
void 
OptionGroupTest::test_accessor()
{
	//test: OptionGrup::virtual void setName(const String& name);
	//test: OptionGrup::virtual const String& getName() const;
	const String groupName("MainGroup");
	OptionGroup parent;
	CPPUNIT_ASSERT(OptionsConstants::defaultGroupName() == parent.getName());
	parent.setName(groupName);
	CPPUNIT_ASSERT(groupName == parent.getName());

	//test: OptionGrup::virtual const SetString optionNames() const;
	SetString names = parent.optionNames();
	CPPUNIT_ASSERT(0 == names.size());
	parent.setOption("debug", "debug description", "d", true, true);
	
	OptionGroup child("child");
	child.setOption("help", "help description");
	child.setOption("version", "version description");
	parent.setGroup(child);
	names = parent.optionNames();
	CPPUNIT_ASSERT(3 == names.size());
}

void 
OptionGroupTest::test_options()
{
	const String optionName("help");
	const String optionShortName("h");
	const String optionDesc("Help Option Description");
	const Bool  mandatoryFlag = true;
	const Bool  argRequiredFlag = true;
	Option option;

	option.setName(optionName);
	option.setShortName(optionShortName);
	option.setDescription(optionDesc);
	option.setMandatory(mandatoryFlag);
	option.setArgRequired(argRequiredFlag);

	OptionGroup group;

	//test: OptionGrup::virtual void set(const Option& option);
	//test: OptionGrup::virtual void set(const String& name, const String& shortName, const String& description);
	//test: OptionGrup::virtual void remove(const String& name);
	//test: OptionGrup::virtual Bool isDefined(const String& name) const;

	CPPUNIT_ASSERT(false == group.isOptionDefined(optionName));
	CPPUNIT_ASSERT(0 == group.sizeOptions());

	group.setOption(option);
	CPPUNIT_ASSERT(true == group.isOptionDefined(optionName));
	CPPUNIT_ASSERT(1 == group.sizeOptions());

	group.setOption(optionName,  optionDesc, optionShortName, mandatoryFlag, argRequiredFlag);
	CPPUNIT_ASSERT(true == group.isOptionDefined(optionName));
	CPPUNIT_ASSERT(1 == group.sizeOptions());

	group.removeOption(optionName);
	CPPUNIT_ASSERT(false == group.isOptionDefined(optionName));
	CPPUNIT_ASSERT(0 == group.sizeOptions());

	try {
		group.removeOption(optionName);
	}
	catch(BaseException& ex)
	{
		std::cout << "caught expected exception; details: " << ex.details() << std::endl;
	}
}


void 
OptionGroupTest::test_group()
{

	const String parentGroupName = "parent";
	const String childGroupName = "child";

	OptionGroup parent;
	parent.setName(parentGroupName);

	OptionGroup child;
	child.setName(childGroupName);

	CPPUNIT_ASSERT(0  == parent.sizeGroups());
	//test: OptionGrup::virtual void setGroup(const OptionGroup& optionGroup);
	parent.setGroup(child);
	CPPUNIT_ASSERT(1  == parent.sizeGroups());
	
	//test: OptionGrup::virtual Bool isGroupDefined(const String& groupName) const;
	CPPUNIT_ASSERT(true == parent.isGroupDefined(childGroupName));

	//test: OptionGrup::virtual void removeGroup(const String& groupName);
	parent.removeGroup(childGroupName);
	CPPUNIT_ASSERT(0  == parent.sizeGroups());



}

} //namespace options
} //namespace test
} //namespace ondalear

