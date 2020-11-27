#include <iostream>
#include "src/types.h"

int main() {

    MatrixXd A(3,3);
    A << 4,-1,2, -1,6,0, 2,0,5;
    cout << "The matrix A is" << endl << A << endl;

    Eigen::LLT<MatrixXd> lltofA(A);

    MatrixXd L = lltofA.matrixL();

    cout << L << endl;

    cout << L * L.transpose() << endl;
    return 0;
}
