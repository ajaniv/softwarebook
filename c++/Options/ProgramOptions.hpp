/**
 * \file ProgramOptions.hpp
 * \brief Program options     header file.
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


#ifndef ONDALEAR_OPTIONS_ProgramOptions_HPP
#define ONDALEAR_OPTIONS_ProgramOptions_HPP


#include <map>
#include <boost/lexical_cast.hpp>

#include "core/CoreIncludes.hpp"
#include "core/CoreContainerTypes.hpp"

#include "OptionsConstants.hpp"
#include "OptionGroup.hpp"


namespace ondalear {
namespace options {


typedef std::map<String, OptionGroup> OptionGroupMap;
	
/**
 * @todo:  ProgramOptions - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  ProgramOptions - attributes/methods -  completeness/need/correctness
 * @todo:  ProgramOptions - unit test completeness/need/correctness
 * @todo:  ProgramOptions - doc - completeness/correctness

 */
DECLARE_SCOPED_POINTER(ProgramOptionsImpl);

/**
 * \class ProgramOptions
 * \brief Manage option defition and retrieval
 *
 */



class CORE_API ProgramOptions {

public:

	/** @name public constructors */
	//@{

	ProgramOptions();
	ProgramOptions (const ProgramOptions& other);

	virtual ~ProgramOptions();

	//@}

	/** @name operators - general */
	//@{

	ProgramOptions& operator=(const ProgramOptions &other);
	 

	//@}

	/** @name groups */
	//@{
	virtual void set(const OptionGroup& group);
	virtual void remove(const String& groupName);
	virtual Bool isGroupDefined(const String& groupName) const;
	const OptionGroup& getGroup(const String& groupName) const;
	//@}

	/** @name options */
	//@{
	virtual void parse(int argc, const char* argv[]);
	virtual void validate() const;
	virtual Bool isOptionDefined(const String& optionName) const;
	virtual String getOptionValue(const String& optionName) const;
	virtual String getOptionValueOrDefault(const String& optionName, const String& defaultValue) const;
	virtual String helpMessage() const ;
	virtual VectorString positionalArgs() const ;

	template <typename T>  T get(const String& key) const;
	template <typename T>  T getOrDefault(const String& key, const T& defaultValue) const;

	//@}

protected:

	/** @name protected constructors */
	//@{

	ProgramOptions(ProgramOptionsImpl* impl); 
	
	//@}
	 

	/** @name protected utilities */
	//@{

	virtual void findMissingOptions(const OptionGroup& group, SetString& missing) const;
	//@}

	/** @name protected accessors */
	//@{
	ProgramOptionsImplScopedPtr& getImpl();
	const ProgramOptionsImplScopedPtr& getImpl() const;
	//@}

	
private:

	/** @name private utilities */
	//@{

	void init(const ProgramOptions& other);

	//@}

	ProgramOptionsImplScopedPtr impl;
	
	OptionGroupMap groups;
};


DECLARE_SHARED_POINTER(ProgramOptions);



template <typename T>  
inline T 
ProgramOptions::get(const String& optionName) const
{
	String strValue = getOptionValue(optionName);
	try {
		T valueType = boost::lexical_cast<T>(strValue);
		return valueType;
	}
	catch (std::exception& ex) {
		THROW_MSG(CoreText::instance().conversionFailure(ex.what()));
	}
}


template <typename T>  
inline T 
ProgramOptions::getOrDefault(const String& optionName, const T& defaultValue) const
{
	String dummyDefault = OptionsConstants::dummyDefaultValue();
	String strValue = getOptionValueOrDefault(optionName, dummyDefault);
	try {
		T valueType = strValue  != dummyDefault ? boost::lexical_cast<T>(strValue) : defaultValue;
		return valueType ;
	}
	catch(std::exception& ex) {
		THROW_MSG(CoreText::instance().conversionFailure(ex.what()));
	}
}


} //namespace options
} //namespace ondalear



DECLARE_USING_DEFAULT(ondalear::options,ProgramOptions);

#endif //ONDALEAR_OPTIONS_ProgramOptions_HPP



