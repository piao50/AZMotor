#include "erpi.h"

using namespace std;

modbus_motor::modbus_motor()
{

}

string modbus_motor::hello(string name) {
    return ("Hello " + name + "!");
}

double modbus_motor::integrate(double a, double b, int n){
	double sum = 0, dx = (b-a)/n;
	for(int i = 0; i < n; i++){ sum += sin((a+i)*dx); }
	return sum*dx;
}

extern "C" double modbus_motor::foo(){
	return 2; 
}

extern "C" void modbus_motor::foo1(){
}

double modbus_motor::hello1(){
    foo1();
    return 100 * foo();
}