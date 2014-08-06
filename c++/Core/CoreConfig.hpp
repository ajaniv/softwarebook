/**
 * \file CoreConfig.hpp
 * \brief Core component configuration file.
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

#ifndef ONDALEAR_CORE_CoreConfig_HPP
 
#define ONDALEAR_CORE_CoreConfig_HPP

#undef CORE_API

/** 
 * \def CORE_API
 * \brief Required for cross platform dynamic library support
 *
 * Used to provide transparent cross   platform dynamic libraries implementation support
 * (i.e. Windows dllspec
 */

#ifdef WIN32
	#ifdef BUILD_DLL
		#define CORE_API __declspec(dllexport)
	#else
		#define CORE_API
	#endif
	#if defined (_MSC_VER)
		#pragma warning(disable:4251)
	#endif
#else
	#define CORE_API
#endif


 
#endif  //ONDALEAR_CORE_CoreConfig_HPP