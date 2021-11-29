#include <iostream>

#define MAXSIZE 1000

typedef struct {
    int m_score;
} element;

typedef struct stack_node {
    element m_data;
    stack_node *next;
} stack_node, *link_stack;

int init_stack(link_stack &S);

int destroy_stack(link_stack &S);

bool is_empty(link_stack S);

int length_stack(link_stack S);

element get_top(link_stack S);

int clear_stack(link_stack &S);

int push(link_stack &S, element e);

element pop(link_stack &S);

int main() {
    link_stack time;
    init_stack(time);
    element erase[5];
    for (int i = 0; i < 5; ++i) {
        erase[i].m_score = i * i;
    }
    for (element &i : erase) {
        push(time, i);
    }
    std::cout << is_empty(time) << '\n';

    std::cout << length_stack(time) << '\n';

    element out;
    out = get_top(time);
    std::cout << out.m_score << '\n';
    std::cout << length_stack(time) << '\n';

    out = pop(time);
    std::cout << out.m_score << '\n';
    std::cout << length_stack(time) << '\n';

    destroy_stack(time);
    std::cout << length_stack(time) << '\n';
}

//  1. init_stack(&S) 初始化操作
//       操作结果 构造一个空栈S
int init_stack(link_stack &S) {
//    构造一个空栈
    S = nullptr;
    return 1;
}

//  2. destroy_stack(&S) 销毁栈
//       初始条件: 栈S存在
//       操作结果: 栈S销毁
int destroy_stack(link_stack &S) {
    delete S;
//        S.stack_size = 0;

}

//  3. stack_is_empty(S) 判断S是否为空栈
//       初始条件: 栈S已存在
//       操作结果: 若为空栈则返回true 否则false
bool is_empty(link_stack S) {
    if (S == nullptr)return true;
    else return false
}

//  4. length_stack(S) 求栈长度
//       初始条件: 栈S存在
//       操作结果: 返回S的元素个数
int length_stack(link_stack S) {
    int len = 0;

}

//  5. get_top(S,&e) 取栈顶元素
//       初始条件: 栈S存在且不为空
//       操作结果: 用e返回S的栈顶元素
element get_top(link_stack S) {
    if(S == nullptr){
        throw "the stack is empty";
    } else{
        return S->m_data;
    }
}

//  6. clear_stack(&S) 栈置空
//       初始条件: 栈S存在
//       操作结果: 将S清为空栈
int clear_stack(link_stack &S) {
    if (S) S = nullptr;
    return 1;
}

//  7. push(&S,e) 入栈
//       初始条件: 栈S存在且没满
//       操作结果: 插入e元素为新的栈顶元素
int push(link_stack &S, element e) {
    if (S) {
        stack_node *p = new stack_node;
        p->m_data = e;
        p->next = S;
        S = p;
        return 1;
    } else
        return 0;
}

//  8. pop(&S,&e) 出栈
//       初始条件: 栈S存在且不为空
//       操作结果: 删除S的栈顶元素an,并用e返回
element pop(link_stack &S) {
    if(S){
        element e = S->m_data;
        stack_node *temp = S;
        S = S->next;
        delete temp;
        return e;
    } else if(S== nullptr){
        throw "the stack is empty";
    }
}

