#include <iostream>
#include "Currency.h"

using namespace std;

int main() {
    Currency time, book;
    try {
        time.set_value(m_minus, 34, 34);
    } catch (IllegalParameterValue e) {
        std::cout << "there is an error happened" << '\n';
        e.output_message();
        exit(1);
    }


//    time.output();

    book.set_value(-35.347);
    time.set_value(-36.25);
//    book.output();
    book = time.compare_big(book);
    cout<<book;
//    time.add(book).output();


//    time.increment(book);
//    time.output();

    return 0;
}