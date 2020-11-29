//
// Created by lisandro on 27/11/20.
//

#include <iostream>
#include "CholeskySolver.h"
#include "TriangularSolver.h"

void CholeskySolver::fit(){
    if( this->trained )
        cout << "The matrix has already been trained." << endl;
    else{
        this->trained = true;
        Eigen::LLT<MatrixXd> lltofSelfMatrix(this->selfMatrix);
        this->L = lltofSelfMatrix.matrixL(); // If the constructor matrix wasn't trained, Cholesky decomposition is performed.
        this->Lt = lltofSelfMatrix.matrixU();
    }
}

MatrixXd CholeskySolver::getLMatrix() {
    return this->L;
}

Vector CholeskySolver::predict(Vector &x) {
    Vector y = forwardSubstitution(L, x);
    Vector res = backwardSubstitution(Lt, y);
    return res;
}
