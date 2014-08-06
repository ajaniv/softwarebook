/**
 * \file LoggingUtil.hpp
 * \brief Logging util header file.
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


#ifndef ONDALEAR_LOGGING_LoggingUtil_HPP
#define ONDALEAR_LOGGING_LoggingUtil_HPP


#include "core/CoreIncludes.hpp"

 


namespace ondalear {
namespace logging {



	
/**
 * @todo:  LoggingUtil - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  LoggingUtil - attributes/methods -  completeness/need/correctness
 * @todo:  LoggingUtil - unit test completeness/need/correctness
 * @todo:  LoggingUtil - doc - completeness/correctness
 */
 

/**
 * \class LoggingInitializer
 * \brief Logging facilities initialization, shutdown
 *
 */

class CORE_API LoggingInitializer {
public:
	LoggingInitializer();
	virtual ~LoggingInitializer();
private:
    // Prohibit copying and assignment
    LoggingInitializer(const LoggingInitializer&);
    LoggingInitializer& operator=(const LoggingInitializer&);
};


} //namespace logging
} //namespace ondalear



DECLARE_USING_TYPE(ondalear::logging,LoggingInitializer);

#endif //ONDALEAR_LOGGING_LoggingUtil_HPP



