#include <Python.h>
#include <math.h>

static PyObject* hello(PyObject*, PyObject*);

int main(int argc, char* argv[])
{
  printf("hello, gushi, from cpp\r\n");

  hello(NULL, NULL);
  
  printf("bye, gushi!\r\n");
  return 0;
}

static PyObject* hello(PyObject* self, PyObject* args){
  Py_RETURN_NONE;
}
