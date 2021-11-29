//
// Created by wang on 2021/11/11.
//
//这个计算斐波那契数列的递归方法会将已经计算过的某个值在
//计算其他值时再次计算 即将F(n) 分解成许多个F(1)和F(0) 但我们只需要计算一次某个
//F(i) 而我们需要它时再直接使用
//                          动态规划

#include <iostream>

int fibonacci(int n){
    if(n==1){
        return 1;
    } else if (n==0){
        return 0;
    } else{
        return fibonacci(n-1)+ fibonacci(n-2);
    }
}


int main(){
    int ans = fibonacci(3);
    std::cout << ans;
    return 0;
}