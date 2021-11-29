//
// Created by wang on 2021/11/20.
//

#include <iostream>

//顺序二叉树
#define MAX_SIZE 100

//结点元素结构定义
template<typename T>
struct element{
    T m_data;
};

//二叉树数组类型定义
typedef element<int> sq_binary_tree[MAX_SIZE];

//二叉树全局变量声明
//sq_binary_tree bt;

void creat_bt(sq_binary_tree &T){
    int i=0,len;
    std::cin>>len;
    while (i<len){
        int p =0;
        std::cin >> p;
        T[i].m_data = p;
        i++;
    }
}

int main(){
    sq_binary_tree bt;
    creat_bt(bt);
    return 0;
}