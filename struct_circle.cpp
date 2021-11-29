#include <iostream>

const double pi = 3.14;
//todo: 圆的数据结构:
//              数据对象:半径r x y 圆心坐标 double型
//              数据关系:
//              基本操作:



struct Circle{
    double m_x=0,m_y=0,m_r=0;
};

//    1.初始化一个圆: Circle(&C,r,x,y){
//        边界条件(r<=0)    返回异常
int m_initCircle(Circle &C,double r,double x,double y){
    if (r<=0){
        std::cout << "the round must bigger than 0 \n";
        return 0 ;
    } else{
        C.m_r = r;
        C.m_x = x;
        C.m_y = y;
        return 1;
    }
}
//   2.计算面积: double area(C){
//       判断是否是一个圆
//       返回圆的面积
double m_area(Circle C){
    if (C.m_r <= 0){
        std::cout << "the round must bigger than 0 \n";
        return 0;
    } else{
        return pi*C.m_r*C.m_r;
    }
}


//    3.计算周长: double circumference(C){
//                       判断是否是一个圆
//                       返回圆的周长
double m_circumference(Circle C){
    if (C.m_r <= 0){
        std::cout << "the round must bigger than 0 \n";
        return 0;
    } else{
        return pi*2*C.m_r;
    }
}
int main() {
    Circle C;
    double x,y,r;
    std::cin >> x>>y>>r;
    m_initCircle(C,r,x,y);
//    std::cout << C.m_x << C.m_y <<C.m_r << std::endl;
    double area = m_area(C);
    std::cout << area <<'\n';
    double circumference = m_circumference(C);
    std::cout << circumference <<'\n';
    return 0;
}
