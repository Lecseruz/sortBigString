#include <iostream>
#include <fstream>
#include <queue>
#include <boost/python.hpp>
#include <boost/python/list.hpp>
#include <boost/python/extract.hpp>

class Inp{
public:
    std::ifstream *file;
    char value;
};


bool operator < (const Inp& inp_1, const Inp& inp_2)
{
    return (inp_1.value > inp_2.value);
}


std::string create_string_from_fileschar(int count)
{
    std::priority_queue<Inp> PriQue;
    char value;
    for (size_t i = 0; i < count; ++i)
    {
        std::ifstream* f_ = new std::ifstream(std::to_string(i + 1) + ".txt");
        *f_ >> value;
        Inp inp_{};
        inp_.value = value;
        inp_.file = f_;
        PriQue.push(inp_);
    }

    std::string line;
    while (!PriQue.empty())
    {
        Inp inp_ = PriQue.top();
        PriQue.pop();
        if (inp_.value != 0)
        {
            line += inp_.value;
        }
        if (!(*inp_.file).eof() && (*inp_.file >> inp_.value))
        {
            PriQue.push(inp_);
        }
        else
        {
            (*(inp_.file)).close();
        }
    }
    return line;
}


BOOST_PYTHON_MODULE(hello)
{
    using namespace boost::python;
    def("create_string_from_fileschar", create_string_from_fileschar);
    class_<Inp>("Inp");
}