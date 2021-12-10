#ifndef __GRAPH__
#define __GRAPH__
#include <iostream>
#include <queue>
//邻接矩阵(数组)表示法

typedef int ArcType;

template<typename VerTexType>
class AMGraph {//array matrix graph
 private:
    static const int MAX;
    
    VerTexType *vertices;//顶点数组 存储顶点的信息
    ArcType **matArray;//邻接矩阵
    //顶点数
    int vex_num;
    //边数
    int arc_num;
    //DFS遍历标记数组
    int *m_book;
 
 public:
    AMGraph(int the_vex_num,
            int the_arc_num)
        : vex_num(the_vex_num),
          arc_num(the_arc_num) {
        vertices = new VerTexType[the_vex_num]{};
        m_book = new int[the_vex_num]{};
        
        matArray = new ArcType *[the_vex_num];
        for (int i = 0; i != the_vex_num; ++i) {
            matArray[i] = new ArcType[the_vex_num];
        }
    }
    ~AMGraph() {
        for (int i = 0; i != vex_num; ++i) {
            delete[] matArray[i];
        }
        delete[]matArray;
        delete vertices;
    };
//    创建无向图
    void creat_UDG();
//    创建无向网(带权值的无向图)
    void creat_UDN();
//    创建有向网
    void creat_DN();

//    最小生成树
//        --prim算法
    void prim(VerTexType v) const;

//
    void kruskal() const;

//    单源最短路径算法 dijkstra
    void dijkstra(VerTexType source_ver) const;

//
    void floyd() const;

//
    void DFS(VerTexType) const;
//
    void BFS(VerTexType v) const;

//    邻接矩阵输出
    friend std::ostream &operator<<(std::ostream &out,
                                    AMGraph<VerTexType> x) {
        for (int i = 0; i != x.vex_num; ++i) {
            for (int j = 0; j != x.vex_num; ++j) {
                out << x.matArray[i][j] << ' ';
            }
            out << '\n';
        }
        return out;
    }
 
 private:
    void book_clear() const {
        for (int i = 0; i != vex_num; ++i) {
            m_book[i] = 0;
        }
    }
    
    bool traverse_finished() const {
        int sum = 0;
        for (int i = 0; i != vex_num; ++i) {
            sum += m_book[i];
        }
        if (sum == vex_num)
            return true;
        else
            return false;
    }
    
    int Locate_vex(VerTexType u) const {
        for (int position = 0; position != vex_num; ++position) {
            if (u == vertices[position])
                return position;
        }
        return -1;
    }
};

template<typename T> const int AMGraph<T>::MAX = INT_MAX;

template<typename T>
void AMGraph<T>::creat_UDG() {
    // 输入每个T类型顶点信息
    for (int i = 0; i != vex_num; ++i) {
        std::cin >> vertices[i];
    }
    
    // 邻接矩阵边的权值初始化为0
    for (int i = 0; i != vex_num; ++i) {
        for (int j = 0; j != vex_num; ++j) {
            matArray[i][j] = 0;
        }
    }

//    填充矩阵
    for (int i = 0; i != arc_num; ++i) {
        T v1, v2;
        // 输入一条边的开始和结尾以及权值
        std::cin >> v1 >> v2;
        // 根据输入的结点的值获得该结点在邻接矩阵中的位置
        int v1_position = Locate_vex(v1);
        int v2_position = Locate_vex(v2);
        // 无向图的邻接矩阵是对称的
        matArray[v1_position][v2_position] = 1;
        matArray[v2_position][v1_position] = 1;
    }
}

//深度优先遍历算法
template<typename T>
void AMGraph<T>::DFS(T current_vex) const {
    int current_pos = Locate_vex(current_vex);
//        visit node
    std::cout << vertices[current_pos] << ' ';
    
    m_book[current_pos] = 1;
    
    if (traverse_finished()) {
//        book_clear();
        return;
    }
    for (int i = 0; i != vex_num; ++i) {
        if (m_book[i] == 0 && matArray[current_pos][i] == 0) {
            m_book[i] = 1;
            DFS(vertices[i]);
        }
    }
    
}

template<typename VerTexType>
void AMGraph<VerTexType>::BFS(VerTexType v) const {
    std::queue<VerTexType> q1;
    int current_pos = Locate_vex(v);
    q1.push(v);
    m_book[current_pos] = 1;
    while (!q1.empty()) {
        for (int i = 0; i != vex_num; ++i) {
            if (matArray[current_pos][i] && m_book[i] == 0) {
                q1.push(vertices[i]);
                m_book[i] = 1;
            }
        }
//        visit node
        std::cout << q1.front() << " ";
        
        q1.pop();
        current_pos = Locate_vex(q1.front());
    }
    if (traverse_finished()) {
//        book_clear();
        return;
    } else {
        for (int i = 0; i != vex_num; ++i) {
            if (!m_book[i]) {
                BFS(vertices[i]);
            }
        }
    }
}

