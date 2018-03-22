#include "erpi.h"

using namespace std;

string modbus_motor::hello(string name) {
    return ("Hello " + name + "!");
}

double modbus_motor::integrate(double a, double b, int n){
	double sum = 0, dx = (b-a)/n;
	for(int i = 0; i < n; i++){ sum += sin((a+i)*dx); }
	return sum*dx;
}

double modbus_motor::foo(){	
	modbus_t *ctx;
	/* Read 5 holding registers from address 1 */
	uint8_t raw_req[] = { 0xFF, MODBUS_FC_READ_HOLDING_REGISTERS, 0x00, 0x01, 0x0, 0x05};

	uint8_t raw_1[] = { 0x01, 0x06, 0x00, 0x7d, 0x00, 0x10 };

	int req_length;
	uint8_t rsp[MODBUS_TCP_MAX_ADU_LENGTH];

	int rc;
	ctx = modbus_new_rtu("/dev/ttyUSB0", 115200, 'E', 8, 1);
	if (ctx == NULL) {
		fprintf(stderr, "Unable to allocate libmodbus context\n");
		return -1;
	}

	modbus_set_debug(ctx, TRUE);
	// modbus_set_error_recovery(ctx, MODBUS_ERROR_RECOVERY_LINK | MODBUS_ERROR_RECOVERY_PROTOCOL);

	modbus_set_slave(ctx, 2);
	if (modbus_connect(ctx) == -1) {
		fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
		modbus_free(ctx);
		return -1;
	}

	printf("hello, gushi\r\n");

	/* Single register */
	rc = modbus_write_register(ctx, 0x007d, 0x0010);
	printf("1/2 modbeus_write_register: \r\n");
	if (rc == -1) {
		printf("FAIL: rc=%d\r\n", rc);
		printf("errno:%d\r\n", errno);
	}

	sleep(1);

	return 2; 
}

void modbus_motor::foo1(){
}

double modbus_motor::hello1(){
    foo1();
    return 100 * foo();
}

int main(int argc, char* argv[])
{
	printf("hello, gushi\r\n");
	modbus_motor m;
	// m.foo();

	m.set_position();

	printf("bye gushi!\r\n");
	return 0;
}