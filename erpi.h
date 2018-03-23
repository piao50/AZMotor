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
		if (modbus_connect(ctx) == -1) {
			fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
			modbus_free(ctx);
			return -1;
		}
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

	int alarm_reset(uint16_t slave_id)
	{
		modbus_set_slave(ctx, slave_id);
		if(-1 == modbus_write_register(ctx, 0x007D, 0x0080)){
			printf("ERR:%d\r\n", errno);
		}
		if(-1 == modbus_write_register(ctx, 0x007D, 0x0000)){
			printf("ERR:%d\r\n",errno);
		}
		return 0;
	}

	int set_position_current(uint16_t slave_id, uint32_t pos_id, uint32_t current)
	{
		uint16_t tab_reg[512]; memset(tab_reg, 0, 512);
		uint16_t base_addr = 0x1800;
		uint16_t addr_offset = 0x0040;
		uint16_t current_offset = 0x000A;
		uint16_t addr = base_addr + pos_id * addr_offset + current_offset;
		tab_reg[0] = (current & 0xFFFF0000) >> 16; tab_reg[1] = current & 0x0000FFFF;
		modbus_set_slave(ctx, slave_id);
		if(-1 == modbus_write_registers(ctx, addr, 0x0002, tab_reg)){
			printf("ERR:%d\r\n", errno);
			return -1;
		}
		return 0;
	}

	int set_position_info(uint16_t slave_id, uint32_t pos_id, uint32_t method, uint32_t position, uint32_t speed, uint32_t start_slope, uint32_t stop_slope)
	{
		printf("I'm set_position_info. [%d-(%d)],%d,%d,%d,%d,%d\r\n",
			slave_id,
			pos_id,
			method,
			position,
			speed,
			start_slope,
			stop_slope);
		if (ctx == NULL) {
			fprintf(stderr, "Unable to allocate libmodbus context\n");
			return -1;
		}

		uint16_t tab_reg[512]; memset(tab_reg, 0, 512);
		uint16_t base_addr = 0x1800;
		uint16_t addr_offset = 0x0040;
		uint16_t addr = base_addr + pos_id * addr_offset;

		tab_reg[0] = (method & 0xFFFF0000) >> 16; tab_reg[1] = method & 0x0000FFFF;
		tab_reg[2] = (position & 0xFFFF0000) >> 16; tab_reg[3] = position & 0x0000FFFF;
		tab_reg[4] = (speed & 0xFFFF0000) >> 16; tab_reg[5] = speed & 0x0000FFFF;
		tab_reg[6] = (start_slope & 0xFFFF0000) >> 16; tab_reg[7] = start_slope & 0x0000FFFF;
		tab_reg[8] = (stop_slope & 0xFFFF0000) >> 16; tab_reg[9] = stop_slope & 0x0000FFFF;

		for(int i = 0; i < 10; i++)
		{
			printf("0x%.*X ", 4, tab_reg[i]);
		}

		modbus_set_slave(ctx, slave_id);
		if(-1 == modbus_write_registers(ctx, addr, 0x000A, tab_reg)){
			printf("ERR:%d\r\n", errno);
			return -1;
		}

		return 0;
	}

	int goto_position(uint16_t slave_id, uint16_t pos_id)
	{
		modbus_set_slave(ctx, slave_id);
		printf("I'm goto_position(%d,%d).\r\n", slave_id, pos_id);

		uint16_t start_cmd = 0x0008 + (pos_id << 8);
		// clear alarm reset
		// start_cmd = start_cmd | 0x0080;
		uint16_t reset_cmd = 0x0000;

		printf("start_cmd: 0x%.*X\r\n", 4, start_cmd);
		printf("reset_cmd: 0x%.*X\r\n", 4, reset_cmd);		

		if(-1 == modbus_write_register(ctx, 0x007D, start_cmd)){
			printf("ERR:%d\r\n", errno);
		}
		if(-1 == modbus_write_register(ctx, 0x007D, reset_cmd)){
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