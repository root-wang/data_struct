#include "adjacentMatrix.h"

//1 2 3 4 5
//1 2 4
//1 3 2
//1 5 8
//2 4 4
//2 5 5
//3 4 1
//4 5 3

int main() {
    AMGraph<int> g1(5, 7);
    g1.creat_DN();
    g1.dijkstra(1);
//    std::cout << g1;
    return 0;
}