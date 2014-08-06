/**
 * \file ProgramOptionsSamples.cpp
 * \brief ProgramOptions    samples source file
 *
 *
 * ProgramOptions provides support for storing command line option description as well as parsing 
 * the arguments that are passed to the program at run time.  It supports the grouping of options, 
 * nested option groups, and facilitates the uniform handling of command line optins which can be
 * defined by more then one component.
 * The following samples focus on demonstrating key ProgramOptions features including:
 * - Description of options and their grouping into option groups.
 * - Parsing of command line options
 * - Converstion of passed arguments from String into application specific types.
 * - Generation of help message
 * - Processing of positional arguments.
 *
 * Exceptions are raised when:
 * - An option is passed which is not defined/expected
 * - An option is missing the value that needs to be specified
 * - An option is designated as mandatory and is missing
 * - The option value cannot be translated to the required type
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
#include <iostream>
#include "options/ProgramOptions.hpp"
#include "OptionsSamples.hpp"



namespace ondalear {
namespace samples {
namespace options {


//Simulated command line arguments
static const Integer argc = 6;
static const char* argv[] = {
	"Progam Name",
	"--help",			//help
	"-m20",				//maxIter
	"--precision=0.25",	//precistion
	"pos1",				//positional arg 1
	"pos2",				//positional arg 2
	""
};
/**
 * \fn programOptionsSamples
 * \brief Demonstrate ProgramOptions   features
 *
 */
void
programOptionsSamples()
{
	/*
	 * Step 1: Describe the options
	 *          
	 */

	//Create the container
	ProgramOptions pgmOptions;
	
	//Create am option group
	OptionGroup  groupA("groupA");
	
	//Define a  'flag' option (no subsequent value is expected)
	groupA.setOption("help", "Help on application usage", "h");
	pgmOptions.set(groupA);
	
	//create another option group
	OptionGroup groupB("groupB");

	//Define an option that requires a value, and is mandatory
	groupB.setOption("maxIter", "Max iterations" , "m", true, true);
	pgmOptions.set(groupB);

	//Define a few other options in group C
	OptionGroup groupC("groupC");
	//madatory, arg required
	groupC.setOption("precision", "Computation precision" , "p", true, true);
	//not mandatory, arg required
	groupC.setOption("exist", "Exit on error" , "e", false, true);
	pgmOptions.set(groupC);

	//parse the command line options
	pgmOptions.parse(argc, argv);

	//check if an option is defined
	if (pgmOptions.isOptionDefined("help"))
		//dump to std::out the help message
		std::cout << "Help Message: " << pgmOptions.helpMessage() << std::endl;

	//convert command line option to an internal application variable
	Integer maxIter = pgmOptions.get<Integer>("maxIter");
	std::cout << "maxIter (expect 20): " << maxIter << std::endl;
	
	Real precision = pgmOptions.get<Real>("precision");
	std::cout << "precision (expect 0.25): " << precision << std::endl;

	//get an option that was registered but not passed
	Bool exitOnError = pgmOptions.getOrDefault<Bool>("exit", false);
	std::cout << "exit (expect 0): " << exitOnError << std::endl;

	//get positional arguments
	VectorString posArgs = pgmOptions.positionalArgs();
	std::cout << "Positional args (expect arg1,arg2) " << posArgs[0] << "," << posArgs[1] << std::endl;
}

} //namespace options
} //namespace samples
} //namespace ondalear