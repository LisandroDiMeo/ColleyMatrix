//
// Created by lisandro on 27/11/20.
//

#ifndef COLLEYMATRIX_CHOLESKYSOLVER_H
#define COLLEYMATRIX_CHOLESKYSOLVER_H
#include "types.h"


class CholeskySolver {
public:
    CholeskySolver(MatrixXd A){ this->selfMatrix = A; };
    void fit();
    MatrixXd getLMatrix();
    Vector predict(Vector &x);

private:
    MatrixXd selfMatrix;
    MatrixXd L;
    MatrixXd Lt;
    bool trained = false;

};


#endif //COLLEYMATRIX_CHOLESKYSOLVER_H
