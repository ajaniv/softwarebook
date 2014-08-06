/**
 * \file CustomApplicaiton.hpp
 * \brief Custome Application      header file
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
#ifndef ONDALEAR_TEST_CustomApplication_HPP
#define ONDALEAR_TEST_CustomApplication_HPP

#include "core/CoreIncludes.hpp"

#include "logging/Logger.hpp"

#include "application/Application.hpp"


namespace ondalear {
namespace test {
namespace application {


/**
  * \class CustomApplication
  * \brief Custom application
  *
  */
	
class CORE_API CustomApplication
	: public Application {

public:
	static CustomApplication& instance();

	void exit(int resultCode);

protected:
	CustomApplication();

	/** @name protected processing */
	//@{
	virtual void doSetup() ;
	virtual void prepareForWork() ;
	virtual void doWork() ;
	//@}

private:
	String modelName;
	String modelVersion;
	Integer maxIter;
	Logger logger;
};


} //namespace application
} //namespace test
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::test::application,CustomApplication);

#endif //ONDALEAR_TEST_CustomApplication_HPP

