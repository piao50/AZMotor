#ifndef _ERPI_H
#define _ERPI_H

#include <string>
#include <boost/python.hpp>

extern "C" {
#include <stdio.h>
#include <unistd.h>
#include <error.h>
#include <stdlib.h>
#include <modbus.h>
}

using namespace std;

namespace modbus_motor {
public:
	string hello(string name);
	double integrate(double a, double b, int n);
	extern "C" double foo();
	extern "C" void foo1();
	double hello1();

	BOOST_PYTHON_MODULE(erpi){
		using namespace boost::python;
		using namespace exploringrpi;
		def("hello1", hello1);
		def("hello", hello);
		def("integrate", integrate);
	}
}

#endif