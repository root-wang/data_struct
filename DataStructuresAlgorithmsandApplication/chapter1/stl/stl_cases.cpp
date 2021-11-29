//
// Created by wang on 2021/11/18.
//

#include <iostream>
#include <numeric>
#include <vector>

typedef int T;

//计算累加和
template<class T>
T sum(T a[], int len) {
    T the_sum = 0;
    return std::accumulate(a, a + len, the_sum);
}

//计算累乘积
template<class T>
T the_multiplies(T a[],int len){
    T the_multiplies = 1;
    return std::accumulate(a,a+len,the_multiplies, std::multiplies<T>());
}

//复制


int main() {
    T a[4] = {1, 2, 3, 4};
    std::cout << sum(a, 4);
    std::cout << '\n';
    std::cout << the_multiplies(a,4);
    return 0;
}