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

namespace exploringrpi {
  string hello(string name) {
    return ("Hello " + name + "!");
  }

  double integrate(double a, double b, int n){
    double sum = 0, dx = (b-a)/n;
    for(int i = 0; i < n; i++){ sum += sin((a+i)*dx); }
    return sum*dx;
  }
  
  extern "C" double foo(){ return 2; }

  extern "C" void foo1(){
modbus_t *ctx;
ctx = modbus_new_rtu("/dev/ttyUSB0", 115200, 'E', 8, 1);
if(ctx == NULL){
fprintf(stderr, "Unable to allocate libmodbus context\n");
return;
}

modbus_set_debug(ctx, TRUE);

modbus_set_slave(ctx, 1);
if(modbus_connect(ctx) == -1){
fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
modbus_free(ctx);
return;
}

int rc = modbus_write_register(ctx, 0x007d, 0x0010);
if(rc == -1){
printf("FAIL: rc=%d\r\n", rc);
printf("errno:%d\r\n", errno);
}
uint16_t cmd[2]; cmd[0] = 0x0000; cmd[1] = 0x0002;
if(-1 == modbus_write_registers(ctx, 0x1800, 0x0002, cmd))
  printf("ERR:%d\r\n", errno);

modbus_close(ctx);
modbus_free(ctx);
  }

  double hello1(){
    foo1();
    return 100 * foo();
  }

  BOOST_PYTHON_MODULE(erpi){
    using namespace boost::python;
    using namespace exploringrpi;
    def("hello1", hello1);
    def("hello", hello);
    def("integrate", integrate);
  }
}
