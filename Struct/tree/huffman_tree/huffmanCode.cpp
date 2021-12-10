#include "huffmanTree.h"
#include <algorithm>
#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
  std::string s("1234rfe");
  std::reverse(s.begin(), s.end());
  std::cout << s;
  return 0;
}