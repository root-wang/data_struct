//
// Created by wang on 2021/11/17.
//

#include "matrix.h"

template<class T>
Matrix<T>::Matrix(int the_row, int the_col) {
    if(the_col<0||the_row<0){
        throw "the row and col both must >=0";
    } else if(the_row==0||the_col==0){
        throw "either both or neither rows and cols should == 0";
    } else{
        m_cols = the_col;
        m_rows = the_row;
        m_element = new T [the_row*the_col];
    }
}

template<class T>
Matrix<T>::Matrix(const Matrix<T> &x) {
    m_cols = x.m_cols;
    m_rows = x.m_rows;
    m_element = new T [x.m_rows*x.m_cols];
//    for (int i = 0; i < x.m_rows*x.m_cols; ++i) {
//
//    }
    copy(x.m_element,
         x.m_element+x.m_cols*x.m_rows,
         m_element);
}

template<class T>
T &Matrix<T>::operator()(int i, int j) const {

}

template<class T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &) {

}