template<typename T>
void AMGraph<T>::creat_UDN() {
    const int MAX = INT_MAX;
    // 输入每个T类型顶点信息
    for (int i = 0; i != vex_num; ++i) {
        std::cin >> vertices[i];
    }
    
    // 邻接矩阵边的权值初始化为无穷(即没有相邻的边) 矩阵对角线元素为0
    for (int i = 0; i != vex_num; ++i) {
        for (int j = 0; j != vex_num; ++j) {
            if (i == j) {
                matArray[i][j] = 0;
            } else {
                matArray[i][j] = MAX;
            }
        }
    }

//    填充矩阵
    for (int i = 0; i != arc_num; ++i) {
        T v1, v2;
        int value;
        // 输入一条边的开始和结尾以及权值
        std::cin >> v1 >> v2 >> value;
        // 根据输入的结点的值获得该结点在邻接矩阵中的位置
        int v1_position = Locate_vex(v1);
        int v2_position = Locate_vex(v2);
        // 无向图的邻接矩阵是对称的
        matArray[v1_position][v2_position] = value;
        matArray[v2_position][v1_position] = value;
    }
}

template<typename VerTexType>
void AMGraph<VerTexType>::prim(VerTexType v) const {
//    找到节点对应的矩阵下标
//    并将该结点加入最小生成树节点集合
    int pos_init = Locate_vex(v);
    m_book[pos_init] = 1;
//    一共需要添加n-1条边 执行n-1次
    for (int i = 0; i != vex_num - 1; ++i) {
        int min_load = INT_MAX;
        int min_pos_end = -1, min_pos_start = -1;
//     每次需要搜索当前已获得的结点最短的边
//              最后保存在min_load
        for (int j = 0; (j != vex_num) && m_book[j]; ++j) {
//            每个已获得结点的所有可行边长度
            for (int k = 0; k != vex_num; ++k) {
                if (matArray[j][k] != 0 && matArray[j][k] < INT_MAX && m_book[k] == 0) {
                    if (matArray[j][k] < min_load) {
                        min_load = matArray[j][k];
                        min_pos_start = j;
                        min_pos_end = k;
                    }
                }
            }
        }
//        输出找到的新一条最小生成树的路径
        std::cout << vertices[min_pos_start] << "->" << vertices[min_pos_end] << '\n';
//        将该路径终点的结点加入最小生成树结点集合
        m_book[min_pos_end] = 1;
    }
}
template<typename VerTexType>
void AMGraph<VerTexType>::kruskal() const {

}

template<typename T>
void AMGraph<T>::creat_DN() {
    const int MAX = INT_MAX;
    // 输入每个T类型顶点信息
    for (int i = 0; i != vex_num; ++i) {
        std::cin >> vertices[i];
    }
    
    // 邻接矩阵边的权值初始化为无穷(即没有相邻的边) 矩阵对角线元素为0
    for (int i = 0; i != vex_num; ++i) {
        for (int j = 0; j != vex_num; ++j) {
            if (i == j) {
                matArray[i][j] = 0;
            } else {
                matArray[i][j] = MAX;
            }
        }
    }

//    填充矩阵
    for (int i = 0; i != arc_num; ++i) {
        T v1, v2;
        int value;
        // 输入一条边的开始和结尾以及权值
        std::cin >> v1 >> v2 >> value;
        // 根据输入的结点的值获得该结点在邻接矩阵中的位置
        int v1_position = Locate_vex(v1);
        int v2_position = Locate_vex(v2);
        // 无向图的邻接矩阵是对称的
        matArray[v1_position][v2_position] = value;
    }
}

template<typename T>
void AMGraph<T>::dijkstra(T source_ver) const {
    int source_pos = Locate_vex(source_ver);
    const int MAX = INT_MAX;
    
    int *book = new int[vex_num]{0};
    int *prev_pos = new int[vex_num];
    int *distance_from_source = new int[vex_num]{0};
    for (int i = 0; i != vex_num; ++i) {
        distance_from_source[i] = matArray[source_pos][i];
        if (matArray[source_pos][i] < INT_MAX) {
            prev_pos[i] = source_pos;
        } else {
            prev_pos[i] = -1;
        }
    }
    prev_pos[source_pos] = source_pos;
    
    book[source_pos] = 1;

//    循环vex_num-1次每次找到剩余的顶点的最短路径
    for (int i = 0; i != vex_num - 1; ++i) {
//        每次重置最短路径
        int min_dis = INT_MAX;
        int min_dis_index = -1;
        
        for (int j = 0; j != vex_num; ++j) {
            if (book[j] == 0 && distance_from_source[j] < min_dis) {
                min_dis = distance_from_source[j];
                min_dis_index = j;
            }
        }
        book[min_dis_index] = 1;
        
        for (int j = 0; j != vex_num; ++j) {
            int tmp_dis = (matArray[min_dis_index][j] == MAX) ? MAX : (min_dis + matArray[min_dis_index][j]);
            if (book[j] == 0 && tmp_dis < distance_from_source[j]) {
                distance_from_source[j] = tmp_dis;
                prev_pos[j] = min_dis_index;
            }
        }
    }
    for (int j = 0; j != vex_num; ++j) {
        std::cout << distance_from_source[j] << ' ';
    }
    std::cout << '\n';
    for (int j = 0; j != vex_num; ++j) {
        std::cout << vertices[prev_pos[j]] << ' ';
    }
}

template<typename VerTexType>
void AMGraph<VerTexType>::floyd() const {

}

#endif //__GRAPH__