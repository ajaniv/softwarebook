/**
 * \file PropertyTreeFileHandler.cpp
 * \brief Property Tree File Handler  source file.
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



#include "PropertyTreeFileHandler.hpp"

#include "ContainerConstants.hpp"
#include "ContainerRegistry.hpp"
#include "PropertyTreeFileHandlerImpl.hpp"

namespace ondalear {
namespace container {

/*
 *
 * public constructors
 *
 */

PropertyTreeFileHandler::PropertyTreeFileHandler()
	:
	impl(ContainerRegistry::instance().getFactory()->createPropertyTreeFileHandlerImpl())
{
}

PropertyTreeFileHandler::PropertyTreeFileHandler (const PropertyTreeFileHandler& other)
{
	init(other);
}




PropertyTreeFileHandler::~PropertyTreeFileHandler()
{
}

 
/*
 *
 * public operators - general
 *
 */
PropertyTreeFileHandler&
PropertyTreeFileHandler::operator=(const PropertyTreeFileHandler &other)
{
	if (this != &other){
		init(other);
	}
	return *this;
}




/*
 *
 * public file access
 *
 */

PropertyTreeSharedPtr
PropertyTreeFileHandler::readFrom(const String& fileName,  FileType::eFileType fileType)
{
	return impl->readFrom(fileName, fileType);
}

PropertyTreeSharedPtr
PropertyTreeFileHandler::readFrom(std::istream& inputStream, FileType::eFileType fileType) 
{
	return impl->readFrom(inputStream, fileType);
}

void 
PropertyTreeFileHandler::writeTo(const String& fileName, FileType::eFileType fileType,
		const PropertyTree& tree) 
{
	impl->writeTo(fileName, fileType, tree);
}

void
PropertyTreeFileHandler::writeTo(std::ostream& outputStream, FileType::eFileType fileType,
		const PropertyTree& tree) 
{
	impl->writeTo(outputStream, fileType, tree);
}



/*
 *
 * private utilities
 *
 */
void
PropertyTreeFileHandler::init(const PropertyTreeFileHandler& other )
{
	const PropertyTreeFileHandlerImpl* otherImpl = other.impl.get();
	impl.reset(
		 ContainerRegistry::instance().getFactory()->createPropertyTreeFileHandlerImpl(*otherImpl)) ;
}


} //namespace snippets
} //namespace ondalear

