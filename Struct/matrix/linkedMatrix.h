//
// Created by ROOT_WANG on 2021/12/13.
//

#ifndef LEARNING_CPP_STRUCT_MATRIX_LINKEDMATRIX_H_
#define LEARNING_CPP_STRUCT_MATRIX_LINKEDMATRIX_H_
#include <iostream>

template<typename T>
struct triple {
  //      元素行标
  int m_row{};
//      元素列标
  int m_col{};
//      元素值
  T m_val;
  triple() {
  };
  triple(int the_row,
         int the_col) : m_row(the_row),
                        m_col(the_col) {
  }
  triple(int the_row,
         int the_col,
         T the_val) : m_row(the_row),
                      m_col(the_col),
                      m_val(the_val) {
  };
  ~triple() = default;;
};

template<typename T>
static const triple<T> *tri_zero = new triple<T>(0, 0);

template<typename T>
class linkedMatrix {
 private:
    struct valueElement {
//    列标
      int col{};
//    元素值
      T value{};
//    该行下一个非零元素结点
      valueElement *next{};
      valueElement() = default;
      valueElement(int the_col,
                   int the_value) : col(the_col),
                                    value(the_value),
                                    next(nullptr) {
      }
    };
    struct headElement {
//    行标
      int row;
//    每行首个非零元素
      valueElement *firstNode;
//    下一行行标
      headElement *next;
      headElement() {
      };
      explicit headElement(int the_row) : row(the_row),
                                          firstNode(nullptr),
                                          next(nullptr) {
      }
    };
    headElement *head;
//    非零元素个数
    int m_size{};
//    矩阵行数
    int m_row{};
//    矩阵列数
    int m_col{};

//    定义零元
    T m_zero;

//

//    检查行列索引合法
    int index_OK(int i,
                 int j) {
        if ((i >= 1 && i <= m_row) && (j >= 1 && j <= m_col)) {
            return 1;
        } else
            return 0;
    }
//    检查两个矩阵维度
    bool size_check(const linkedMatrix<T> &x) const {
        if (x.m_row == m_row && x.m_col == m_col) {
            return true;
        } else {
            return false;
        }
    }

//    检查两个矩阵维度
    bool multi_check(const linkedMatrix<T> &x) const {
        if (x.m_row == m_col && x.m_col == m_row) {
            return true;
        } else {
            return false;
        }
    }
 public:
    linkedMatrix() = default;
//    构造函数
    linkedMatrix(int the_size,
                 int the_row,
                 int the_col,
                 T the_zero);
//    析构函数
    ~linkedMatrix();
//    矩阵元素填充
    void creat_matrix(triple<T> *&the_tri = tri_zero<T>);

//    返回矩阵非零元元素个数
    int get_size() const {
        return m_size;
    }

//    设置元素值
    void set(int,
             int,
             T);
//    返回元素值
    T operator()(int,
                 int) const;
//    矩阵加法
    linkedMatrix<T> &operator+(linkedMatrix<T> &) const;
//    矩阵减法
    linkedMatrix<T> &operator-(linkedMatrix<T> &) const;
//    矩阵相乘
    linkedMatrix<T> &operator*(linkedMatrix<T> &) const;
//    清空矩阵
    void clear();
//    矩阵归零
    void zero();
//    矩阵转置
    void transpose(linkedMatrix<T> &);

//    矩阵输出
    void output() const;
};

template<typename T>
linkedMatrix<T>::linkedMatrix(int the_size,
                              int the_row,
                              int the_col,
                              T the_zero) {
    m_zero = the_zero;
    m_size = the_size;
    m_row = the_row;
    m_col = the_col;
    head = new headElement(0);
}

//析构函数
template<typename T>
linkedMatrix<T>::~linkedMatrix() = default;

//矩阵输出
template<typename T>
void linkedMatrix<T>::output() const {
    headElement *head_p = head->next;
    
    while (head_p) {
        valueElement *value_p = head_p->firstNode;
        while (value_p) {
            std::cout << head_p->row << ' ' << value_p->col << ' ' << value_p->value << '\n';
            value_p = value_p->next;
        }
        head_p = head_p->next;
    }
}

template<typename T>
void linkedMatrix<T>::transpose(linkedMatrix<T> &b) {
//    b.clear();
    auto *b_new = new linkedMatrix<T>(m_size, m_col, m_row, m_zero);
    headElement *b_current_p = b_new->head;
    for (int i = 1; i != m_col + 1; ++i) {
        headElement *head_p = head->next;
        while (head_p) {
            valueElement *current_val_node = head_p->firstNode;
            while (current_val_node) {
                if (current_val_node->col == i) {
                    valueElement *new_val_node = new valueElement(head_p->row, current_val_node->value);
                    valueElement *b_current_val_node;
                    if (b_current_p->row != i) {
                        b_current_p->next = new headElement(i);
                        b_current_p = b_current_p->next;
                        b_current_p->firstNode = new_val_node;
                        b_current_val_node = b_current_p->firstNode;
                    } else {
                        b_current_val_node->next = new_val_node;
                        b_current_val_node = b_current_val_node->next;
                    }
                }
                current_val_node = current_val_node->next;
            }
            head_p = head_p->next;
        }
    }
    b = *b_new;
}

