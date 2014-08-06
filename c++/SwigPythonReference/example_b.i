/* File : example.i */
%module example
%include "std_vector.i"
%{
#include <vector>
#include "example.h"
%}

/* Let's just grab the original header file here */
%include "example.h"

namespace std {
   
   %template(DoubleVector) vector<double>;
}
