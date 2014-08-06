/**
 * \file ProgramOptions.cpp
 * \brief Program options     source  file.
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



#include "ProgramOptions.hpp"

#include <algorithm>

#include "core/CoreContainerTypes.hpp"

#include "OptionsRegistry.hpp"
#include "ProgramOptionsImpl.hpp"

namespace ondalear {
namespace options {

/*
 *
 * public constructors
 *
 */

ProgramOptions::ProgramOptions()
	:
	impl(OptionsRegistry::instance().getFactory()->createProgramOptionsImpl())
{
}

 


ProgramOptions::ProgramOptions (const ProgramOptions& other)
{
	init(other);
}


ProgramOptions::~ProgramOptions()
{
}

 
/*
 *
 * public operators - general
 *
 */
ProgramOptions&
ProgramOptions::operator=(const ProgramOptions &other)
{
	if (this != &other){
		init(other);
	}
	return *this;
}

/*
 *
 * public groups
 *
 */
void
ProgramOptions::set(const OptionGroup& group)
{
		groups[group.getName()] = group;
}

void
ProgramOptions::remove(const String& groupName)
{
	OptionGroupMap::iterator it = groups.find(groupName);
	if (it != groups.end()){
		groups.erase(it);
		return;
	}
	THROW_MSG(CoreText::instance().objectNotFound(groupName));
}

Bool
ProgramOptions::isGroupDefined(const String& groupName) const
{
	OptionGroupMap::const_iterator it = groups.find(groupName);
	return it != groups.end() ? true : false;
}

const OptionGroup&
ProgramOptions::getGroup(const String& groupName) const
{
	OptionGroupMap::const_iterator it = groups.find(groupName);
	if (it != groups.end()){
		return it->second;
	}
	THROW_MSG(CoreText::instance().objectNotFound(groupName));
}

/*
 *
 * public options
 *
 */
void
ProgramOptions::parse(int argc, const char* argv[])
{
	impl->reset();
	for (OptionGroupMap::const_iterator it = groups.begin();
		it != groups.end();
		++it){
			impl->registerGroup(it->second);
	}
	impl->parse(argc, argv);
}


void
ProgramOptions::validate() const
{
	SetString missing;
	 
	for (OptionGroupMap::const_iterator it = groups.begin();
		it != groups.end();
		++it){
			findMissingOptions(it->second, missing);
			 
	}
	Size sz = missing.size();
	if (sz  > 0 )
	{
		String buffer;
		std::stringstream ss(buffer);
		Size index = 0;
		for (SetString::const_iterator it = missing.begin(); it != missing.end(); ++it){
			ss << *it;
			if (index + 1 < sz)
				ss << ",";
			++index;
		}

		THROW_MSG(CoreText::instance().missingOption(ss.str()));
	}

}


Bool
ProgramOptions::isOptionDefined(const String& optionName) const
{

	return impl->isOptionDefined(optionName);
}

String
ProgramOptions::getOptionValue(const String& optionName) const
{
	return impl->getOptionValue(optionName);
}

String
ProgramOptions::getOptionValueOrDefault(const String& optionName, const String& defaultValue) const
{
	String value;
	try {
		value = getOptionValue(optionName);
	}
	catch (BaseException& )
	{
		value = defaultValue;
	}
	return value;
	
}


VectorString
ProgramOptions::positionalArgs() const 
{
	return impl->positionalArgs();
}

String
ProgramOptions::helpMessage() const 
{
	return impl->helpMessage();
}



/*
 *
 * protected constructors 
 */

ProgramOptions::ProgramOptions(ProgramOptionsImpl* impl)
	: impl(impl)
{
}

/*
 *
 * protected accessors
 */
ProgramOptionsImplScopedPtr&
ProgramOptions::getImpl()
{
	return impl;
}


const ProgramOptionsImplScopedPtr&
ProgramOptions::getImpl() const
{
	return impl;
}


/*
 *
 * protected utilities
 */



void
ProgramOptions::findMissingOptions(const OptionGroup& group, SetString& missing) const
{
	 
	for (OptionMap::const_iterator it = group.getOptions().begin(); 
		it != group.getOptions().end();
		++it)
	{
		if (it->second.isMandatory() && !isOptionDefined (it->first)){
			missing.insert(it->second.getName());
		}
	}

	for (OptionGroupMap::const_iterator git = group.getGroups().begin();
		git != group.getGroups().end();
		++git)
	{
		findMissingOptions(git->second, missing);
	}
}

/*
 *
 * private utilities
 *
 */
void
ProgramOptions::init(const ProgramOptions& other )
{
	const ProgramOptionsImpl* otherImpl = other.impl.get();
	impl.reset(
		 OptionsRegistry::instance().getFactory()->createProgramOptionsImpl(*otherImpl)) ;
}


} //namespace options
} //namespace ondalear

