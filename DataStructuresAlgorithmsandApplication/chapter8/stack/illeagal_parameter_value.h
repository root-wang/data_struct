//
// Created by wang on 2021/11/13.
//

#ifndef LEARNING_ILLEAGAL_PARAMETER_VALUE_H
#define LEARNING_ILLEAGAL_PARAMETER_VALUE_H

#include <string>
#include <iostream>

//TODO:定义一个异常类 IllegalParameterValue
//  1. private:
//            -- WString message
//  2. public:
//            -- 1.抛出缺省值得异常 "Illegal parameter value"
//            -- 2.自定义抛出异常的信息
//            -- 3.抛出异常操作
class IllegalParameterValue {
private:
    std::string m_message;
public:
    //    默认构造函数
    IllegalParameterValue() :
//    string类的默认构造函数在string变量的后面输入char型指针变量
            m_message("Illegal parameter value") {}

    //    构造函数
    IllegalParameterValue(std::basic_string<char, std::char_traits<char>, std::allocator<char>> the_message) {
        m_message = the_message;
    }

    //    catch (IllegalParameterValue e)
    //    use e.output_message() throw error
    void output_message() const {
        std::cout << m_message << '\n';
    }
};
#endif //LEARNING_ILLEAGAL_PARAMETER_VALUE_H
