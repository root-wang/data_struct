//
// Created by wang on 2021/11/14.
//

#include <iostream>
//#include <cmath>

long Ackermann_s_fun(int i,int j){
    if(1==i&&j>=1){
        return j+1;
    } else if(i>=2&&j==1){
        return Ackermann_s_fun(i-1,2);
    } else{
        return Ackermann_s_fun(i-1, Ackermann_s_fun(i,j-1));
    }
}

int main(){
    int i = 4, j= 3;
    long ans = Ackermann_s_fun(i,j);
    std::cout << ans;
    return 0;
}