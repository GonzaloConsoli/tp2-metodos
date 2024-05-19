#include <iostream>
#include "pca.h"
#include "eigen.h"

using namespace std;


PCA::PCA(unsigned int alfa)
{
  this->alfa= alfa;
}

void PCA::fit(Matrix &X)
{	
	Matrix centered = X.rowwise() - X.colwise().mean();
	Matrix cov = (centered.transpose() * centered) / sqrt(X.rows() - 1);
	pair<Vector, Matrix> tupla_magica_is_back = get_first_eigenvalues(cov, this->alfa);

	this->Transformacion = (tupla_magica_is_back.second).transpose();

}

MatrixXd PCA::transform(Matrix &X)
{ 	
	return X * this->Transformacion;
}

Eigen::MatrixXd PCA::get_transformacion(){
	return this->Transformacion;
}

void PCA::set_transformacion(Matrix &X){
	this->Transformacion=X;
}