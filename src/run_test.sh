rm -f test
g++ -o test -I ../eigen test.cpp eigen.cpp -lgtest -lgtest_main -pthread
./test