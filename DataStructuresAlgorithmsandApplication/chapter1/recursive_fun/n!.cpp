//
// Created by wang on 2021/11/11.
//

#include <iostream>

int factorial(int n){
    long ans = 1;
    for (int i = 1; i <= n; ++i) {
        ans *= i;
    }
    return ans;
}

int main(){
    int n = 5;
    int ans = factorial(n);
    std::cout << ans;
}