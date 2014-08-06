/**
 *
 * \file ObjectRegistry.hpp 
 * \brief Associative map of Managed Objects header file
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


#ifndef ONDALEAR_CORE_ObjectRegistry_HPP
#define ONDALEAR_CORE_ObjectRegistry_HPP



#include <map>

#include "CoreIncludes.hpp"


#include "ManagedObject.hpp"

namespace ondalear {
namespace core {

/**
 * @todo:  ObjectRegistry - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  ObjectRegistry - attributes/methods -  completeness/need/correctness
 * @todo:  ObjectRegistry - unit test completeness/need/correctness
 * @todo:  ObjectRegistry - doc - completeness/correctness
 * @todo:  ObjectRegistry - design/impl - add search capability by query
 */

/**
  * \class ObjectRegistry
  * \brief Simple cache for managed objects
  *
  * The key is UUID based; lookup methods based on instance name and version 
  * as well as UUID are supported.
  */
	
class CORE_API ObjectRegistry : public ManagedObject{
public:
	/** @name public constructors */
	//@{
	ObjectRegistry();
	ObjectRegistry(const String& registryName, const String& registryVersion);
	ObjectRegistry(const ObjectRegistry& other);

	virtual ~ObjectRegistry();

	//@}

	/** @name operators - general */
	//@{
	ObjectRegistry& operator=(const ObjectRegistry& other);
	//@}

	
	//@{
	/** @name registry manipulation */
	virtual void add(const ManagedObjectSharedPtr& instance);
	virtual void remove(const ManagedObjectSharedPtr& instance);
	//@}

	//@{
	/** @name object search  */
	virtual ManagedObjectSharedPtr findByUid(const UniversalId& uid) const;
	virtual ManagedObjectSharedPtr findByName(const String& instanceName) const;
	virtual ManagedObjectSharedPtr findByNameAndVersion(const String& instanceName,
		const String& instanceVersion) const;
	//@}

	//@{
	/** @name object search - lookup exception  */
	virtual ManagedObjectSharedPtr getByUid(const UniversalId& uid) const;
	//@}

protected:
	//@{
	/** @name object search utilities  */
	ManagedObjectSharedPtr getByUidWithException(const UniversalId& uid, 
									  bool raiseException) const;
	//@}

private:
	
	//@{
	/** @name utilities  */
	void init (const ObjectRegistry& other);
	//@}
	 
	
	typedef std::map< UniversalId, ManagedObjectSharedPtr > ObjectMap;

	ObjectMap registry;

	
	
};

DECLARE_SHARED_POINTER(ObjectRegistry);

} //namespace core
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::core,ObjectRegistry);

#endif //ONDALEAR_CORE_ObjectRegistry_HPP
