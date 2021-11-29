//
// Created by wang on 2021/11/14.
//

#ifndef LEARNING_WSTRING_H
#define LEARNING_WSTRING_H

class WString{
private:
//    static const int MAX_LEN = 255;
    char *m_str;
    int m_length;//当前长度
public:
    WString();
    ~WString();

//     传入char*指针
    explicit WString(const char *ch);
//     传入一个字符char
    explicit WString(char ach);
//     传入WString型
    WString(const WString &str);
//      = overload :
//                 -- 1. 传入一个字符char
//                 -- 2. 传入char*
//                 -- 3. 传入String

//      计算长度
    int length_string();

//todo:      字符串分割数组 split(const char ch)
//           根据一个字符分割数组
//           返回一个WString数组
    WString split(const char ch) const;

//      连接两个String
//      连接成功返回1
//      否则返回0
    int concat(const WString &str);

//      返回某个WString字符串在主串中出现的位置
//      str  是模式文本
//      pos  是匹配的起始位置 默认是0
//      mode 匹配主串中所有匹配的元素的下标
//           'f'是返回int型元素 表示返回首次匹配的子串的首元素下标
//           'a'是返回int型指针 表示返回所有匹配的子串的首元素下标
    static int indexOf(const WString &str, int pos = 0, char mode = 'f') ;

//todo:      提取字符串的某个部分，并以新的WString字符串的地址返回被提取的部分
//          begin 是切割的第一个元素位置(包含)
//          end   是切割的最后个元素位置(不包含)
    const WString &slice(int begin, int end);

//      BF算法 WString是传入的需要判断的子字符串
//            pos 是查找的起始位置 默认是0 返回首次找到的子串的首元素下标
    int indexOf_BF(const WString &str, int pos=0) ;

//      KMP算法 int indexOf_KMP(const WString &x)const
    static int indexOf_KMP(const WString &x, int pos) ;

//      直接由cout输出
    void out();
};
#endif //LEARNING_WSTRING_H
