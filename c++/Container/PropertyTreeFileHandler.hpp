/**
 * \file PropertyTreeFileHandler.hpp
 * \brief Property Tree File Handler  header file.
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


#ifndef ONDALEAR_CONTAINER_PropertyTreeFileHandler_HPP
#define ONDALEAR_CONTAINER_PropertyTreeFileHandler_HPP

 

#include "core/CoreIncludes.hpp"

#include "core/FileType.hpp"
#include "PropertyTree.hpp"


namespace ondalear {
namespace container {



	
/**
 * @todo:  PropertyTreeFileHandler - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  PropertyTreeFileHandler - attributes/methods -  completeness/need/correctness
 * @todo:  PropertyTreeFileHandler - unit test completeness/need/correctness
 * @todo:  PropertyTreeFileHandler - doc - completeness/correctness

 */
DECLARE_SCOPED_POINTER(PropertyTreeFileHandlerImpl);

/**
 * \class PropertyTreeFileHandler
 * \brief Manage property tree write/read file access
 *
 */

class CORE_API PropertyTreeFileHandler {

public:

	/** @name public constructors */
	//@{
	PropertyTreeFileHandler();

	PropertyTreeFileHandler (const PropertyTreeFileHandler& other);

	 


	virtual ~PropertyTreeFileHandler();

	//@}

	/** @name operators - general */
	//@{
	PropertyTreeFileHandler& operator=(const PropertyTreeFileHandler &other);
	 
 


	/** @name file access */
	//@{
 
	virtual PropertyTreeSharedPtr readFrom(const String& fileName, 
		FileType::eFileType fileType)  ;
	virtual PropertyTreeSharedPtr readFrom(std::istream& istream, 
		FileType::eFileType fileType)  ;

	virtual void writeTo(const String& fileName, FileType::eFileType fileType,
		const PropertyTree& tree)  ;
	virtual void writeTo(std::ostream& ostream, FileType::eFileType fileType,
		const PropertyTree& tree)  ;
	//@}

private:

	/** @name private utilities */
	//@{

	void init(const PropertyTreeFileHandler& other);

	//@}




	PropertyTreeFileHandlerImplScopedPtr impl;
	
};


DECLARE_SHARED_POINTER(PropertyTreeFileHandler);




} //namespace container
} //namespace ondalear



DECLARE_USING_DEFAULT(ondalear::container,PropertyTreeFileHandler);

#endif //ONDALEAR_CONTAINER_PropertyTreeFileHandler_HPP



