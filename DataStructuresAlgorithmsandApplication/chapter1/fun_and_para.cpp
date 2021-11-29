#include <iostream>

int abc(int a, int b, int c) {
    return a + b * c;
}

typedef float T;//定义T的数据类型

//函数模板参数类型是一个变量
template<class T>
const T &abc(const T &a, const T &b, const T &c, T &ans) {//常量引用
    ans = a + b * c;
    return ans;
}

//一个更通用的版本
template<class Ta, class Tb, class Tc>
Ta abc(const Ta &a, const Tb &b, const Tc &c) {
    return a + b * c;
}

int main() {
    T a, b, c, ans;
    std::cin >> a >> b >> c;
    abc(a, b, c, ans);
//    ans = 2;
    std::cout << a << '\n';
    std::cout << ans;
    return 0;
}