#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <modbus.h>

enum {
  TCP,
  TCP_PI,
  RTU
};

int main(int argc, char* argv[])
{
  printf("hello gushi!\r\n");


  printf("bye gushi!\r\n");
  return 0;
}
