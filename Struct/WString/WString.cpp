//
// Created by wang on 2021/11/14.
//

#include <iostream>
#include <cstring>
#include "WString.h"

WString::WString() {
    m_str = nullptr;
    m_length = 0;
}

WString::~WString() {
    delete[] m_str;
}

WString::WString(const char *ch) {
    if (ch && *ch) {
        m_length = strlen(ch);
        m_str = new char[m_length + 1];
        strcpy(m_str, ch);
    } else {
        m_length = 0;
        m_str = nullptr;
    }
}

WString::WString(const char ach) {

    m_str = new char[2];
    m_str[0] = ach;
    m_str[1] = '\0';
    m_length = 1;
//    } else {
//        m_str = 0;
//        m_length = 0;
//    }
}

WString::WString(const WString &str) {
    if (str.m_str) {
        m_str = new char[str.m_length + 1];
        strcpy(m_str, str.m_str);
        m_length = str.m_length;
    } else {
        m_str = nullptr;
        m_length = 0;
    }
}

int WString::length_string() {
    if (m_str) {
        return m_length;
    } else {
        return 0;
    }
}

WString WString::split(const char ch) const {

}

int WString::concat(const WString &str) {
    if (str.m_str) {
        m_length = m_length + str.m_length - 1;
        char *new_str = new char[m_length];
        strcpy(new_str, m_str);
        for (int i = m_length - str.m_length; i < m_length; ++i) {
            new_str[i] = str.m_str[i - m_length + str.m_length];
        }
        m_str = new_str;
        return 1;
    } else {
        return 0;
    }
}

int WString::indexOf(const WString &str, int pos, char mode) {
    return 0;
}

const WString &WString::slice(int begin, int end) {

}


int WString::indexOf_BF(const WString &str, int pos) {
    if (!str.m_str) {
        return 0;
    } else {
        int i = pos, j = 0;
        while (i < m_length && j < str.m_length) {
//            子串和主串一个字符匹配成功 两个指针向前
            if (m_str[i] == str.m_str[j]) {
                i++;
                j++;
            }
//            匹配失败 主串回溯到之前的下一个位置
//                    子串置零
            else {
                i = i - j + 1;
                j = 0;
            }
        }
//        子串所有元素匹配成功 返回下标
        if (j >= str.m_length) {
            return i - str.m_length;
        } else {
            return 0;
        }
    }
}



int WString::indexOf_KMP(const WString &x, int pos = 0) {

}

void WString::out() {
    if (m_str) {
        for (int i = 0; i < m_length; ++i) {
            std::cout << m_str[i];
        }
        std::cout << '\n';
    } else {
        throw "no out";
    }
}
