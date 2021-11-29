//
// Created by wang on 2021/11/18.
//

#include <iostream>

using namespace std;

string gray_code(int n){
    if(1==n){
       string str0 = "1";
        return str0;
    } else{
        return gray_code(n-1)+to_string(n)+ gray_code(n-1);
    }
}

int main(){
    string ans = gray_code(3);
    cout<<ans;
}