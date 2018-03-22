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
public:	
	string hello(string name);
	double integrate(double a, double b, int n);
	double foo();
	void foo1();
	double hello1();

	int set_position()
	{
		return set_position(0, 0, 0, 0, 0, 0);
	}

	int set_position(uint16_t slave_id, uint16_t pos_id, uint16_t method, uint16_t position, uint16_t speed, uint16_t current)
	{
		printf("I'm in set_position\r\n");

		modbus_t *ctx;
		/* Read 5 holding registers from address 1 */
		uint8_t raw_req[] = { 0xFF, MODBUS_FC_READ_HOLDING_REGISTERS, 0x00, 0x01, 0x0, 0x05};

		uint8_t raw_1[] = { 0x01, 0x06, 0x00, 0x7d, 0x00, 0x10 };

		int req_length;
		uint8_t rsp[MODBUS_TCP_MAX_ADU_LENGTH];

		printf("xxxfuck 001\r\n");
		int rc;
		ctx = modbus_new_rtu("/dev/ttyUSB0", 115200, 'E', 8, 1);
		if (ctx == NULL) {
			fprintf(stderr, "Unable to allocate libmodbus context\n");
			return -1;
		}
		printf("xxxfuck 001!!\r\n");
		modbus_set_slave(ctx, 2);
		if (modbus_connect(ctx) == -1) {
			fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
			modbus_free(ctx);
			return -1;
		}

		int cnt = 0;
		int loop = 100;
		while(loop-- > 0)
		{
			printf("fuck loop=%d, cnt=%d\r\n", loop, cnt);
			modbus_set_slave(ctx, loop % 2 == 0 ? 1 : 2);
			uint16_t cmd[8];
			int pos = 0;
			uint16_t addr = 0x1800 + pos * 0x40;
			cmd[0] = 0x0000; cmd[1] = 0x0001;
			cmd[2] = 0x0000; cmd[3] = cnt++ * 1000;
			cmd[4] = 0x0000; cmd[5] = 2000;
			cmd[6] = 0x0000; cmd[7] = 500;
			printf("fuck 001\r\n");
			if(-1 == modbus_write_registers(ctx, addr, 0x0008, cmd)){
				printf("ERR:%d\r\n", errno);
			}
			// sleep(5);
			printf("fuck 002\r\n");
			if(-1 == modbus_write_register(ctx, 0x007D, 0x0008)){
				printf("ERR:%d\r\n",errno);
			}
			// sleep(5);
			printf("fuck 003\r\n");
			if(-1 == modbus_write_register(ctx, 0x007D, 0x0000)){
				printf("ERR:%d\r\n",errno);
			}
			// printf("fuck fuck fuck 003\r\n");
			// if(-1 == modbus_write_register(ctx, 0x0072, 0x0000)){
			// 	printf("ERR:%d\r\n",errno);
			// }
			if(loop % 2 == 0)
				sleep(1);
		}


		modbus_close(ctx);
		modbus_free(ctx);

		return 0;
	}

	int set_current_position(uint16_t slave_id, uint16_t pos_id)
	{
		return 0;
	}

	int get_current_position(uint16_t slave_id)
	{
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