template<typename T>
void linkedMatrix<T>::set(int the_row,
                          int the_col,
                          T the_val) {
    if (!index_OK(the_row, the_col)) {
        exit(-1);
    };
    headElement *head_p = head;
    while (true) {
        if (head_p->next->row >= the_row) {
            break;
        }
        head_p = head_p->next;
    }
    if (head_p->next->row > the_row) {
        headElement *new_the_row = new headElement(the_row);
        
        new_the_row->next = head_p->next;
        head_p->next = new_the_row;
        head_p = new_the_row;
        
        head_p->firstNode = new valueElement(the_col, the_val);
        m_size++;
    } else {
        head_p = head_p->next;
        if (the_col < head_p->firstNode->col) {
            valueElement *new_the_val = new valueElement(the_col, the_val);
            new_the_val->next = head_p->firstNode;
            head_p->firstNode = new_the_val;
            m_size++;
            return;
        }
        valueElement *value_node_last = head_p->firstNode;
        if (the_col == value_node_last->col) {
            value_node_last->value = the_val;
            return;
        }
        while (true) {
            if (value_node_last->next->col >= the_col) {
                break;
            }
            value_node_last = value_node_last->next;
        }
        
        if (value_node_last->next->col == the_col) {
            value_node_last->next->value = the_val;
        } else {
            valueElement *new_the_val = new valueElement(the_col, the_val);
            new_the_val->next = value_node_last->next;
            value_node_last->next = new_the_val;
            m_size++;
        }
    }
}

template<typename T>
T linkedMatrix<T>::operator()(int the_row,
                              int the_col) const {
    if (!index_OK(the_row, the_col)) {
        exit(-1);
    };
    headElement *head_p = head->next;
    valueElement *value_p;
    
    while (head_p && head_p->row != the_row) {
        head_p = head_p->next;
    }
    if (!head_p) {
        return m_zero;
    }
    
    value_p = head_p->firstNode;
    
    while (value_p && value_p->col != the_col) {
        value_p = value_p->next;
    }
    if (!value_p) {
        return m_zero;
    }
    
    return value_p->value;
}

