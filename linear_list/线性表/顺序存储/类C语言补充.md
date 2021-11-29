## C++ 中的参数传递

    函数调用时实参与形参必须一致:
        1. 类型
        2. 个数
        3. 顺序
    传递方式:
        1. 传值:  
            - 整型
            - 实型等
        2. 传地址(实参和形参公用一个地址):
            - 参数为指针变量
            - 参数为引用类型(C++特有)
            - 参数为数组名

### 传地址

#### 1. 参数为指针

> 形参变化影响实参

```c++
#include
<iostream>

//函数调用了传入的地址将地址赋值给形参,然后形参的前面加上* 可以将地址的内容读取
//同时进行操作可以改变原始的值
void swap(int *m, int *n) {
int temp;
temp = *m;
*m = *n;
*n = temp;
}

int main() {
int a, b, *p1, *p2;//定义了整型指针
std::cin >> a >> b;
p1 = &a;// 将输入的地址赋值给指针变量
p2 = &b;// p1 存储的是内存地址,*p1存储的是该地址保存的内容
swap(p1, p2);//将地址传递给了函数
std::cout << a << ' ' << b;
return 0;
}
```

> 形参变化不影响实参

```c++
#include
<iostream>

void swap(int *m, int *n) {
int *temp;// 定义了一个新的指针
temp = m;
m = n;
n = temp;// 只是交换了m n的地址 就是m之前指向的是a 现在交换了以后就
// 指向了b 但是在内存地址中这两个地址没有发生改变 
// 就换了个名字
}

int main() {
int a, b, *p1, *p2;
std::cin >> a >> b;
p1 = &a;
p2 = &b;
swap(p1, p2);
std::cout << a << ' ' << b;
return 0;
}
```

#### 2. 参数为数组名

```c++
#include
<iostream>

void sub(char b[]) {
for (int i = 0; i < 5; ++i) {
b[i] = 'h';
}
}

int main() {
char a[10] = {
"hello"
};
sub(a);
std::cout << a;
return 0;
}
```

#### 3. 参数为引用类型

    引用:
        用一个替代的名字

```c++
#include
<iostream>

void swap(int &i, int &j) {
int temp;
temp = i;
i = j;
j = temp;
}

int main() {
int i = 0;
//    int &j = i;
int j = 0;
std::cin >> i >> j;
swap(i, j);
std::cout << i << j;
return 0;
}
```

    1.  传递引用给函数与传递指针的效果一样:
            形参变化实参也变化
    2.  引用作为形参没有开辟新的地址就只是将原来的地址带入,直接对实参进行操作:
            传递参数效率高
    3.  指针变量内容进行操作时,必须使用 *变量 容易产生错误