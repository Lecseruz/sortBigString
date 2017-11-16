g++ -std=c++0x -fPIC -shared -Wl,-soname,sort_from_files.so -o sort_from_files.so sort_from_files.cpp -I /usr/include/python2.7 -lboost_python
