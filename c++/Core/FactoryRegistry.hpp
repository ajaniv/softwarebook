/**
 * \file FactoryRegistry.hpp
 * \brief Component factory registry base abstraction header  file
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

#ifndef ONDALEAR_CORE_FactoryRegistry_HPP
#define ONDALEAR_CORE_FactoryRegistry_HPP


#include "CoreIncludes.hpp"
#include "ObjectRegistry.hpp"

namespace ondalear {
namespace core {

/**
 * @todo:  FactoryRegistry - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  FactoryRegistry - attributes/methods -  completeness/need/correctness
 * @todo:  FactoryRegistry - unit test completeness/need/correctness
 * @todo:  FactoryRegistry - doc - completeness/correctness
 */

/**
  * \class FactoryRegistry
  * \brief Base class for supporting instance creation via factory patterns.
  *
  *
  * @see ObjectRegistry
  * @see ComponentFactory
  */

class CORE_API FactoryRegistry  {

public:
	/** @name public constructors */
	//@{
	FactoryRegistry(const FactoryRegistry& other);
	virtual ~FactoryRegistry();
	//@}

	/** @name operators - general */
	//@{
	FactoryRegistry& operator=(const FactoryRegistry& other);
	//@}
	

	/** @name public - accessors - setter */
	//@{
	virtual void setFactoryName(const String& factoryName);
	virtual void setFactoryVersion(const String& version);

	//@}
	

	/** @name public - accessors - getter */
	//@{
	virtual const String& getFactoryName() const;
	virtual const String& getFactoryVersion() const;
	virtual ObjectRegistry& getRegistry() ;

	//@}

protected:
	/** @name protected constructors */
	//@{
	FactoryRegistry();
	FactoryRegistry(const String& factoryName, const String& factoryVersion);
	//@}


private:
	/** @name private  utilities */
	//@{
	void init(const FactoryRegistry& other);
	//@}

private:
	String			factoryName;
	String			factoryVersion;

	ObjectRegistry	registry;
	
};


DECLARE_SHARED_POINTER(FactoryRegistry);

} //namespace core
} //namespace ondalear


DECLARE_USING_DEFAULT(ondalear::core,FactoryRegistry);


#endif //ONDALEAR_CORE_FactoryRegistry_HPP
