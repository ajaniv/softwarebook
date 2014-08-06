/**
 * \file BoostProgramOptionsImpl.hpp
 * \brief Boost program options implementation header file
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


#ifndef ONDALEAR_OPTIONS_BoostProgramOptionsImpl_HPP
#define ONDALEAR_OPTIONS_BoostProgramOptionsImpl_HPP

 
#include <boost/program_options.hpp>

#include "core/CoreIncludes.hpp"


#include "../ProgramOptionsImpl.hpp"




namespace ondalear {
namespace options {
namespace boostimpl {

/**
  * @todo:  BoostProgramOptionsImpl - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  BoostProgramOptionsImpl - attributes/methods -  completeness/need/correctness
  * @todo:  BoostProgramOptionsImpl - unit test completeness/need/correctness
  * @todo:  BoostProgramOptionsImpl - doc - completeness/correctness
  * @todo:  BoostProgramOptionsImpl - Force an exception to happen, enusre proper recovery
  */

typedef boost::program_options::positional_options_description BoostPositionalOptionDesc;
typedef boost::program_options::options_description BoostOptionDesc;
typedef boost::program_options::variables_map BoostVariableMap;

/**
  * \class BoostPropertyTreeImpl
  * \brief Boost Property Tree  implementation
  *
  */


class CORE_API BoostProgramOptionsImpl : 
	public ProgramOptionsImpl{

public:
	/** @name public constructors */
	//@{

	BoostProgramOptionsImpl();
	BoostProgramOptionsImpl(const BoostProgramOptionsImpl& other);

	~BoostProgramOptionsImpl();
	 
	//@}

 
	/** @name public operators general */
	//@{
	BoostProgramOptionsImpl& operator=(const BoostProgramOptionsImpl& other);

	 
	//@}

	/** @name options */
	//@{
	virtual void reset() ;
	virtual void registerGroup(const OptionGroup& group) ;
	virtual void parse(int argc, const char* argv[]);

	virtual Bool isOptionDefined(const String& optionName) const ;
	virtual String getOptionValue(const String& optionName) const ;

	virtual String helpMessage() const;

	virtual VectorString positionalArgs() const;
	//@}

	/** @name implementation utilities */
	//@{
	virtual Bool isParsed() const;
	virtual void setParsed(Bool flag);
	//@}
protected:
 	/** @protected utilities */
	//@{
	virtual BoostOptionDesc createBoostOptionDesc(const String& groupName,
		const OptionMap& options) const;

	virtual void doRegisterGroup(BoostOptionDesc& root, const OptionGroup& group);

	void doReset();
	BoostPositionalOptionDesc createPositionalArg();
	//@}

private:
	/** @name private constructors */
	//@{

	void init (const BoostProgramOptionsImpl& other);
	//@}



	boost::scoped_ptr<BoostOptionDesc>  sysDescPtr;
	boost::scoped_ptr<BoostOptionDesc>  appDescPtr;
	boost::scoped_ptr<BoostVariableMap> variableMapPtr;
 
	Bool parsed;
	
};

DECLARE_SHARED_POINTER(BoostProgramOptionsImpl);
DECLARE_SCOPED_POINTER(BoostProgramOptionsImpl);





} //namespace boostimpl
} //namespace options
} //namespace ondalear


DECLARE_USING_ALL(ondalear::options::boostimpl,BoostProgramOptionsImpl);

#endif //ONDALEAR_OPTIONS_BoostProgramOptionsImpl_HPP
