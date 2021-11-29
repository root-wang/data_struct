#include <iostream>

/*todo:
 * 1. 加减乘除 四则运算
 * 2. 除法判断分母是否为零
 * 3. 指针 和 引用
 */
struct Complex {
    double m_r = 0, m_i = 0;
};

struct ComplexList {
    Complex Com[101];
    int m_len = 0;
};

//  m_assign(&C,r,i){
//       是否有已经存在的复数
//       初始化复数赋值r i
int m_assign(ComplexList &C, double r, double i) {

    for (int j = 0; j < C.m_len; j++) {
        if (C.Com[j].m_r == r && C.Com[j].m_i == i) {
            std::cout << "the complex " << C.Com[j].m_r << '+' << C.Com[j].m_i << 'i' << " is already exist\n";
            return -1;
        }
    }
    C.Com[C.m_len].m_i = i;
    C.Com[C.m_len].m_r = r;
    C.m_len++;
    return 0;
}

//   m_destroy(&C){
//       是否存在C
//       将成员数据清零
//   [1+2i,2+3i,3+2i] m_len = 3, index must <=2
int m_destroy(ComplexList &C, int index) {
    if (index > C.m_len - 1) {
        std::cout << "the index of Com is not exist\n";
        return -1;
    } else {
        C.Com[index].m_r = 0;
        C.Com[index].m_i = 0;
        return 0;
    }
}

//    m_getReal(&C){
//            是否存在C
//            返回C.m_r

double m_getReal(ComplexList &CList, int index) {
    if (index > CList.m_len - 1) {
        std::cout << "the index of Com is not exist\n";
        return -1;
    } else {
        return CList.Com[index].m_r;
    }
}

//    m_getImag(&C){
//        是否存在C
//        返回C.m_i
double m_getImag(ComplexList &CList, int index) {
    if (index > CList.m_len - 1) {
        std::cout << "the index of Com is not exist\n";
        return -1;
    } else {
        return CList.Com[index].m_i;
    }
}


int main() {
    using namespace std;
    ComplexList CList;
    double r, i;
    int complexNum;
    cout << "plz enter the number of complex\n";
    std::cin >> complexNum;
    for (int j = 0; j < complexNum; ++j) {
        std::cin >> r >> i;
        m_assign(CList, r, i);
    }
    std::cout << CList.m_len << '\n';
    for (int j = 0; j < CList.m_len; ++j) {
        std::cout << CList.Com[j].m_r << ' ' << CList.Com[j].m_i << '\n';
    }
    return 0;

}

