//
// Created by wang on 2021/11/14.
//

#include "linkQueue.h"

template<class T>
Link_queue<T>::Link_queue() {
    m_front = new Link_queue_node<T>;
    m_rear = m_front;
}

template<class T>
Link_queue<T>::~Link_queue() {
    m_rear = m_front->next;
    while (m_front) {
        delete m_front;
        m_front = m_rear;
        m_rear = m_rear->next;
    }
}

template<class T>
bool Link_queue<T>::en_queue(const T &e) {
    Link_queue_node<T> *p = new Link_queue_node<T>;
    p->m_data = e;
    p->next = nullptr;
    m_rear->next = p;
    m_rear = m_rear->next;
    return true;
}

template<class T>
bool Link_queue<T>::de_queue(T &e) {
    if (m_rear == m_front) {
        return false;
    } else {
        Link_queue_node<T> *p = m_front->next;
        e = p->m_data;
        m_front->next = p->next;
        if(m_rear==p) m_rear = m_front;
        delete p;
        return true;
    }
}