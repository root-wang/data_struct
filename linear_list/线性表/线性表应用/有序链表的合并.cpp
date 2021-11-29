#include <iostream>

typedef int T;

typedef struct {
    T ele_data;
} element;

typedef struct Lnode {
    element data;
    Lnode *next;
} Lnode, *link_list;

//采用头插法
link_list creat_list(int length) {
    if (length < 0) {
        throw "the length of list must >=0";
    }
    element *data = new element[length];
    for (int i = 0; i < length; ++i) {
        std::cin >> data[i].ele_data;
    }
    Lnode *L = new Lnode;
    L->next = nullptr;
    int i = length - 1;
    while (i >= 0) {
        Lnode *p = new Lnode;
        p->data = data[i];
        p->next = L->next;
        L->next = p;
        i--;
    }
    return L;
}

//有序表合并 已知线性表元素非递减
link_list insert_list(link_list La, link_list Lb) {
    Lnode *L_new = new Lnode;
    Lnode *p = L_new;
    La = La->next;
    Lb = Lb->next;
    while (La && Lb) {
        if (La->data.ele_data <= Lb->data.ele_data) {
            p->next = La;
            p = p->next;
            La = La->next;
        } else {
            p->next = Lb;
            p = p->next;
            Lb = Lb->next;
        }
    }
    if (La) {
        p->next = La;
    } else if (Lb) {
        p->next = Lb;
    }
    return L_new;
}

int main() {
    int length_la, length_lb;
    std::cin >> length_la >> length_lb;
    try {
        Lnode *La = creat_list(length_la);
        Lnode *Lb = creat_list(length_lb);
        Lnode *L_new = insert_list(La, Lb);
        Lnode *p = L_new;
        while (p->next) {
            std::cout << p->next->data.ele_data << '\n';
            p = p->next;
        }
    } catch (const char *e) {
        std::cout << "there just happened an error";
        std::cout << *e;
        exit(1);
    }
    return 0;
}