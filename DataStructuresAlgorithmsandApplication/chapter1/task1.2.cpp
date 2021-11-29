#include <iostream>

typedef int T;

template<class T>
int count(T a[], T value, int len) {
    int cout1 = 0;
    for (int i = 0; i < len; i++) {
        if (a[i] == value) {
            cout1++;
        }
    }
    return cout1;
}

template<class T>
void fill(T a[], int start, int end) {
    for (int i = start; i < end; ++i) {
        T temp;
        std::cin >> temp;
        a[i] = temp;
    }
}

template<class T>
T inner_product(T a[], T b[], int n) {
    T sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i] * b[i];
    }
    return sum;
}

template<class T>
T *iota(T value, int n) {
//    局部定义的数组变量在函数结束后就会使用析构函数
//    然后会释放局部变量 所以就不可以返回它
//    在变量前添加static即可
    static int a[1001]{};
    for (int i = 0; i < n; ++i) {
        a[i] = value + i;
    }
    return a;
}


template<class T>
int is_sorted(T a[], int len) {
    for (int i = 0; i < len - 2; ++i) {
        if ((a[i + 1] > a[i] && a[i + 2] < a[i + 1]) || (a[i + 1] < a[i] && a[i + 2] > a[i + 1]))
            return false;
    }
    return true;
}


template<class T>
int mismatch(T a[], T b[], int len) {
    static int index_min = 0;
    for (int i = 0; i < len; ++i) {
        if (a[i] != b[i]) {
            index_min = i;
            break;
        }
    }
    return index_min;
}

int main() {
    T a[5]{1, 2, 3, 4, 5}, b[5]{1, 2, 3, 5, 4};
    int index_min = mismatch(a, b, 5);
    std::cout << index_min;
    return 0;
}