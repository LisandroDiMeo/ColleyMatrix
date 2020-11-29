//
// Created by lisandro on 27/11/20.
//

#ifndef COLLEYMATRIX_TYPES_H
#define COLLEYMATRIX_TYPES_H

#include <Eigen/Sparse>
#include <Eigen/Dense>
#include <Eigen/Cholesky>

using namespace std;

using Eigen::MatrixXd;
typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> Matrix;
typedef Eigen::SparseMatrix<double> SparseMatrix;

typedef Eigen::VectorXd Vector;

#endif //COLLEYMATRIX_TYPES_H
