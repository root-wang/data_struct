#include "huffmanTree.h"
#include <iostream>

int main(int argc, char const *argv[]) {
  int num = 8;
  Huffman_tree_node *huffman_tree = new Huffman_tree_node[2 * num - 1];
  int *the_weight = new int[num]{7, 19, 2, 6, 32, 3, 21, 10};
  creat_huffman_tree(huffman_tree, the_weight, num);
  for (int i = 0; i != 2 * num - 1; ++i) {
    std::cout << i << " :" << huffman_tree[i].m_weight << ' '
              << huffman_tree[i].parent << ' ' << huffman_tree[i].left_child
              << ' ' << huffman_tree[i].right_child << ' ' << '\n';
  }
  return 0;
}