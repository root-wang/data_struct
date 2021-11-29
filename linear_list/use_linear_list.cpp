//
// Created by wang on 2021/11/26.
//
#include "Linear_list.cpp"
#include <iostream>

int main(){
    int a[5] = {1,2,3,4,5};
    Linear_list<int> time(5,5,a);
    for (int *pInt = a; pInt !=a+5 ; ++pInt) {
        std::cout << *pInt << '\n';
    }
    return 0;
}