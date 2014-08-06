/**
 * \file CoreImplIncludes.hpp
 * \brief Core implementation specific include files
 *
 *  It is designed to encapsulate and limit the exposure to a specific underlying
 *  implementation (i.e. boost shared pointer).
 *  These can be replaced and enhanced with other underlying implementations
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
#ifndef ONDALEAR_CORE_CoreImplIncludes_HPP
#define ONDALEAR_CORE_CoreImplIncludes_HPP

#ifdef CORE_USE_BOOST

#ifdef WIN32


#pragma warning(disable:4275)
#pragma warning(disable:4996)

#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/exception/all.hpp>





typedef boost::uuids::uuid ImplUUID;
typedef boost::exception ImplException;
typedef boost::error_info<struct tag_core_msg,std::string> ImplErrorMessage;

#else 
#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/exception/all.hpp>


typedef boost::uuids::uuid ImplUUID;
typedef boost::exception ImplException;
typedef boost::error_info<struct tag_core_msg,std::string> ImplErrorMessage;


#endif //WIN32



#endif //CORE_USE_BOOST
 
#endif  // ONDALEAR_CORE_CoreImplIncludes_HPP