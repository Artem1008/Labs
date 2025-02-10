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
    for(int i=0;i<this->rows;++i)
    {
        for (int j = 0; j<this->columns; ++j)
        {
             this->data[i][ j]=this->data[i][ j]*x;
        }
    }
    return *this;
}
template<typename T>
Matrix<T>& Matrix<T>::add(Matrix<T> m)
{
    if((this->columns!=m.columns)||(this->rows!=m.rows))
    {
        throw -1;
    }
    for(int i=0;i<this->rows;++i)
    {
        for (int j = 0; j<this->columns; ++j)
        {
             this->data[i][ j]=this->data[i][ j]+m.data[i][ j];
        }
    }
    return *this;
}
template<typename T>
Matrix<T>& Matrix<T>::sub(Matrix<T> m)
{
    if((this->columns!=m.columns)||(this->rows!=m.rows))
    {
        throw -1;
    }
    for(int i=0;i<this->rows;++i)
    {
        for (int j = 0; j<this->columns; ++j)
        {
             this->data[i][ j]=this->data[i][ j]-m.data[i][ j];
        }
    }
    return *this;
}
template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& m) const
{
    if((this->columns!=m.columns)||(this->rows!=m.rows))
    {
        throw -1;
    }
    Matrix<T>* temp=new Matrix<T>(m.rows,m.columns);
    for(int i=0;i<m.rows;++i)
    {
        for (int j = 0; j<m.columns; ++j)
        {
             temp->data[i][ j]=this->data[i][ j]+m.data[i][ j];
        }
    }
    return *temp;
}
template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& m) const
{
    if((this->columns!=m.columns)||(this->rows!=m.rows))
    {
        throw -1;
    }
    Matrix<T>* temp=new Matrix<T>(m.rows,m.columns);
    for(int i=0;i<m.rows;++i)
    {
        for (int j = 0; j<m.columns; ++j)
        {
             temp->data[i][ j]=this->data[i][ j]-m.data[i][ j];
        }
    }
    return *temp;
}
template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& m) const
{
    if((this->columns!=m.rows))
    {
        throw -1;
    }
    Matrix<T>* temp=new Matrix<T>(this->rows,m.columns);
    for(int i=0;i<this->rows;++i)
    {
        for(int j=0;j<m.columns;++j)
        {
            temp->data[i][j]=0;
             for(int k=0;k<m.rows;++k)
             {
                 temp->data[i][j]+=this->data[i][k]*m.data[k][j];
             }
        }
    }
    return *temp;
}
template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& m)
{
    if((this->columns!=m.columns)||(this->rows!=m.rows))
    {
        throw -1;
    }
    for(int i=0;i<this->rows;++i)
    {
        for (int j = 0; j<this->columns; ++j)
        {
             this->data[i][ j]=m.data[i][ j];
        }
    }
    return *this;
}
template<typename T>
std::ostream& operator<<(std::ostream &os,const Matrix<T>& refmatrix)
{
    for(int i=0;i<refmatrix.rows;++i)
    {
        for (int j = 0; j<refmatrix.columns; ++j)
        {
             os<<refmatrix.data[i][ j]<<' ';
        }
        os<<'\n';
    }
   return os;
}
