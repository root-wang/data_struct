#include <iostream>

//typedef struct student {
//    char m_num[8];
//    char m_name[8];
//    int m_score;
//    struct student *next;
//} *linkList, Lnode;

struct elemType {
//    char m_num[8];
//    char m_name[8];
    int m_score;
};

struct Lnode {
    elemType data;
    Lnode *next;
};

Lnode *m_initList() {
    Lnode *p, *head;
    head = new Lnode;
    p = head;

    int score;
    while (true) {
        std::cin >> score;
        if (score) {
            Lnode *temp = new Lnode;
            temp->data.m_score = score;
            p->next = temp;
            p = temp;
        } else {
            break;
        }
    }
    p->next = nullptr;
    p = head;
    return head;
}

int m_lengthL(Lnode *Lhead) {
    Lnode *p = Lhead;
    int len = 0;
    while (p->next != nullptr) {
        p = p->next;
        len++;
    }
    return len;
}

void m_printL(Lnode *Lhead) {
    Lnode *p = Lhead;
    while (p->next != nullptr) {
        std::cout << p->next->data.m_score << '\n';
        p = p->next;
    }
}

int main() {
    Lnode *Lhead = m_initList();
    m_printL(Lhead);
    int len = m_lengthL(Lhead);
    std::cout << len << '\n';
    return 0;
}