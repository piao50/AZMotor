#include "AZModuleCPlusCplus.h"

string AZModule::hello(string name){
  return ("Hello " + name + "!");
}

double integrate(double a, double b, int n){
  double sum = 0, dx = (b-a)/n;
  for(int i = 0; i < n; i++){ sum += sin((a+i)*dx); }
  return sum*dx;
}
