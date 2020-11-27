//
// Created by lisandro on 27/11/20.
//

#include <iostream>
#include "CholeskySolver.h"

void CholeskySolver::fit(){
    if( this->trained )
        cout << "The matrix has been already trained, please reset the matrix to perform a new fit." << endl;
    else
        this->L = this->selfMatrix.llt().matrixL(); // If the constructor matrix wasn't trained, Cholesky decomposition is performed.
}

MatrixXd CholeskySolver::getLMatrix() {
    return this->L;
}

Vector CholeskySolver::predict(Vector &x) {
    return Vector();
}
