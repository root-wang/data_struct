#include "maxHeap.cpp"
#include <iostream>
int main() {
    using std::cout;
    int len = 7;
    int *a = new int[len]{3, 5, 1, 12, 8, 16, 3};
    maxHeap<int> heap;
    heap.initialize(a, len);
//    heap.output();
    maxHeap<int> time(heap);
//    time.output();
    
    int *ans = new int[len];
    heap.heap_sort(ans, len);
//    std::cout << heap.top();
    for (int i = 0; i != len; ++i) {
        cout << ans[i] << '\n';
    }
    heap.output();
    return 0;
}