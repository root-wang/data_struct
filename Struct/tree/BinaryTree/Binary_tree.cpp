//
// Created by wang on 2021/11/19.
//

#include "Binary_tree.h"
#include <stack>
#include <queue>
#include <iostream>



void Binary_tree::pre_order_traversal(Binary_tree *T) const{
    if(!T)return;
    visit(T);
    pre_order_traversal(T->left_child);
    pre_order_traversal(T->right_child);
}

void Binary_tree::mid_order_traversal(Binary_tree *T) const{
    if(!T)return;
    pre_order_traversal(T->left_child);
    visit(T);
    pre_order_traversal(T->right_child);
}

void Binary_tree::pos_order_traversal(Binary_tree *T) const{
    if(!T)return;
    pre_order_traversal(T->left_child);
    pre_order_traversal(T->right_child);
    visit(T);
}

void Binary_tree::mid_order_traversal_non_recursive(Binary_tree *T) const{
    std::stack<Binary_tree> s1{};
    Binary_tree *p = T ;
    while (!s1.empty()||p){
        if(p){
            s1.push(*p);
        } else{
            visit(&s1.top());
            p = s1.top().right_child;
            s1.pop();
        }
    }
}

void Binary_tree::level_order_traversal(Binary_tree *T) const {
    std::queue<Binary_tree> q1;
    q1.push(*T);
    while (!q1.empty()){
        if(q1.front().left_child){
            q1.push(*q1.front().right_child);
        }
        if(q1.front().right_child){
            q1.push(*q1.front().right_child);
        }
        visit(&q1.front());
        q1.pop();
    }
}


