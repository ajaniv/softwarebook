/**
 * \file Component.hpp
 * \brief Abstraction of class, package, module required to support several design
 *  patterns header file
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

#ifndef ONDALEAR_CORE_Component_HPP
#define ONDALEAR_CORE_Component_HPP





#include "CoreIncludes.hpp"

#include "ManagedObject.hpp"

namespace ondalear {
namespace core {

/**
 * @todo:  Component - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  Component - attributes/methods -  completeness/need/correctness
 * @todo:  Component - unit test completeness/need/correctness
 * @todo:  Component - doc - completeness/correctness
 */


/**
  * \class Component
  * \brief Abstract class required for several design patterns, including factory
  *
  */
	
class CORE_API Component 
	: public ManagedObject{
public:
	/** @name public  constructors */
	//@{
	Component(const Component& other);

	virtual ~Component();
	//@}

	/** @name operators - general */
	//@{
	Component& operator=(const Component& rhs);
	//@}
	

	 
	 
protected:
	/** @name protected constructors */
	//@{
	Component();
	Component(const String& componentName, const String& componentVersion);
	//@}

private:
	
	/** @name utilities */
	//@{
	void init (const Component& other);
	//@}

	 
	
};

DECLARE_SHARED_POINTER(Component);

} //namespace core
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::core,Component);

#endif //ONDALEAR_CORE_Componenty_HPP
