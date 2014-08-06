/**
 * \file LoggerSink.hpp
 * \brief LoggerSink header file.
 *
 * Defines logger destination abstraction
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


#ifndef ONDALEAR_LOGGING_LoggerSink_HPP
#define ONDALEAR_LOGGING_LoggerSink_HPP


#include "core/CoreIncludes.hpp"

namespace ondalear {
namespace logging {



	
/**
 * @todo:  LoggerSink - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  LoggerSink - attributes/methods -  completeness/need/correctness
 * @todo:  LoggerSink - unit test completeness/need/correctness
 * @todo:  LoggerSink - doc - completeness/correctness
 */

class LoggingConfiguratorImpl;
/**
 * \class LoggerSink
 * \brief Base abstraction for logger destination
 *
 */

class CORE_API LoggerSink {

public:

	/** @name public constructors */
	//@{

	LoggerSink (const LoggerSink& other);

	virtual ~LoggerSink();

	//@}

	/** @name operators - general */
	//@{

	LoggerSink& operator=(const LoggerSink &other);
	Bool operator==(const LoggerSink& other) const;

	//@}

	/** @name accessors  */
	//@{
	virtual void setSinkName(const String& sinkName);
	virtual const String& getSinkName() const;
	//@}

	/** @name sink  */
	//@{
	virtual void addTo(LoggingConfiguratorImpl* impl) = 0;
	//@}
protected:

	/** @name protected constructors */
	//@{

	LoggerSink();/**< empty constructor*/  
	LoggerSink(const String& sinkName);
	
	//@}

private:

	/** @name private utilities */
	//@{

	void init(const LoggerSink& other);

	//@}

	String sinkName;
};


DECLARE_SHARED_POINTER(LoggerSink);


} //namespace logging
} //namespace ondalear



DECLARE_USING_DEFAULT(ondalear::logging,LoggerSink);

#endif //ONDALEAR_LOGGING_LoggerSink_HPP



