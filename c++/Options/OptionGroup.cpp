/**
 * \file OptionGroup.cpp
 * \brief Option  group    source file.
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

#include "core/CoreText.hpp"

#include "OptionGroup.hpp"
#include "OptionsConstants.hpp"


namespace ondalear {
namespace options {

/*
 *
 * public constructors
 *
 */

OptionGroup::OptionGroup()
	: 
	name(OptionsConstants::defaultGroupName())

{
}

OptionGroup::OptionGroup(const String& name)
	: 
	name(name)
{
}

OptionGroup::OptionGroup (const OptionGroup& other)
{
	init(other);
}


OptionGroup::~OptionGroup()
{
}

 
/*
 *
 * public operators - general
 *
 */
OptionGroup&
OptionGroup::operator=(const OptionGroup &other)
{
	if (this != &other){
		init(other);
	}
	return *this;
}

Bool
OptionGroup::operator==(const OptionGroup &other)
{
	return this == &other
		? true
		: this->name == other.name;
}
/*
 *
 * public accessors
 *
 */
void
OptionGroup::setName(const String& name)
{
	this->name = name;
}

const String&
OptionGroup::getName() const
{
	return name;
}

const OptionMap& 
OptionGroup::getOptions() const
{
	return options;
}

const OptionGroupMap&
OptionGroup::getGroups() const
{
	return groups;
}

const SetString
OptionGroup::optionNames() const
{
	SetString names;
	addOptionNames(*this, names);
	return names;
}
/*
 *
 * public options
 *
 */

void
OptionGroup::setOption(const Option& option)
{
	options[option.getName()] = option;
}


void
OptionGroup::setOption(const String& optionName, const String& description)
{
	setOption(optionName, description, "", false, false);
}

void
OptionGroup::setOption(const String& optionName, const String& description, const String& shortName)
{
	setOption(optionName, description, shortName, false, false);
}

void
OptionGroup::setOption(const String& optionName, const String& description, const String& shortName, 
				 Bool mandatory, Bool argRequired)
{
	Option option;

	option.setName(optionName);
	option.setShortName(shortName);
	option.setDescription(description);
	option.setMandatory(mandatory);
	option.setArgRequired(argRequired);

	setOption(option);
}

void
OptionGroup::removeOption(const String& optionName)
{
	OptionMap::iterator it = options.find(optionName);
	if (it != options.end()){
		options.erase(it);
		return;
	}
	THROW_MSG(CoreText::instance().objectNotFound(optionName));
}

Bool
OptionGroup::isOptionDefined(const String& optionName) const
{
	OptionMap::const_iterator it = options.find(optionName);
	return it != options.end() ? true : false;
}

const Option&
OptionGroup::getOption(const String& optionName) const
{
	OptionMap::const_iterator it = options.find(optionName);
	if (it != options.end()){
		return it->second;
	}
	THROW_MSG(CoreText::instance().objectNotFound(optionName));
}

/*
 *
 * public group
 *
 */


void
OptionGroup::setGroup(const OptionGroup& optionGroup)
{
	groups[optionGroup.getName()]  = optionGroup;
}

void
OptionGroup::removeGroup(const String& groupName)
{
	OptionGroupMap::iterator it = groups.find(groupName);
	if (it != groups.end()){
		groups.erase(it);
		return;
	}
	THROW_MSG(CoreText::instance().objectNotFound(groupName));

}

Bool
OptionGroup::isGroupDefined(const String& groupName) const
{
	OptionGroupMap::const_iterator it = groups.find(groupName);
	return it != groups.end() ? true : false;
}


/*
 *
 * public utilities
 *
 */
 
Size
OptionGroup::sizeOptions() const
{
	return options.size();
}

Size
OptionGroup::sizeGroups() const
{
	return groups.size();
}


/*
 *
 * protected utilities
 *
 */

void
OptionGroup::addOptionNames(const OptionGroup& root, SetString& names) const
{
	for (OptionMap::const_iterator oit = root.options.begin(); 
		oit != root.options.end(); 
		++oit)
		names.insert(oit->first);

	for (OptionGroupMap::const_iterator git = root.groups.begin(); 
		git != root.groups.end(); 
		++git)
		addOptionNames(git->second, names);
	
}



/*
 *
 * private utilities
 *
 */
void
OptionGroup::init(const OptionGroup& other )
{
	this->name = other.name;
	this->options = other.options;
	this->groups = other.groups;
}


} //namespace options
} //namespace ondalear

