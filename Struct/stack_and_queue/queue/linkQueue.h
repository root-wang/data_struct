//
// Created by wang on 2021/11/14.
//

#ifndef LEARNING_LINK_QUEUE_H
#define LEARNING_LINK_QUEUE_H

template<class T>
class Link_queue_node{
public:
    Link_queue_node(){
        next = nullptr;
    }
    ~Link_queue_node()=default;
    Link_queue_node<T> *next;
    T m_data;
};

template<class T>
class Link_queue{
private:
    Link_queue_node<T> *m_front;
    Link_queue_node<T> *m_rear;
public:
    Link_queue();
    ~Link_queue();
    //    入队
    bool en_queue(const T &e);
    //    出队
    bool de_queue(T &e);

};


#endif //LEARNING_LINK_QUEUE_H
