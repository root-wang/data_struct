#ifndef __ADIACENCY_LIST__
#define __ADIACENCY_LIST__
#include <iostream>

const int MVNum = 1000;

//结点信息类型
typedef char VerTexType;

// 弧(边)的结点结构
typedef struct ArcNode {
  int pos_vex;              //该边所指向顶点的位置
  struct ArcNode *next_arc; //指向下一条边的指针
} ArcNode;

// 顶点的结点结构
typedef struct VNode {
  VerTexType data;   //顶点信息
  ArcNode *firstarc; //指向第一条依附该顶点的边的指针
} VNode;

//整体图的定义
typedef struct ALGrape {
  VNode vertices[MVNum]; //邻接表的数组
  int vex_num, arc_num;  //图当前的顶点数和弧数
};

int locateVex(ALGrape &G, char v);

// 采用邻接表表示法创建无向网
void CreatUDG(ALGrape &G) {
  std::cin >> G.vex_num >> G.arc_num;
  for (size_t i = 0; i < G.vex_num; i++) {
    std::cin >> G.vertices[i].data;
    G.vertices[i].firstarc = nullptr;
  }
  for (int k = 0; k != G.arc_num; ++k) {
    char v1, v2;
    std::cin >> v1 >> v2;
    int i = locateVex(G, v1);
    int j = locateVex(G, v2);

    ArcNode *p1 = new ArcNode;
    p1->pos_vex = j;
    p1->next_arc = G.vertices[i].firstarc;
    G.vertices[i].firstarc = p1;

    ArcNode *p2 = new ArcNode;
    p2->pos_vex = i;
    p2->next_arc = G.vertices[j].firstarc;
    G.vertices[j].first = p2;
  }
}
#endif __ADIACENCY_LIST__