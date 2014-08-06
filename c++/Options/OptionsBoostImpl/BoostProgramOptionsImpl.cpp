/**
 * \file BoostProgramOptionsImpl.hpp
 * \brief Boost program options implementation source file
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
#include <iostream>
#include <vector>

#include "BoostProgramOptionsImpl.hpp"

#include "../OptionsConstants.hpp"


namespace ondalear {
namespace options {
namespace boostimpl {

	

/*
 *
 * public constructors
 *
 */

BoostProgramOptionsImpl::BoostProgramOptionsImpl()
{
	doReset();
}

BoostProgramOptionsImpl::BoostProgramOptionsImpl (const BoostProgramOptionsImpl& other)
{
	init(other);
}


 

BoostProgramOptionsImpl::~BoostProgramOptionsImpl()
{
}



/*
 *
 * public operators-general
 *
 */

BoostProgramOptionsImpl&
BoostProgramOptionsImpl::operator=(const BoostProgramOptionsImpl &other)
{
	if (this != &other){
		init(other);
	}
	return *this;
}


/*
 *
 * public options
 *
 */

void
BoostProgramOptionsImpl::reset()
{
	doReset();
}



void
BoostProgramOptionsImpl::registerGroup(const OptionGroup& group)
{

	ASSERT_MSG(group.sizeOptions() > 0 || group.sizeGroups() > 0, "empty group");

	setParsed(false);

	BoostOptionDesc boostOptions;
	try{
		doRegisterGroup(boostOptions, group);
		appDescPtr->add(boostOptions);
	}
	catch (std::exception& ex ){
		THROW_MSG(CoreText::instance().reviewImplementation(ex.what()));
	}

}


    
void
BoostProgramOptionsImpl::parse(int argc, const char* argv[])
{
	ASSERT_MSG(argc > 0, "invalid argc");
	setParsed(false);
	try {
		using namespace boost::program_options;

		BoostOptionDesc rootDesc;
		rootDesc.add(*sysDescPtr);
		rootDesc.add(*appDescPtr);

		const char** firstArg =  argv ;
		command_line_parser parser(argc, const_cast<char**  > (firstArg));

		parser.options(rootDesc);
		BoostPositionalOptionDesc posDesc = createPositionalArg();
		parser.positional(posDesc);
		basic_parsed_options<char> parserResults  = parser.run();
		store(parserResults, *variableMapPtr);

		notify(*variableMapPtr); 
		setParsed(true);
	}
	catch (std::exception& ex ){
		THROW_MSG(CoreText::instance().reviewImplementation(ex.what()));
	}
}

Bool
BoostProgramOptionsImpl::isOptionDefined(const String& optionName) const 
{
	Bool result = false;
	ASSERT(isParsed());
	try {
		result =  (*variableMapPtr).count(optionName.c_str()) > 0 ? true : false;
	}
	catch (std::exception& ex ){
		THROW_MSG(CoreText::instance().reviewImplementation(ex.what()));
	}
	return result;
            
}

String
BoostProgramOptionsImpl::getOptionValue(const String& optionName) const 
{
	String result;
	ASSERT(isParsed());

	if (isOptionDefined(optionName)){
		try {
			result = (*variableMapPtr)[optionName.c_str()].as<String>();
		}
		catch (std::exception& ex ){
			THROW_MSG(CoreText::instance().reviewImplementation(ex.what()));
		}
	}
	else 
		THROW_MSG(CoreText::instance().objectNotFound(optionName));
	return result;
	       
}


String 
BoostProgramOptionsImpl::helpMessage() const
{
	String buffer;
	std::stringstream ss(buffer);
	ss <<  *appDescPtr;

	String help = ss.str();
	return help;
}

VectorString
BoostProgramOptionsImpl::positionalArgs() const
{
	ASSERT(isParsed());

	VectorString result;
 
	const String optionName = OptionsConstants::positionalArgName();

	if (isOptionDefined(optionName)){
		try {
			result = (*variableMapPtr)[optionName.c_str()].as<VectorString>();
		}
		catch (std::exception& ex ){
			THROW_MSG(CoreText::instance().reviewImplementation(ex.what()));
		}
	}
	 
	return result;
}
/*
 *
 * public implementation utilities
 *
 */

Bool
BoostProgramOptionsImpl::isParsed() const
{
	return parsed;
}

void
BoostProgramOptionsImpl::setParsed(Bool flag)
{
	this->parsed = flag;
}


/*
 *
 * protected utilities
 *
 */


void
BoostProgramOptionsImpl::doRegisterGroup(BoostOptionDesc& root, const OptionGroup& group)
{
	
	const OptionMap& options = group.getOptions();


	BoostOptionDesc boostOptions = createBoostOptionDesc(group.getName(), options);
	const OptionGroupMap& groups = group.getGroups();
	for (OptionGroupMap::const_iterator iter = groups.begin();
		iter != groups.end(); ++iter){
			doRegisterGroup(boostOptions, iter->second);
	}
	
	root.add(boostOptions);


}

BoostOptionDesc
BoostProgramOptionsImpl::createBoostOptionDesc(const String& groupName,
											   const OptionMap& options) const
{
	
	String shortName ;
	String optionName ;
	String optionDesc ;
	Bool argReguired = false;

	BoostOptionDesc boostDesc (groupName);
	 
	for (OptionMap::const_iterator iter = options.begin();
		iter != options.end();
		++iter){
			
			const Option& option = iter->second;
			shortName = option.getShortName();
			optionName = option.getName();
			optionDesc = option.getDescription();
			argReguired = option.isArgRequired();

			optionName =
				shortName == "" 
				? optionName
				: optionName + "," + shortName; 

			if (argReguired)
				boostDesc.add_options()(optionName.c_str(), 
					boost::program_options::value<String>(),
					optionDesc.c_str());
					
			else
				boostDesc.add_options()(optionName.c_str(), optionDesc.c_str());
				
	}
	return boostDesc;
}

BoostPositionalOptionDesc
BoostProgramOptionsImpl::createPositionalArg()
{
	BoostPositionalOptionDesc pd; 
	pd.add(OptionsConstants::positionalArgName().c_str(), OptionsConstants::maxPositionalArgs);
	return pd;
}

void
BoostProgramOptionsImpl::doReset()
{

	sysDescPtr.reset(new BoostOptionDesc());
	appDescPtr.reset(new BoostOptionDesc());
	variableMapPtr.reset(new BoostVariableMap());

	sysDescPtr->add_options()(OptionsConstants::positionalArgName().c_str(), 
		boost::program_options::value< std::vector<String> >(), "");
					 

	setParsed(false);

}

/*
 *
 * private utilities
 *
 */
void
BoostProgramOptionsImpl::init(const BoostProgramOptionsImpl& other )
{
	doReset();
}
} //namespace boostimpl
} //namespace options
} //namespace ondalear