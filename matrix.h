#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

using namespace std;

class Matrix
{
private:
    unsigned short int m;
    unsigned short int n;
    int *arr;

    Matrix(unsigned short int m, unsigned short int n, int *arr);
public:
    Matrix();
    ~Matrix();

    friend Matrix operator+(Matrix const& m1, Matrix const& m2){
        if (m1.m != m2.m || m1.n != m2.n){
            throw "Размеры матрицы не совпадают. Сложение невозможно.";
        }
        int *arr = new int[m1.m*m1.n];
        for (int i = 0; i < m1.m * m1.n; i++){
            arr[i] = m1.arr[i] + m2.arr[i];
        }
        Matrix result(m1.m, m1.n, arr);
        return result;
    }
    friend Matrix operator*(Matrix const& m1, Matrix const& m2){
        if (m1.n != m2.m){
            throw "Размеры матриц не позволяют произвести умножение.";
        }
        int *arr = new int[m1.m*m2.n];
        int s = 0;
        for (int h = 0; h < m1.m; h++){
            for (int j = 0; j < m2.n; j++){
                for (int i = 0; i < m2.m; i++){
                    s += m1.arr[h*m1.n+i] * m2.arr[i*m2.n+j];
                }
                arr[h*m2.n+j] = s;
                s = 0;
            }
        }
        Matrix result(m1.m, m2.n, arr);
        return result;
    }
    friend Matrix operator*(int const& n, Matrix const& m){
        int *arr = new int[m.m*m.n];
        for (int i = 0; i < m.m*m.n; i++){
            arr[i] = m.arr[i] * n;
        }
        Matrix result(m.m, m.n, arr);
        return result;
    }
    friend ostream& operator<< (ostream &out, const Matrix &m){
        for (int i = 0; i < m.m; i++){
            for (int j = 0; j < m.n; j++){
                out << m.arr[i*m.n+j] << " ";
            }
            out << endl;
        }
        return out;
    }
};

#endif // MATRIX_H
