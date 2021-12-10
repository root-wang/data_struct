#include "Huffman_tree.h"
#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char const *argv[])
{
  std::string s("1234rfe");
  std::reverse(s.begin(), s.end());
  std::cout << s;
  return 0;
}