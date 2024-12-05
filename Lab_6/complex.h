#ifndef COMPLEX_H
#define COMPLEX_H
#include <QString>
#include <cmath>

template<typename T>
class Complex
{
    typedef T type_value;
    typedef T& ref;
    typedef T* point;
private:
     type_value Re;
     type_value Im;
     QChar Op;
public:  
     void setRe(type_value value){Re=value;}
     void setIm(type_value value){Im=value;}
     void setOp(QChar value){Op=value;}
    Complex( const type_value _re=type_value(1),const type_value _im=type_value(1),const QChar _op='+'):Re(_re),Im(_im),Op(_op){}
    template<typename secT>
    Complex( const Complex<secT>& copy_complex):Re(copy_complex.Re),Im(copy_complex.Im){}
    Complex<T> operator+(const Complex<T>& complex) const;
    Complex<T> operator-(const Complex<T>& complex) const;
    Complex<T> operator*(const Complex<T>& complex) const;
    Complex<T> operator/(const Complex<T>& complex) const;
    const Complex<T>& operator+=(const Complex<T>& complex) const;
    const Complex<T>& operator-=(const Complex<T>& complex) const;
    const Complex<T>& operator*=(const Complex<T>& complex) const;
    const Complex<T>& operator/=(const Complex<T>& complex) const;
    const Complex<T>& operator!() const;
    //вычисление корня
    Complex<T> sqrt();
    //возвести в квадрат
    Complex<T> pow();
    QString GetTrigonometricForm() const;
    QString GetArefmicForm() const;
    QString GetExpForm() const;
};

#endif // COMPLEX_H
