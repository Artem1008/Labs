# include <matrix.h>

template<typename T>
Matrix<T>::Matrix(int _rows, int _columns):rows(_rows),columns(_columns)
{
    srand (time(NULL));
    data = new (std::nothrow)T*[rows];
    for(int i=0;i<rows;++i)
    {
        data[i] = new (std::nothrow)T[columns];
        for (int j = 0; j < columns; ++j)
        {
            data[i][j] = rand() % 256;
        }
    }
}
template<typename T>
Matrix<T>& Matrix<T>::multiply(int x)
{
    for(int i=0;i<(*data).size();++i)
    {
        for (int j = 0; j < (*data[i]).size(); ++j)
        {
            data[i][j]*=x;
        }
    }
}
template<typename T>
Matrix<T>& Matrix<T>::add(Matrix<T> m)
{

}
template<typename T>
Matrix<T>& Matrix<T>::sub(Matrix<T> m)
{

}
template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> m) const
{

}
template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> m) const
{

}
template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> m) const
{

}
template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& m) const
{

}
template<typename T2>
std::ostream& operator<<(std::ostream &os,const Matrix<T2>& refmatrix)
{
    for(int i=0;i<refmatrix.rows;++i)
    {
        for (int j = 0; j<refmatrix.columns; ++j)
        {
             os<<refmatrix.data[i][ j]<<' ';
        }
        os<<'\n';
    }
   return  os;
}
