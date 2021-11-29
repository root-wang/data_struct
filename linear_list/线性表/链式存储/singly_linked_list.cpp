#include <iostream>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef struct {
    int m_score;
} elemData;

typedef struct Lnode {
    elemData data;
    Lnode *next;
} Lnode, *LinkList;

//单链表初始化
int m_initList_L(LinkList &L) {
    L = new Lnode;
    L->next = nullptr;
    return OK;
}

//判断是否为空链表
//判断L的指针域是否为空(L为头指针)
bool m_isListEmpty(LinkList L) {
    if (L->next == nullptr) {
        return FALSE;
    } else {
        return TRUE;
    }
}

//单链表销毁
//  从头指针开始依次释放每个结点
int m_destroyList(LinkList &L) {
    Lnode *p;
    while (L != nullptr) {
        p = L;
        delete p;
        L = L->next;
    }
    return OK;
}

//清空单链表:
//      链表中无元素 但链表仍存在 称为空表
//算法思路:
//      依次释放所有结点 并将头结点指针域置空

//与之前不同的地方是保留了头指针
int m_clearList(LinkList &L) {
    Lnode *p, *q;
    p = L->next;// 将p置于首元结点
    q = p->next;//第一次q在首元结点的下一个结点
    while (p != nullptr) {
        delete p;//删除当前的p
        p = q;//把p移动到下一个结点 就是当前q的位置
        q = q->next;
    }
    L->next = nullptr;
    return OK;
}

//单链表求表长
// 算法思路:
//          从首元结点开始依次计数所有结点
int m_lengthList(LinkList L) {
    Lnode *p = L->next;
    int len = 0;
    while (p != nullptr) {
        len++;
        p = p->next;
    }
    return len;
}


//取值--取单链表中第i个元素
//算法思路:
//      顺着首元结点开始顺着链域next向后计数
//  index<0||index>=m_lengthList(L) return ERROR
int m_searchListByIndex(LinkList L, int index, elemData &ele) {
    //    if (index < 0 || index >= m_lengthList(L)) {
    //        return ERROR;
    //    } else {
    //        Lnode *p = L->next;
    //        int num = 0;
    //        while (true) {
    //            num++;
    //            p = p->next;
    //            if (num == index - 1) {
    //                ele = p->data;
    //                return OK;
    //            }
    //        }
    //    }
    Lnode *p = L;
    int num = 0;
    while (p && num < index) {// 搜索到了p或者index大于元素个数
        num++;
        p = p->next;
    }
    if (!p || num > index) {// index小于0 或者 L为空链表
        return ERROR;
    }
    ele = p->data;
    return OK;
}

//查找 :
//      1. 按值查找:根据数据查找获取数据地址
//      2. 按值查找:根据数据查找获取数据位序
int m_searchListByData(LinkList L, elemData eleInput, Lnode &pReturn) {
    Lnode *p = L->next;
    int num = 0;
    while (p != nullptr) {
        if (eleInput.m_score == p->data.m_score) {
            pReturn = *p;// 返回找到的地址
            return num;// 返回找到的位序
        }
        p = p->next;
        num++;
    }
    return FALSE;// 所有结点找完了没有找到
}


//插入--在第index个结点前插入值为ele的新结点
//算法步骤:
//      1. 找到第index-1的结点,保存该结点
//      2. 将输入结点保存在s
//      3.
//          ① s的next域链接p的next
//          ② p的next域链接s
int m_insertListByIndex(LinkList &L, elemData eleInput, int index) {
    Lnode *p = L->next, *s = new Lnode;
    int num = 0;
    while ((num < index - 1) && p) {
        p = p->next;
        num++;
    }
    if (!p || num > index) {
        return ERROR;
    }
    s->data = eleInput;
    s->next = p->next;
    p->next = s;
    return OK;
}

//删除第index的结点
int m_deleteListBuIndex(LinkList &L, int index) {
    Lnode *p = L->next, *q = new Lnode;
    elemData ele;
    int num = 0;
    while (p && num < index - 1) {
        p = p->next;
        num++;
    }
    if (!p || num > index - 1) {
        return ERROR;
    }
    q = p->next;//保存删除结点
    ele = q->data;
    p->next = p->next->next;//被删除结点的后继结点链接到p的后继
    delete q;
    return OK;
}

//单链表的建立-头插法
//  1. 从一个空表开始,重复读入数据
//  2. 生成新结点,将读入数据存放到新结点的数据域中
//  3. 从最后一个结点开始，依次将各结点插入到链表的前端
void m_creatLinkListFromTail(LinkList L, elemData a[], int len) {
    L->next = nullptr;
    int i = len;
    while (i--) {
        Lnode *p = new Lnode;
        p->data = a[i];
        p->next = L->next;
        L->next = p;
    }
}

//单链表的建立-尾插法
//  1. 从一个空表开始,将新结点逐个插入到链表的尾部 尾指针r指向链表的尾结点
//  2. 初始时,r同L均指向头结点.每读入一个数据则申请一个新结点,将新结点插入到尾结点后,r指向新结点
void m_creatLinkListFromHead(LinkList &L, elemData a[], int len) {
    L->next = nullptr;
    Lnode *r = L;
    int i = 0;
    while (i < len) {
        Lnode *p = new Lnode;
        p->data = a[i];
        //      p->next = nullptr;
        r->next = p;
        r = p;
        i++;
    }
    r->next = nullptr;
}

int main() {
    elemData a[5];
    for (int i = 0; i < 5; ++i) {
        std::cin >> a[i].m_score;
    }
    LinkList root = new Lnode;
    m_creatLinkListFromTail(root, a, 5);
    while (root->next) {
        std::cout << root->next->data.m_score << '\n';
        root = root->next;
    }
    return 0;
}