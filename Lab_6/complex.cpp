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
    a=::sqrt((mod+a)/2);
    b=(b/fabs(b))*(::sqrt((mod-a)/2));
    return *this;
}
template<typename T>
Complex<T>  Complex<T> ::pow()
{
 return this*=this;
}
template<typename T>
QString Complex<T> ::GetTrigonometricForm()
{
    mod=(::sqrt(a*a+b*b));
    double alpha=1 / tan(b/a);
    if(a>=0&&b>=0) phi=alpha;
    else if(a<0&&b>=0) phi=M_PI-alpha;
    else if(a<0&&b<0) phi=M_PI+alpha;
    else if(a>=0&&b>0) phi=2*M_PI-alpha;
    return QString::number(mod)+"(cos"+QString::number(phi)+"+sin"+QString::number(phi)+')';
}
template<typename T>
QString Complex<T> ::GetArefmicForm()
{
    if(Im>0)return QString::number(Re)+'+'+QString::number(Im)+"i";
    else return QString::number(Re)+QString::number(Im)+"i";
}
template<typename T>
QString Complex<T> ::GetExpForm()
{
return QString::number(mod)+"exp(i"+QString::number(phi)+")";
}
