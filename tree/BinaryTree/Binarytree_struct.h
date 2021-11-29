//
// Created by wang on 2021/11/28.
//

#ifndef LEARNING_BINARYTREE_STRUCT_H
#define LEARNING_BINARYTREE_STRUCT_H

#include <iostream>
#include <queue>
#include <stack>

struct Binary_tree_node {
    char m_data;
    Binary_tree_node *left_child,
            *right_child;

    void visit() const {
        std::cout << m_data
                  << '\n';
    }
};

//创建二叉树
void creat_binary_tree(Binary_tree_node *&p) {
    char data;
    std::cin >> data;
    if (data == '#') p = nullptr;
    else {
        p = new Binary_tree_node;
        p->m_data = data;
        creat_binary_tree(p->left_child);
        creat_binary_tree(p->right_child);
    }
}

//复制二叉树
int Binary_tree_copy(Binary_tree_node *T,
                     Binary_tree_node *&NewT) {
    if (T == nullptr) {
        NewT = nullptr;
        return 0;
    } else {
        NewT = new Binary_tree_node;
        NewT->m_data = T->m_data;
        Binary_tree_copy(T->left_child,
                         NewT->left_child);
        Binary_tree_copy(T->right_child,
                         NewT->right_child);
    }
}

//前序遍历
void pre_order_traversal(Binary_tree_node *p) {
    if (p) {
        p->visit();
        pre_order_traversal(p->left_child);
        pre_order_traversal(p->right_child);
    }
}

//中序遍历_递归
void mid_order_traversal_res(Binary_tree_node *p) {
    if (p) {
        mid_order_traversal_res(p->left_child);
        p->visit();
        mid_order_traversal_res(p->right_child);
    }
}

//非递归中序遍历
void mid_order_traversal(Binary_tree_node *p) {
    std::stack<Binary_tree_node> s1{};
    Binary_tree_node *tmp = p;
    while (!s1.empty() || tmp) {
        if (tmp) {
            s1.push(*tmp);
            tmp = tmp->left_child;
        } else {
            s1.top().visit();
            tmp = s1.top().right_child;
            s1.pop();
        }
    }
}

//后序遍历
void pos_order_traversal_res(Binary_tree_node *p) {
    if (p) {
        pos_order_traversal_res(p->left_child);
        pos_order_traversal_res(p->right_child);
        p->visit();
    }
}

//非递归后序遍历
void pos_order_traversal(Binary_tree_node *root) {
    std::stack<Binary_tree_node> s_node;
    std::stack<bool> s_flag;
    Binary_tree_node *p = root;
    while (p || !s_node.empty()) {
        while (p) {
            s_node.push(*p);
            s_flag.push(false);
            p = p->left_child;
        }
        if (s_flag.top() == true) {
            s_node.top().visit();
            s_node.pop();
            s_flag.pop();
            p = nullptr;
        }
        else {
            s_flag.pop();
            s_flag.push(true);
            p = s_node.top().right_child;
        }
    }
}

//层次遍历
void level_order_traversal(Binary_tree_node *p) {
    std::queue<Binary_tree_node> q1;
    q1.push(*p);
    while (!q1.empty()) {
        q1.front().visit();
        if (q1.front().left_child) {
            q1.push(*q1.front().left_child);
        }
        if (q1.front().right_child) {
            q1.push(*q1.front().right_child);
        }
        q1.pop();
    }
}

//求二叉树深度
int depth(Binary_tree_node *&T) {
    if (T == nullptr) return 0;
    else {
        int m = depth(T->left_child);
        int n = depth(T->right_child);
        if (m > n) return (m + 1);
        else return (n + 1);
    }
}

//求二叉树结点个数
int node_count(Binary_tree_node *T) {
    if (T == nullptr)return 0;
    else {
        return node_count(T->left_child) +
               node_count(T->right_child) +
               1;
    }
}

//求二叉树叶子结点数
int leaf_count(Binary_tree_node *T) {
//    如果是空树返回0
    if (T == nullptr)return 0;
//    如果是叶子结点返回1
    if (T->right_child == nullptr &&
        T->left_child == nullptr) {
        return 1;
    } else {
        return leaf_count(T->left_child) +
               leaf_count(T->right_child);
    }
}

#endif //LEARNING_BINARYTREE_STRUCT_H
