//
// Created by wang on 2021/11/14.
//

#include <iostream>

//递归版本
int fun_recursive(int n){
    if(n%2==0){
        return n/2;
    } else{
        return fun_recursive(3*n+1);
    }
}

int fun(int n){
    if (n%2==0){
        return n/2;
    } else{
        return (3*n+1)/2;
    }
}

int main(){
    int ans = fun(5);
    std::cout << ans;
}