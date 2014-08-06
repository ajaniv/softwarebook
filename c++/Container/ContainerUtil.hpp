/**
 * \file ContainerUtil.hpp
 * \brief Container util  header file.
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


#ifndef ONDALEAR_CONTAINER_ContainerUtil_HPP
#define ONDALEAR_CONTAINER_ContainerUtil_HPP



#include "core/CoreIncludes.hpp"
#include "core/FileType.hpp"

#include "PropertyTree.hpp"



namespace ondalear {
namespace container {



	
/**
 * @todo:  ContainerUtil - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  ContainerUtil - design/imple -  tight coupling with boost lexical cast
 * @todo:  ContainerUtil - design/imple -  support for find, iteration
 * @todo:  ContainerUtil - attributes/methods -  completeness/need/correctness
 * @todo:  ContainerUtil - unit test completeness/need/correctness
 * @todo:  ContainerUtil - doc - completeness/correctness

 */


/**
 * \class ContainerUtil
 * \brief Container package utilities including file access
 *
 */

class CORE_API ContainerUtil {

public:

	/** @name export/import   */
	//@{

	static PropertyTreeSharedPtr readPropertyTree();
	static PropertyTreeSharedPtr readPropertyTree(const String& fileName);
	static PropertyTreeSharedPtr readPropertyTree(const String& fileName, FileType::eFileType fileType );
	static PropertyTreeSharedPtr readPropertyTree(std::istream& inputStream, FileType::eFileType fileType );
	
	static void  writePropertyTree(const PropertyTree& tree);
	static void  writePropertyTree(const String& fileName, const PropertyTree& tree);
	static void  writePropertyTree(const String& fileName, FileType::eFileType fileType, const PropertyTree& tree);
	static void  writePropertyTree(std::ostream& outputStream, FileType::eFileType fileType, const PropertyTree& tree);

	//@}
	
};






} //namespace container
} //namespace ondalear



DECLARE_USING_TYPE(ondalear::container,ContainerUtil);

#endif //ONDALEAR_CONTAINER_ContainerUtil_HPP



