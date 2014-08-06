/**
 * \file calendar_impl.i
 * \brief Calendar implementation swig python interface file  
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
%module calendar_impl

%include core.i
%include datetime.i
%include calendar.i

 


%inline %{



//Initialization classes

#include "constrained/BoostConstrainingTypeComponentManager.hpp"
#include "datetime/BoostDateTimeComponentManager.hpp"


%}



%init %{

 
   // pCalendarException = PyErr_NewException("_calendar_impl.CalendarException", NULL, NULL);
    //Py_INCREF(pCalendarException);
    //PyModule_AddObject(m, "CalendarException", pCalendarException);
 

	ondalear::logging::log4cppimpl::Log4cppComponentManager::bootstrap();
	ondalear::xml::xercesimpl::XercesComponentManager::bootstrap();
	ondalear::constrained::boostimpl::BoostConstrainingTypeComponentManager::bootstrap();
	ondalear::datetime::boostimpl::BoostDateTimeComponentManager::bootstrap();
	
	LoggingConfig config;
	config.setDefaults();
	LoggingConfigurator& configurator = LoggingConfigurator::instance();
	configurator.initialize();
	configurator.apply(config);
	
	XMLConfigurator::instance().initialize();
%}




%include misc.i
 


