#include "binary-heap.h"
#include "linked-list.h"

#include <vector>
#include <iostream>

using namespace std;

void print_list(const SingleLinkedList &list) {
    Node* head = list.front();
    while (head) {
        cout << "Element: " << head->data << "\n";
        head = head->next;
    }
}

void test_single_linked_list() {
    SingleLinkedList list;
    list.push_front(12);
    list.push_front(10);    
    list.insert_sorted(1);
    list.insert_sorted(11);
    list.insert_sorted(15);

    SingleLinkedList list2;
    list2.insert_sorted(14);

    print_list(list);
    print_list(list2);

    if (list.find(15)) {
        cout << "Found 15\n";
    }

    if (!list.find(22)) {
        cout << "Not Found 22\n";
    }
}

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
    cout << "================= TESTING HEAP =======================\n";
    test_bin_heap();
    cout << "================= TESTING LINKED LIST ================\n";
    test_single_linked_list();
}
