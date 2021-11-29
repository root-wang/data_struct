#include <iostream>
#include <string>
#include <cstring>

typedef char T;


//创建一个二维数组,每行的行数存储在数组中
template<class T>
void make_2d_array_without_exception_handling(T **&x, int num_row, const int row_size_array[]) {
    x = new T *[num_row];
    for (int i = 0; i < num_row; ++i) {
        x[i] = new T[row_size_array[i]];
    }
}

//扩展一个一维旧数组的长度 复制原数组元素 并删除原数组
template<class T>
T *change_length_1d(T *old_1d_array, int old_length, int new_length) {
    static T *new_1d_array = new T[new_length];
    for (int i = 0; i < old_length; ++i) {
        new_1d_array[i] = old_1d_array[i];
    }
    delete[]old_1d_array;//删除数组的形式
    return new_1d_array;
}

//扩展一个二维旧数组的长度 复制原数组元素 并删除原数组
//TODO: 待测试
template<class T>
T **change_length_2d(T **old_2d_array, int old_num_row, int old_num_col, int new_num_row, int new_num_col) {
    static T **new_2d_array = new T *[new_num_row];
    for (int i = 0; i < new_num_row; ++i) {
        new_2d_array = new T[new_num_col];
    }
    for (int i = 0; i < old_num_row; ++i) {
        for (int j = 0; j < old_num_col; ++j) {
            new_2d_array[i][j] = old_2d_array[i][j];
        }
    }
    for (int i = 0; i < old_num_row; ++i) {
        delete[] old_2d_array[i];
    }
    delete[]old_2d_array;
    return new_2d_array;
}


int main() {
    T *x = new T[3]{'1', 'f', 'g'};
    int old_length = 3, new_length = 7;
    T *new_x = change_length_1d(x, old_length, new_length);
//    for (int i = 0; i < new_length; ++i) {
//        std::cout << new_x[i] << '\n';
//    }
//    std::cout << strlen(new_x);


    return 0;
}