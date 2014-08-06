/**
 * \file BoostDateTimeFactory.hpp
 * \brief Abstraction for creation of datetime implementation specific classes source file
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
#include "BoostDateTimeFactory.hpp"

#include "core/CoreConstants.hpp"

#include "../DateTimeConstants.hpp"
#include "../DateTimeText.hpp"

#include "BoostIncludes.hpp"
#include "ImplUtil.hpp"

#include "BoostBootstrapDateUtilImpl.hpp"
#include "BoostDate.hpp"
#include "BoostDateImpl.hpp"

namespace ondalear {
namespace datetime {
namespace boostimpl{
/*
 *
 * public - constructors
 *
 */


BoostDateTimeFactory::BoostDateTimeFactory()
	:
	DateTimeFactory(
		DateTimeConstants::defaultFactoryName(),
		CoreConstants::defaultVersion())
{
}

/*
 *
 * public - instance creation
 *
 */

BootstrapDateUtilImpl* 
BoostDateTimeFactory::createBootstrapDateUtilImpl()
{
	return new BoostBootstrapDateUtilImpl();
	 
}


DateImpl*
BoostDateTimeFactory::createDateImpl()
{
	try {
		using namespace boost::gregorian;
		date dt (boost::gregorian::day_clock::local_day());
		return new BoostDateImpl(dt);
	}
	catch (std::exception& ex){
		 
		THROW_MSG(DateTimeText::instance().dateCreationFailure(ex.what()));
		 
	}
}


DateImpl*
BoostDateTimeFactory::createDateImpl(const DateImpl& other)
{ 

	const BoostDateImpl& boostDateImpl = dynamic_cast< const BoostDateImpl& > (other);
 
	return new BoostDateImpl(boostDateImpl);
}

DateImpl*
BoostDateTimeFactory::createDateImpl(Integer year, Integer month, Integer day)
{
	try {
		using namespace boost::gregorian;
		date dt (year, month, day);
		return new BoostDateImpl(dt);
	}
	catch (std::exception& ex){
		 
		THROW_MSG(DateTimeText::instance().invalidDateArgs(year, month, day, ex.what()));
		 
	}
	
}


DateImpl*
BoostDateTimeFactory::createDateImpl(const String& isoDateStr)
{

	try {
		using namespace boost::gregorian;
		date dt (from_undelimited_string(isoDateStr));
		return new BoostDateImpl(dt);
	}
	catch (std::exception& ex){
		 
		THROW_MSG(DateTimeText::instance().invalidDateString(isoDateStr.c_str(),ex.what()));
		 
	}
}

DateImpl*
BoostDateTimeFactory::createDateImpl(BigInteger ymd)
{
	Integer year = ymd/10000;
	Integer md = ymd - year * 10000;
	Integer month = md/100;
	Integer day = md - month * 100;
	 
	return createDateImpl(year, month, day);
}

Date
BoostDateTimeFactory::createDateFromDelimitedString(const String& delemetedDateStr)  
{
	
	try {
		using namespace boost::gregorian;
		date dt (from_simple_string(delemetedDateStr));

		return BoostDate(new BoostDateImpl(dt));
	}
	catch (std::exception& ex){
		THROW_MSG(DateTimeText::instance().invalidDateString(delemetedDateStr.c_str(),ex.what()));
	}
}

Date
BoostDateTimeFactory::createLocal()
{
	try {
		using namespace boost::gregorian;
		 
		date dt(day_clock::local_day());

		return BoostDate(new BoostDateImpl(dt));
	}
	catch (std::exception& ex){
		THROW_MSG(DateTimeText::instance().dateCreationFailure(ex.what()));
	}
}

Date
BoostDateTimeFactory::createUTC()
{
	try {
		using namespace boost::gregorian;
		 
		date dt(day_clock::universal_day());

		return BoostDate(new BoostDateImpl(dt));
	}
	catch (std::exception& ex){
		THROW_MSG(DateTimeText::instance().dateCreationFailure(ex.what()));
	}
}

/*
 *
 * public - conversions
 *
 */

String
BoostDateTimeFactory::toString(const Date& date)   const
{
	using namespace boost::gregorian;

	try {
		BoostDate boostDate (date);
		return to_simple_string(boostDate.dateRep());
	}
	catch (std::exception& ex){
		THROW_MSG(DateTimeText::instance().toStringConversionFailure(
			date.year().getValue(), 
			date.month().getValue(), 
			date.dayOfMonth().getValue(),
			ex.what()));
	}
}

String
BoostDateTimeFactory::toISOString(const Date& date)    const
{
	try {
		using namespace boost::gregorian;

		BoostDate boostDate (date);

		return to_iso_string(boostDate.dateRep());
	}
	catch (std::exception& ex){
		THROW_MSG(DateTimeText::instance().toStringConversionFailure(
			date.year().getValue(), 
			date.month().getValue(), 
			date.dayOfMonth().getValue(),
			ex.what()));
	}
}

String
BoostDateTimeFactory::toDelemetedISOString(const Date& date)  const
{
	try {
		using namespace boost::gregorian;

		const BoostDate& boostDate (date);

		return to_iso_extended_string(boostDate.dateRep());
	}
	catch (std::exception& ex){
		THROW_MSG(DateTimeText::instance().toStringConversionFailure(
			date.year().getValue(), 
			date.month().getValue(), 
			date.dayOfMonth().getValue(),
			ex.what()));
	}
}

} //namespace boostimpl
} //namespace datetime
} //namespace ondalear
