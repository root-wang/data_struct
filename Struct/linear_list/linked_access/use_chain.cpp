//
// Created by wang on 2021/12/9.
//

#include "chain.cpp"
#include <iostream>

int main()
{
    int len = 50000;
    Chain<int> time(len);
    time.push_back(5);
    time.push_back(3);
    time.push_back(4);
    time.push_back(1);
    time.bin_sort(5);
    time.output();

    return 0;
}