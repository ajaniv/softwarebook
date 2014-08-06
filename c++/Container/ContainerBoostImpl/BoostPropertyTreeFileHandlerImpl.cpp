/**
 * \file BoostPropertyTreeFileHandlerImpl.cpp
 * \brief Boost property tree file handler implementation source file
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

#include "BoostPropertyTreeFileHandlerImpl.hpp"

#include <map>

#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/xml_parser.hpp>

#include "core/CoreText.hpp"


#include "BoostPropertyTree.hpp"


namespace ondalear {
namespace container {
namespace boostimpl {



/*
 *
 * public constructors
 *
 */

BoostPropertyTreeFileHandlerImpl::BoostPropertyTreeFileHandlerImpl()
{
}

BoostPropertyTreeFileHandlerImpl::BoostPropertyTreeFileHandlerImpl (const BoostPropertyTreeFileHandlerImpl& other)
	: 
	PropertyTreeFileHandlerImpl(other)
{
	 
}

/*
 * public file access   
 */

PropertyTreeSharedPtr
BoostPropertyTreeFileHandlerImpl::readFrom(const String& fileName, 
		FileType::eFileType fileType)
{

	BoostPropertyTreeRep implRep;
     
    doRead(fileName, fileType, implRep);

	BoostPropertyTreeImpl* impl = new BoostPropertyTreeImpl(implRep);
	return PropertyTreeSharedPtr(new BoostPropertyTree(impl));
}

PropertyTreeSharedPtr
BoostPropertyTreeFileHandlerImpl::readFrom(std::istream& inputStream, 
		FileType::eFileType fileType) 
{
	BoostPropertyTreeRep implRep;
     
    doRead(inputStream, fileType, implRep);

	BoostPropertyTreeImpl* impl = new BoostPropertyTreeImpl(implRep);
	return PropertyTreeSharedPtr(new BoostPropertyTree(impl));
}

void
BoostPropertyTreeFileHandlerImpl::writeTo(const String& fileName, FileType::eFileType fileType,
		const PropertyTree& tree)
{

	BoostPropertyTree boostTree(tree);

	doWrite(fileName, fileType, boostTree.getImplRep());
}

void
BoostPropertyTreeFileHandlerImpl::writeTo(std::ostream& outputStream, FileType::eFileType fileType,
		const PropertyTree& tree)
{
	BoostPropertyTree boostTree(tree);

	doWrite(outputStream, fileType, boostTree.getImplRep());
}






/*
 * protected utilities
 *
 */

void
BoostPropertyTreeFileHandlerImpl::doRead(const String& fileName, 
		 FileType::eFileType fileType,
		 BoostPropertyTreeRep& implRep)
{
	 
	try {
		switch (fileType){
			case FileType::XML:
				read_xml(fileName, implRep, 
					boost::property_tree::xml_parser::no_comments | boost::property_tree::xml_parser::trim_whitespace);
				break;
			case FileType::JSON:
				read_json(fileName, implRep);
				break;
			case FileType::INI:
				read_ini(fileName, implRep);
				break;
			default:
				break;
		}
	}
	catch (std::exception& ex)
	{
		THROW_MSG(CoreText::instance().fileAccessError(fileName, ex.what()));
	}
	 
}

void
BoostPropertyTreeFileHandlerImpl::doRead(std::istream& inputStream, 
		 FileType::eFileType fileType,
		 BoostPropertyTreeRep& implRep)
{
	 
	try {
		switch (fileType){
			case FileType::XML:
				read_xml(inputStream, implRep, 
					boost::property_tree::xml_parser::no_comments | boost::property_tree::xml_parser::trim_whitespace);
				break;
			case FileType::JSON:
				read_json(inputStream, implRep);
				break;
			case FileType::INI:
				read_ini(inputStream, implRep);
				break;
			default:
				break;
		}
	}
	catch (std::exception& ex)
	{
		THROW_MSG(CoreText::instance().streamAccessError(ex.what()));
	}
	 
}


void
BoostPropertyTreeFileHandlerImpl::doWrite(const String& fileName, 
		 FileType::eFileType fileType,
		 const BoostPropertyTreeRep& implRep)
{
	try {
		switch (fileType){
			case FileType::XML:
				write_xml(fileName, implRep,
					std::locale(),
					boost::property_tree::xml_parser::xml_writer_make_settings(' ', 8));
				break;
			case FileType::JSON:
				write_json(fileName, implRep);
				break;
			case FileType::INI:
				write_ini(fileName, implRep);
				break;
			default:
				THROW_MSG(CoreText::instance().invalidOption(FileType::instance().toString(fileType)));
				break;
		}
	}
	catch (std::exception& ex)
	{
		 THROW_MSG(CoreText::instance().fileAccessError(fileName, ex.what()));
	}
	 
}

void
BoostPropertyTreeFileHandlerImpl::doWrite(std::ostream& outputStream, 
		 FileType::eFileType fileType,
		 const BoostPropertyTreeRep& implRep)
{
	try {
		switch (fileType){
			case FileType::XML:
				write_xml(outputStream, implRep);
				break;
			case FileType::JSON:
				write_json(outputStream, implRep);
				break;
			case FileType::INI:
				write_ini(outputStream, implRep);
				break;
			default:
				THROW_MSG(CoreText::instance().invalidOption(FileType::instance().toString(fileType)));
				break;
		}
	}
	catch (std::exception& ex)
	{
		 THROW_MSG(CoreText::instance().streamAccessError(ex.what()));
	}
	 
}



} //namespace log4cppimpl
} //namespace logging
} //namespace ondalear