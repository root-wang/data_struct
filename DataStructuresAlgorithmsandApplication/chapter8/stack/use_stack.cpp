//
// Created by wang on 2021/11/13.
//

#include "arrayStack.cpp"
#include <iostream>

typedef long T;

int main() {
  array_stack<T> time(5);
  T a[5]{1, 2, 3, 4, 5};
  for (long &i : a) {
    time.push(i);
    std::cout << time.is_empty() << '\n';
  }
  std::cout << time.is_full() << '\n';
  T coco;
  for (int i = 0; i < 5; ++i) {
    time.pop(coco);
    std::cout << coco << '\n';
  }
  std::cout << time.is_empty() << '\n';
  return 0;
}