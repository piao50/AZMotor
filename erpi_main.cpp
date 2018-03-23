#include "erpi.h"

using namespace std;

string modbus_motor::hello(string name) {
    return ("Hello " + name + "!");
}

int main(int argc, char* argv[])
{
	printf("hello, gushi\r\n");
	modbus_motor m;
	m.hello("gushi");

	m.open();

	int KHz = 1000;

	m.set_position_info(1, 0, 1, 1000, 8000, 10000*KHz, 1000*KHz);
	m.set_position_info(1, 1, 1, 2000, 1000, 5000*KHz, 1000*KHz);
	m.set_position_info(1, 2, 1, 3000, 1000, 5000*KHz, 1000*KHz);
	m.set_position_info(1, 3, 1, 3000, 1000, 5000*KHz, 1000*KHz);
	m.set_position_info(1, 4, 1, 4000, 1000, 5000*KHz, 1000*KHz);
	m.set_position_info(1, 5, 1, 5000, 1000, 5000*KHz, 1000*KHz);
	m.set_position_info(1, 6, 1, 6000, 1000, 5000*KHz, 1000*KHz);
	m.set_position_info(1, 7, 1, 7000, 1000, 5000*KHz, 1000*KHz);
	m.set_position_info(1, 8, 1, 8000, 1000, 5000*KHz, 1000*KHz);
	m.set_position_info(1, 9, 1, 9000, 1000, 5000*KHz, 1000*KHz);
	m.set_position_info(1, 10, 1, 10000, 1000, 5000*KHz, 1000*KHz);
	m.set_position_info(1, 11, 1, 11000, 1000, 5000*KHz, 1000*KHz);
	m.set_position_info(1, 12, 1, 12000, 1000, 5000*KHz, 1000*KHz);
	m.set_position_info(1, 13, 1, 13000, 1000, 5000*KHz, 1000*KHz);
	m.set_position_info(1, 14, 1, 14000, 1000, 5000*KHz, 1000*KHz);
	m.set_position_info(1, 15, 1, 15000, 1000, 5000*KHz, 1000*KHz);
	m.set_position_info(1, 16, 1, 16000, 1000, 5000*KHz, 1000*KHz);
	m.set_position_info(1, 17, 1, 17000, 1000, 5000*KHz, 1000*KHz);
	m.set_position_info(1, 18, 1, 18000, 1000, 5000*KHz, 1000*KHz);
	m.set_position_info(1, 19, 1, 19000, 1000, 5000*KHz, 1000*KHz);
	m.set_position_info(1, 20, 1, 20000, 1000, 5000*KHz, 1000*KHz);

	m.set_position_info(2, 0, 1, 1000, 8000, 10000*KHz, 1000*KHz);
	m.set_position_info(2, 1, 1, 2000, 1000, 5000*KHz, 1000*KHz);
	m.set_position_info(2, 2, 1, 3000, 1000, 5000*KHz, 1000*KHz);
	m.set_position_info(2, 3, 1, 3000, 1000, 5000*KHz, 1000*KHz);
	m.set_position_info(2, 4, 1, 4000, 1000, 5000*KHz, 1000*KHz);
	m.set_position_info(2, 5, 1, 5000, 1000, 5000*KHz, 1000*KHz);
	m.set_position_info(2, 6, 1, 6000, 1000, 5000*KHz, 1000*KHz);
	m.set_position_info(2, 7, 1, 7000, 1000, 5000*KHz, 1000*KHz);
	m.set_position_info(2, 8, 1, 8000, 1000, 5000*KHz, 1000*KHz);
	m.set_position_info(2, 9, 1, 9000, 1000, 5000*KHz, 1000*KHz);
	m.set_position_info(2, 10, 1, 10000, 1000, 5000*KHz, 1000*KHz);
	m.set_position_info(2, 11, 1, 11000, 1000, 5000*KHz, 1000*KHz);
	m.set_position_info(2, 12, 1, 12000, 1000, 5000*KHz, 1000*KHz);
	m.set_position_info(2, 13, 1, 13000, 1000, 5000*KHz, 1000*KHz);
	m.set_position_info(2, 14, 1, 14000, 1000, 5000*KHz, 1000*KHz);
	m.set_position_info(2, 15, 1, 15000, 1000, 5000*KHz, 1000*KHz);
	m.set_position_info(2, 16, 1, 16000, 1000, 5000*KHz, 1000*KHz);
	m.set_position_info(2, 17, 1, 17000, 1000, 5000*KHz, 1000*KHz);
	m.set_position_info(2, 18, 1, 18000, 1000, 5000*KHz, 1000*KHz);
	m.set_position_info(2, 19, 1, 19000, 1000, 5000*KHz, 1000*KHz);
	m.set_position_info(2, 20, 1, 20000, 1000, 5000*KHz, 1000*KHz);

	while(1)
	{
		for(int i = 0; i <= 20; i++)
		{
			m.goto_position(1, i);
			m.goto_position(2, i);
			if(i == 0) sleep(5);
			else sleep(2);
		}
	}

	m.close();

	printf("bye gushi!\r\n");
	return 0;
}