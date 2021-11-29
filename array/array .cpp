//
// Created by wang on 2021/11/16.
//

#include <iostream>


int main(){
//    定义一个3*2的不规则数组
    int num_row = 3;
    int length_col[2] = {2,1};
    int **irregular_arr = new int* [num_row];

    for (int i = 0; i < num_row; ++i) {
        irregular_arr[i] = new int [length_col[i]];
    }
    irregular_arr[0][0] = 1;
    irregular_arr[0][1] = 4;
    irregular_arr[1][0]  =7;
    std::cout<< "第一行的元素是"<<'\n';
    for (int i = 0; i < length_col[0]; ++i) {
        std::cout << irregular_arr[0][i] << ' ';
    }
    std::cout << '\n';
    std::cout<< "第二行的元素是"<<'\n';
    for (int i = 0; i < length_col[1]; ++i) {
        std::cout << irregular_arr[1][i] << ' ';
    }
    return 0;
}