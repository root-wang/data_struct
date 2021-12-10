//
// Created by wang on 2021/11/26.
//
#include "Linear_list.cpp"
#include <iostream>

int main() {
    int              a[5] = {1, 2, 3, 4, 5};
    int              b[5] = {1, 2, 3, 4, 2};
    Linear_list<int> time(5, 5, a);
    Linear_list<int> tree(6, 5, b);
    bool             ans  = time != tree;
    std::cout << ans;
    return 0;
}