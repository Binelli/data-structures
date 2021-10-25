#include "binary-heap.h"
#include <vector>
#include <algorithm>

using namespace std;

BinHeap::BinHeap() {

}

BinHeap::BinHeap(const vector<int> &v) {
    heap = v;
    heapify();
}

BinHeap::BinHeap(vector<int> &&v) {
    heap = v;
    heapify();
}

void BinHeap::heapify() {
    for (auto it = heap.begin(); it != heap.end(); ++it) {
        auto idx = it - heap.begin();
        auto parent = parent_idx(idx);

        while ((idx != parent) && (heap[parent] < heap[idx])) {
            swap(heap[idx], heap[parent]);
            idx = parent;
            parent = parent_idx(idx);
        }
    }
}

size_t BinHeap::lchild_idx(const size_t idx) const {
    return idx * 2 + 1;
}

size_t BinHeap::rchild_idx(const size_t idx) const {
    return idx * 2 + 2;
}

size_t BinHeap::parent_idx(const size_t idx) const {
    return (idx != 0) ? (idx - 1) / 2 : 0;
}

int BinHeap::get_max() const {
    return heap.empty() ? 0 : heap[0];
}

void BinHeap::insert(int elem) {
    heap.push_back(elem);

    int idx = heap.size() - 1;
    int parent = parent_idx(idx);

    while ((idx != parent) && (heap[parent] < heap[idx])) {
        swap(heap[parent], heap[idx]);
        idx = parent;
        parent = parent_idx(idx);
    }
}

void BinHeap::remove_max() {
    if (heap.empty()) {
        return;
    }

    swap(heap[0], heap[heap.size() - 1]);
    size_t idx = 0;
    while (idx < heap.size()) {
        size_t child = lchild_idx(idx);
        if (child >= heap.size()) {
            break;
        }
        size_t right = rchild_idx(idx);

        if ((right < heap.size()) && (heap[right] > heap[child])) {
            child = right;
        }

        if (heap[idx] >= heap[child]) {
            break;
        }

        swap(heap[idx], heap[child]);
        idx = child;
    }
}