//
// Created by wang on 2021/11/13.
//

#include "arrayStack.h"
#include "illeagal_parameter_value.h"
#include <sstream>

//构造函数 输入栈的最大长度
template<class T>
array_stack<T>::array_stack(int init_capacity) {
    if (init_capacity < 1) {
        std::ostringstream s;
        s << "initial capacity = " << init_capacity << "must be > 0";
        throw IllegalParameterValue(s.str());
    }
//    栈顶指针指向栈顶元素
    stack_length = init_capacity;
    stack_top = -1;
    stack = new T[stack_length];
}

//析构函数
template<class T>
array_stack<T>::~array_stack() {
    delete[]stack;
}

//栈空?
template<class T>
bool array_stack<T>::is_empty() const {
    if (stack_top == -1)
        return true;
    else
        return false;
}

//栈满?
template<class T>
bool array_stack<T>::is_full() const {
    if (stack_top == stack_length - 1)
        return true;
    else
        return false;
}

template<class T>
bool array_stack<T>::push(const T &item) {
    if (is_full()) {
//        栈上溢返回错误
        return false;

//        或者为栈分配更大空间

    } else {
        stack_top++;
        stack[stack_top] = item;

        return true;
    }
}

template<class T>
bool array_stack<T>::pop(T &item) {
    if(stack_top==-1) {
        return false;
    } else {
        item = stack[stack_top];
//        此处是使用了T的析构函数来释放弹出元素的栈顶
        stack[stack_top].~T();
        stack_top--;
        return true;
    }
}


template<class T>
void array_stack<T>::change_length_1d(array_stack<T>, int, int) {

}