/**
 * \file  ManagedObject.hpp
 * \brief Base class abstraction header file for objects that participate in key design aspects
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

#ifndef ONDALEAR_CORE_ManagedObject_HPP
#define ONDALEAR_CORE_ManagedObject_HPP





#include "CoreIncludes.hpp"



namespace ondalear {
namespace core {


/**
 * @todo:  ManagedObject - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  ManagedObject - attributes/methods -  completeness/need/correctness
 * @todo:  ManagedObject - unit test completeness/need/correctness
 * @todo:  ManagedObject - doc - completeness/correctness
 */

/**
  * \class ManagedObject
  * \brief Basic object abstraction
  *
  * Classes derived from ManagedObject conform to a set of interfaces
  * including naming, versioning, unique id, and more
  */
class CORE_API ManagedObject {
public:

	/** @name public constructors */
	//@{
	ManagedObject(const ManagedObject& other);
	virtual ~ManagedObject();
	//@}

	 
	
	/** @name accessor - setters */
	//@{
	virtual void  setName(const String& name);
	virtual void  setVersion(const String& version);
	virtual void  setUniversalId(const UniversalId& id);
	//@}

	/** @name accessor - setters */
	//@{
	virtual const String& getVersion() const;
	virtual const String& getName() const;
	virtual const UniversalId& getUniversalId() const;
	//@}

	/** @name operators-general */
	//@{
	ManagedObject& operator=(const ManagedObject& rhs);
	Bool operator==(const ManagedObject& rhs);
	Bool operator!=(const ManagedObject& rhs);
	//@}

	
	/** @name utilities */
	//@{
	virtual String id() const;
	//@}
	
	 
protected:
	/** @name protected constructors */
	//@{
	ManagedObject();
	ManagedObject(const String& objectName, const String& objectVersion);
	//@}

private:
	
	/** @name utilities */
	//@{
	void init (const ManagedObject& other);
	//@}

	UniversalId		universalId;
	String			name;
	String			version;
	
	
};

DECLARE_SHARED_POINTER(ManagedObject);

} //namespace core
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::core,ManagedObject);

#endif //ONDALEAR_CORE_ManagedObject_HPP
