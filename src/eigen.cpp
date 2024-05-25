#include <algorithm>
#include <chrono>
#include <iostream>
#include "eigen.h"

using namespace std;


pair<double, Vector> power_iteration(const Matrix& A, unsigned num_iter, double eps)
// Devuelve un par con el autovalor dominante y el autovector correspondiente
{
    Vector v = Vector::Random(A.cols());
    double a;
    double b=0;
    for (int i=0;i<num_iter;i++){
        v= (A * v) /  (A*v).norm();

        b = ((v.transpose() * A).dot(v)) / (v.dot(v.transpose()) );

        if(abs(b-a)<eps){
            break;
        }
        a=b;
    }

    return make_pair(a, v);
}

pair<Vector, Matrix> get_first_eigenvalues(const Matrix& X, unsigned num, unsigned num_iter, double epsilon)
// Devuelve un par con un vector de los primeros num autovalores y una matriz con los autovectores correspondientes
{
    Matrix A(X);
    Vector eigvalues(num);
    Matrix eigvectors(num, A.cols());
    for (int i=0; i<num;i++){
        pair<double,Vector> tupla_magica = power_iteration(A,num_iter,epsilon);

        eigvalues[i] = tupla_magica.first ;
        eigvectors.row(i) = tupla_magica.second ;
        

        A = A-(get<0>(tupla_magica) * get<1>(tupla_magica) * get<1>(tupla_magica).transpose());
    }

    return make_pair(eigvalues, eigvectors);
}

double calcularDist(const Vector &v1, const Vector &v2){
    double dist = (v1 - v2).norm();
    return dist;
}
