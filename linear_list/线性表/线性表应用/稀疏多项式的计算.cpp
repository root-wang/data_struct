#include <iostream>

// 稀疏多项式的计算
// 多项式的存储方式为线性表
// 考虑使用链式存储
//      1. element_data存放系数和指数
//      2. link_list存储一个多项式

typedef struct {
    double m_coe;
    int m_exp;
} element_data;

typedef struct Lnode {
    element_data m_data;
    Lnode *next;
} *link_list, Lnode;

link_list creat_list(int length);

Lnode *add_list(link_list &la, link_list &lb);
//TODO:还有乘法计算

int main() {
    int length_la, length_lb;
    std::cin >> length_la >> length_lb;
    link_list la = creat_list(length_la);
    link_list lb = creat_list(length_lb);
    link_list L = add_list(la, lb);
    Lnode *p = L->next;
    while (p) {
        std::cout << p->m_data.m_coe << ' ' << p->m_data.m_exp << '\n';
        p = p->next;
    }
    return 0;
}

link_list creat_list(int length) {
    Lnode *L = new Lnode;
    L->next = nullptr;
    double *coe = new double[length];
    int *exp = new int[length];
    for (int i = 0; i < length; ++i) {
        std::cin >> coe[i] >> exp[i];
    }
    int i = length - 1;
    while (i >= 0) {
        Lnode *p = new Lnode;
        p->m_data.m_coe = coe[i];
        p->m_data.m_exp = exp[i];
        p->next = L->next;
        L->next = p;
        i--;
    }
    return L;
}

link_list add_list(link_list &la, link_list &lb) {
    la = la->next;
    lb = lb->next;
    Lnode *L = new Lnode;
    Lnode *p = L;
    while (la && lb) {
        if (la->m_data.m_exp == lb->m_data.m_exp) {
            if (0 == la->m_data.m_coe + lb->m_data.m_coe) {
                Lnode *temp1 = la;
                Lnode *temp2 = lb;
                la = la->next;
                lb = lb->next;
                delete temp1;
                delete temp2;
                continue;
            } else {
                la->m_data.m_coe = la->m_data.m_coe + lb->m_data.m_coe;
                p->next = la;
                p = p->next;
                la = la->next;
                lb = lb->next;
            }
        } else if (la->m_data.m_exp < lb->m_data.m_exp) {
            p->next = la;
            p = p->next;
            la = la->next;
            continue;
        } else if (la->m_data.m_exp > lb->m_data.m_exp) {
            p->next = lb;
            p = p->next;
            lb = lb->next;
            continue;
        }
    }
    if (la) {
        p->next = la;
    }
    if (lb) {
        p->next = la;
    }
    return L;
}