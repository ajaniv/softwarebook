/**
 * \file Option.hpp
 * \brief Option Descriptor     header file.
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


#ifndef ONDALEAR_OPTIONS_Option_HPP
#define ONDALEAR_OPTIONS_Option_HPP



#include "core/CoreIncludes.hpp"



namespace ondalear {
namespace options {



	
/**
 * @todo:  OptionDescriptor - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  OptionDescriptor - attributes/methods -  completeness/need/correctness
 * @todo:  OptionDescriptor - unit test completeness/need/correctness
 * @todo:  OptionDescriptor - doc - completeness/correctness

 */


/**
 * \class Option
 * \brief Option details 
 *
 */



class CORE_API Option {

public:

	/** @name public constructors */
	//@{

	Option();
	Option (const Option& other);

	virtual ~Option();

	//@}

	/** @name operators - general */
	//@{

	Option& operator=(const Option &other);
	Bool operator==(const Option& other);
	 

	//@}

	/** @name accessors - setters */
	//@{
	virtual void setName(const String& name);
	virtual void setShortName(const String& shortName);
	virtual void setDescription(const String& description);
	virtual void setMandatory(Bool flag);
	virtual void setArgRequired(Bool flag);
	//@}


	/** @name accessors - getters */
	//@{
	virtual const String& getName() const;
	virtual const String& getShortName() const;
	virtual const String& getDescription() const;
	virtual Bool  isMandatory() const;
	virtual Bool  isArgRequired() const;



	
	//@}

private:

	/** @name private utilities */
	//@{

	void init(const Option& other);

	//@}
	String name;
	String shortName;
	String description;
	Bool   mandatoryFlag;
	Bool   argRequiredFlag;
};


DECLARE_SHARED_POINTER(Option);






} //namespace options
} //namespace ondalear



DECLARE_USING_DEFAULT(ondalear::options,Option);

#endif //ONDALEAR_OPTIONS_Option_HPP



