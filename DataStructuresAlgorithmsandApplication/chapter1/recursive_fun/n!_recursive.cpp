//
// Created by wang on 2021/11/11.
//

#include <iostream>

int factorial(int n){
    if(n<=1) return 1;
    else return (n)* factorial(n-1);
}

int main(){
    int n = 6;
    int ans = factorial(n);
    std::cout << ans;
}