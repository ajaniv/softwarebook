/**
 * \file Unittest.hpp
 * \brief base class unit test abstraction header file
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

#ifndef ONDALEAR_TEST_UNITTEST_HPP
#define ONDALEAR_TEST_UNITTEST_HPP

#include <cppunit/extensions/HelperMacros.h>

#include "core/CoreIncludes.hpp"

#define CAUGHT_EXCEPTION(ex,msg) reportException(ex,msg,__FILE__,__LINE__,__FUNCSIG__)

namespace ondalear {
namespace test {

/**
  * \class Unittest
  * \brief Base class unit test abstraction
  *
  * Defined to facilitate common unit test initialization
  * and migration to other unit test pacakges.
  */


#if defined (_MSC_VER)
	#pragma warning(push)
	#pragma warning(disable:4275)

class CORE_API Unittest : public CPPUNIT_NS::TestFixture{

	#pragma warning(pop)
#else

	class CORE_API Unittest : public CPPUNIT_NS::TestFixture{

#endif




protected:
	Unittest();
	virtual void reportException(BaseException& ex, const char* msg, const char* file, int lineNo, const char* funcSig) const;

};

} //namespace test
} //namespace ondalear

using ondalear::test::Unittest;

#endif // ONDALEAR_TEST_UNITTEST_HPP