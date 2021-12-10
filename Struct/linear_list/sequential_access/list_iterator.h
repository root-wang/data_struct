//
// Created by wang on 2021/11/28.
//

#ifndef LEARNING_LIST_ITERATOR_H
#define LEARNING_LIST_ITERATOR_H


template<typename T>
class list_iterator{
protected:
    T* position;
public:
    typedef std::bidirectional_iterator_tag iterator_category;
    typedef T value_type;
    typedef std::ptrdiff_t difference_type;
    typedef T *pointer;
    typedef T &reference;

//    构造函数
    explicit list_iterator(T* the_position = 0){position = the_position;}

//    解引用操作符
    T& operator*(){return *position;}
    T* operator->(){return &*position;}
};
#endif //LEARNING_LIST_ITERATOR_H
