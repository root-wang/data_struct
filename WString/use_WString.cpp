//
// Created by wang on 2021/11/15.
//
#include <iostream>
#include "WString.h"
#include <windows.h>

using namespace std;


int main(){
    WString tin("waeeng i0 ee");
    WString took("ee");
    WString love('0');
//    tin.concat(took);
    DWORD begin = GetTickCount();
    cout << tin.indexOf_BF(took,5) << '\n';
    DWORD end    = GetTickCount();
//    cout <<(end-begin)<< '\n';
    return 0;
}