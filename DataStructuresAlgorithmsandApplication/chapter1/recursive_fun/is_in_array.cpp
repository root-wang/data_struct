//
// Created by wang on 2021/11/18.
//

#include <iostream>

typedef int T;

template<class T>
bool is_in_array(T a[], int len, T val) {
    if (val == a[len - 1]) {
        return true;
    } else if(len==1&&val!=a[len-1]){
        return false;
    } else {
        is_in_array(a, len - 1, val);
    }
}


int main() {
    T a[6] = {1, 2, 3, 4, 5, 6};
    std::cout<< is_in_array(a, 6, 2);
    return 0;
}