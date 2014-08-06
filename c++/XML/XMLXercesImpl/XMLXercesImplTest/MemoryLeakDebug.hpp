/**
 * \file MemoryDebugging.hpp
 * \brief Memory leak debuging   header file
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

#ifndef ONDALEAR_CORE_MemoryDebugging_HPP
#define ONDALEAR_CORE_MemoryDebugging_HPP




#ifdef _DEBUG
   #define DEBUG_NORMAL_BLOCK   new( _NORMAL_BLOCK, __FILE__, __LINE__)
	#define new DEBUG_NORMAL_BLOCK
#else
   #define DEBUG_NORMAL_BLOCK
#endif // _DEBUG



#endif //ONDALEAR_CORE_MemoryDebugging_HPP