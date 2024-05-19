#pragma once
#include "types.h"

class PCA {
public:
    PCA(unsigned int alfa);

    void fit(Matrix &X);

    Eigen::MatrixXd transform(Matrix &X);

    Eigen::MatrixXd get_transformacion();
    void set_transformacion(Matrix &X);
private:

    unsigned int alfa;
    Matrix Transformacion;


};
