//
// Created by wang on 2021/11/14.
//

#ifndef LEARNING_ARRAY_QUEUE_H
#define LEARNING_ARRAY_QUEUE_H

template<class T>
class Array_queue {
private:
//    static const int MAXSIZE = 5;
    T *m_base;
    int m_front;//头指针 队头元素的下标
    int m_rear;//尾指针 指向队尾元素后的一个位置
    int m_length;
public:
    Array_queue(int the_length);
    ~Array_queue();

//    求循环队列的长度
    int length_queue()const{return ((m_rear-m_front+m_length)%m_length);}
//    入队
    bool en_queue(const T &e);
//    出队
    bool de_queue(T &e);
//    取队头元素
    T  get_head();
};



#endif //LEARNING_ARRAY_QUEUE_H
