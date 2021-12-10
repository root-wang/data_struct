//
// Created by ROOT_WANG on 2021/12/13.
//

#ifndef LEARNING_CPP_STRUCT_MATRIX_SPARSEMATRIX_H_
#define LEARNING_CPP_STRUCT_MATRIX_SPARSEMATRIX_H_
#include <iostream>

class sparseMatrix {
 private:
    struct triple {
//      元素行标
      int m_row;
//      元素列标
      int m_col;
//      元素值
      int m_val;
      triple() {
      };
      triple(int the_row,
             int the_col,
             int the_val) : m_row(the_row),
                            m_col(the_col),
                            m_val(the_val) {
      };
      ~triple() = default;;
    };
    triple *m_mat_array;
//    矩阵非零元素个数
    int m_num;
//    矩阵行数
    int m_srow;
//    矩阵列数
    int m_scol;
//    检查两个矩阵是否可以进行加法
    int check_add(const sparseMatrix &x) const {
        if (m_scol == x.m_scol && m_srow == x.m_srow)
            return true;
        exit(-1);
    }
//    检查两个矩阵是否可以相乘
    int check_multiple(const sparseMatrix &x) const {
        if (m_scol == x.m_srow)
            return true;
        exit(-1);
    }
 public:
//  构造函数
    explicit sparseMatrix(int,
                          int,
                          int);
//  拷贝构造函数
    sparseMatrix(const sparseMatrix &);
//
    ~sparseMatrix() = default;;
    
    void creatMatrix();
    
    sparseMatrix &operator+(const sparseMatrix &) const;
    
    sparseMatrix &operator+=(const sparseMatrix &);
    
    sparseMatrix &operator-(const sparseMatrix &) const;
    
    sparseMatrix &operator-=(const sparseMatrix &);
    
    int operator()(int,
                   int);
};

#endif // LEARNING_CPP_STRUCT_MATRIX_SPARSEMATRIX_H_