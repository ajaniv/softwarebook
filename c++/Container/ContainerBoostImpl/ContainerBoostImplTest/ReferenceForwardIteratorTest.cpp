/**
 * \file ReferenceForwardIteratorTest.hpp
 * \brief Sample forward iterator test header file
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
#include "ReferenceForwardIteratorTest.hpp"



namespace ondalear {
namespace test {
namespace container {
namespace boostimpl {




//public member functions
ReferenceForwardIteratorTest::ReferenceForwardIteratorTest()
{

}

void 
ReferenceForwardIteratorTest::test_features()
{
	FixedArray<double> point3d(3);
    point3d[0] = 2.3;
    point3d[1] = 3.2;
    point3d[2] = 4.2;

    for(FixedArray<double>::iterator i = point3d.begin(); i != point3d.end(); i++)
    {
        std::cout << *i << " ";
    }

    std::cout << std::endl;

    std::vector<double> vec;
    std::copy(point3d.begin(), point3d.end(), std::back_inserter(vec));

    for(std::vector<double>::iterator i = vec.begin(); i != vec.end(); i++)
    {
        std::cout << *i << " ";
    }

    std::cout << std::endl;
}


} //namespace boostimpl
} //namespace container
} //namespace test
} //namespace ondalear

