#include <iostream>

typedef struct {
    int m_score;
} element_data;

typedef struct Lnode {
    element_data m_data;
    Lnode *next;
} Lnode, *link_list;

//带尾指针的循环链表合并
link_list connect(link_list Ta, link_list Tb) {
//    ta和tb都是空链表
    if (Ta->next == Ta && Tb->next == Tb) {
        throw "Ta or Tb must be not empty!";
    }

    Lnode *p = new Lnode;
    p = Ta->next;
    Ta->next = Tb->next->next;
    delete Tb->next;
    Tb->next = p;
    return Tb;
}