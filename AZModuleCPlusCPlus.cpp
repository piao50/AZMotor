#include "AZModuleCPlusCPlus.h"
#include "AZModule.h"

string AZModule::hello(string name){
  return ("Hello " + name + "!");
}

void AZModule::hello1(){
  return ("Hello1");
}

double AZModule::integrate(double a, double b, int n){
  double sum = 0, dx = (b-a)/n;
  for(int i = 0; i < n; i++){ sum += sin((a+i)*dx); }
  return sum*dx;
}
