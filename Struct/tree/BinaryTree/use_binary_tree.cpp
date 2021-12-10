//
// Created by wang on 2021/11/27.
//

//#include "Binary_tree.h"
#include "Binarytree_struct.h"
//#include "Binarytree_struct.cpp"


int main(){
    Binary_tree_node *root;
    creat_binary_tree(root);
//    std::cout<< "creat tree successfully" << '\n';
    pos_order_traversal(root);
//    std::cout << "mid order traversal is : \n";
//    std::cout << "pos order traversal is : \n";
//    pos_order_traversal_res(root);
//    int dep = node_count(root);
//    std::cout << dep;
    return 0;
}
