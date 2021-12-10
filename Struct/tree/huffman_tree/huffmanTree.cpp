#include "huffmanTree.h"

// root长为2*num-1;
void creat_huffman_tree(Huffman_tree_node *&tree, int *&the_weight, int num) {
  for (int i = 0; i != num; ++i) {
    tree[i].m_weight = the_weight[i];
  }
  for (int i = 0; i != num - 1; ++i) {
    int min1_index = 0, min2_index = 0;
    min_two(num, i, min1_index, min2_index, tree);
    tree[num + i].m_weight =
        tree[min1_index].m_weight + tree[min2_index].m_weight;
    tree[num + i].left_child = min1_index;
    tree[num + i].right_child = min2_index;
    tree[num + i].parent = 0;
    tree[min1_index].parent = tree[min2_index].parent = num + i;
  }
}

void min_two(int num, int new_node_index, int &min1_index, int &min2_index,
             Huffman_tree_node *&tree) {
  int min1_weight = 10000;
  int min2_weight = 10000;
  for (int j = 0; j != num + new_node_index; ++j) {
    if (!tree[j].parent && tree[j].m_weight < min1_weight &&
        tree[j].m_weight < min2_weight) {
      // 在取得最小元素之前需要将最小元素的
      // 属性赋给次小元素才能保证保留次小元素
      min2_index = min1_index;
      min2_weight = min1_weight;
      min1_index = j;
      min1_weight = tree[j].m_weight;
    } else if (!tree[j].parent && tree[j].m_weight < min2_weight) {
      min2_index = j;
      min2_weight = tree[j].m_weight;
    }
    // std::cout << min1_index << ' ' << min2_index << "\n";
  }
}