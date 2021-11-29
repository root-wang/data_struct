//
// Created by wang on 2021/11/19.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

//实现对顺序表元素累加求和
//  begin是顺序表求和的首元素的地址
//  end  是顺序表求和的尾元素的下一个位置的地址
//  initial_value
//       是求和的初始值
template<typename T>
T w_accumulate(T *begin,T *end,T initial_value){
    T *p = begin;
    static T the_sum = initial_value;
    while (p!=end){
        the_sum += *p;
        p++;
    }
    return the_sum;
}


int main(){
    int b[] = {1,2,3,4,5};
    int init_val = 0;
//    int ans = w_accumulate(b,b+5,init_val);
    int ans = std::accumulate(b,b+5,1,std::multiplies<int>());
    std::cout << ans;
    return 0;
}