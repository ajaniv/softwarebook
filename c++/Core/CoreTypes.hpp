/**
 * \file CoreTypes.hpp
 * \brief Core component types header file
 *
 * Defined to facilitate reuse and encapsulate from underlying platform implementation
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
#ifndef ONDALEAR_CORE_CoreTypes_HPP
#define ONDALEAR_CORE_CoreTypes_HPP

#include <iostream>
#include <string>
#include "CoreImplIncludes.hpp"

namespace ondalear{
namespace core{
	
	typedef bool				Bool;
	typedef int					Integer;
	typedef long int			BigInteger;
	typedef float				Real;
	typedef double				BigReal;
	typedef std::string			String;
	typedef size_t				Size;
	typedef ImplUUID			UniversalId;
	typedef std::ostream		OutputStream;
}//core
}//ondalear


//note: not using DECLARE constructs to avoid 'include-deadlock'
using ondalear::core::Bool;
using ondalear::core::Integer;
using ondalear::core::BigInteger;
using ondalear::core::Real;
using ondalear::core::BigReal;
using ondalear::core::String;
using ondalear::core::Size;
using ondalear::core::UniversalId;
using ondalear::core::OutputStream;

#endif  //ONDALEAR_CORE_CoreTypes_HPP
