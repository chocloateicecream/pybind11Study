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

void addmessage()
{
    //test push command on github
}

struct Pet
{
    Pet(const std::string &name):name(name){}
    void setName(const std::string &name_){name=name_;}
    const std::string &getName() const {return name;}

    std::string name;
};
// int main(){}
// PYBIND11_MODULE(example, m)//
// {
//     m.doc()="pybind11 example plugin";// optional module docstring

//     m.def("add",&add, "A function that adds two numbers");

//     m.def("deduct",&deduct,"A function that deduct two numbers");

//     m.def("hello",&hello, "a function that print some message");
// }

PYBIND11_MODULE(example, m)
{
    py::class_<Pet>(m, "Pet")
        .def(py::init<const std::string &>())
        .def("setName",&Pet::setName)
        .def("getName",&Pet::getName);
}