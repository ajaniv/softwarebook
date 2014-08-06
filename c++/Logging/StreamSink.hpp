/**
 * \file StreamSink.hpp
 * \brief Output Stream Sink header file.
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


#ifndef ONDALEAR_LOGGING_StreamSink_HPP
#define ONDALEAR_LOGGING_StreamSink_HPP



#include "core/CoreIncludes.hpp"

#include "LoggerSink.hpp"

namespace ondalear {
namespace logging {



	
/**
 * @todo:  StreamSink - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  StreamSink - attributes/methods -  completeness/need/correctness
 * @todo:  StreamSink - unit test completeness/need/correctness
 * @todo:  StreamSink - doc - completeness/correctness
 * @todo: StreamSink - design would have liked to have constructor receive OutputStream& as arg
 * 
 */


/**
 * \class StreamSink
 * \brief StreamSink logger output
 *
 */

class CORE_API StreamSink :
	public LoggerSink{

public:

	/** @name public constructors */
	//@{

	StreamSink();
	StreamSink(const String& sinkName, OutputStream* const stream);
	StreamSink (const StreamSink& other);


	//@}

	/** @name operators - general */
	//@{

	StreamSink& operator=(const StreamSink &other);

	//@}

	/** @name accessors  */
	//@{
	virtual void setStream( OutputStream* const stream);
	virtual OutputStream* getStream() const;
	//@}


	 /** @name sink  */
	//@{
	virtual void addTo(LoggingConfiguratorImpl* impl);
	//@}

private:

	/** @name private utilities */
	//@{

	void init(const StreamSink& other);

	//@}

	OutputStream* stream;
};


DECLARE_SHARED_POINTER(StreamSink);


} //namespace logging
} //namespace ondalear



DECLARE_USING_DEFAULT(ondalear::logging,StreamSink);

#endif //ONDALEAR_LOGGING_StreamSink_HPP



