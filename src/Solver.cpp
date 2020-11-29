//
// Created by lisandro on 28/11/20.
//

#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include "CholeskySolver.h"

PYBIND11_MODULE(Solver, m){
    pybind11::class_<CholeskySolver>(m, "Solver")
            .def(pybind11::init<MatrixXd>())
            .def("fit", &CholeskySolver::fit)
            .def("predict", &CholeskySolver::predict)
            .def("getLMatrix", &CholeskySolver::getLMatrix);
}
