/**
 * \file OptionGroup.hpp
 * \brief Option  group    header file.
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


#ifndef ONDALEAR_OPTIONS_OptionGroup_HPP
#define ONDALEAR_OPTIONS_OptionGroup_HPP


#include <map>

#include "core/CoreIncludes.hpp"
#include "core/CoreContainerTypes.hpp"

#include "Option.hpp"

namespace ondalear {
namespace options {



	
/**
 * @todo:  OptionGroup - design/imple -  completeness/need/correctness/performance/memory

 * @todo:  OptionGroup - attributes/methods -  completeness/need/correctness
 * @todo:  OptionGroup - unit test completeness/need/correctness
 * @todo:  OptionGroup - doc - completeness/correctness

 */

class OptionGroup;
typedef std::map<String, Option> OptionMap;
typedef std::map<String, OptionGroup> OptionGroupMap;


/**
 * \class OptionGroup
 * \brief Grouping of option descriptions
 *
 */



class CORE_API OptionGroup {

public:

	/** @name public constructors */
	//@{

	OptionGroup();
	OptionGroup(const String& name);
	OptionGroup (const OptionGroup& other);

	virtual ~OptionGroup();

	//@}

	/** @name operators - general */
	//@{

	OptionGroup& operator=(const OptionGroup &other);
	Bool operator==(const OptionGroup &other);

	//@}

	/** @name accessors */
	//@{
	virtual void setName(const String& name);
	virtual const String& getName() const;
	virtual const OptionMap& getOptions() const;
	virtual const OptionGroupMap& getGroups() const;

	virtual const SetString optionNames() const;

	//@}

	/** @name options */
	//@{
	virtual void setOption(const Option& option);
	virtual void setOption(const String& name, const String& description);
	virtual void setOption(const String& name, const String& description, const String& shortName);
	virtual void setOption(const String& name,  const String& description, const String& shortName,
		Bool mandatory, Bool argRequired);
	virtual void removeOption(const String& name);
	virtual Bool isOptionDefined(const String& name) const;

	const Option& getOption(const String& name) const;
	//@}

	/** @name option group */
	//@{
	virtual void setGroup(const OptionGroup& optionGroup);
	virtual void removeGroup(const String& groupName);
	virtual Bool isGroupDefined(const String& groupName) const;
	//@}

	/** @name public utilities */
	//@{
	virtual Size sizeOptions() const;
	virtual Size sizeGroups() const;
	//@}

protected:

	/** @name protected utilities */
	//@{
	virtual void addOptionNames(const OptionGroup& root, SetString& names) const;
	//@}
	
private:

	/** @name private utilities */
	//@{

	void init(const OptionGroup& other);

	//@}

	 
	String name;
	OptionMap options;
	OptionGroupMap groups;
	
};


DECLARE_SHARED_POINTER(OptionGroup);






} //namespace options
} //namespace ondalear



DECLARE_USING_DEFAULT(ondalear::options,OptionGroup);

#endif //ONDALEAR_OPTIONS_OptionGroup_HPP



