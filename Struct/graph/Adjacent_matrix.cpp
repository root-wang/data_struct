#include "graph.h"

// 创建无向网
template <typename T>
void creat_UDN(AMGrape<T> &G)
{
    std::cin >> G.vex_num >> G.arc_num;
    // 输入每个T类型顶点信息
    for (int i = 0; i != G.vex_num; ++i)
    {
        std::cin >> G.vexs[i];
    }
    // 邻接矩阵边的权值初始化为无穷大
    for (int i = 0; i != G.vex_num; ++i)
    {
        for (int j = 0; j != G.vex_num; ++j)
        {
            G.arcs[i][j] = INFTY;
        }
    }
    for (int i = 0; i != G.arc_num; ++i)
    {
        ArcType w;
        T v1, v2;
        // 输入一条边的开始和结尾以及权值
        std::cin >> v1 >> v2 >> w;
        // 根据输入的结点的值获得该结点在邻接矩阵中的位置
        int v1_position = Locate_vex(G, v1);
        int v2_position = Locate_vex(G, v2);
        // 无向图的邻接矩阵是对称的
        G.arcs[v1_position][v2_position] = w;
        G.arcs[v2_position][v1_position] = w;
    }
    return;
}

template <typename T>
int Locate_vex(AMGrape<T> G, T u)
{
    int position = 0;
    for (position = 0; position != G.vex_num; ++position)
    {
        if (u == G.vex[i])
            return position;
    }
    return -1;
}