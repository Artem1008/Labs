/*
 * Класс комплексных чисел
*/
#ifndef COMPLEX_H
#define COMPLEX_H
#define Cre complex.Re
#define CIm complex.Im

#include <QString>
#include <cmath>

//(a + bi)
//(c + di)

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
    Complex<T> operator+(const Complex<T>& complex) const
    {
        return Complex<T>(Re+Cre,Im+CIm);
    }
    Complex<T> operator-(const Complex<T>& complex) const
    {
        return Complex<T>(Re-Cre,Im-CIm);
    }
    Complex<T> operator*(const Complex<T>& complex) const
    {
        return Complex<T>((Re*Cre-Im*CIm),(Im*Cre+Re*CIm));
    }
    Complex<T> operator/(const Complex<T>& complex) const
    {
        return Complex<T>((Re*Cre+Im*CIm)/(Cre*Cre+CIm*CIm), (Im*Cre-Re*CIm)/(Cre*Cre+CIm*CIm));
    }
    const Complex<T>& operator+=(const Complex<T>& complex) const
    {
        Re += Cre;
        Im += CIm;
        return *this;
    }
    const Complex<T>& operator-=(const Complex<T>& complex) const
    {
        Re -= Cre;
        Im -= CIm;
        return *this;
    }
    const Complex<T>& operator*=(const Complex<T>& complex) const
    {
        Re=(Re*Cre-Im*CIm);
        Im=(Im*Cre+Re*CIm);
        return *this;
    }
    const Complex<T>& operator/=(const Complex<T>& complex) const
    {
        Re=(Re*Cre+Im*CIm)/(Cre*Cre+CIm*CIm);
        Im=(Im*Cre-Re*CIm)/(Cre*Cre+CIm*CIm);
        return *this;
    }
    const Complex<T>& operator!() const
    {
        setRe(Re);
        setIm(Im*-1);
        return *this;
    }
    //вычисление корня
    Complex<T> sqrt()
    {
        Re=::sqrt((mod+Re)/2);
        Im=(Im/fabs(Im))*(::sqrt((mod-Re)/2));
        return *this;
    }
    //возвести в квадрат
    Complex<T> pow()
    {
        return this*=this;
    }
    QString GetTrigonometricForm()
    {
        mod=(::sqrt(Re*Re+Im*Im));
        double alpha=1 / tan(Im/Re);
        if(Re>=0&&Im>=0) phi=alpha;
        else if(Re<0&&Im>=0) phi=M_PI-alpha;
        else if(Re<0&&Im<0) phi=M_PI+alpha;
        else if(Re>=0&&Im>0) phi=2*M_PI-alpha;
        return QString::number(mod)+"(cos"+QString::number(phi)+"+sin"+QString::number(phi)+')';
    }
    QString GetArefmicForm()
    {
        if(Im>0)return QString::number(Re)+'+'+QString::number(Im)+"i";
        else return QString::number(Re)+QString::number(Im)+"i";
    }
    QString GetExpForm()
    {
        return QString::number(mod)+"exp(i"+QString::number(phi)+")";
    }
};

#endif // COMPLEX_H
