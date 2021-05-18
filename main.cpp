#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
    cout << "Матрица А" << endl;
    Matrix<int> a;
    cout << "Матрица В" << endl;
    Matrix<int> b;
    cout << endl << -5 * a + 2 * b << endl;
//    cout << endl << a * b << endl;
    return 0;
}
