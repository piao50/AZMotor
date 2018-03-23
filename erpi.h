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

class modbus_motor {
protected:
	int a;
	int b;
	int c;	
	modbus_t *ctx = NULL;
public:	
	string hello(string name);

	int open()
	{
		printf("open.\r\n");
		if(ctx == NULL)
			ctx = modbus_new_rtu("/dev/ttyUSB0", 115200, 'E', 8, 1);
		return 0;
	}
	int close()
	{
		printf("close!\r\n");		
		if(ctx != NULL)
		{
			modbus_close(ctx);
			modbus_free(ctx);
			ctx = NULL;
		}
		return 0;
	}

	int set_position_info(uint16_t slave_id, uint16_t pos_id, uint16_t method, uint16_t position, uint16_t speed, uint16_t current)
	{
		printf("I'm set_position_info.\r\n");

		if (ctx == NULL) {
			fprintf(stderr, "Unable to allocate libmodbus context\n");
			return -1;
		}
		modbus_set_slave(ctx, 2);
		if (modbus_connect(ctx) == -1) {
			fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
			modbus_free(ctx);
			return -1;
		}



		return 0;
	}

	int goto_position(uint16_t slave_id, uint16_t pos_id)
	{
		modbus_set_slave(ctx, slave_id);
		printf("I'm goto_position(%d,%d).\r\n", slave_id, pos_id);
		if(-1 == modbus_write_register(ctx, 0x007D, 0x0008 + (pos_id << 8))){
			printf("ERR:%d\r\n", errno);
		}
		if(-1 == modbus_write_register(ctx, 0x007D, 0x0000)){
			printf("ERR:%d\r\n",errno);
		}
		return 0;
	}

	// BOOST_PYTHON_MODULE(modbus_motor){
	// 	using namespace boost::python;
	// 	using namespace modbus_motor;
	// 	def("hello1", hello1);
	// 	def("hello", hello);
	// 	def("integrate", integrate);
	// }
};

#endif