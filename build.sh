#!/usr/bin/env bash

echo 'hello, bash!'

#echo 'build erpi module...'
#g++ -O3 erpi.cpp -shared -I/usr/include/python2.7 -lpython2.7 -lboost_python -o erpi.so

echo 'build AZModule...'
# gcc -O3 AZModule.c -shared -I /usr/local/include/modbus -L /usr/local/lib -lmodbus -o AZModule.so
<<<<<<< HEAD
gcc -O3 AZModule.c -shared -I /usr/local/include/modbus -L /usr/local/lib -lmodbus -o AZModule
# ./AZModule

echo 'build AZModuleCPlusPlus...'
g++ -O3 AZModuleCPlusCPlus.cpp -shared -I /usr/local/include/modbus -lmodbus -I /usr/include/python2.7/ -I. -lpython2.7 -lboost_python -o AZ.so

echo 'running AZController.py'
./AZController.py
=======
gcc -O3 AZModule.c -I /usr/local/include/modbus -L /usr/local/lib -lmodbus -o AZModule
./AZModule

#echo 'build AZModuleCPlusPlus...'
# g++ -O3 AZModuleCPlusCPlus.cpp -shared -I /usr/local/include/modbus -lmodbus -I /usr/include/python2.7/ -I. -lpython2.7 -lboost_python -o AZ.so

#echo 'running AZController.py'
# ./AZController.py

echo 'running test...'
gcc -O3 test.c -I /usr/local/include/modbus -L /usr/local/lib -lmodbus -o test
./test
>>>>>>> 17cfad5c6502e93b6a8a59ff078e1ac82752e0d8
