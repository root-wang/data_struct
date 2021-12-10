//
// Created by wang on 2021/11/23.
//

#include "Linear_list.h"
#include <iostream>

template<typename T>
Linear_list<T>::Linear_list(int initial_capacity) {
    if (initial_capacity < 1) {
        exit(-1);
    } else {
        array_length = initial_capacity;
        element      = new T[initial_capacity];
        list_size    = 0;
    }
}

template<typename T>
Linear_list<T>::Linear_list(int initial_capacity, int num, T* e) {
    if (initial_capacity < 1) {
        exit(-1);
    } else {
        array_length = initial_capacity;
        element      = new T[num];
        std::copy(e, e + num, element);
        list_size = num;
    }
}


template<typename T>
Linear_list<T>::Linear_list(const Linear_list<T>& x) {
    array_length = x.array_length;
    element      = new T[array_length];
    std::copy(x, x + list_size, element);
    list_size = x.list_size;
}


template<typename T>
void Linear_list<T>::check_index(int the_index) const {
    if (the_index < 0 || the_index >= array_length) {
        exit(-1);
    }
}

//返回引用是减少
template<typename T>
const T& Linear_list<T>::get_element(int the_index) const {
    check_index(the_index);
    return element[the_index];
}

template<typename T>
int Linear_list<T>::indexOf(const T& e, int pos) const {
    int      index;
    for (int i = pos; i != list_size; ++i) {
        if (element[i] == e)
            return i;
    }
    return -1;
}

template<typename T>
const T& Linear_list<T>::erase(int the_index) {
    check_index(the_index);
    for (int i = the_index; i != list_size; ++i) {
        element[i] = element[i + 1];
    }
    list_size--;
//    调用析构函数 删除最后一个空出来的位置
    element[list_size].~T();
    return element[the_index];
}

template<typename T>
const T& Linear_list<T>::insert(int the_index, const T& e, int full_act) {
    if (the_index < 0) {
        exit(-1);
    } else if (list_size >= array_length) {
        if (full_act == 0) {
            change_1d_length(element, list_size, 2 * array_length);
            array_length *= 2;
        } else {
            change_1d_length(element, list_size, full_act);
            array_length = full_act;
        }
    }
    if (array_length == list_size) {
        array_length *= 2;
        T* element_new = new T[array_length];
        std::copy(element, element + list_size, element_new);
        delete[]element;
        for (int i             = list_size - 1; i >= the_index; --i) {
            element_new[i + 1] = element_new[i];
        }
        element_new[the_index] = e;
        list_size++;
//        element = element_new;
        element = element_new;
        return element_new[the_index];
    }
    for (int i         = list_size - 1; i >= the_index; --i) {
        element[i + 1] = element[i];
    }
    element[the_index] = e;
    list_size++;
    return element[the_index];
}

template<typename T>
void Linear_list<T>::output() const {
//    std::cout;
    for (int i = 0; i != list_size; ++i) {
        std::cout << element[i] << '\n';
    }
}

template<typename T>
void Linear_list<T>::trim_to_size() {
    if (list_size > 1) {
        change_1d_length(element, array_length, list_size);
        array_length = list_size;
    } else {
        array_length = 1;
    }
}

template<typename T>
int Linear_list<T>::set_size(int size) {
    if (size < 0) {
        exit(-1);
    }
    change_1d_length(element, array_length, size);
    if (size >= list_size) {
        array_length = size;
    } else {
        list_size = array_length = size;
    }
    return 0;
}

template<typename T>
T& Linear_list<T>::operator [](int i) const {
    check_index(i);
    return element[i];
}

template<typename T>
bool Linear_list<T>::operator ==(Linear_list<T>& x) const {
    if (list_size != x.list_size)
        return false;
    for (int i = 0; i != list_size; ++i) {
        if (element[i] != x.element[i])
            return false;
    }
    return true;
}

template<typename T>
bool Linear_list<T>::operator !=(Linear_list<T>& x) const {
    if (list_size != x.list_size)
        return true;
    for (int i = 0; i != list_size; ++i) {
        if (element[i] != x.element[i])
            return true;
    }
    return false;
}

template<typename T>
bool Linear_list<T>::operator <(Linear_list<T>& x) const {
    if (list_size != x.list_size)
        return false;
    for (int i = 0; i != list_size; ++i) {
        if (element[i] >= x.element[i])
            return false;
    }
    return true;
}

template<typename T>
bool Linear_list<T>::operator >(Linear_list<T>& x) const {
    if (list_size != x.list_size)
        return false;
    for (int i = 0; i != list_size; ++i) {
        if (element[i] <= x.element[i])
            return false;
    }
    return true;
}