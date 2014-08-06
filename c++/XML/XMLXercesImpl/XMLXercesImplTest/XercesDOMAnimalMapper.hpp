/**
 * \file XercesDOMAnimalMapper.hpp
 * \brief Xerces DOM Animal  xml mapper header file
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

#ifndef ONDALEAR_TEST_XercesDOMAnimalMapper_HPP
#define ONDALEAR_TEST_XercesDOMAnimalMapper_HPP

#include "core/CoreIncludes.hpp"

#include <xercesc/dom/DOM.hpp>
#include "Animal.hpp"
 

namespace ondalear {
namespace test {
namespace xml {
namespace xercesimpl {


VectorAnimal  buildTree(xercesc::DOMDocument* object);

} //namespace xercesimpl
} //namespace xml
} //namespace test
} //namespace ondalear



#endif //ONDALEAR_TEST_XercesDOMAnimalMapper_HPP