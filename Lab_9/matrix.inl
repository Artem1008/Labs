# include <matrix.h>

template<typename T>
Matrix<T>::Matrix(int _rows, int _columns):rows(_rows),columns(_columns)
{
    srand (time(NULL));
    T** data = new T*[rows];
    for(int i=0;i<rows;++i)
    {
        data[i] = new int[columns];
        for (int j = 0; j < columns; ++j)
        {
            data[i][j] = rand() % 256;
            //printf("%d ", data[i][j]);
        }
        //printf("\n");
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
template<typename T>
std::ostream& operator<<(std::ostream &os,const Matrix<T>& refmatrix)
{
    for(int i=0;i<refmatrix.rows;++i)
    {
        for (int j = 0; j<refmatrix.columns; ++j)
        {
            printf("%d",refmatrix.data[i][ j]);
        }
        os<<'\n';
    }
   return  os;
}
