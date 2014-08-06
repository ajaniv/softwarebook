/**
 * \file BoostProgramOptionsImplTest.cpp
 * \brief Boost program options  impl test source file
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
#include "BoostProgramOptionsImplTest.hpp"


namespace ondalear {
namespace test {
namespace option {
namespace boostimpl {


 

//public member functions
BoostProgramOptionsImplTest::BoostProgramOptionsImplTest()
{

}

void 
BoostProgramOptionsImplTest::test_lifecycle()
{
	//test: BoostProgramOptionsImpl::BoostProgramOptionsImpl();
	BoostProgramOptionsImpl impl1;
	CPPUNIT_ASSERT(false == impl1.isParsed());
	//test: BoostProgramOptionsImpl::BoostProgramOptionsImpl(const BoostProgramOptionsImpl& other);
	BoostProgramOptionsImpl impl2(impl1);
	CPPUNIT_ASSERT(false == impl2.isParsed());
	//test: BoostProgramOptionsImpl::~BoostProgramOptionsImpl();
	 
}

static const String flagOption = "helpOption";
static const String flagOptionShortName = "h";
static const String flagOptionDesc = "flag option description";
static const String detailOption = "detailOption";
static const String detailOptionShortName = "d";
static const String detailOptionDesc = "detail option description";
static const String groupOneName = "groupOne";
static const String arg1 = "arg1";
static const String arg2 = "arg2";

void 
BoostProgramOptionsImplTest::test_options_valid()
{
	BoostProgramOptionsImpl impl;
	OptionGroup group;
	String result;
	

	//valid 
	int argc1 = 1;
	const char* argv1 [] = {
		"pgm",
		""
	};



	//valid 
	int argc3 = 3;
	const char* argv3 [] = {
		"pgm",
		"-h",
		"-d25",
		""
	};

	//valid
	int argc4 = 3;
	const char* argv4 [] = {
		"pgm",
		"--helpOption",
		"--detailOption=25",
		""
	};

	//valid
	int argc5 = 3;
	const char* argv5 [] = {
		"pgm",
		"-h",
		"-d25",
		""
	};



	//positional
	int argc7 = 5;
	const char* argv7 [] = {
		"pgm",
		"-h",
		"-d25",
		arg1.c_str(),
		arg2.c_str(),
		""
	};

	CPPUNIT_ASSERT(false == impl.isParsed());

	CPPUNIT_ASSERT(String() == impl.helpMessage());
	//test: BoostProgramOptionsImpl::virtual void reset() ;
	impl.reset();

	//test: BoostProgramOptionsImpl::virtual void registerGroup(const OptionGroup& group) ;
	
	group = createOptionGroup();
	CPPUNIT_ASSERT(2 == group.sizeOptions());
	impl.registerGroup(group);

	//test: BoostProgramOptionsImpl::virtual void parse(int argc, char* argv[]);

	
	impl.parse(argc1, argv1);
	//test: BoostProgramOptionsImpl::virtual Bool isOptionDefined(const String& optionName) const ;
	CPPUNIT_ASSERT(false == impl.isOptionDefined(flagOption));
	
	//test: BoostProgramOptionsImpl::virtual String getOptionValue(const String& optionName) const ;

	impl.parse(argc3, argv3);

	CPPUNIT_ASSERT(true == impl.isOptionDefined(flagOption));
	CPPUNIT_ASSERT(true == impl.isOptionDefined(detailOption));
	result = impl.getOptionValue(flagOption);
	CPPUNIT_ASSERT(String("") == result);
	result = impl.getOptionValue(detailOption);
	CPPUNIT_ASSERT("25" ==  result);

	impl.parse(argc4, argv4);

	CPPUNIT_ASSERT(true == impl.isOptionDefined(flagOption));
	CPPUNIT_ASSERT(true == impl.isOptionDefined(detailOption));
	result = impl.getOptionValue(flagOption);
	CPPUNIT_ASSERT(String("") == result);
	result = impl.getOptionValue(detailOption);
	CPPUNIT_ASSERT("25" ==  result);

	impl.parse(argc5, argv5);

	CPPUNIT_ASSERT(true == impl.isOptionDefined(flagOption));
	CPPUNIT_ASSERT(true == impl.isOptionDefined(detailOption));
	result = impl.getOptionValue(flagOption);
	CPPUNIT_ASSERT(String("") == result);
	result = impl.getOptionValue(detailOption);
	CPPUNIT_ASSERT("25" ==  result);


	impl.parse(argc7, argv7);

	//test: BoostProgramOptionsImplTest::virtual String helpMessage() const;
	String helpMessage = impl.helpMessage();
	std::cout << "help messaage: " << helpMessage << std::endl;


	//test: BoostProgramOptionsImplTest::virtual VectorString positionalArgs() const;

	VectorString positionalArgs = impl.positionalArgs();
	CPPUNIT_ASSERT(2 == positionalArgs.size());
	CPPUNIT_ASSERT(arg1 == positionalArgs[0]);
	CPPUNIT_ASSERT(arg2 == positionalArgs[1]);


}


void 
BoostProgramOptionsImplTest::test_options_invalid()
{
	BoostProgramOptionsImpl impl;
	OptionGroup group;
	 
	//invalid
	int argc0 = 0;
	const char* argv0 [] = {""};

	 

	//invalid  - improper -d option
	int argc2 = 3;
	const char* argv2 [] = {
		"pgm",
		"-h",
		"-d",
		""
	};

	 
	//invalid option -z
	int argc6 = 4;
	const char* argv6 [] = {
		"pgm",
		"-h",
		"-d25",
		"-z",
		""
	};




	//registery empty group
	try{
		impl.registerGroup(group);
	}
	catch (BaseException& ex)
	{
		std::cout << std::endl;
		std::cout << "Caught expected exception (empty group); details: " << ex.details() << std::endl;
	}

	group = createOptionGroup();
	CPPUNIT_ASSERT(2 == group.sizeOptions());
	impl.registerGroup(group);
	
	//parse with no arguments
	try {
		impl.parse(argc0, argv0);
	}
	catch (BaseException& ex)
	{
		std::cout << std::endl;
		std::cout << "Caught expected exception (argc == 0); details: " << ex.details() << std::endl;
	}

	
	//test: BoostProgramOptionsImpl::virtual String getOptionValue(const String& optionName) const ;
	String result;
	try {
		result = impl.getOptionValue(flagOption);
	}
	catch (BaseException& ex)
	{
		std::cout << std::endl;
		std::cout << "Caught expected exception (arg not defined); details: " << ex.details() << std::endl;
	}

	try {
		impl.parse(argc2, argv2);
	}
	catch (BaseException& ex)
	{
		std::cout << std::endl;
		std::cout << "Caught expected exception (detail option missing); details: " << ex.details() << std::endl;
	}

	try {
		impl.parse(argc6, argv6);
	}
	catch (BaseException& ex)
	{
		std::cout << std::endl;
		std::cout << "Caught expected exception (invalide option); details: " << ex.details() << std::endl;
	}

}

OptionGroup
BoostProgramOptionsImplTest::createOptionGroup()
{
	OptionGroup group;
	group.setName(groupOneName);
	group.setOption(flagOption, flagOptionDesc, flagOptionShortName);
	group.setOption(detailOption, detailOptionDesc, detailOptionShortName, true, true);
	CPPUNIT_ASSERT(2 == group.sizeOptions());

	return group;
}

} //namespace boostimpl
} //namespace container
} //namespace test
} //namespace ondalear

