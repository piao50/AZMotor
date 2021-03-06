#include "AZModule.h"

int main(int argc, char *argv[])
{
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
  modbus_set_error_recovery(ctx, MODBUS_ERROR_RECOVERY_LINK | MODBUS_ERROR_RECOVERY_PROTOCOL);

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

  uint16_t tab_reg[512];
  /* Read 5 registers from the address 0 */
  while(1)
    {
      modbus_set_slave(ctx,1);
  modbus_read_registers(ctx, 0x00C6, 0x00DF - 0x00C6 + 1, tab_reg);
  for(int i = 0; i < 16; i++)
    printf("0x%.*X(%d) ", 4, tab_reg[i], tab_reg[i]);
  printf("\r\n");
  modbus_set_slave(ctx,2);
  modbus_read_registers(ctx, 0x00CC, 0x0006, tab_reg);
  for(int i = 0; i < 6; i++)
    printf("0x%.*X(%d) ", 4, tab_reg[i], tab_reg[i]);
  printf("\r\n");
  sleep(1);
    }
  //  modbus_write_registers(ctx, 0x1840, 0x0006, tab_reg);

  printf("bye gushi!\r\n");
  
 //  int delay = 2000;
 //  int loop = 10000;
 //  /* multiply register */
 //  while(loop-- > 0)
 //    {
 //      modbus_set_slave(ctx, loop % 2 == 0 ? 1 : 2);
 //      printf("--------------------\r\n");
 //      //      sleep(5);
 //      //      uint16_t UT_REGISTERS_TAB[] = { 0x0000, 0x0008 };
 //      //      rc = modbus_write_registers(ctx, 0x007c, 0x0002, UT_REGISTERS_TAB);
 //      //      if (rc == -1) {
 //      //	printf("FAIL: write registers, rc=%d.\r\n", rc);
 //      //      }

 //      uint16_t cmd[2];
 //      cmd[0] = 0x0000; cmd[1] = 0x0002;
 //      if(-1 == modbus_write_registers(ctx,0x1800,0x0002,cmd))
 //      {printf("ERR:%d\r\n", errno);}

 //      cmd[0] = 0x0000; cmd[1] = 0x0140;
 //      if(-1 == modbus_write_registers(ctx,0x1802,0x0002,cmd))
 //      {printf("ERR:%d\r\n", errno);}

 //      cmd[0] = 0x0000; cmd[1] = 0x00ff;
 //      if(-1 == modbus_write_registers(ctx,0x1804,0x0002,cmd))
 //      {printf("ERR:%d\r\n",errno);}

 //      cmd[0] = 0x0000; cmd[1] = 0x05dc;
 //      if(-1 == modbus_write_registers(ctx,0x1806,0x0002,cmd))
 //      {printf("ERR:%d\r\n",errno);}

 //      cmd[0] = 0x0000; cmd[1] = 0x05dc;
 //      if(-1 == modbus_write_registers(ctx,0x1808,0x0002,cmd))
 //      {printf("ERR:%d\r\n",errno);}

 //      cmd[0] = 0x0000; cmd[1] = 0x0008;
 //      if(-1 == modbus_write_registers(ctx,0x007c,0x0002,cmd))
 //      {printf("ERR:%d\r\n",errno);}

 //      cmd[0] = 0x0000; cmd[1] = 0x0000;
 //      if(-1 == modbus_write_registers(ctx,0x007c,0x0002,cmd))
 //      {printf("ERR:%d\r\n",errno);}

 //      printf("waiting %d ms.\r\n", delay);
 //      if(loop % 2 == 0) usleep(delay*1000);
 //      if(-1 == modbus_write_register(ctx,0x007d,0x0010))
	// {printf("ERR:%d\r\n",errno);}
 //    }

  /*
  req_length = modbus_send_raw_request(ctx, raw_1, 6 * sizeof(uint8_t));
  modbus_receive_confirmation(ctx, rsp);
  */

  modbus_close(ctx);
  modbus_free(ctx);
  return 0;
}
