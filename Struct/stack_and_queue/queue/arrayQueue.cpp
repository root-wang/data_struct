//
// Created by Wang on 2021/11/13.
//
#include <cstdlib>
#include "arrayQueue.h"

//构造函数
template<class T>
Array_queue<T>::Array_queue(int the_length) {
    m_base = new T[the_length];
    m_length = the_length;
    m_rear = 0;
    m_front = 0;
    if (!m_base) {
        m_front = m_rear = 0;
        exit(-1);
    }
}

//析构函数
template<class T>
Array_queue<T>::~Array_queue() {
    delete[]m_base;
}

//入队
//队满?
template<class T>
bool Array_queue<T>::en_queue(const T &e) {
    if (length_queue() == m_length-1) {
        exit(-1);
    } else {
        m_base[m_rear] = e;
        m_rear = (m_rear + 1) % m_length;
    }
}

// 队空?
template<class T>
bool Array_queue<T>::de_queue(T &e) {
    if (m_rear==m_front )exit(-2);
    else{
        e = m_base[m_front];
        m_front = (m_front+1)%m_length;
    }
}

//取队头元素
//队空?
template<class T>
T Array_queue<T>::get_head() {
    if(m_rear==m_front) {
        exit(-3);
    } else{
        return m_base[m_front];
    }
}