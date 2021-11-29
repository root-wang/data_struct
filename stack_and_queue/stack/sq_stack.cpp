#include <iostream>

#define MAXSIZE 1000

typedef struct {
    int m_score;
} element;

typedef struct sq_stack {
    element *top{}, *base{};
//    栈的最大空间
    int stack_size = 0;
} sq_stack;

int init_stack(sq_stack &S);
int destroy_stack(sq_stack &S);
bool is_empty(const sq_stack &S);
int length_stack(const sq_stack &S);
int get_top(const sq_stack &S, element &e);
int clear_stack(sq_stack &S);
int push(sq_stack &S, const element &e);
int pop(sq_stack &S,element &e);

int main(){
    sq_stack time;
    init_stack(time);
    element erase[5];
    for (int i = 0; i < 5; ++i) {
        erase[i].m_score = i*i;
    }
    for (element & i : erase) {
        push(time,i);
    }
    std::cout << is_empty(time) << '\n';

    std::cout << length_stack(time) << '\n';

    element out;
    get_top(time,out);
    std::cout << out.m_score << '\n';
    std::cout << length_stack(time) <<'\n';

    pop(time,out);
    std::cout << out.m_score << '\n';
    std::cout << length_stack(time) << '\n';

    destroy_stack(time);
    std::cout << length_stack(time) <<'\n';
}

//  1. init_stack(&S) 初始化操作
//       操作结果 构造一个空栈S
int init_stack(sq_stack &S) {
//    为栈分配数组空间
    S.base = new element[MAXSIZE];
//    分配内存失败
    if (!S.base) exit(0);

    S.top = S.base;
    S.stack_size = MAXSIZE;
    return 1;
}

//
//
//  2. destroy_stack(&S) 销毁栈
//       初始条件: 栈S存在
//       操作结果: 栈S销毁
int destroy_stack(sq_stack &S) {
    if (S.base) {
        delete S.base;
        S.base = S.top = nullptr;
//        S.stack_size = 0;
    }
}

//  3. stack_is_empty(S) 判断S是否为空栈
//       初始条件: 栈S已存在
//       操作结果: 若为空栈则返回true 否则false
bool is_empty(const sq_stack &S) {
    if (S.base == S.top)
        return true;
    else
        return false;
}

//  4. length_stack(S) 求栈长度
//       初始条件: 栈S存在
//       操作结果: 返回S的元素个数
int length_stack(const sq_stack &S) {
    return (int)(S.top - S.base);
}

//  5. get_top(S,&e) 取栈顶元素
//       初始条件: 栈S存在且不为空
//       操作结果: 用e返回S的栈顶元素
int get_top(const sq_stack &S, element &e){
    if(S.base){
        e = *(S.top-1);
        return 1;
    } else return 0;
}

//  6. clear_stack(&S) 栈置空
//       初始条件: 栈S存在
//       操作结果: 将S清为空栈
int clear_stack(sq_stack &S) {
    if (S.base) S.top = S.base;
    return 1;
}

//  7. push(&S,e) 入栈
//       初始条件: 栈S存在且没满
//       操作结果: 插入e元素为新的栈顶元素
int push(sq_stack &S, const element &e) {
    if(S.top-S.base>=MAXSIZE){
        exit(-1);
    }
    else if (S.base) {
        *S.top = e;
        S.top++;
//        S.stack_size++;
        return 1;
    } else return 0;
}
//  8. pop(&S,&e) 出栈
//       初始条件: 栈S存在且不为空
//       操作结果: 删除S的栈顶元素an,并用e返回
element pop(sq_stack &S){
    if(S.top==S.base){
        exit(-2);
    } else{
        S.top--;
        return *S.top;
    }
}