template<typename T>
linkedMatrix<T> &linkedMatrix<T>::operator+(linkedMatrix<T> &x) const {
    if (!size_check(x)) {
        exit(-1);
    }
    static linkedMatrix<T> add_(0, m_row, m_col, m_zero);
    int add_size = 0;
    headElement *add_head = add_.head;
    
    headElement *head_p_this = head->next;
    headElement *head_p_that = x.head->next;
    headElement *head_p_add = nullptr;

//    行头结点循环
    while (head_p_this && head_p_that) {
        
        if (head_p_this->row == head_p_this->row) {
            valueElement *val_p_this = head_p_this->firstNode;
            valueElement *val_p_that = head_p_that->firstNode;
            valueElement *val_p_add = nullptr;

//            列值结点循环
            while (val_p_that && val_p_this) {
                if (val_p_this->col == val_p_that->col) {
                    if (m_zero != val_p_that->value + val_p_this->value) {
                        if (!head_p_add) {
//                        遇到相同位置的元素且和不为零 创建新的数值结点
                            valueElement
                                *add_node = new valueElement(val_p_this->col, val_p_that->value + val_p_this->value);
//                        同时是第一个列的值结点创建行头结点
                            headElement *new_add_head = new headElement(head_p_this->row);
                            head_p_add = new_add_head;


//                         加法矩阵列值循环
                            head_p_add->firstNode = add_node;
                            val_p_add = head_p_add->firstNode;
//                        循环
                            val_p_this = val_p_this->next;
                            val_p_that = val_p_that->next;
                            
                            add_size++;
                        } else {
//                        头结点已经创建
                            valueElement
                                *add_node = new valueElement(val_p_this->col, val_p_that->value + val_p_this->value);
                            val_p_add->next = add_node;
//                        循环
                            val_p_add = val_p_add->next;
                            val_p_this = val_p_this->next;
                            val_p_that = val_p_that->next;
                            add_size++;
                        }
                    } else if (m_zero == val_p_that->value + val_p_this->value) {
                        val_p_this = val_p_this->next;
                        val_p_that = val_p_that->next;
                    }
                } else if (val_p_this->col < val_p_that->col) {
                    if (!head_p_add) {
//                      创建行头结点
                        headElement *new_add_head = new headElement(head_p_this->row);
                        head_p_add = new_add_head;
//                      创建新的数值结点
                        valueElement *add_node = new valueElement(val_p_this->col, val_p_this->value);
                        
                        head_p_add->firstNode = add_node;
                        val_p_add = head_p_add->firstNode;
//                      循环
                        add_size++;
                        
                        val_p_this = val_p_this->next;
                    } else {
//                      创建新的数值结点
                        valueElement *add_node = new valueElement(val_p_this->col, val_p_this->value);
                        
                        val_p_add->next = add_node;
                        add_size++;
                        val_p_add = val_p_add->next;
                        val_p_this = val_p_this->next;
                    }
                    
                } else if (val_p_this->col > val_p_that->col) {
                    if (!head_p_add) {
//                      创建行头结点
                        headElement *new_add_head = new headElement(head_p_that->row);
                        head_p_add = new_add_head;
//                      创建新的数值结点
                        valueElement *add_node = new valueElement(val_p_that->col, val_p_that->value);
                        head_p_add->firstNode = add_node;
                        val_p_add = head_p_add->firstNode;
//                      循环
                        add_size++;
                        
                        val_p_that = val_p_that->next;
                    } else {
//                      创建新的数值结点
                        valueElement *add_node = new valueElement(val_p_that->col, val_p_that->value);
                        val_p_add->next = add_node;
                        add_size++;
                        val_p_add = val_p_add->next;
                        val_p_that = val_p_that->next;
                    }
                }
            }
            while (val_p_this) {
                val_p_add->next = val_p_this;
                add_size++;
                val_p_add = val_p_add->next;
                val_p_this = val_p_this->next;
            }
            while (val_p_that) {
                val_p_add->next = val_p_that;
                add_size++;
                val_p_add = val_p_add->next;
                val_p_that = val_p_that->next;
            }
            add_head->next = head_p_add;
            add_head = add_head->next;
            
            head_p_add = head_p_add->next;
            head_p_this = head_p_this->next;
            head_p_that = head_p_that->next;
        } else if (head_p_this->row < head_p_this->row) {
            head_p_this = head_p_this->next;
        } else {
            head_p_that = head_p_that->next;
        }
    }
    while (head_p_this) {
        head_p_add->next = head_p_this;
        break;
    }
    while (head_p_that) {
        head_p_add->next = head_p_that;
        break;
    }
    add_.m_size = add_size;
    return add_;
}

