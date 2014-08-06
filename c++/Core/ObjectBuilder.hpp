/**
 * \file ObjectBuilder.hpp
 * \brief Object Builder    header file
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

#ifndef ONDALEAR_CORE_ObjectBuilder_HPP
#define ONDALEAR_CORE_ObjectBuilder_HPP



#include "core/CoreIncludes.hpp"

 

 
namespace ondalear {
namespace core {


class CORE_API ObjectBuilder {
public:
	/** @name public constructors */
	//@{
	virtual ~ObjectBuilder();
	//@}
	
	 

	/** @name public utilities */
	//@{
	virtual void import();
	
	//@}

protected:
	/** @name protected constructors */
	//@{
	ObjectBuilder();
	//@}

	/** @name protected utilities */
	//@{
	virtual void setFields() = 0;
	
	//@}



};

DECLARE_SHARED_POINTER(ObjectBuilder);



} //namespace core
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::core,ObjectBuilder);

#endif //ONDALEAR_CORE_ObjectBuilder_HPP