#include <iostream>


template<typename T>
void Swap(T &a,T &b){
    T temp;
    temp = a;
    a = b;
    b = temp;
}

int main(){
    int a=9,b=2;
    Swap(a,b);
    float a1= 2.3,b1 = 2.5;
    Swap(a1,b1);
    char a2 = '2',b2 = 'y';
    Swap(a2,b2);
    std::cout<<a<<b<<'\n';
    std::cout<<a1<<b1<<'\n';
    std::cout<<a2<<b2<<'\n';
    return 0;
}