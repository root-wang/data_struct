//
// Created by wang on 2021/11/17.
//
#include "sparseMatrix.h"

int main() {
    sparseMatrix gih(4, 4, 4);
    gih.creatMatrix();
    sparseMatrix hit(gih);
    gih += hit;
    return 0;
}