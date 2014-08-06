/**
 * \file FileSink.hpp
 * \brief FileSink header file.
 *
 * Defines logger file  sink
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


#ifndef ONDALEAR_LOGGING_FileSink_HPP
#define ONDALEAR_LOGGING_FileSink_HPP


#include "core/CoreIncludes.hpp"

#include "LoggerSink.hpp"

namespace ondalear {
namespace logging {



	
/**
 * @todo:  FileSink - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  FileSink - attributes/methods -  completeness/need/correctness
 * @todo:  FileSink - unit test completeness/need/correctness
 * @todo:  FileSink - doc - completeness/correctness
 */


/**
 * \class FileSink
 * \brief File logger output
 *
 */

class CORE_API FileSink :
	public LoggerSink{

public:

	/** @name public constructors */
	//@{

	FileSink();
	FileSink(const String& fileName);
	FileSink(const String& sinkName, const String& fileName);
	FileSink (const FileSink& other);


	//@}

	/** @name operators - general */
	//@{

	FileSink& operator=(const FileSink &other);

	//@}

	/** @name accessors  */
	//@{
	virtual void setFileName(const String& fileName);
	virtual const String& getFileName() const;
	//@}


	 /** @name sink  */
	//@{
	virtual void addTo(LoggingConfiguratorImpl* impl);
	//@}

private:

	/** @name private utilities */
	//@{

	void init(const FileSink& other);

	//@}

	String fileName;
};


DECLARE_SHARED_POINTER(FileSink);


} //namespace logging
} //namespace ondalear



DECLARE_USING_DEFAULT(ondalear::logging,FileSink);

#endif //ONDALEAR_LOGGING_FileSink_HPP



