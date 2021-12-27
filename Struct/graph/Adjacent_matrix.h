#ifndef __GRAPH__
#define __GRAPH__

#include <iostream>

//邻接矩阵(数组)表示法

const int MAXVEXNUM = 100;
const int INFTY = INT_MAX;

typedef int ArcType;

template <typename VerTexType>
struct AMGrape
{
    VerTexType vexs[MAXVEXNUM];
    ArcType arcs[MAXVEXNUM][MAXVEXNUM];
    int vex_num, arc_num;
};

template <typename T>
void creat_UDN(AMGrape<T>);

template <typename T>
inline int Locate_vex(AMGrape<T> G, T u);
#endif __GRAPH__