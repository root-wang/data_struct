//
// Created by wang on 2021/12/9.
//

#include "chain.cpp"
#include <iostream>

int main()
{
    int len = 50000;
    Chain<int> time(len);
    Chain<int> git(len);
    
    time.push_back(1);//0
    time.push_back(1);//1
    time.push_back(1);//2
    time.push_back(1);//3
    time.push_back(1);//4
    time.push_back(1);//5
    time.push_back(1);//6
    
    git.push_back(0);//0
    git.push_back(0);//1
    git.push_back(0);//2
//    git.push_back(0);//3
//    git.push_back(0);//4
//    git.push_back(0);//5
//    git.push_back(0);//6

    Chain<int> meld ;
    meld = time.meld(git);
    meld.output();
    return 0;
}