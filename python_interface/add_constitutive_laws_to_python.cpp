
// System includes
#include <pybind11/pybind11.h>

#include "../StarFEM/Constitutive/mytest.h"

namespace py = pybind11;

namespace Star{

    PYBIND11_MODULE(StarFEM, m){

        //py::class_<StarFEM>(m, "StarFEM")
        //    .def(init<>());
        //    ;
        
        m.doc() = "pybind11 StarFEM plugin";

        py::class_<FirstTest>(m, "FirstTest")
            .def(py::init<>())
            .def("MyName", &FirstTest::MyName)
            ;

    }


}