//
// Created by wang on 2021/12/7.
//

#ifndef GREEDYLOADING_CPP_MAXHEAP_H
#define GREEDYLOADING_CPP_MAXHEAP_H

#include <cstdlib>

template<typename T>
class maxHeap {
 
 private:
    T *m_heap;
    int array_length; //数组最大容量
    int heap_size;    //数组当前元素
 public:
    maxHeap() : m_heap(nullptr),
                array_length(0),
                heap_size(0) {
    };
//    拷贝函数
    maxHeap(const maxHeap<T> &x);
    
    ~maxHeap() = default;
    
    T &top() const {
        return m_heap[0];
    }
    
    void push(const T &e);
    
    void pop();

//  通过输入的数组和长度进行大跟堆的初始化
//  在原有数组的位置上重新排列
//  the_heap:
//       需要进行初始化的数组
//  the_size:
//       数组元素长度
//  返回:
//       无
    void initialize(T *the_heap,
                    int the_size);
    
    void output() const;
//  对当前的大跟堆进行降序输出
//  x:
//      用于接收堆排序后的数组
//  len:
//      数组元素长度
//  说明:
//      该方法需要使用一个数组进行大根堆的初始化
//      进而使用大根堆进行堆排序
//      不会破坏原本的大跟堆结构
    void heap_sort(T *&x,
                   int len);
};

#endif //GREEDYLOADING_CPP_MAXHEAP_H