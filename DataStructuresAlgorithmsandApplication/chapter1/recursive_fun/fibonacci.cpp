//
// Created by wang on 2021/11/11.
//
// 本次尝试使用动态规划来设计斐波那契计算
//  即将每次计算F(i) 的结果保留
#include <iostream>
#define max 100

//弄一个表把计算过的数据记录
//把递归函数的出口条件判断改成表里的初始值
int table[max] {0,1};

int fibonacci(int n){
//    计算一开始的初始值
//    就是计算第一个需要计算的值F(2)
//    确保在1时返回 而下边刚好是计算的F(2)
    if (n==1){
        return 1;
    } else  {
//       0 1 2 3 4 5 6
//    从6开始逐步回溯到2 可以直接计算 然后开始向前进
        fibonacci(n-1);
//    这里把递归的函数改成了直接查表就没有了需要再把
//    每一个子计算当成一个新的函数入参
        table[n] = table[n-1]+table[n-2];
    }
//    可以从上边的表看到结果在最后一个位置存放
    return table[n];
}

int main(){
    int ans = fibonacci(6);
    std::cout << ans;
    return 0;
}
