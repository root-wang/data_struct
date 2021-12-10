//
// Created by wang on 2021/12/7.
//

#include "maxHeap.h"
#include <iostream>

//拷贝函数 重新开辟内存地址
//重新复制一次
template<typename T>
maxHeap<T>::maxHeap(const maxHeap<T> &x) {
    array_length = x.array_length;
    heap_size = x.heap_size;
    m_heap = new T[array_length];
    std::copy(x.m_heap, x.m_heap + x.heap_size, m_heap);
}

template<typename T>
void maxHeap<T>::push(const T &e) {
    if (heap_size == array_length - 1) {
        exit(-1);
    }
    int current_node = ++heap_size;
    while (current_node != 0 || m_heap[current_node / 2 - 1] < e) {
        m_heap[current_node] = m_heap[current_node / 2 - 1];
        current_node = current_node / 2 - 1;
    }
    m_heap[current_node] = e;
}

template<typename T>
void maxHeap<T>::pop() {
    if (heap_size == 0) {
        exit(-1);
    }
    m_heap[0].~T();
    T last_element = m_heap[heap_size - 1];
    heap_size--;
    int current_node = 0;
    int child = 1;
    while (child <= heap_size) {
        if (child < heap_size && m_heap[child] < m_heap[child + 1]) {
            child++;
        }
        if (last_element >= m_heap[child]) {
            break;
        }
        m_heap[current_node] = m_heap[child];
        current_node = child;
        child = child * 2 + 1;
    }
    m_heap[current_node] = last_element;
}

template<typename T>
void maxHeap<T>::initialize(T *the_heap,
                            int the_size) {
    delete[] m_heap;
    m_heap = the_heap;
    heap_size = the_size;
    
    for (int root = (heap_size - 1) / 2; root >= 0; root--) {
        T root_element = m_heap[root];
        
        int child = root * 2 + 1;
        while (child < heap_size) {
            if (child < heap_size && m_heap[child] < m_heap[child + 1]) {
                child++;
            }
            if (root_element >= m_heap[child]) {
                break;
            }
            m_heap[(child - 1) / 2] = m_heap[child];
            child = child * 2 + 1;
        }
        m_heap[(child - 1) / 2] = root_element;
    }
}

template<typename T>
void maxHeap<T>::output() const {
    for (int i = 0; i != heap_size; ++i) {
        std::cout << m_heap[i] << ' ';
    }
    std::cout << m_heap;
    std::cout << '\n';
}

//原本堆排序需要每次pop()
//这也就会破坏原本的大跟堆结构
//对原来的数组保存 再排序完成后恢复
template<typename T>
void maxHeap<T>::heap_sort(T *&x,
                           int len) {
    T *temp = new T[len];
    std::copy(m_heap, m_heap + heap_size, temp);
    for (int i = 0; i != len; ++i) {
        x[i] = this->top();
        this->pop();
    }
    delete[]m_heap;//及时删除掉原本被破坏的数组
    heap_size = len;
    m_heap = temp;
    
}