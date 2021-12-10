//
// Created by wang on 2021/11/17.
//
#include <iostream>
#include "matrix.cpp"

int main() {
    Matrix<int> time(3, 3);
    for (int i = 1; i != 4; ++i)
        for (int j = 1; j != 4; ++j) {
            int val = i + j;
            time(i, j) = val;
        }
//    time.output();
    Matrix<int> git(3, 3);
    git = time;
    time.output();
    return 0;
}