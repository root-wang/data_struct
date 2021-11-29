#include <iostream>

typedef float T;

template<class T>
T abc(T a, T b, T c) {
//    if (a <= 0 || b <= 0 || c <= 0) {
//        throw "all parameters should be > 0";
//    } else
    if (a < 0 && b < 0 && c < 0) {
        throw 1;
    } else if (a == 0 && b == 0 && c == 0) {
        throw 2;
    }
    return a + b * c;
}


template<class T>
int count(T a[], int n, T value) {
    if (n < 1) {
        throw "the length of array should be >0";
    }
    static int temp = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == value) {
            temp++;
        }
    }
    return temp;
}

int main() {
    try {
        std::cout << abc(-5, -6, -1) << std::endl;
    } catch (const char *e) {
        std::cout << "the parameter to abc were 2 ,0 ,5" << '\n';
        std::cout << "an exception has been thrown" << '\n';
        std::cout << e;
        return 1;
    } catch (int e) {
        if (e == 1) {
            std::cout << "the parameter to abc should be >=0" << '\n';
            std::cout << e;
            return 2;
        } else if (e == 2) {
            std::cout << "the parameter to abc should be not eq 0" << '\n';
            std::cout << e;
            return 3;
        }
    }
    T a[5] = {1, 2, 3, 1, 5};
    T value = 1;
    try {
        std::cout << count(a, 0, value) << '\n';
    } catch (const char *e) {
        std::cout << "there is an error happened" << '\n';
        std::cout << e;
        return 1;
    }

    return 0;
}