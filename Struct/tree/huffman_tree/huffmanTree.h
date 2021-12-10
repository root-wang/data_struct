#ifndef __HUFFMAN_TREE__
#define __HUFFMAN_TREE__
#include <iostream>

// 一维数组 顺序存储
struct Huffman_tree_node
{
  int m_weight;
  int parent, left_child, right_child;

  Huffman_tree_node() : m_weight(-1),
                        parent(0),
                        left_child(0),
                        right_child(0) {}
  ~Huffman_tree_node() {}
};
inline void min_two(int,
                    int,
                    int &,
                    int &,
                    Huffman_tree_node *&);

void creat_huffman_tree(Huffman_tree_node *&,
                        int *&,
                        int);
#endif __HUFFMAN_TREE__