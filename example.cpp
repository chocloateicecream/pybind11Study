#include <pybind11/pybind11.h>
#include <iostream>

namespace py=pybind11;

int add(int i, int j)
{
    return i+j;
}

int deduct(int i, int j)
{
    return i-j;
}

void hello()
{
    std::cout<<"hello, pybind"<<std::endl;
}

PYBIND11_MODULE(example, m)//
{
    m.doc()="pybind11 example plugin";// optional module docstring

    m.def("add",&add, "A function that adds two numbers");

    m.def("deduct",&deduct,"A function that deduct two numbers");

    m.def("hello",&hello, "a functions that print some message");
}