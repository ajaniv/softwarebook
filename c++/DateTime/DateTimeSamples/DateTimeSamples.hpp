/**
 * \file DateTimeSamples.hpp
 * \brief Datetime    samples header  file
 *
 *  Datetime provides comprehensive facilities related to date calculaltions.
 *  There are numerous implementations within the open source and proprietary domains.
 *  Application developers have some tough choices to make, resulting often in solutions
 *  that result in conflicting date calculations at the higher end of the application stack.
 *
 *  The objectives of this effort are as follows:
 *  - Provide    simple, complete date functionality
 *  - Leverage the date functionality to build periods, calendars, and other derived constructs 
 *  - Support the above functionality using a common interface on top of multiple implementations (i.e. Boost)
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

#ifndef ONDALEAR_SAMPLES_DateTimeSamples_HPP
#define ONDALEAR_SAMPLES_DateTimeSamples_HPP


/**
 * @namespace ondalear
 * Root name space
 */

/**
 * @namespace ondalear::samples
 * Demonstrate key component features
 */

/**
 * @namespace ondalear::samples::datetime
 * Demonstrate date, date period, relative date specification features
 */

namespace ondalear {
namespace samples {
namespace datetime {


/**
 * \fn basicDateSamples
 * \brief Demonstrate Date related features
 *
 * These include base date creation, iteration,
 * and stream IO
 */
void basicDateSamples();


/**
 * \fn datePeriodSamples
 * \brief Demonstrate DatePeriod related features
 *
 * These include the definition of date ranges and related 
 * operations including assignment, comparision, intersection 
 * containment and more
 */
void datePeriodSamples();


/**
 * \fn dateSpecSamples
 * \brief Demonstrate DateSpec related features
 */
void dateSpecSamples();




} //namespace datetime
} //namespace samples
} //namespace ondalaer


#endif //ONDALEAR_SAMPLES_DateTimeSamples_HPP