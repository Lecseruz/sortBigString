#include <iostream>
#include <fstream>
#include <queue>
#include <boost/python.hpp>
#include <boost/python/list.hpp>
#include <boost/python/extract.hpp>


char const* bubbleSort(char* line, int size){

    int temp; // временная переменная для обмена элементов местами

    for (int i = 0; i < size - 1; i++) {
       for (int j = 0; j < size - i - 1; j++) {
            if (line[j] > line[j + 1]) {
                // меняем элементы местами
                temp = line[j];
                line[j] = line[j + 1];
                line[j + 1] = temp;
            }
        }
    }
    return line;
}


BOOST_PYTHON_MODULE(sort_from_files)
{
    using namespace boost::python;
    def("bubbleSort", bubbleSort);
}