template<typename T>
linkedMatrix<T> &linkedMatrix<T>::operator-(linkedMatrix<T> &x) const {
    if (!size_check(x)) {
        exit(-1);
    }
    static linkedMatrix<T> minus_(0, m_row, m_col, m_zero);
    int minus_size = 0;
    headElement *minus_head = minus_.head;
    
    headElement *head_p_this = head->next;
    headElement *head_p_that = x.head->next;
    headElement *head_p_minus = nullptr;
    
    while (head_p_this && head_p_that) {
        
        if (head_p_this->row == head_p_this->row) {
            valueElement *val_p_this = head_p_this->firstNode;
            valueElement *val_p_that = head_p_that->firstNode;
            valueElement *val_p_minus = nullptr;

//            列值结点循环
            while (val_p_that && val_p_this) {
                if (val_p_this->col == val_p_that->col) {
                    if (m_zero != val_p_that->value - val_p_this->value) {
                        if (!head_p_minus) {
//                        遇到相同位置的元素且和不为零 创建新的数值结点
                            valueElement
                                *minus_node = new valueElement(val_p_this->col, val_p_that->value - val_p_this->value);
//                        同时是第一个列的值结点创建行头结点
                            headElement *new_minus_head = new headElement(head_p_this->row);
                            head_p_minus = new_minus_head;


//                         加法矩阵列值循环
                            head_p_minus->firstNode = minus_node;
                            val_p_minus = head_p_minus->firstNode;
//                        循环
                            val_p_this = val_p_this->next;
                            val_p_that = val_p_that->next;
                            
                            minus_size++;
                        } else {
//                        头结点已经创建
                            valueElement
                                *minus_node = new valueElement(val_p_this->col, val_p_this->value - val_p_that->value);
                            val_p_minus->next = minus_node;
//                        循环
                            val_p_minus = val_p_minus->next;
                            val_p_this = val_p_this->next;
                            val_p_that = val_p_that->next;
                            minus_size++;
                        }
                    } else if (m_zero == val_p_that->value - val_p_this->value) {
                        val_p_this = val_p_this->next;
                        val_p_that = val_p_that->next;
                    }
                } else if (val_p_this->col < val_p_that->col) {
                    if (!head_p_minus) {
//                      创建行头结点
                        headElement *new_minus_head = new headElement(head_p_this->row);
                        head_p_minus = new_minus_head;
//                      创建新的数值结点
                        valueElement *minus_node = new valueElement(val_p_this->col, val_p_this->value);
                        
                        head_p_minus->firstNode = minus_node;
                        val_p_minus = head_p_minus->firstNode;
//                      循环
                        minus_size++;
                        
                        val_p_this = val_p_this->next;
                    } else {
//                      创建新的数值结点
                        valueElement *minus_node = new valueElement(val_p_this->col, val_p_this->value);
                        
                        val_p_minus->next = minus_node;
                        minus_size++;
                        val_p_minus = val_p_minus->next;
                        val_p_this = val_p_this->next;
                    }
                    
                } else if (val_p_this->col > val_p_that->col) {
                    if (!head_p_minus) {
//                      创建行头结点
                        headElement *new_minus_head = new headElement(head_p_that->row);
                        head_p_minus = new_minus_head;
//                      创建新的数值结点
                        valueElement *minus_node = new valueElement(val_p_that->col, -val_p_that->value);
                        head_p_minus->firstNode = minus_node;
                        val_p_minus = head_p_minus->firstNode;
//                      循环
                        minus_size++;
                        
                        val_p_that = val_p_that->next;
                    } else {
//                      创建新的数值结点
                        valueElement *minus_node = new valueElement(val_p_that->col, -val_p_that->value);
                        val_p_minus->next = minus_node;
                        minus_size++;
                        val_p_minus = val_p_minus->next;
                        val_p_that = val_p_that->next;
                    }
                }
            }
            while (val_p_this) {
                val_p_minus->next = val_p_this;
                minus_size++;
                val_p_minus = val_p_minus->next;
                val_p_this = val_p_this->next;
            }
            while (val_p_that) {
                val_p_minus->next = val_p_that;
                minus_size++;
                val_p_minus = val_p_minus->next;
                val_p_that = val_p_that->next;
            }
            if (head_p_minus) {
                minus_head->next = head_p_minus;
                minus_head = minus_head->next;
            }
            
            if (head_p_minus) {
                head_p_minus = head_p_minus->next;
            }
            head_p_this = head_p_this->next;
            head_p_that = head_p_that->next;
        } else if (head_p_this->row < head_p_this->row) {
            head_p_this = head_p_this->next;
        } else {
            head_p_that = head_p_that->next;
        }
    }
    while (head_p_this) {
        head_p_minus->next = head_p_this;
        break;
    }
    while (head_p_that) {
        head_p_minus->next = head_p_that;
        break;
    }
    minus_.m_size = minus_size;
    return minus_;
}

template<typename T>
linkedMatrix<T> &linkedMatrix<T>::operator*(linkedMatrix<T> &x) const {
    if (!multi_check(x)) {
        exit(-1);
    }
    linkedMatrix<T> tra_multi;
    x.transpose(tra_multi);
    linkedMatrix<T> multi(0, m_row, x.m_col, m_zero);
    
    headElement *head_p_this = head->next;
    headElement *head_p_that = tra_multi.head->next;
    headElement *head_p_multi = multi.head;
    
    for (int i = 0; i != m_row; ++i) {
        while (head_p_that) {
        
        }
    }
}

template<typename T>
void linkedMatrix<T>::clear() {
    headElement *heap_p = head->next;
    while (heap_p) {
        valueElement *val_node_p = heap_p->firstNode;
        while (val_node_p) {
            valueElement *current_val_node = val_node_p->next;
            delete val_node_p;
            val_node_p = current_val_node;
        }
        headElement *del_head_p = heap_p;
        heap_p = heap_p->next;
        delete del_head_p;
    }
    std::cout << "this matrix is clear now" << '\n';
}

template<typename T>
void linkedMatrix<T>::zero() {
    m_size = 0;
}

template<typename T>
void linkedMatrix<T>::creat_matrix(triple<T> *&the_tri) {
    headElement *current_head = head;
    valueElement *val_node;
    for (int i = 0; i != m_size; ++i) {
        int val_row, val_col;
        T val;
        if (!the_tri[i].m_row) {
            std::cin >> val_row >> val_col >> val;
        }
        val_row = the_tri[i].m_row;
        val_col = the_tri[i].m_col;
        val = the_tri[i].m_val;
        if (val_row != current_head->row) {
            auto *temp_row_node = new headElement(val_row);
            current_head->next = temp_row_node;
            current_head = current_head->next;
            
            auto *first_val_node = new valueElement(val_col, val);
            current_head->firstNode = first_val_node;
            val_node = first_val_node;
            continue;
        }
        auto *p = new valueElement(val_col, val);
        val_node->next = p;
        val_node = val_node->next;
    }
}

#endif // LEARNING_CPP_STRUCT_MATRIX_LINKEDMATRIX_H_