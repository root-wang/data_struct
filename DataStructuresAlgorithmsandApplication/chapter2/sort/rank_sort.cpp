//
// Created by wang on 2021/11/18.
//

#include <iostream>

typedef int T;

// a = [4,3,9,3,7]
// r = [2,0,4,1,3]

template<class T>
int &rank(T *a, int len) {
    int *r = new int[len]{0};
    for (int i = 0; i < len; ++i) {
        for (int j = i; j < len; ++j) {
            if (a[i] > a[j + 1]) r[i]++;
            else r[j + 1]++;
        }
    }
    return *r;
}

void rank_sort(T *&a, int len, int *r) {
//    附加一个新的数组来将a中的元素按照顺序放入
    T *u = new T[len];
    for (int i = 0; i < len; ++i) {
        u[r[i]] = a[i];
    }

//    再将u中的元素移动回a
    for (int i = 0; i < len; ++i) {
        a[i] = u[i];
    }

//    删除额外的空间
    delete[]u;
}

// i    0 1 2 3 4
// a = [4,3,9,3,7]
// r = [2,0,4,1,3]
template<class T>
void rank_sort_in_place(T *&a, int len,int *r) {
    for (int i = 0; i < len; i++) {
        while (r[i] != i) {
//            一定是先交换元素数组 再去交换排序数组
//            如果先交换排序数组 此时 元素数组对应的次序已经改变了
//            就无法定位正确的排序
//          或者使用 t = r[i]保存未交换次序的时候的排序
            std::swap(a[i], a[r[i]]);
            std::swap(r[i], r[r[i]]);

        }
    }
}

int main() {
    int *r;
    int *a = new int[5]{4, 3, 9, 3, 7};
    r = &rank(a, 5);
//    rank_sort(a,5,r);
    rank_sort_in_place(a, 5, r);
    for (int i = 0; i < 5; ++i) {
        std::cout << a[i] << '\n';
    }
    return 0;
}