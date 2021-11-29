//
// Created by wang on 2021/11/18.
//

#include <iostream>

void select_sort(int *&a,int len){
    for (int i = 0; i < len; ++i) {
        int max_index = 0,max = a[0];
        for (int j = 0; j < len-i; ++j) {
            if(max<a[j]) {
                max = a[j];
                max_index = j;
            }
        }
        std::swap(a[max_index],a[len-i-1]);
    }
}


int main(){
    int *a = new int[5]{4,9,126,5,2};
    select_sort(a,5);
    for (int i = 0; i < 5; ++i) {
        std::cout << a[i] << '\n';
    }
}