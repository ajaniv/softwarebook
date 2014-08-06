/**
 * \file ProgramOptionsTest.cpp
 * \brief Program options  unit test header file
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
#include "ProgramOptionsTest.hpp"



namespace ondalear {
namespace test {
namespace options {


static const String groupA = "groupA";
static const String groupB = "groupB";
static const String groupC = "groupC";

static const String undefinedOption = "undefinedOption";
static const String defaultValue = "defaultValue";

static const String flagOption = "helpOption";
static const String flagOptionShortName = "h";
static const String flagOptionDesc = "flag option description";

static const String detailOptionInteger = "integerDetailOption";
static const String detailOptionIntegerShortName = "i";
static const String detailOptionIntegerDesc = "detail option integer description";
static const String detailOptionIntegerValue = "25";
static const Integer detailOptionsIntegerValueInteger = 25;

static const String detailOptionBool = "boolDetailOption";
static const String detailOptionBoolShortName = "b";
static const String detailOptionBoolDesc = "detail option bool description";
static const String detailOptionBoolValue = "1";


static const String detailOptionString = "stringDetailOption";
static const String detailOptionStringShortName = "s";
static const String detailOptionStringDesc = "detail option string description";
static const String detailOptionStringValue = "string";

static const String detailOptionFloat = "floatDetailOption";
static const String detailOptionFloatShortName = "f";
static const String detailOptionFloatDesc = "detail option float description";
static const String detailOptionFloatValue = "0.25";

static const String arg1 = "arg1";
static const String arg2 = "arg2";






//valid 
static const int argc3 = 3;
static const char* argv3 [] = {
	"pgm",
	"-h",
	"-i25",
	""
};

//valid
static const int argc4 = 3;
static const char* argv4 [] = {
	"pgm",
	"--helpOption",
	"--integerDetailOption=25",
	""
};

//valid
static const int argc5 = 3;
static const char* argv5 [] = {
	"pgm",
	"-h",
	"-i25",
	""
};



//valid positional
static const int argc7 = 5;
static const char* argv7 [] = {
	"pgm",
	"-h",
	"-i25",
	arg1.c_str(),
	arg2.c_str(),
	""
};


//invalid
static const int argc0 = 0;
static const char* argv0 [] = {""};

//invalid missing mandatory arguments
static const int argc1 = 1;
static const char* argv1 [] = {
	"pgm",
	""
};

//invalid  - improper -d option
static const int argc2 = 3;
static const char* argv2 [] = {
	"pgm",
	"-h",
	"-i",
	""
};

 
//invalid option -z
int argc6 = 4;
static const char* argv6 [] = {
	"pgm",
	"-h",
	"-i25",
	"-z",
	""
};

//public member functions
ProgramOptionsTest::ProgramOptionsTest()
{
	

}

void
ProgramOptionsTest::test_lifecycle()
{
	//test: ProgramOptions::ProgramOptions();
	ProgramOptions programOptions1;
	//test: ProgramOptions::ProgramOptions (const ProgramOptions& other);
	ProgramOptions programOptions2 (programOptions1);;

	//test: ProgramOptions::virtual ~ProgramOptions();
	 
}

void
ProgramOptionsTest::test_group()
{
	
	 

	ProgramOptions pgmOptions;
	 
	OptionGroup group = createGroupA ();

	//test: ProgramOptions::virtual void set(const OptionGroup& group);
	pgmOptions.set(group);

	//test: ProgramOptions::virtual Bool isGroupDefined(const String& groupName) const;
	CPPUNIT_ASSERT(true == pgmOptions.isGroupDefined(groupA));

	//test: ProgramOptions::const OptionGroup& getGroup(const String& groupName) const;
	OptionGroup copyGroup = pgmOptions.getGroup(groupA);
	CPPUNIT_ASSERT(copyGroup == group);
	
	//test: ProgramOptions::virtual void remove(const String& groupName);
	pgmOptions.remove(groupA);

	CPPUNIT_ASSERT(false == pgmOptions.isGroupDefined(groupA));



}


void
ProgramOptionsTest::test_options_valid()
{
	Integer resultInteger;

	String result;
	ProgramOptions pgmOptions;
	OptionGroup groupA = createGroupA ();
	OptionGroup groupB = createGroupB ();

	pgmOptions.set(groupA);
	pgmOptions.set(groupB);

	//test: ProgramOptions::virtual void parse(int argc, const char* argv[]);
	pgmOptions.parse(argc3, argv3);

	
	//test: ProgramOptions::virtual Bool isOptionDefined(const String& optionName) const;
	CPPUNIT_ASSERT(true == pgmOptions.isOptionDefined(flagOption));
	CPPUNIT_ASSERT(true == pgmOptions.isOptionDefined(detailOptionInteger));
	CPPUNIT_ASSERT(false == pgmOptions.isOptionDefined(detailOptionBool));


	//test: ProgramOptions::virtual String getOptionValue(const String& optionName) const;
	result = pgmOptions.getOptionValue(flagOption);
	CPPUNIT_ASSERT(String("") == result);
	result = pgmOptions.getOptionValue(detailOptionInteger);
	CPPUNIT_ASSERT(detailOptionIntegerValue ==  result);

	resultInteger = pgmOptions.get<Integer>(detailOptionInteger);
	CPPUNIT_ASSERT(detailOptionsIntegerValueInteger == resultInteger);

	pgmOptions.parse(argc4, argv4);

	CPPUNIT_ASSERT(true == pgmOptions.isOptionDefined(flagOption));
	CPPUNIT_ASSERT(true == pgmOptions.isOptionDefined(detailOptionInteger));
	result = pgmOptions.getOptionValue(flagOption);
	CPPUNIT_ASSERT(String("") == result);
	result = pgmOptions.getOptionValue(detailOptionInteger);
	CPPUNIT_ASSERT(detailOptionIntegerValue ==  result);



	pgmOptions.parse(argc5, argv5);

	CPPUNIT_ASSERT(true == pgmOptions.isOptionDefined(flagOption));
	CPPUNIT_ASSERT(true == pgmOptions.isOptionDefined(detailOptionInteger));
	result = pgmOptions.getOptionValue(flagOption);
	CPPUNIT_ASSERT(String("") == result);
	result = pgmOptions.getOptionValue(detailOptionInteger);
	CPPUNIT_ASSERT(detailOptionIntegerValue ==  result);

	 
	//test: ProgramOptions::virtual String getOptionValueOrDefault(const String& optionName, const String& defaultValue) const;
	result = pgmOptions.getOptionValueOrDefault(undefinedOption, defaultValue);
	CPPUNIT_ASSERT(defaultValue ==  result);

	
	resultInteger = pgmOptions.getOrDefault<Integer>(undefinedOption, detailOptionsIntegerValueInteger);
	CPPUNIT_ASSERT(detailOptionsIntegerValueInteger == resultInteger);

	pgmOptions.parse(argc7, argv7);


	//test: ProgramOptions::virtual String helpMessage() const ;
	String helpMessage = pgmOptions.helpMessage();
	std::cout << "help messaage: " << helpMessage << std::endl;


	//test: BoostProgramOptionsImplTest::virtual VectorString positionalArgs() const;

	VectorString positionalArgs = pgmOptions.positionalArgs();
	CPPUNIT_ASSERT(2 == positionalArgs.size());
	CPPUNIT_ASSERT(arg1 == positionalArgs[0]);
	CPPUNIT_ASSERT(arg2 == positionalArgs[1]);

}

void
ProgramOptionsTest::test_options_invalid()
{
	ProgramOptions pgmOptions;
	OptionGroup group;
	 
	
	
	group = createGroupA();
	CPPUNIT_ASSERT(2 == group.sizeOptions());
	pgmOptions.set(group);
	
	//parse with no arguments
	try {
		pgmOptions.parse(argc0, argv0);
	}
	catch (BaseException& ex)
	{
		std::cout << std::endl;
		std::cout << "Caught expected exception (argc == 0); details: " << ex.details() << std::endl;
	}

	try {
		pgmOptions.parse(argc1, argv1);
	}
	catch (BaseException& ex)
	{
		std::cout << std::endl;
		std::cout << "Caught expected exception (missing mandatory option); details: " << ex.details() << std::endl;
	}
	
	//test: BoostProgramOptionsImpl::virtual String getOptionValue(const String& optionName) const ;
	String result;
	try {
		result = pgmOptions.getOptionValue(flagOption);
	}
	catch (BaseException& ex)
	{
		std::cout << std::endl;
		std::cout << "Caught expected exception (arg not defined); details: " << ex.details() << std::endl;
	}

	try {
		pgmOptions.parse(argc2, argv2);
	}
	catch (BaseException& ex)
	{
		std::cout << std::endl;
		std::cout << "Caught expected exception (detail option missing); details: " << ex.details() << std::endl;
	}

	try {
		pgmOptions.parse(argc6, argv6);
	}
	catch (BaseException& ex)
	{
		std::cout << std::endl;
		std::cout << "Caught expected exception (invalid option); details: " << ex.details() << std::endl;
	}

	pgmOptions.parse(argc3, argv3);
	try {
		Bool resultBool = pgmOptions.getOrDefault<Bool>(detailOptionInteger, false);
	}
	catch (BaseException& ex)
	{
		std::cout << std::endl;
		std::cout << "Caught expected exception (invalide cast); details: " << ex.details() << std::endl;
	}
}

OptionGroup
ProgramOptionsTest::createGroupA()
{
	
	OptionGroup  group(groupA);
	group.setOption(flagOption, flagOptionDesc, flagOptionShortName);
	group.setOption(detailOptionInteger, detailOptionIntegerDesc, detailOptionIntegerShortName, true, true);
	CPPUNIT_ASSERT(2 == group.sizeOptions());

	return group;
}


OptionGroup
ProgramOptionsTest::createGroupB()
{
	
	OptionGroup  group(groupB);
 
	group.setOption(detailOptionBool, detailOptionBoolDesc, detailOptionBoolShortName, false, true);
	group.setOption(detailOptionString, detailOptionStringDesc, detailOptionStringShortName, false, true);
	group.setOption(detailOptionFloat, detailOptionFloatDesc, detailOptionFloatShortName, false, true);


	CPPUNIT_ASSERT(3 == group.sizeOptions());

	return group;
}

} //namespace options
} //namespace test
} //namespace ondalear

