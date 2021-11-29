#include <iostream>

typedef struct {
    int m_socre;
} T;

template<class T>
T *creat_T(int T_length) {
    T *L = new T[T_length];
    for (int i = 0; i < T_length; ++i) {
        int input;
        std::cin >> input;
        L[i].m_socre = input;
    }
    return L;
}

int insert_T(T *&La, int la_length, T *&Lb, int lb_length) {
    static int index_add = la_length;
    for (int i = 0; i < lb_length; ++i) {
        int flag_appear = 0;
        for (int j = 0; j < la_length; ++j) {
            if (Lb[j].m_socre == La[i].m_socre) {
                flag_appear = 1;
                break;
            }
        }
        if (!flag_appear) {
            La[index_add++].m_socre = Lb[i].m_socre;
        }
    }
    delete[] Lb;
    return index_add;
}

int main() {
    int la_length, lb_length;
    std::cin >> la_length >> lb_length;
    T *La = creat_T<T>(la_length);
    T *Lb = creat_T<T>(lb_length);
    int length_add = insert_T(La, la_length, Lb, lb_length);
    for (int i = 0; i < length_add; ++i) {
        std::cout << La[i].m_socre << '\n';
    }
    return 0;
}