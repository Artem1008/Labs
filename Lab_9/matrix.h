#ifndef MATRIX_H
#define MATRIX_H
#include <cstdlib>
#include <ctime>
#include <iostream>


template<typename T>
class Matrix {
private:
    T** data;
    int rows;
    int columns;
public:
    Matrix(int rows, int columns);
    ~Matrix(){};
    Matrix<T>& multiply(int x);
    Matrix<T>& add(Matrix<T> m);
    Matrix<T>& sub(Matrix<T> m);
    Matrix<T> operator+(const Matrix<T>& m) const;
    Matrix<T> operator-(const Matrix<T>& m) const;
    Matrix<T> operator*(const Matrix<T>& m) const;
    Matrix<T>& operator=(const Matrix<T>& m);
    template<typename T2>
    friend Matrix<T>& operator*(Matrix<T>& refmatrix,T2 val)
    {
        Matrix<T>* temp=new Matrix<T>(refmatrix.rows,refmatrix.columns);
        for(int i=0;i<refmatrix.rows;++i)
        {
            for (int j = 0; j<refmatrix.columns; ++j)
            {
                 temp->data[i][ j]=refmatrix.data[i][ j]*val;
            }
        }
        return *temp;
    }
    template<typename T2>
    friend std::ostream& operator << (std::ostream& os, const Matrix<T2>& refmatrix);
};

#include <matrix.inl>
#endif // MATRIX_H
