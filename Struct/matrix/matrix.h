//
// Created by wang on 2021/11/17.
//

#ifndef LEARNING_MATRIX_H
#define LEARNING_MATRIX_H

#include <ostream>

using namespace std;

template<class T>
class Matrix {
//    friend ostream &operator<<(ostream &, const Matrix<T> &);
 
 private:
//    该矩阵的总共行数
    int m_rows;
//    该矩阵的总共列数
    int m_cols;
    T **m_element;
//    序号有效性检查
    void check(int the_row,
               int the_col) {
        if (the_row <= 0 || the_col <= 0)
            exit(-1);
    }
 public:
//    构造函数
    explicit Matrix(int the_row = 0,
                    int the_col = 0);

//    拷贝个构造函数
    Matrix(const Matrix<T> &);

//    析构函数
    ~Matrix();

//    矩阵输出
    void output() const;
    
    int get_row() const {
        return m_rows;
    }
    
    int get_col() const {
        return m_cols;
    }

//    元素提取赋值重载
    T &operator()(int i,
                  int j) const;

//    拷贝构造重载
    Matrix<T> &operator=(const Matrix<T> &);

//    所有元素加一个相同的值
    Matrix<T> &operator+() const;

//    矩阵加法
    Matrix<T> &operator+(const Matrix<T> &) const;

//    所有元素减去一个相同的值
    Matrix<T> &operator-() const;

//    矩阵减法
    Matrix<T> &operator-(const Matrix<T> &) const;

//    矩阵乘法
    Matrix<T> &operator*(const Matrix<T> &) const;

//    矩阵加法返回给自身
    Matrix<T> &operator+=(const Matrix<T> &);
};

#endif //LEARNING_MATRIX_H