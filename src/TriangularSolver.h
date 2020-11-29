//
// Created by lisandrodimeo on 27/11/20.
//

#ifndef COLLEYMATRIX_TRIANGULARSOLVER_H
#define COLLEYMATRIX_TRIANGULARSOLVER_H

#include "types.h"

Vector backwardSubstitution(MatrixXd &A, Vector &b){
    Vector result(b.size());

    auto currentRowIndex = A.rows() - 1;
    for(; currentRowIndex >= 0; currentRowIndex--){
        // In the first iteration, because it's no necessary to sum over the row, just xn = bn / a_nn
        // TODO: Check alternatives to avoid these lines (and the use of 'continue' statement).
        if(currentRowIndex + 1 == A.rows()) {
            result.coeffRef(currentRowIndex) = b.coeffRef(currentRowIndex) / A.coeffRef(currentRowIndex, currentRowIndex);
            continue;
        }

        auto col = A.cols() - 1;
        double calc = b.coeffRef(currentRowIndex);
        for(; col != currentRowIndex; col--){
            calc -= A.coeffRef(currentRowIndex, col) * result.coeffRef(col);
        }

        calc /= A.coeffRef(currentRowIndex, col);

        result.coeffRef(col) = calc;

    }
    return result;
}

Vector forwardSubstitution(MatrixXd &A, Vector &b){
    Vector result(b.size());

    auto currentRowIndex = 0;
    for(; currentRowIndex < A.rows(); currentRowIndex++){

        if(currentRowIndex == 0){
            result.coeffRef(0) = b.coeffRef(0) / A.coeffRef(0, 0);
            continue;
        }

        auto col = 0;
        double calc = b.coeffRef(currentRowIndex);
        for(; col != currentRowIndex; col++){
            calc -= A.coeffRef(currentRowIndex,col) * result.coeffRef(col);
        }

        calc /= A.coeffRef(currentRowIndex,col);

        result.coeffRef(col) = calc;
    }

    return result;
}


#endif //COLLEYMATRIX_TRIANGULARSOLVER_H
