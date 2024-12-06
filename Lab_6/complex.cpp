#include "complex.h"
#define a Re
#define b Im
#define c complex.Re
#define d complex.Im

//(a + bi)
//(c + di)

template<typename T>
Complex<T> Complex<T>::operator+(const Complex<T>& complex) const
{
    return Complex<T>(a+c,b+d);
}
template<typename T>
Complex<T> Complex<T>::operator-(const Complex<T>& complex) const
{
  return Complex<T>(a-c,b-d);
}
template<typename T>
Complex<T> Complex<T>::operator*(const Complex<T>& complex) const
{
    return Complex<T>((a*c-b*d),(b*c+a*d));
}
template<typename T>
Complex<T> Complex<T>::operator/(const Complex<T>& complex) const
{
  return Complex<T>((a*c+b*d)/(c*c+d*d), (b*c-a*d)/(c*c+d*d));
}
template<typename T>
const Complex<T>& Complex<T>::operator!() const
{
   setRe(a);
   setIm(b*-1);
  return *this;
}

template<typename T>
const Complex<T>& Complex<T>::operator+=(const Complex<T>& complex) const
{
    a += c;
    b += d;
    return *this;
}
template<typename T>
const Complex<T>& Complex<T>::operator-=(const Complex<T>& complex) const
{
    a -= c;
    b -= d;
    return *this;
}
template<typename T>
const Complex<T>& Complex<T>::operator*=(const Complex<T>& complex) const
{
    a=(a*c-b*d);
    b=(b*c+a*d);
    return *this;
}
template<typename T>
const Complex<T>& Complex<T>::operator/=(const Complex<T>& complex) const
{
    a=(a*c+b*d)/(c*c+d*d);
    b=(b*c-a*d)/(c*c+d*d);
    return *this;
}
template<typename T>
Complex<T>  Complex<T> ::sqrt()
{

}
template<typename T>
Complex<T>  Complex<T> ::pow()
{

}
template<typename T>
QString Complex<T> ::GetTrigonometricForm()
{
    //double mod=::sqrt(a*a+b*b);
}
template<typename T>
QString Complex<T> ::GetArefmicForm()
{
    return QString::number(Re)+"+"+QString::number(Im)+"i";
}
template<typename T>
QString Complex<T> ::GetExpForm()
{

}
