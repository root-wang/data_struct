//
// Created by wang on 2021/11/14.
//

#include <iostream>

int gcd(int x,int y){
    if(y==0){
        return x;
    } else if(x==0){
        return y;
    } else{
        return gcd(y,x%y);
    }
}

int main(){
    int ans = gcd(30,20);
    std::cout <<ans;
}