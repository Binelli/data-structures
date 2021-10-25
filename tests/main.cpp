#include "binary-heap.h"
#include <vector>
#include <iostream>

using namespace std;

void test_bin_heap() {
    vector<int> v {10, 4, 6, 3, 20, 18, 3};
    BinHeap heap(std::move(v));

    cout << heap.get_max() << "\n";

    heap.insert(4);
    heap.insert(40);

    cout << heap.get_max() << "\n";

    heap.remove_max();
    heap.remove_max();

    cout << heap.get_max() << "\n";
}

int main(int argc, char *argv[]) {
    test_bin_heap();
}