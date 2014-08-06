/**
 * \file BoostPropertyTreeFileHandlerImpl.hpp
 * \brief Boost property tree file handler implementation header file
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


#ifndef ONDALEAR_CONTAINER_BoostPropertyTreeFileHandlerImpl_HPP
#define ONDALEAR_CONTAINER_BoostPropertyTreeFileHandlerImpl_HPP


#include "core/CoreIncludes.hpp"

#include "../PropertyTreeFileHandlerImpl.hpp"
#include "BoostPropertyTreeImpl.hpp"

namespace ondalear {
namespace container {
namespace boostimpl {

/**
  * @todo:  BoostPropertyTreeFileHandlerImpl - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  BoostPropertyTreeFileHandlerImpl - attributes/methods -  completeness/need/correctness
  * @todo:  BoostPropertyTreeFileHandlerImpl - unit test completeness/need/correctness
  * @todo:  BoostPropertyTreeFileHandlerImpl - doc - completeness/correctness
  */


/**
  * \class BoostPropertyTreeFileHandlerImpl
  * \brief Boost Property Tree file handler  implementation
  *
  */


class CORE_API BoostPropertyTreeFileHandlerImpl : 
	public PropertyTreeFileHandlerImpl{

public:
	/** @name public constructors */
	//@{

	BoostPropertyTreeFileHandlerImpl();  
	BoostPropertyTreeFileHandlerImpl(const BoostPropertyTreeFileHandlerImpl& other);

	//@}

	 /** @name file access */
	//@{
	


	virtual PropertyTreeSharedPtr readFrom(const String& fileName, FileType::eFileType fileType) ;
	virtual PropertyTreeSharedPtr readFrom(std::istream& istream, FileType::eFileType fileType) ;

	virtual void writeTo(const String& fileName, FileType::eFileType fileType, const PropertyTree& tree);
	virtual void writeTo(std::ostream& ostream, FileType::eFileType fileType, const PropertyTree& tree);


	//@}

protected:

	virtual void doRead(const String& fileName, 
		 FileType::eFileType fileType,
		 BoostPropertyTreeRep& implRep);

	virtual void doRead(std::istream& inputStream, 
		 FileType::eFileType fileType,
		 BoostPropertyTreeRep& implRep);

	virtual void doWrite(const String& fileName, 
		 FileType::eFileType fileType,
		 const BoostPropertyTreeRep& implRep);

	virtual void doWrite(std::ostream& outputStream, 
		 FileType::eFileType fileType,
		 const BoostPropertyTreeRep& implRep);

	
};

DECLARE_SHARED_POINTER(BoostPropertyTreeFileHandlerImpl);
DECLARE_SCOPED_POINTER(BoostPropertyTreeFileHandlerImpl);

} //namespace boostimpl
} //namespace container
} //namespace ondalear


DECLARE_USING_ALL(ondalear::container::boostimpl,BoostPropertyTreeFileHandlerImpl);

#endif  //ONDALEAR_CONTAINER_BoostPropertyTreeFileHandlerImpl_HPP
