#ifdef PYBIND11_BUILD
#include <pybind11/pybind11.h>
#include <pybind11//operators.h>

#include "Util.h"

namespace py = pybind11;
using namespace DcUtil;

void InitUtil_pybind11(py::module& m)
{
    py::class_<Vec2<int>>(m, "IntVec2")
        .def(py::init<>())
        .def(py::init<int, int>())
        .def_readwrite("x", &Vec2<int>::x)
        .def_readwrite("y", &Vec2<int>::y);

    py::class_<Vec2<double>>(m, "FloatVec2")
        .def(py::init<>())
        .def(py::init<double, double>())
        .def_readwrite("x", &Vec2<double>::x)
        .def_readwrite("y", &Vec2<double>::y);

    m.def("wstringToOem", &wstringToOem, "Convert a string of wide characters to an OEM code page.");
    //m.def("randomInt", &randomInt, "Return a random integer in the range min-max (inclusive).");
    m.def("desktopDirectory", &desktopDirectory, "Find the location of the user's desktop directory.");
}

#endif