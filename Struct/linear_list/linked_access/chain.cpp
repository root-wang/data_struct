//
// Created by wang on 2021/12/8.
//

#include "chain.h"

template <typename T>
Chain<T>::Chain(int capacity)
{
    if (capacity < 1)
    {
        exit(-1);
    }
    head = new chainNode<T>(0, nullptr);
    m_length = 0;
}

template <typename T>
Chain<T>::Chain(const Chain<T> &x)
{
    m_length = x.m_length;
    if (m_length == 0)
    {
        head = nullptr;
        return;
    }
    chainNode<T> *source_node = x.head;
    head = new chainNode<T>(source_node->m_data);
    source_node = source_node->next;
    chainNode<T> *target_node = head;

    while (source_node)
    {
        target_node->next = new chainNode<T>(source_node->m_data);
        target_node = target_node->next;
        source_node = source_node->next;
    }
    target_node->next = nullptr;
}

template <typename T>
Chain<T>::~Chain()
{
    while (head)
    {
        chainNode<T> *next_node = head->next;
        delete head;
        head = next_node;
    }
}

template <typename T>
T &Chain<T>::insert(T &e,
                    int position)
{
    if (position > m_length || position < 0)
    {
        exit(-1);
    }
    chainNode<T> *pos_node = head;
    for (int i = 0; i != position; ++i)
    {
        pos_node = pos_node->next;
    }
    chainNode<T> *insert_node = new chainNode<T>(e, pos_node->next);
    pos_node->next = insert_node;
    m_length++;
    return e;
}
template <typename T>
T &Chain<T>::erase(int the_index)
{
    check_index(the_index);
    chainNode<T> *pos_node = head;
    for (int i = 0; i != the_index; ++i)
    {
        pos_node = pos_node->next;
    }
    chainNode<T> *del_node = pos_node->next;
    static T del_data = del_node->m_data;
    pos_node->next = del_node->next;
    delete del_node;
    m_length--;
    return del_data;
}
template <typename T>
T &Chain<T>::get(int the_index) const
{
    check_index(the_index);
    chainNode<T> *current_node = head->next;
    for (int j = 0; j != the_index; ++j)
    {
        current_node = current_node->next;
    }
    return current_node->m_data;
}

template <typename T>
int Chain<T>::indexOf(const T &e) const
{
    int i = 0;
    chainNode<T> *current_node = head;
    while (current_node)
    {
        current_node = current_node->next;
        if (current_node->m_data == e)
            return i;
        i++;
    }
    return -1;
}

template <typename T>
void Chain<T>::output() const
{
    for (chainNode<T> *current_node = head->next; current_node != nullptr; current_node = current_node->next)
    {
        std::cout << current_node->m_data << '\n';
    }
}
template <typename T>
int Chain<T>::push_back(const T &e)
{
    if (!head)
    {
        head->next = new chainNode<T>(e, nullptr);
        m_length++;
    }
    chainNode<T> *next_node = head;
    while (next_node->next)
    {
        next_node = next_node->next;
    }
    next_node->next = new chainNode<T>(e, nullptr);
    m_length++;
    return 0;
}

template <typename T>
void Chain<T>::set_size(int the_size)
{
    if (m_length <= the_size)
        return;
    chainNode<T> *size_node = head;
    for (int i = 0; i != the_size; ++i)
    {
        size_node = size_node->next;
    }

    chainNode<T> *del_node = size_node->next;
    size_node->next = nullptr;

    chainNode<T> *p = del_node;
    while (p)
    {
        p = p->next;
        delete del_node;
        del_node = p;
    }
}

template <typename T>
void Chain<T>::set(int the_index,
                   T &e)
{
    check_index(the_index);
    chainNode<T> *current_node = head->next;
    for (int j = 0; j != the_index; ++j)
    {
        current_node = current_node->next;
    }
    current_node->m_data = e;
}

template <typename T>
void Chain<T>::remove_range(int from_index,
                            int to_index)
{
    check_index(from_index);
    check_index(to_index);
    chainNode<T> *begin_node = head;
    chainNode<T> *end_node = head;
    for (int j = 0; j != from_index; ++j)
    {
        begin_node = begin_node->next;
    }

    for (int j = 0; j != to_index; ++j)
    {
        end_node = end_node->next;
    }

    chainNode<T> del_node = begin_node->next;
    begin_node->next = end_node->next;

    chainNode<T> *p = del_node;
    for (int i = 0; i != to_index - from_index; ++i)
    {
        p = p->next;
        delete del_node;
        del_node = p;
    }
}

template <typename T>
int Chain<T>::last_indexOf(T &e) const
{
    return 0;
}

template <typename T>
T &Chain<T>::operator[](int index) const
{
    return get(index);
}

template <typename T>
bool Chain<T>::operator==(const Chain<T> &x) const
{
    return false;
}

template <typename T>
bool Chain<T>::operator!=(const Chain<T> &x) const
{
    return false;
}

template <typename T>
bool Chain<T>::operator<(const Chain<T> &x) const
{
    return false;
}

template <typename T>
int Chain<T>::swap(const Chain<T> &the_chain)
{
    return 0;
}

template <typename T>
int Chain<T>::left_shift(int i)
{
    return 0;
}

template <typename T>
void Chain<T>::reverse()
{
}

template <typename T>
void Chain<T>::bin_sort(int range)
{
    chainNode<T> **base = new chainNode<T> *[range + 1];
    chainNode<T> **top = new chainNode<T> *[range + 1];

    for (int i = 0; i != range + 1; ++i)
    {
        base[i] = nullptr;
        top[i] = nullptr;
    }

    chainNode<T> *current_node = head->next;
    for (; current_node != nullptr; current_node = current_node->next)
    {
        int the_bin = current_node->m_data;
        if (base[the_bin] == nullptr)
        {
            base[the_bin] = top[the_bin] = current_node;
        }
        else
        {
            top[the_bin]->next = current_node;
            top[the_bin] = current_node;
        }
    }
    chainNode<T> *y = NULL;
    for (int theBin = 0; theBin <= range + 1; theBin++)
    {
        if (base[theBin] != NULL)
        {
            if (y == NULL)
            {
                head->next = base[theBin];
            }
            else
            {
                y->next = base[theBin];
            }
            y = top[theBin];
        }

        if (y != NULL)
        {
            y->next = NULL;
        }
    }
    delete[] base;
    delete[] top;
}