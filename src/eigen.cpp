#include <algorithm>
#include <chrono>
#include <iostream>
#include "eigen.h"

using namespace std;


tuple<double, Vector, int> power_iteration(const Matrix& A, unsigned num_iter, double eps)
{
    Vector v = Vector::Random(A.cols());
    double a;
    double b=0;
    int i=0;
    for (i=0;i<num_iter;i++){
        v= (A * v) /  (A*v).norm();

        b = ((v.transpose() * A).dot(v)) / (v.dot(v.transpose()) );

        if(abs(b-a)<eps){
            break;
        }
        a=b;
    }
    return make_tuple(a, v, i);
}

pair<Vector, Matrix> get_first_eigenvalues(const Matrix& X, unsigned num, unsigned num_iter, double epsilon)
// Devuelve un par con un vector de los primeros num autovalores y una matriz con los autovectores correspondientes
{
    Matrix A(X);
    Vector eigvalues(num);
    Matrix eigvectors(num, A.cols());
    for (int i=0; i<num;i++){
        tuple<double, Vector, int> tupla_magica = power_iteration(A,num_iter,epsilon);

        eigvalues[i] = get<0>(tupla_magica);
        // NOTA: SE PONEN LOS AUTOVECTORES COMO FILAS
        eigvectors.row(i) = get<1>(tupla_magica);

        A = A - (get<0>(tupla_magica) * get<1>(tupla_magica) * get<1>(tupla_magica).transpose());
    }

    return make_pair(eigvalues, eigvectors);
}

double calcularDist(const Vector &v1, const Vector &v2){
    double dist = (v1 - v2).norm();
    return dist;
}

// Helper para los tests
// https://stackoverflow.com/questions/41251911/check-if-an-array-is-a-multiple-of-another-array
bool isMultiple(const Vector &one, const Vector &two) {
    double abab = one.dot(two) * one.dot(two);
    double aabb = one.dot(one) * two.dot(two);
    return abab > aabb * 0.9999997;
    }
