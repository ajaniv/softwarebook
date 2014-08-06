/**
 * \file Class.hpp
 * \brief Sample C++ header file code snippet.
 *
 * It establishes minimal  self-describing C++ header file coding best practices.
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


#ifndef ONDALEAR_SNIPPETS_Class_HPP
#define ONDALEAR_SNIPPETS_Class_HPP


#include "core/CoreIncludes.hpp"

namespace ondalear {
namespace snippets {



	
/**
 * @todo:  Class - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  Class - attributes/methods -  completeness/need/correctness
 * @todo:  Class - unit test completeness/need/correctness
 * @todo:  Class - doc - completeness/correctness
 */


/**
 * \class Class
 * \brief Condensced set of C++  coding best practices
 *
 * This set of  minimal and self describing best practices has been
 * synthesized from other open-source projects.
 */

class CORE_API Class {

public:

	/** @name public constructors */
	//@{

	Class (const Class& other);

	virtual ~Class();

	//@}

	/** @name operators - general */
	//@{

	Class& operator=(const Class &other);

	//@}

protected:

	/** @name protected constructors */
	//@{

	Class();/**< empty constructor*/  
	
	//@}

private:

	/** @name private utilities */
	//@{

	void init(const Class& other);

	//@}
};





} //namespace snippets
} //namespace ondalear


/**
 * Makes Class accessible without ns qualification
 */ 
DECLARE_USING_TYPE(ondalear::snippets,Class);

#endif //ONDALEAR_SNIPPETS_Class_HPP



