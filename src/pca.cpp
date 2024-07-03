#include <iostream>
#include "pca.h"
#include "eigen.h"

using namespace std;


PCA::PCA(unsigned int p)
{
  this->p= p;
  this->eigen_values = Vector(p);
}

void PCA::fit(Matrix &X)
{	
	Matrix centered = X.rowwise() - X.colwise().mean();
	Matrix cov = (centered.transpose() * centered) / sqrt(X.rows() - 1);
	tuple<Vector, Matrix, Vector> tupla = get_first_eigenvalues(cov, this->p);
	
	this->Transformacion = (get<1>(tupla)).transpose();
	this->eigen_values = get<0>(tupla);

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

Vector PCA::get_explained_variance_ratio(){
	Vector explained_variance(this->p);
	for (unsigned int i=0; i<this->p;i++){
		explained_variance[i] = this->eigen_values[i] / this->eigen_values.sum();
	}
	return explained_variance;
}

Vector PCA::get_eigen_values(){
	return this->eigen_values;
}