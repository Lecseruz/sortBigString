#include <boost/python.hpp>


char const* bubbleSort(char* line, int size)
    int temp;
    for (int i = 0; i < size - 1; i++) {
       for (int j = 0; j < size - i - 1; j++) {
            if (line[j] > line[j + 1]) {
                temp = line[j];
                line[j] = line[j + 1];
                line[j + 1] = temp;
            }
        }
    }
    return line;
}


BOOST_PYTHON_MODULE(bubbleSort)
{
    using namespace boost::python;
    def("bubbleSort", bubbleSort);
}