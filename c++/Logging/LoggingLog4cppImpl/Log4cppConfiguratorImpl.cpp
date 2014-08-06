/**
 * \file Log4cppConfiguratorImpl.cpp
 * \brief Log4cpp Configurator Implementation source file
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

#include "Log4cppConfiguratorImpl.hpp"

#include <log4cpp/Category.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/HierarchyMaintainer.hh>

#include "Core/CoreText.hpp"

#include "../LoggingText.hpp"

#include "Log4cppUtil.hpp"

namespace ondalear {
namespace logging {
namespace log4cppimpl {


/*
 *
 * public constructor
 *
 */


Log4cppConfiguratorImpl::Log4cppConfiguratorImpl()
		 
{
}

/*
 *
 * public sink
 *
 */

void
Log4cppConfiguratorImpl::addSink(const LoggerSinkSharedPtr& sinkPtr)
{
	sinkPtr->addTo(this);
}

void
Log4cppConfiguratorImpl::removeSink(const String& sinkName)
{
	using namespace log4cpp;
	try {
		Category& rootCategory = Category::getRoot();
		Appender* appender = rootCategory.getAppender(sinkName);
		if (appender == NULLPTR){
			THROW_MSG(CoreText::instance().objectNotFound(sinkName));
		}
		rootCategory.removeAppender(appender);
	}
	catch (std::exception& ex){
		THROW_MSG(LoggingText::instance().implementationError(ex.what()));
	}
}

void
Log4cppConfiguratorImpl::addFileSink(const FileSink& sink)
{
	using namespace log4cpp;
	try {
		Category& rootCategory = Category::getRoot();
		FileAppender* appender = 
			new FileAppender(sink.getSinkName(),
				sink.getFileName());
		appender->setLayout(createLayout());
		rootCategory.addAppender(appender);
	}
	catch (std::exception& ex){
		THROW_MSG(LoggingText::instance().implementationError(ex.what()));
	}
}


void
Log4cppConfiguratorImpl::addStreamSink(const StreamSink& sink)
{
	using namespace log4cpp;
	try {
		Category& rootCategory = Category::getRoot();
		OstreamAppender* appender = 
			new OstreamAppender(sink.getSinkName(),
				sink.getStream());
		appender->setLayout(createLayout());
		rootCategory.addAppender(appender);
	}
	catch (std::exception& ex){
		THROW_MSG(LoggingText::instance().implementationError(ex.what()));
	}
}

Bool
Log4cppConfiguratorImpl::sinkExists(const String& sinkName) const
{
	using namespace log4cpp;
	try {
		Category& rootCategory = Category::getRoot();
		Appender* appender = rootCategory.getAppender(sinkName);
		return appender != NULLPTR  ? true : false;
	}
	catch (std::exception& ex){
		THROW_MSG(LoggingText::instance().implementationError(ex.what()));
	}
}

Integer
Log4cppConfiguratorImpl::sinkCount() const
{
	using namespace log4cpp;
	try {
		Category& rootCategory = Category::getRoot();
		return rootCategory.getAllAppenders().size();
	}
	catch (std::exception& ex){
		THROW_MSG(LoggingText::instance().implementationError(ex.what()));
	}
}

/*
 *
 * public priority
 *
 */

	 
void 
Log4cppConfiguratorImpl::setPriorityLevel(LoggingPriority::eLoggingPriority priority) 
{
	using namespace log4cpp;
	try {
		Category& rootCategory = Category::getRoot();
		rootCategory.setRootPriority(Log4cppUtil::log4cppPriority(priority));
	}
	catch (std::exception& ex){
		THROW_MSG(LoggingText::instance().implementationError(ex.what()));
	}
}

void
Log4cppConfiguratorImpl::setPriorityLevel(const String& loggerName, LoggingPriority::eLoggingPriority priority)
{
	using namespace log4cpp;
	Category& category  = log4cpp::Category::getInstance(loggerName);
	category.setPriority(Log4cppUtil::log4cppPriority(priority));
}

LoggingPriority::eLoggingPriority
Log4cppConfiguratorImpl::getPriorityLevel() const
{
	using namespace log4cpp;
	try {
		Category& rootCategory = Category::getRoot();
		Priority::Value value = rootCategory.getRootPriority();
		return Log4cppUtil::loggingPriority(value);
	}
	catch (std::exception& ex){
		THROW_MSG(LoggingText::instance().implementationError(ex.what()));
	}
}

Bool
Log4cppConfiguratorImpl::isPriorityEnabled(LoggingPriority::eLoggingPriority priority) const
{
	using namespace log4cpp;
	try {
		Category& rootCategory = Category::getRoot();
		return rootCategory.isPriorityEnabled(Log4cppUtil::log4cppPriority(priority));
	}
	catch (std::exception& ex){
		THROW_MSG(LoggingText::instance().implementationError(ex.what()));
	}
}

/*
 *
 * public utilities
 *
 */
	
void
Log4cppConfiguratorImpl::initialize()
{
	using namespace log4cpp;
	try {
		Category& rootCategory = Category::getRoot();
		rootCategory.setRootPriority(Log4cppUtil::log4cppPriority(LoggingPriority::Default));
	}
	catch (std::exception& ex){
		THROW_MSG(LoggingText::instance().implementationError(ex.what()));
	}
}


void
Log4cppConfiguratorImpl::reset()
{
	
	using namespace log4cpp;
	try {
		Category& rootCategory = Category::getRoot();
		rootCategory.removeAllAppenders();
		rootCategory.setRootPriority(Log4cppUtil::log4cppPriority(LoggingPriority::Debug));

	}
	catch (std::exception& ex){
		THROW_MSG(LoggingText::instance().implementationError(ex.what()));
	}

}

void
Log4cppConfiguratorImpl::shutdown()
{
	using namespace log4cpp;
	try {
		Category::shutdown();
	}
	catch (std::exception& ex){
		THROW_MSG(LoggingText::instance().implementationError(ex.what()));
	}
}


/*
 *
 * protected utilities
 *
 */

static const std::string conversionPattern("|%d|%c|%p|%m|%n");

log4cpp::Layout*
Log4cppConfiguratorImpl::createLayout() const
{
	using namespace log4cpp;
	PatternLayout* layout = new PatternLayout();
	layout->setConversionPattern(conversionPattern);
	return layout;
}



} //namespace log4cppimpl
} //namespace logging
} //namespace ondalear
