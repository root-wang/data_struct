//
// Created by wang on 2021/11/11.
//

#include <iostream>

template<class T>
T rsum(T a[],int n){
    if(n>0){
        return rsum(a,n-1)+a[n-1];
    }
    return 0;
}