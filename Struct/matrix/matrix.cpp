//
// Created by wang on 2021/11/17.
//

#include <iostream>
#include "matrix.h"

template<class T>
Matrix<T>::Matrix(int the_row,
                  int the_col) {
    check(the_row, the_col);
    
    m_rows = the_row;
    m_cols = the_col;
    
    m_element = new T *[the_row + 1];
    for (int i = 1; i != the_row + 1; ++i) {
        m_element[i] = new T[the_col + 1];
    }
}

template<class T>
Matrix<T>::Matrix(const Matrix<T> &x) {
    m_cols = x.m_cols;
    m_rows = x.m_rows;
    m_element = new T *[x.m_rows + 1];
    for (int i = 1; i != x.m_rows + 1; ++i) {
        m_element[i] = new T[x.m_cols + 1];
    }
    
    for (int i = 1; i != x.m_rows + 1; ++i) {
        copy(x.m_element[i], x.m_element[i] + x.m_cols, m_element[i]);
    }
}

template<class T>
Matrix<T>::~Matrix() {
    for (int i = 0; i != m_rows + 1; ++i) {
        delete[]m_element[i];
    }
    delete[]m_element;
}

template<class T>
T &Matrix<T>::operator()(int i,
                         int j) const {
//    check(i, j);
    return m_element[i][j];
}

template<class T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &x) {
    if (&x != this) {
        for (int i = 1; i != m_rows + 1; ++i) {
            delete[]m_element[i];
        }
        delete[]m_element;
        m_rows = x.m_rows;
        m_cols = x.m_cols;
        m_element = new T *[x.m_rows + 1];
        for (int i = 1; i != x.m_rows + 1; ++i) {
            m_element[i] = new T[x.m_cols + 1];
        }
        
        for (int i = 1; i != x.m_rows + 1; ++i) {
            copy(x.m_element[i], x.m_element[i] + x.m_cols, m_element[i]);
        }
    }
    return *this;
}

template<class T>
void Matrix<T>::output() const {
    for (int i = 1; i != m_rows + 1; ++i) {
        for (int j = 1; j != m_cols + 1; ++j) {
            std::cout << m_element[i][j] << ' ';
        }
        cout << '\n';
    }
}