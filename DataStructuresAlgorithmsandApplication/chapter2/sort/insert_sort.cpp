//
// Created by wang on 2021/11/18.
//

#include <iostream>

void insert(int *a,int len, const int x){
    int i ;
    for (i = len-1; i>=0&&x<a[i] ; i--) {
        a[i+1] = a[i];
    }
    a[i+1]  =x;
}

void insert_sort(int *a,int len){
    for (int i = 0; i < len; ++i) {
        insert(a,i+1,a[i+1]);
    }
}


int main(){
    int *a = new int[5]{3,4,1,5,2};
    insert_sort(a,5);
    for (int i = 0; i < 5; ++i) {
        std::cout << a[i] << '\n';
    }
    return 0;
}