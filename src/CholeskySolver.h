//
// Created by lisandro on 27/11/20.
//

#ifndef COLLEYMATRIX_CHOLESKYSOLVER_H
#define COLLEYMATRIX_CHOLESKYSOLVER_H
#include "types.h"


class CholeskySolver {
    explicit CholeskySolver(MatrixXd A){selfMatrix = A;}
    void fit();
    MatrixXd getLMatrix();
    Vector predict(Vector &x);

private:
    MatrixXd selfMatrix;
    MatrixXd L;
    bool trained = false;

};


#endif //COLLEYMATRIX_CHOLESKYSOLVER_H
