#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

using namespace std;

template<typename T>
class Matrix
{
private:
    unsigned short int m;
    unsigned short int n;
    T *arr;

    Matrix(unsigned short int M, unsigned short int N, T *Arr){
        m = M;
        n = N;
        arr = Arr;
    }
public:
    Matrix(){
        cout << "Введите размеры матрицы" << endl;
        cin >> m >> n;
        if (m < 1 || n < 1){
            throw "Неправильный размер матрицы";
        }
        arr = new T[m*n];
        cout << "Введите матрицу" << endl;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                cin >> arr[i*n+j];
            }
        }
    }
    ~Matrix(){
        delete [] arr;
    }
    friend Matrix<T> operator+(Matrix<T> const& m1, Matrix<T> const& m2){
        if (m1.m != m2.m || m1.n != m2.n){
            throw "Размеры матрицы не совпадают. Сложение невозможно.";
        }
        T *arr = new T[m1.m*m1.n];
        for (int i = 0; i < m1.m * m1.n; i++){
            arr[i] = m1.arr[i] + m2.arr[i];
        }
        Matrix<T> result(m1.m, m1.n, arr);
        return result;
    }
    friend Matrix<T> operator*(Matrix<T> const& m1, Matrix<T> const& m2){
        if (m1.n != m2.m){
            throw "Размеры матриц не позволяют произвести умножение.";
        }
        T *arr = new T[m1.m*m2.n];
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
        Matrix<T> result(m1.m, m2.n, arr);
        return result;
    }
    friend Matrix<T> operator*(int const& n, Matrix<T> const& m){
        T *arr = new T[m.m*m.n];
        for (int i = 0; i < m.m*m.n; i++){
            arr[i] = m.arr[i] * n;
        }
        Matrix<T> result(m.m, m.n, arr);
        return result;
    }
    friend ostream& operator<< (ostream &out, const Matrix<T> &m){
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
