#pragma once
#include "types.h"

class PCA {
public:
    PCA(unsigned int alfa);

    void fit(Matrix &X);

    Eigen::MatrixXd transform(Matrix &X);

    Eigen::MatrixXd get_transformacion();
    void set_transformacion(Matrix &X);
    Vector get_explained_variance();
    Vector get_eigen_values();
private:

    Vector eigen_values;
    unsigned int alfa;
    Matrix Transformacion;


};
