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

	m.set_position_info(1, 0, 0, 0, 0, 0);
	m.goto_position(2, 2);

	m.close();

	printf("bye gushi!\r\n");
	return 0;
}