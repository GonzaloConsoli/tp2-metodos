#pragma once
#include "types.h"
using namespace std;
/*
Calcula el autovalor (y autovector correspondiente) de módulo máximo

Parámetros:
----------

mat: const Matrix& mat
    Matriz sobre la que queremos calcular el autovalor

num_iter: unsigned (=5000 por defecto)
    Cantidad de iteraciones a correr

eps: double
    Tolerancia a residuo (opcional)

Devuelve:
--------

pair<double, Vector> donde el primer valor es el autovalor
y el segundo el autovector asociado
*/
tuple<double, Vector, int> power_iteration(const Matrix& A, unsigned num_iter, double eps);


/*
Calcula

Parámetros:
----------

mat: const Matrix& mat
    Matriz sobre la que queremos calcular el autovalor

num: unsigned (=5000 por defecto)
    Cantidad de autovectores/autovalores a calcular

num_iter: unsigned (=5000 por defecto)
    Cantidad de iteraciones a correr

eps: double
    Tolerancia a residuo (opcional)
Devuelve:
--------

pair<Vector, Matrix> donde:
    - El primero elemento es un vector de los autovalores
    - El segundo elemento es una matriz cuyas columnas son los autovectores
      correspondientes
*/
std::pair<Eigen::VectorXd, Matrix>
    get_first_eigenvalues(const Matrix& mat, unsigned num, unsigned num_iter=5000, double epsilon=1e-16);

double calcularDist(const Vector &v1, const Vector &v2);
bool isMultiple(const Vector &vector1, const Vector &vector2);