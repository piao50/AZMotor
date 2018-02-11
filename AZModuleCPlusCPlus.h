#ifndef _AZMODULECPLUSCPLUS_H_
#define _AZMODULECPLUSCPLUS_H_

#include <string>
#include <boost/python.hpp>

using namespace std;

namespace AZModule {
  string hello(string);
  double integrate(double, double, int);

  BOOST_PYTHON_MODULE(AZ){
    using namespace boost::python;
    using namespace AZModule;
    def("hello", hello);
    def("integrate", integrate);
  }
}

#endif
