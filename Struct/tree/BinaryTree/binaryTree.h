//
// Created by wang on 2021/11/19.
//

#ifndef LEARNING_BINARY_TREE_H
#define LEARNING_BINARY_TREE_H

#include <iostream>


// 二叉树的根
class Binary_tree {
private:
    char m_data{};
    Binary_tree *left_child,
                *right_child;
    static void visit(Binary_tree *T){
        std::cout << T->m_data << '\n';
    };
public:
//    构造函数
    Binary_tree() {
        left_child = nullptr;
        right_child = nullptr;
    }

//    生成数据结点
    explicit Binary_tree(const char &the_element) :
            m_data(the_element),
            left_child(nullptr),
            right_child(nullptr) {}


//    拷贝函数
    Binary_tree(const Binary_tree &x) {
        m_data = x.m_data;
        left_child = x.left_child;
        right_child = x.right_child;
    }

//  创建二叉树
    void creat_tree(Binary_tree *p) {
        char ch;
        std::cin >> ch;
        if ('#' == ch) {
            p = nullptr;
        } else {
            p = new Binary_tree(ch);
            creat_tree(p->left_child);
            creat_tree(p->right_child);
        }
    }

//    前序遍历
    void pre_order_traversal(Binary_tree *T) const;

//    中序遍历
    void mid_order_traversal(Binary_tree *T) const;

//    后序遍历
    void pos_order_traversal(Binary_tree *T) const;

//    非递归中序遍历
    void mid_order_traversal_non_recursive(Binary_tree *T) const;

//    层次遍历
    void level_order_traversal(Binary_tree *T) const;
};


#endif //LEARNING_BINARY_TREE_H
