//
// Created by ROOT_WANG on 2021/12/13.
//

#include "sparseMatrix.h"
sparseMatrix::sparseMatrix(int num,
                           int srow,
                           int scol) {
    m_num = num;
    m_srow = srow;
    m_scol = scol;
    m_mat_array = new triple[num];
}
sparseMatrix::sparseMatrix(const sparseMatrix &x) {
    m_num = x.m_num;
    m_srow = x.m_srow;
    m_scol = x.m_scol;
    m_mat_array = new triple[m_num];
    std::copy(x.m_mat_array, x.m_mat_array + x.m_num, m_mat_array);
}
sparseMatrix &sparseMatrix::operator+(const sparseMatrix &x) const {
    check_add(x);
    static sparseMatrix add_new(m_num + x.m_num, m_srow, m_scol);
    int index = 0;
    int i = 0, j = 0;
    while (i < m_num || j < x.m_num) {
        if (m_mat_array[i].m_row == x.m_mat_array[j].m_row) {
            if (m_mat_array[i].m_col == x.m_mat_array[j].m_col) {
                if (0 == m_mat_array[i].m_val + x.m_mat_array[j].m_val) {
                    i++;
                    j++;
                    continue;
                } else {
                    add_new.m_mat_array[index].m_row = m_mat_array[i].m_row;
                    add_new.m_mat_array[index].m_col = m_mat_array[i].m_col;
                    add_new.m_mat_array[index].m_val = m_mat_array[i].m_val + x.m_mat_array[j].m_val;
                    i++;
                    j++;
                    index++;
                    continue;
                }
                
            } else if (m_mat_array[i].m_col < x.m_mat_array[j].m_col) {
                add_new.m_mat_array[index].m_row = m_mat_array[i].m_row;
                add_new.m_mat_array[index].m_col = m_mat_array[i].m_col;
                add_new.m_mat_array[index].m_val = m_mat_array[i].m_val;
                i++;
                index++;
                continue;
            } else {
                add_new.m_mat_array[index].m_row = x.m_mat_array[j].m_row;
                add_new.m_mat_array[index].m_col = x.m_mat_array[j].m_col;
                add_new.m_mat_array[index].m_val = x.m_mat_array[j].m_val;
                j++;
                index++;
                continue;
            }
            
        } else if (m_mat_array[i].m_row < x.m_mat_array[j].m_row) {
            add_new.m_mat_array[index].m_row = m_mat_array[i].m_row;
            add_new.m_mat_array[index].m_col = m_mat_array[i].m_col;
            add_new.m_mat_array[index].m_val = m_mat_array[i].m_val;
            i++;
            index++;
            continue;
        } else {
            add_new.m_mat_array[index].m_row = x.m_mat_array[j].m_row;
            add_new.m_mat_array[index].m_col = x.m_mat_array[j].m_col;
            add_new.m_mat_array[index].m_val = x.m_mat_array[j].m_val;
            j++;
            index++;
            continue;
        }
    }
    while (i < m_num) {
        add_new.m_mat_array[index].m_row = m_mat_array[i].m_row;
        add_new.m_mat_array[index].m_col = m_mat_array[i].m_col;
        add_new.m_mat_array[index].m_val = m_mat_array[i].m_val;
        i++;
        index++;
    }
    while (j < x.m_num) {
        add_new.m_mat_array[index].m_row = x.m_mat_array[j].m_row;
        add_new.m_mat_array[index].m_col = x.m_mat_array[j].m_col;
        add_new.m_mat_array[index].m_val = x.m_mat_array[j].m_val;
        j++;
        index++;
    }
    return add_new;
}
sparseMatrix &sparseMatrix::operator+=(const sparseMatrix &x) {
    static sparseMatrix add_new(m_num + x.m_num, m_srow, m_scol);
    add_new = *this + x;
    delete[]m_mat_array;
    this->m_mat_array = add_new.m_mat_array;
    add_new.~sparseMatrix();
    return *this;
}
sparseMatrix &sparseMatrix::operator-(const sparseMatrix &x) const {
    check_add(x);
    static sparseMatrix minus_new(m_num + x.m_num, m_srow, m_scol);
    int index = 0;
    int i = 0, j = 0;
    while (i < m_num || j < x.m_num) {
        if (m_mat_array[i].m_row == x.m_mat_array[j].m_row) {
            if (m_mat_array[i].m_col == x.m_mat_array[j].m_col) {
                if (0 == m_mat_array[i].m_val - x.m_mat_array[j].m_val) {
                    i++;
                    j++;
                    continue;
                } else {
                    minus_new.m_mat_array[index].m_row = m_mat_array[i].m_row;
                    minus_new.m_mat_array[index].m_col = m_mat_array[i].m_col;
                    minus_new.m_mat_array[index].m_val = m_mat_array[i].m_val - x.m_mat_array[j].m_val;
                    i++;
                    j++;
                    index++;
                    continue;
                }
                
            } else if (m_mat_array[i].m_col < x.m_mat_array[j].m_col) {
                minus_new.m_mat_array[index].m_row = m_mat_array[i].m_row;
                minus_new.m_mat_array[index].m_col = m_mat_array[i].m_col;
                minus_new.m_mat_array[index].m_val = m_mat_array[i].m_val;
                i++;
                index++;
                continue;
            } else {
                minus_new.m_mat_array[index].m_row = x.m_mat_array[j].m_row;
                minus_new.m_mat_array[index].m_col = x.m_mat_array[j].m_col;
                minus_new.m_mat_array[index].m_val = x.m_mat_array[j].m_val;
                j++;
                index++;
                continue;
            }
            
        } else if (m_mat_array[i].m_row < x.m_mat_array[j].m_row) {
            minus_new.m_mat_array[index].m_row = m_mat_array[i].m_row;
            minus_new.m_mat_array[index].m_col = m_mat_array[i].m_col;
            minus_new.m_mat_array[index].m_val = m_mat_array[i].m_val;
            i++;
            index++;
            continue;
        } else {
            minus_new.m_mat_array[index].m_row = x.m_mat_array[j].m_row;
            minus_new.m_mat_array[index].m_col = x.m_mat_array[j].m_col;
            minus_new.m_mat_array[index].m_val = x.m_mat_array[j].m_val;
            j++;
            index++;
            continue;
        }
    }
    while (i < m_num) {
        minus_new.m_mat_array[index].m_row = m_mat_array[i].m_row;
        minus_new.m_mat_array[index].m_col = m_mat_array[i].m_col;
        minus_new.m_mat_array[index].m_val = m_mat_array[i].m_val;
        i++;
        index++;
    }
    while (j < x.m_num) {
        minus_new.m_mat_array[index].m_row = x.m_mat_array[j].m_row;
        minus_new.m_mat_array[index].m_col = x.m_mat_array[j].m_col;
        minus_new.m_mat_array[index].m_val = x.m_mat_array[j].m_val;
        j++;
        index++;
    }
    return minus_new;
}
sparseMatrix &sparseMatrix::operator-=(const sparseMatrix &x) {
    static sparseMatrix minus_new(m_num + x.m_num, m_srow, m_scol);
    minus_new = *this - x;
    delete[]m_mat_array;
    this->m_mat_array = minus_new.m_mat_array;
    minus_new.~sparseMatrix();
    return *this;
    return *this;
}
int sparseMatrix::operator()(int i,
                             int j) {
    for (int k = 0; k != m_num; ++k) {
        if (i == m_mat_array[k].m_row && j == m_mat_array[k].m_col)
            return m_mat_array[k].m_val;
    }
    return 0;
}
void sparseMatrix::creatMatrix() {
    for (int i = 0; i != m_num; ++i) {
        std::cin
            >> m_mat_array[i].m_row
            >> m_mat_array[i].m_col
            >> m_mat_array[i].m_val;
    }
    
}