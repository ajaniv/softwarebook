/**
 * \file PropertyTreeFileHandlerImpl.hpp
 * \brief Property Tree File Handler Implementation header file.
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


#ifndef ONDALEAR_CONTAINER_PropertyTreeFileHandlerImpl_HPP
#define ONDALEAR_CONTAINER_PropertyTreeFileHandlerImpll_HPP


#include "core/CoreIncludes.hpp"

#include "core/FileType.hpp"
#include "PropertyTree.hpp"

namespace ondalear {
namespace container {



	
/**
 * @todo:  PropertyTreeFileHandlerImpl - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  PropertyTreeFileHandlerImpl - attributes/methods -  completeness/need/correctness
 * @todo:  PropertyTreeFileHandlerImpl - unit test completeness/need/correctness
 * @todo:  PropertyTreeFileHandlerImpl - doc - completeness/correctness
 */


/**
 * \class PropertyTreeFileHandlerImpl
 * \brief Property Tree file handler  implementation interface definition
 *
 */

class CORE_API PropertyTreeFileHandlerImpl {

public:

	/** @name public constructors */
	//@{

	PropertyTreeFileHandlerImpl(const PropertyTreeFileHandlerImpl& other);
	virtual ~PropertyTreeFileHandlerImpl();

	//@}

	/** @name operators - general */
	//@{
	PropertyTreeFileHandlerImpl& operator=(const PropertyTreeFileHandlerImpl& other);
	 
	//@}

	 


 	 /** @name file access */
	//@{
	

	virtual PropertyTreeSharedPtr readFrom(const String& fileName, FileType::eFileType fileType) = 0;
	virtual PropertyTreeSharedPtr readFrom(std::istream& istream, FileType::eFileType fileType) = 0;

	virtual void writeTo(const String& fileName, FileType::eFileType fileType, const PropertyTree& tree) = 0;
	virtual void writeTo(std::ostream& ostream, FileType::eFileType fileType, const PropertyTree& tree) = 0;

	//@}
protected:

	/** @name protected constructors */
	//@{

	PropertyTreeFileHandlerImpl();  
	
	//@}

private:

	/** @name private  utilities */
	//@{

	void init(const PropertyTreeFileHandlerImpl& other);
	//@}


	 
};



DECLARE_SHARED_POINTER(PropertyTreeFileHandlerImpl);
DECLARE_SCOPED_POINTER(PropertyTreeFileHandlerImpl);


} //namespace container
} //namespace ondalear


/**
 * Makes PropertyTreeFileHandlerImpl accessible without ns qualification
 */ 
DECLARE_USING_ALL(ondalear::container,PropertyTreeFileHandlerImpl);

#endif //ONDALEAR_CONTAINER_PropertyTreeFileHandlerImpl_HPP



