#!/usr/bin/env bash

echo 'hello, bash!'

# echo 'build erpi module...'
# g++ -O3 erpi.cpp -shared -I/usr/include/python2.7 -lpython2.7 -lboost_python -I /usr/local/include/modbus -L /usr/local/lib -lmodbus -o erpi.so

echo 'build erpi_main...'
g++ -O3 erpi_main.cpp  -o erpi_main -I/usr/include/python2.7 -lpython2.7 -lboost_python -I /usr/local/include/modbus -L /usr/local/lib -lmodbus
sudo ./erpi_main

# echo 'build AZModule...'
# gcc -O3 AZModule.c -shared -I /usr/local/include/modbus -L /usr/local/lib -lmodbus -o AZModule.so
# gcc -O3 AZModule.c -I /usr/local/include/modbus -L /usr/local/lib -lmodbus -o AZModule
# ./AZModule

#echo 'build AZModuleCPlusPlus...'
#g++ -O3 AZModuleCPlusCPlus.cpp -shared -I /usr/local/include/modbus -lmodbus -I /usr/include/python2.7/ -I. -lpython2.7 -lboost_python -o AZ.so

# echo 'running AZController.py'
# ./AZController.py
