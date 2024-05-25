#include "eigen.h"

#include <gtest/gtest.h>

using namespace Eigen;

class EigenTest : public ::testing::Test {
};

TEST_F(EigenTest, Handles2x2Matrix) {
    Matrix2d A;
    A << 4, 1,
         2, 3;
    auto result = power_iteration(A, 1000, 1e-9);
    ASSERT_NEAR(result.first, 5, 1e-9);
    ASSERT_TRUE(result.second.isApprox((Vector2d() << 1, 1).finished().normalized(), 1e-9));
}

TEST_F(EigenTest, Handles3x3Matrix) {
    Matrix3d A;
    A << 7, 2 ,3,
         0 ,2, 0,
        -6 ,-2 ,-2;
    auto result = power_iteration(A, 10000, 1e-9);
    ASSERT_NEAR(result.first, 4, 1e-4);
    Vector3d expected = (Vector3d() << -1, 0, 1).finished();
    Vector3d expected_normalized = expected.normalized();
    Vector3d result_normalized = result.second.normalized();
    for (int i = 0; i < 3; ++i) {
        ASSERT_TRUE(isMultiple(expected_normalized, result_normalized));
    }
}

TEST_F(EigenTest, HandlesGetFirstEigenvaluesWithHouseholder) {
    MatrixXd D = MatrixXd::Zero(5, 5);
    D.diagonal() << 5.0, 4.0, 3.0, 2.0, 1.0;
    VectorXd v = VectorXd::Ones(5);
    v = v / v.norm();
    MatrixXd B = MatrixXd::Identity(5, 5) - 2 * (v * v.transpose());
    MatrixXd M = B.transpose() * D * B;

    auto result = get_first_eigenvalues(M, 5, 1000, 1e-9);
    VectorXd expected_eigenvalues(5);
    expected_eigenvalues << 5.0, 4.0, 3.0, 2.0, 1.0;
    for (int i = 0; i < 5; ++i) {
        ASSERT_NEAR(result.first[i], expected_eigenvalues[i], 1e-4);
    }
    for (int i = 0; i < 5; ++i) {
        VectorXd expected_eigenvector = B.col(i);
        VectorXd result_eigenvector = result.second.row(i);
        ASSERT_TRUE(isMultiple(expected_eigenvector, result_eigenvector));
    }
}

TEST_F(EigenTest, HandlesGetFirstEigenvalues10x10WithHouseholder) {
    
    int N = 10;
    MatrixXd D = MatrixXd::Zero(N, N);
    for (int i = 0; i < N; ++i) {
        D(i, i) = N - i;
    }
    VectorXd v = VectorXd::Ones(N);
    v = v / v.norm();
    MatrixXd B = MatrixXd::Identity(N, N) - 2 * (v * v.transpose());
    MatrixXd M = B.transpose() * D * B;

    auto result = get_first_eigenvalues(M, N, 10000, 1e-9);
    VectorXd expected_eigenvalues(N);
    for (int i = 0; i < N; ++i) {
        expected_eigenvalues[i] = N - i;
    }
    for (int i = 0; i < N; ++i) {
        ASSERT_NEAR(result.first[i], expected_eigenvalues[i], 1e-4);
    }

    for (int i = 0; i < N; ++i) {
        VectorXd expected_eigenvector = B.col(i);
        VectorXd result_eigenvector = result.second.row(i);
        ASSERT_TRUE(isMultiple(expected_eigenvector, result_eigenvector));
    }
}


