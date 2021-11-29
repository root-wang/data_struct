//
// Created by wang on 2021/11/7.
//

#ifndef STRUCT_CURRENCY_H
#define STRUCT_CURRENCY_H

#include <ostream>


//TODO:定义一个类 currency
//  1. private对象:
//            -- 符号(- +) signType      the_sign
//            -- 美元      unsigned long the_dollars
//            -- 美分      unsigned int  the_cents
//  2. public操作:
//            -- 1.给成员赋值                                void set_value
//            -- 2.确定成员值(即确定符号, 美元数目和美分数目)      void set_value
//            -- 3.两个对象相加
//            -- 4.增加成员的值
//            -- 5.输出

enum signType {
    m_plus, m_minus
};

class Currency {
private:
    long m_amount;
public:
    //   构造函数
    Currency(signType the_sign = m_plus,
             unsigned long the_dollars = 0,
             unsigned int the_cents = 0);

    //  析构函数
    ~Currency() {};

    //    根据私有成员赋值
    void set_value(signType, unsigned long, unsigned int);

    //    输入浮点数自动转换
    void set_value(double);


    //    返回私有成员
    signType get_sign() const {
        if (m_amount < 0) return m_minus;
        else return m_plus;
    };

    unsigned long get_dollars() const {
        if (m_amount < 0) return (-m_amount) / 100;
        else return m_amount / 100;
    };

//        -123   -1.23
    unsigned int get_cents() const {
        if (m_amount < 0) return -m_amount - get_dollars() * 100;
        else return m_amount - get_dollars() * 100;
    };


    //    两个对象相加 返回新的对象
    Currency operator+(const Currency &) const;

    //    增加对象的值 直接返回给调用的对象
//    这个函数显示的访问了一个x对象 又隐式访问了一个对象
//    这个函数实现的功能是改变隐式访问对象的成员属性 但不应该改变显示访问x对象的属性 所以入参应当是const
//    所以在函数签名后不应该有const
//    由于返回的是改变了的对象 所以在函数返回类型也不应该有const
    Currency &operator+=(const Currency &x) {
        m_amount += x.m_amount;
        return *this;
    }

//    为了更好地理解const 增加一个比较两个成员对象的方法
//    由于只是比较两个对象的大小所以在隐式 和 显示 访问两个对象的时候都没有
//    应该去改变两个对象的值
//    在这个函数中对于被隐式访问的对象 通过this指针来称呼
//    在调用这个方法时 this就是指向了调用成员函数的对象
    const Currency &compare_big(const Currency &x) const {
        if (m_amount > x.m_amount) return *this;
        else return x;
    }

    //    输出对象的数据
    void output(std::ostream &) const;
};

//  构造函数
Currency::Currency(signType the_sign, unsigned long the_dollars, unsigned int the_cents) {
    set_value(the_sign, the_dollars, the_cents);
}

//  根据对象数据格式设置对象值
void Currency::set_value(signType the_sign, unsigned long the_dollars, unsigned int the_cents) {
    if (the_cents > 99) {
        throw IllegalParameterValue("cents should be <100");
    }
    m_amount = the_dollars * 100 + the_cents;
    if (the_sign == m_minus) m_amount = -m_amount;
}

//   转换格式设置对象值 -2.45 5.63
void Currency::set_value(double the_amount) {
    if (the_amount < 0) {
        m_amount = (long) ((the_amount - 0.001) * 100);
    } else {
        m_amount = (long) ((the_amount + 0.001) * 100);
    }
}

Currency Currency::operator+(const Currency &x) const {
    Currency result;
    result.m_amount = m_amount + x.m_amount;
    return result;
}


void Currency::output(std::ostream &out) const {
    long the_amount = m_amount;
    if (the_amount < 0) {
        out << '-';
        the_amount = -the_amount;
    }
    long dollars = the_amount / 100;
    out << '$' << dollars << '.';
    int cents = the_amount - dollars * 100;
    if (cents < 10) out << '0';
    out << cents;
}

//  重载
std::ostream &operator<<(std::ostream &out, const Currency &x) {
    x.output(out);
    return out;
}


//Currency Currency::add(const Currency &that) const {
//    //    将that和this的对象转换为整数在相加 赋值给一个新的对象result
//    Currency result;
//    long this_integer, that_integer, result_integer;
//
//    //    将调用对象转换为有符号整型
//    this_integer = m_cents + 100 * m_dollars;
//    if (m_minus == m_sign) this_integer = -this_integer;
//
//    //    将that转换为有符号整型
//    that_integer = that.m_cents + 100 * that.m_dollars;
//    if (m_minus == that.m_sign) that_integer = -that_integer;
//
//    result_integer = that_integer + this_integer;
//
//    //    将无符号整型结果转换为对象的表达式
//    if (result_integer < 0) {
//        result.m_sign = m_minus;
//        result_integer = -result_integer;
//    } else result.m_sign = m_plus;
//    result.m_dollars = result_integer / 100;
//    result.m_cents = result_integer - result.m_dollars * 100;
//
//    return result;
//}

//Currency &Currency::increment(const Currency &that) {
//    *this = add(that);
//    return *this;
//}

//void Currency::output() const {
//    if (m_minus == m_sign) std::cout << '-';
//    std::cout << '$' << m_dollars;
//    std::cout << '.';
//    if (m_cents < 10) std::cout << 0;
//    std::cout << m_cents;
//    std::cout << '\n';
//}

#endif //STRUCT_CURRENCY_H
