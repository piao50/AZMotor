#!/usr/bin/env bash

echo 'hello, bash!'

#echo 'build erpi module...'
#g++ -O3 erpi.cpp -shared -I/usr/include/python2.7 -lpython2.7 -lboost_python -o erpi.so

echo 'build AZModule...'
gcc -O3 AZModule.c -shared -I/usr/local/include/modbus -L/usr/local/lib -lmodbus -o AZModule.so

echo 'build AZModuleCPlusPlus...'
#g++ -O3 

echo 'running AZController.py'
./AZController.py
