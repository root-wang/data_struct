//
// Created by wang on 2021/11/13.
//

#ifndef MAIN_CPP_ARRAY_STACK_H
#define MAIN_CPP_ARRAY_STACK_H
//typedef long T;

template<class T>
class array_stack{
private:
    int stack_length;
    int stack_top;
    T *stack;
    void change_length_1d(array_stack<T>,int,int);
public:
//    构造函数 输入初始化的栈容量
    array_stack(int init_capacity=10);
    ~array_stack();
    bool is_empty()const;
    bool is_full()const;
//    将元素item压入栈 元素时const 但是栈会变
    bool push(const T &item);
//    将栈顶元素弹出返回给item
//    item即是入参也是出参
    bool pop(T &item);
};
#endif //MAIN_CPP_ARRAY_STACK_H
