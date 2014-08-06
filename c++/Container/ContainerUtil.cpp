/**
 * \file ContainerUtil.cpp
 * \brief Container util  source file.
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

#include "ContainerUtil.hpp"
#include "ContainerConstants.hpp"
#include "PropertyTreeFileHandler.hpp"


namespace ondalear {
namespace container {

/*
 *
 * public file access
 *
 */

PropertyTreeSharedPtr
ContainerUtil::readPropertyTree()
{
	return ContainerUtil::readPropertyTree(ContainerConstants::defaultPropertyTreeFileName());
}

PropertyTreeSharedPtr
ContainerUtil::readPropertyTree(const String& fileName)
{
	return ContainerUtil::readPropertyTree(fileName, FileType::Default);
}

PropertyTreeSharedPtr
ContainerUtil::readPropertyTree(const String& fileName, FileType::eFileType fileType)
{

	PropertyTreeFileHandler handler;
	return handler.readFrom(fileName, fileType);
	 
}

PropertyTreeSharedPtr
ContainerUtil::readPropertyTree(std::istream& inputStream, FileType::eFileType fileType)
{

	PropertyTreeFileHandler handler;
	return handler.readFrom(inputStream, fileType);
	 
}

void
ContainerUtil::writePropertyTree(const PropertyTree& tree)
{
	ContainerUtil::writePropertyTree(ContainerConstants::defaultPropertyTreeFileName(), tree);
}

void
ContainerUtil::writePropertyTree(const String& fileName, const PropertyTree& tree)
{
	ContainerUtil::writePropertyTree(fileName, FileType::Default,  tree);
}

void
ContainerUtil::writePropertyTree(const String& fileName, FileType::eFileType fileType, const PropertyTree& tree)
{
	PropertyTreeFileHandler handler;
	handler.writeTo(fileName, fileType, tree);
}

void
ContainerUtil::writePropertyTree(std::ostream& outputStream, FileType::eFileType fileType, const PropertyTree& tree)
{
	PropertyTreeFileHandler handler;
	handler.writeTo(outputStream, fileType, tree);
}

} //namespace snippets
} //namespace ondalear

