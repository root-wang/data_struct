//
// Created by wang on 2021/12/8.
//

#ifndef GREEDYLOADING_CPP_CHAIN_H
#define GREEDYLOADING_CPP_CHAIN_H
#include <iostream>

template <typename T>
struct chainNode
{
    T m_data;
    chainNode<T> *next;
    //  默认构造函数
    chainNode() : m_data(), next(nullptr){};
    //  构造函数
    explicit chainNode(const T &data)
    {
        this->m_data = data;
    }
    //  拷贝构造函数
    chainNode(const T &data,
              chainNode<T> *next)
    {
        this->m_data = data;
        this->next = next;
    }
};

template <typename T>
class Chain
{
private:
    chainNode<T> *head;
    int m_length; //链表的元素个数

    void check_index(int the_index) const
    {
        if (the_index >= m_length || the_index < 0)
        {
            exit(-1);
        }
    };

public:
    //    构造函数
    explicit Chain(int capacity = 10);
    //    复制构造函数
    Chain(const Chain<T> &x);
    //    析构函数
    ~Chain();

    //    ADT方法
    //  链表是否为空
    // 返回:
    //      为空则返回true
    //      否则返回false
    bool empty() const
    {
        return head->next;
    };

    //  返回链表当前元素个数
    //  返回:
    //      整型元素个数
    int size() const
    {
        return m_length;
    };

    //  返回the_index下标对应的元素
    //  the_index:
    //      从0位置开始计算的下标
    //  返回:
    //      该位置的元素
    T &get(int the_index) const;

    //  根据元素查找首次出现位置
    //  e:
    //      需要搜索的元素值
    //  返回:
    //      该元素在链表中首次出现的位置
    //      查找失败则返回-1
    int indexOf(const T &e) const;

    //  在指定位置插入元素
    //  e:
    //      需要插入的元素
    //  position:
    //      插入的位置
    //  返回:
    //      插入后的元素
    T &insert(T &e,
              int position);

    //  擦除指定位置的元素
    //  the_index
    //      需要擦除的位置
    //  返回:
    //      擦除位置的元素
    T &erase(int the_index);

    //  链表的尾部插入元素
    //  e：
    //      需要插入的元素
    //  返回:
    //      成功返回0
    int push_back(const T &e);

    //    从链表头依次输出所有元素
    void output() const;

    //  使链表的大小为the_size
    //  过长则截断
    void set_size(int the_size);

    //    使用e来替换the_index位置的元素
    void set(int the_index,
             T &e);

    //    删除指定范围的元素
    //    from_index:
    //        范围开始位置(包括)
    //    to_index:
    //        范围结束(不包括)
    void remove_range(int from_index,
                      int to_index);

    //    返回该元素最后出现的位置
    int last_indexOf(T &e) const;

    //    返回第index元素的引用
    T &operator[](int index) const;

    //    当且仅当两个链表的所有元素都相等时返回true
    bool operator==(const Chain<T> &x) const;

    //    ==的反
    bool operator!=(const Chain<T> &x) const;

    //    当且仅当x的按字典序小于链表this
    bool operator<(const Chain<T> &x) const;

    //    交换链表*this和the_chain的所有元素
    int swap(const Chain<T> &the_chain);

    //    将表中的元素向左移动i个位置
    int left_shift(int i);

    //    原地颠倒*this中的元素顺序
    void reverse();
    //箱子排序
    void bin_sort(int range);
};

#endif //GREEDYLOADING_CPP_CHAIN_H