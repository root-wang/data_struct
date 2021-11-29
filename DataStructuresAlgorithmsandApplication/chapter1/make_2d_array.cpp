#include <iostream>

typedef char T;

//为一个二维数组分配存储空间(可以检测异常)
template<class T>
bool make_2d_array(T **&x, int num_row, int num_col) {
//    创建一个二维数组
    try {
//        创建行指针
        x = new T *[num_row];//这个行数组是一个元素为T类型指针的数组

//        为每一行分配空间
        for (int i = 0; i < num_row; ++i) {
            x[i] = new T[num_col];//列数组为元素为T类型的数组
        }
        return true;
    } catch (std::bad_alloc) {
        return false;
    }
}


template<class T>
void delete_2d_array(T **&x, int num_row) {
//    删除每一行的数组空间
    for (int i = 0; i < num_row; ++i) {
        delete[] x[i];
    }
//    删除行指针数组
    delete[] x;
    x = nullptr;

}

//创建一个二维数组,无异常处理
template<class T>
void make_2d_array_without_exception_handling(T **&x, int num_row, int num_col) {
    x = new T *[num_row];
    for (int i = 0; i < num_row; ++i) {
        x[i] = new T[num_col];
    }
}

int main() {
    T **x;
    int r, c;
    try {
        make_2d_array_without_exception_handling(x, r, c);
    } catch (std::bad_alloc) {
        std::cout << "could not creat x" << '\n';
        exit(1);
    }
}