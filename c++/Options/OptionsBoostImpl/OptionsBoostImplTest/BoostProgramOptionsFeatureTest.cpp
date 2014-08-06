/**
 * \file BoostProgramOptionsFeatureTest.hpp
 * \brief Boost program options  feature test header file
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
#include "BoostProgramOptionsFeatureTest.hpp"
#include <iostream>
#include <iterator>
#include <boost/program_options.hpp>

namespace ondalear {
namespace test {
namespace option {
namespace boostimpl {


typedef boost::program_options::options_description Desc;

//public member functions
BoostProgramOptionsFeatureTest::BoostProgramOptionsFeatureTest()
{

}

void 
BoostProgramOptionsFeatureTest::test_features()
{
	 namespace po = boost::program_options;
	 using namespace std;
	 int ac = 2;
	 char* av []  = {
		 "pgmname",
		 "-h",
		 ""
	 };
	 try {
		
		
        po::options_description desc("Allowed options");
		Desc myDesc("Allowed options");
		myDesc.add_options()
			("help,h", "produce help message")
            ("compression", po::value<int>(), "set compression level")
        ;
        desc.add_options()
            ("help,h", "produce help message")
            ("compression", po::value<int>(), "set compression level")
        ;

        po::variables_map vm;        
        po::store(po::parse_command_line(ac, av, desc), vm);
        po::notify(vm);    

        if (vm.count("help")) {
            cout << desc << "\n";
            return ;
        }

        if (vm.count("compression")) {
            cout << "Compression level was set to " 
                 << vm["compression"].as<int>() << ".\n";
        } else {
            cout << "Compression level was not set.\n";
        }
    }
    catch(exception& e) {
        cerr << "error: " << e.what() << "\n";
        return ;
    }
    catch(...) {
        cerr << "Exception of unknown type!\n";
    }
	
}


} //namespace boostimpl
} //namespace container
} //namespace test
} //namespace ondalear

