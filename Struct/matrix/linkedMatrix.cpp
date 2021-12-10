//
// Created by ROOT_WANG on 2021/12/13.
//

#include "linkedMatrix.h"
#include<ctime>
//122 312 53
//784 23 442
//1543 345 243
//2993 4854 123

//422 3112 233
//1324 2233 1442
//2343 3445 223
//2493 4234 1323
int main(){
    triple<int> *input1 = new triple<int>[400];
    triple<int> *input2 = new triple<int>[400];
    
    for (int i = 0; i != 400; ++i) {
        input1[i].m_row = i+30000;
        input2[i].m_row = i+2341;
        input1[i].m_col = i+3231;
        input2[i].m_col = i+12431;
        input1[i].m_val = 13221;
        input2[i].m_val = 131;
    }
    
    clock_t startTime,endTime,startTime_1,endTime_1;
    int zero = 0;
    linkedMatrix<int> tig(400,50000,50000,zero);
    tig.creat_matrix(input1);
    
    linkedMatrix<int> fig(400,50000,50000,zero);
    fig.creat_matrix(input2);
    
    int **array = new int*[50000];
    for (int i = 0; i != 50000; ++i) {
        array[i]  = new int[50000];
    }
    
    for (int i = 0; i != 50000; ++i) {
        for (int j = 0; j != 50000; ++j) {
            array[i][j]=0;
        }
    }
    
    for (int i = 0; i != 400; ++i) {
        array[i+302][i+234] = 2345;
    }
    
    startTime = clock();
    for (int i = 0; i != 50000; ++i) {
        for (int j = 0; j != 50000; ++j) {
            array[i][j] = array[i][j]+array[i][j];
        }
    }
    endTime = clock();
    std::cout << "The run time is:" <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << '\n';
    
    startTime = clock();
    linkedMatrix<int>add_ = tig+fig;
    std::cout << "tig + fig " << '\n';
    endTime = clock();
    std::cout << "The run time is:" <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << '\n';
    
    add_.output();

    return 0;
}