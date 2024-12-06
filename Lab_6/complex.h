#ifndef COMPLEX_H
#define COMPLEX_H
#include <QString>
#include <cmath>

template<typename T>
class Complex
{
    typedef T value_type;
    typedef T& ref;
    typedef T* point;
private:
    double phi;
    double mod;
    value_type Re;
    value_type Im;
public:  
    void setRe(value_type value){Re=value;}
    void setIm(value_type value){Im=value;}
    void setMod(double value){mod=value;}
    double getMod(){return mod;}
    void setPhi(double value){phi=value;}
    double getPhi(){return phi;}
    Complex( const value_type _re=value_type(1),const value_type _im=T(1)):Re(_re),Im(_im){}
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
    QString GetTrigonometricForm();
    QString GetArefmicForm();
    QString GetExpForm();
};

#endif // COMPLEX_H
