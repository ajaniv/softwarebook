/**
 * \file BoostContainerImplIncludes.hpp
 * \brief Boost Container  implementation header file
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


#ifndef ONDALEAR_CONTAINER_BoostContainerImplIncludes_HPP
#define ONDALEAR_CONTAINER_BoostContainerImplIncludes_HPP

#include <boost/lexical_cast.hpp>
#if defined (_MSC_VER)
#pragma warning(disable:4996)
#include <boost/property_tree/ptree.hpp>
#else
#include <boost/property_tree/ptree.hpp>
#endif




namespace ondalear {
namespace container {
namespace boostimpl {

/**
  * @todo:  BoostContainerImplIncludes - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  BoostContainerImplIncludes - attributes/methods -  completeness/need/correctness
  * @todo:  BoostContainerImplIncludes - unit test completeness/need/correctness
  * @todo:  BoostContainerImplIncludes - doc - completeness/correctnesst
  * @todo:  BoostPropertyTreeImpl - asses impact of introducing dependency on boost lexical cast
  */


typedef boost::property_tree::ptree BoostPropertyTreeRep;




} //namespace boostimpl
} //namespace container
} //namespace ondalear


DECLARE_USING_TYPE(ondalear::container::boostimpl,BoostPropertyTreeRep);

#endif //ONDALEAR_CONTAINER_BoostContainerImplIncludes_HPP
