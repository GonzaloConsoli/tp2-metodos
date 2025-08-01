#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include "pca.h"
#include "eigen.h"

namespace py=pybind11;

PYBIND11_MODULE(metnum, m) {
    py::class_<PCA>(m, "PCA")
        .def(py::init<unsigned int>())
        .def("fit", &PCA::fit)
        .def("transform", &PCA::transform)
        .def("get_transformacion", &PCA::get_transformacion)
        .def("set_transformacion", &PCA::set_transformacion)
        .def("get_explained_variance_ratio", &PCA::get_explained_variance_ratio)
        .def("get_eigen_values", &PCA::get_eigen_values);
    m.def(
        "power_iteration", &power_iteration,
        "Function that calculates eigenvector",
        py::arg("X"),
        py::arg("num_iter")=5000,
        py::arg("epsilon")=1e-16
    );
    m.def(
        "get_first_eigenvalues", &get_first_eigenvalues,
        "Function that calculates first eigenvalues and eigenvectors",
        py::arg("X"),
        py::arg("num"),
        py::arg("num_iter")=5000,
        py::arg("epsilon")=1e-16
    );

}
