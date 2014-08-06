/**
 * \file ProgramOptionsImpl.hpp
 * \brief Program options abstract  implementation header file.
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


#ifndef ONDALEAR_OPTIONS_ProgramOptionsImpl_HPP
#define ONDALEAR_OPTIONS_ProgramOptionsImpl_HPP


#include "core/CoreIncludes.hpp"
#include "core/CoreContainerTypes.hpp"
#include "OptionGroup.hpp"

namespace ondalear {
namespace options {



	
/**
 * @todo:  ProgramOptionsImpl - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  ProgramOptionsImpl - attributes/methods -  completeness/need/correctness
 * @todo:  ProgramOptionsImpl - unit test completeness/need/correctness
 * @todo:  ProgramOptionsImpl - doc - completeness/correctness
 */


/**
 * \class ProgramOptionsImpl
 * \brief Program options  implementation interface definition
 *
 */

class CORE_API ProgramOptionsImpl {

public:

	/** @name public constructors */
	//@{

	 
	virtual ~ProgramOptionsImpl();

	//@}

	/** @name options */
	//@{
	virtual void reset() = 0;
	virtual void registerGroup(const OptionGroup& group) = 0;
	virtual void parse(int argc, const char* argv[]) = 0;

	virtual Bool isOptionDefined(const String& optionName) const = 0;
	virtual String getOptionValue(const String& optionName) const =  0;

	virtual String helpMessage() const = 0;
	virtual VectorString positionalArgs() const = 0;
	//@}

protected:

	/** @name protected constructors */
	//@{

	ProgramOptionsImpl();/**< empty constructor*/  
	
	//@}

private:

	/** @name private constructors */
	//@{
	ProgramOptionsImpl& operator=(const ProgramOptionsImpl& other);
	ProgramOptionsImpl(const ProgramOptionsImpl& other);
	//@}
  
	 
};



DECLARE_SHARED_POINTER(ProgramOptionsImpl);
DECLARE_SCOPED_POINTER(ProgramOptionsImpl);


} //namespace container
} //namespace ondalear


/**
 * Makes PropertyTreeImpl accessible without ns qualification
 */ 
DECLARE_USING_ALL(ondalear::options,ProgramOptionsImpl);

#endif //ONDALEAR_OPTIONS_ProgramOptionsImpl_HPP



