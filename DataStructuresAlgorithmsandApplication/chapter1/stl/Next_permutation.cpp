//
// Created by wang on 2021/11/18.
//

#include <iostream>
#include <algorithm>
#include <vector>

typedef int T;

template<class T>
void permutations(T list[],int k,int m){
//    生成list[k:m]的所有排列
    do {
        std::copy(list+k,list+k+m+1,
                  std::ostreambuf_iterator<T>(std::cout," "));
    } while (std::next_permutation(list+k,list+k+m+1));
}

int main(){

}