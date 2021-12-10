//
// Created by wang on 2021/11/14.
//

#include <iostream>
#include "link_queue.cpp"

using namespace std;

int main() {
    Link_queue<int> time;
    int desk[6]{1, 2, 3, 4, 5, 6};
    for (int & i : desk) {
        time.en_queue(i);
    }
//    cout << time.length_queue() << '\n';

    int out;

//    out = time.get_head();
//    cout << out <<'\n';
    for (int i = 0; i < 6; ++i) {
        time.de_queue(out);
//        cout << "now the queue length is ";
//        cout << time.length_queue() << '\n';
        cout << "now the out is ";
        cout << out << '\n';
    }

    return 0;
}