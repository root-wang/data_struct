//
// Created by wang on 2021/11/11.
//

#include <iostream>
#include <iterator>

typedef char T;

template<class T>
void perm(T *a,int k,int m){
    if(k==m){
        std::copy(a,a+m+1,
                  std::ostream_iterator<T>(std::cout,""));
        std::cout<< std::endl;
    } else{
        for (int i = k; i < m; ++i) {
            std::swap(a[k],a[i]);
            perm(a,k+1,m);
            std::swap(a[i],a[k]);
        }
    }
}


int main(){
    T a[10] = {'a','b','c','d'};
    int n=4;
    perm(a,0,n);
    return 0 ;
}