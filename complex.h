#ifndef __complex__
#define __complex__
#include<cmath>
#include<ostream>
#include<iostream>



class complex
{
private:
    double re,im;
public:
    complex(double r=0, double i=0) 
    : re(r),im(i) 
    {}
    complex& operator +=(const complex&);
    double real () const {return re;}
    double image() const {return im;}

    friend complex& doadd(complex* ths,const complex& r);

};

inline complex& //传递者无需知道接受者是以ref形式接收。
doadd(complex* ths , const  complex& r){
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

inline complex&
complex::operator += (const complex& r){
    return doadd(this,r);
}

inline double
real(const complex& x){
    return x.real();
}

inline double
image(const complex& x){
    return x.image();
}

inline complex
operator + (const complex& x,const complex& y){
    return complex(x.real()+y.real(),x.image()+y.image()) ;
}
inline complex
operator+ (const complex& x,double y){
    return complex(real(x)+y,image(x));
}

inline complex
operator+ (double x,const complex& y){
    return complex(x+real(y),image(y));
}

inline complex
operator + (const complex& x){
    return x;
}

inline complex
operator - (const complex& x){
    return complex(-real(x),-image(x));
}


inline std::ostream&  
operator << (std::ostream& os , const complex& x){   //不能在operator前加std:: 
    return os<<'('<<real(x)<<','<<image(x)<<')';
}

#endif