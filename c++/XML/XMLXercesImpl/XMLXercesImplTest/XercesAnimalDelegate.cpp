/**
 * \file XercesAnimalDelegate.cpp
 * \brief Animal   mapping  delegate source file
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
#include "XercesAnimalDelegate.hpp"

#include "XercesDOMAnimalMapper.hpp"

#include "xml/XercesDOMHandlerImpl.hpp"





namespace ondalear {
namespace test {
namespace xml {
namespace xercesimpl {

/*
 * Public constructors
 */
XercesDOMAnimalDelegate::XercesDOMAnimalDelegate()
{
}

/*
 * Public utilities
 */

const ManagedObjectSharedPtr
XercesDOMAnimalDelegate::getObjectTree(XMLHandlerImpl* impl)
{
	XercesDOMHandlerImpl* domImpl = pointer_cast<XercesDOMHandlerImpl*,XMLHandlerImpl*>(impl);
	VectorAnimal animals = buildTree(domImpl->getDocument());
	return ManagedObjectSharedPtr (new AnimalContainer(animals));
}

} //namespace xercesimpl
} //namespace xml
} //namespace test
} //namespace ondalear
