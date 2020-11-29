#include <iostream>
#include "src/types.h"
#include "src/CholeskySolver.h"

int main() {

    MatrixXd B(3,3);
    B << 4,-1,2, -1,6,0, 2,0,5;
    Vector b(3);
    b << 1,2,3;
    CholeskySolver ch = CholeskySolver(B);
    ch.fit();
    cout << ch.getLMatrix() << endl;
    Vector res = ch.predict(b);
    cout << res << endl;


    return 0;
}
