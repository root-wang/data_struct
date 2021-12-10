//
// Created by ROOT_WANG on 2021/12/26.
//

#ifndef LEARNING__COMPLEX_H_
#define LEARNING__COMPLEX_H_
#include <iostream>

class complex;

std::ostream& operator<<(std::ostream&,
                         const complex&);

class complex {
 private:
    double re, im;
 public:
    complex(double the_re = 0,
            double the_im = 0)
        : re(the_re), im(the_im) {
    };
    
    inline double get_real() const {
        return re;
    }
    inline double get_imag() const {
        return im;
    }
    
    inline complex& operator+=(const complex& x) {
        this->re += x.re;
        this->im += x.im;
        return *this;
    }
    
    
    friend std::ostream& operator<<(std::ostream&,
                                    const complex&);
};

inline complex operator+(const complex& x,
                         const complex& y) {
    //临时对象 函数结束生命消失
//    return complex(x.get_real() + y.get_real(), x.get_imag() + y.get_imag());
    return {x.get_real() + y.get_real(), x.get_imag() + y.get_imag()};
}

inline complex operator+(const double& x,
                         const complex& y) {
    //临时对象 函数结束生命消失
    return {x + y.get_real(), y.get_imag()};
}

inline complex operator+(const complex& x,
                         const double y) {
    //临时对象 函数结束生命消失
    return {x.get_real() + y, x.get_imag()};
}

inline const complex& operator+(const complex& x) {
    return x;
}

inline complex operator-(const complex& x) {
    return {-x.get_real(), -x.get_imag()};
}

std::ostream& operator<<(std::ostream& os,
                         const complex& x) {
    return os << '(' << x.re << "+j" << x.im << ')' << '\n';
}
#endif //LEARNING__COMPLEX_H_