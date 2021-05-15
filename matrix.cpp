#include <iostream>
#include "matrix.h"

using namespace std;

Matrix::Matrix()
{
    cout << "Введите размеры матрицы" << endl;
    cin >> m >> n;
    if (m < 1 || n < 1){
        throw "Неправильный размер матрицы";
    }
    arr = new int[m*n];
    cout << "Введите матрицу" << endl;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> arr[i*n+j];
        }
    }
}
Matrix::Matrix(unsigned short int M, unsigned short int N, int *Arr){
    m = M;
    n = N;
    arr = Arr;
}
Matrix::~Matrix(){
    delete [] arr;
}
