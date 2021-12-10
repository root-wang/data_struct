//
// Created by wang on 2021/11/23.
//

#ifndef LEARNING_LINEAR_LIST_H
#define LEARNING_LINEAR_LIST_H

#include <ostream>
#include "list_iterator.h"

//template<typename T>class list_iterator;

template<typename T>
class Linear_list {
//    迭代器
    friend class list_iterator<T>;

protected:
//    检查索引合法性
    void check_index(int the_index) const;

    T* element;//元素数组
    int array_length {};//一维数组容量
    int list_size {};//线性表元素个数
public:
//    构造函数
    explicit Linear_list(int initial_capacity = 15);

//    数组传入构造函数
    Linear_list(int initial_capacity, int num, T* e);

//    拷贝函数
    Linear_list(const Linear_list<T>&);

//    析构函数
    ~Linear_list() { delete[]element; };


//    ADT方法
//    数组是否为空:
//      数组为空则返回bool型值 true
//      否则返回bool型值 false
    bool is_empty() const { return list_size == 0; }

//    数组元素个数:
//      返回当前数组元素的个数
    int size() const { return list_size; }

//    获取数组元素:
//      the_index: 需要查询元素的位置
//    返回该元素的引用
    const T& get_element(int the_index) const;

//    检查元素索引:
//      e: 需要查询的元素
//      pos: 检查元素的起始位置(包括),默认是0
//    返回:
//      若该元素存在则返回该元素第一次出现在数组中的位置
//      若该元素不存在则返回整型值 -1
    int indexOf(const T& e, int pos = 0) const;

//    擦除数组元素:
//      the_index: 需要删除元素的位置
//    返回:
//      指定删除位置的下一个元素的位置
    const T& erase(int the_index);

//    插入数组元素:
//      the_index: 插入元素的位置
//      e: 要插入的元素
//    返回:
//      插入元素的位置
    const T& insert(int the_index, const T& e, int full_act = 0);

//    输出数组
    void output() const;

//    返回数组最大长度
    int capacity() const { return array_length; }

//    剪枝函数
    void trim_to_size();

//    重新设定数组长度
    int set_size(int size);

//    返回第i个元素的引用
    T& operator [](int i) const;

//  当且仅当两个数组的所有元素都相等时返回true
    bool operator ==(Linear_list<T>& x) const;

//  当两个数组不是全部相等时返回true
    bool operator !=(Linear_list<T>& x) const;

//    当且仅当两个数组按字典序小于时 返回
    bool operator <(Linear_list<T>& x) const;

    bool operator >(Linear_list<T>& x) const;

//  在数组尾部插入
    void push_back(T& e);

//  删除数组尾部元素
    void pop_back();

//    将表中元素向左移动
    void leftShift(int the_shift);
    
//    原地颠倒表中元素 无需额外空间
    void reverse();
    
//    交替合并两个链表
    Linear_list<T>&meld(Linear_list<T> &x);
    
//    将两个有序链表(从左至右非递减)合并为一个新链表
    Linear_list<T>&merge(Linear_list<T>&);
    
//
};

template<typename T>
void change_1d_length(T*& array_old,
                      int length_old,
                      int length_new) {
    T* temp = new T[length_new];
    int number = std::min(length_old, length_new);
    std::copy(array_old, array_old + number, temp);
    delete[]array_old;
    array_old = temp;
}


//TODO:待测试
template<typename T>
void change_2d_length(T*& array_old, int length_1d, int* length_old, int* length_new) {
    for (int i = 0; i != length_1d; ++i) {
        if (length_new[i] < 0) {
            exit(-1);
        }
    }
    for (int i = 0; i != length_1d; ++i) {
        int* temp = new int[length_new[i]];
        std::copy(array_old[i], array_old[i] + length_old[i], temp);
        delete[]array_old[i];
        array_old[i] = temp;
    }

}

#endif //LEARNING_LINEAR_LIST_H