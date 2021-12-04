#include "linked-list.h"

Node::Node(int data): data(data), next(nullptr) {
}

SingleLinkedList::SingleLinkedList(): head(nullptr) {
}

SingleLinkedList::~SingleLinkedList() {
    while (head != nullptr) {
        Node *tmp = head;
        head = head->next;

        delete tmp;
    }
}

Node* SingleLinkedList::push_front(int data) {
    Node *node = new Node(data);

    if (head != nullptr) {
        node->next = head;
    }
    
    head = node;
    
    return node;
}

Node* SingleLinkedList::front() const {
    return head;
}

Node* SingleLinkedList::insert_sorted(int data) {
    Node* node = new Node(data);

    Node* prev = nullptr;
    Node* cur = head;
    while (cur && cur->data < data) {
        prev = cur;
        cur = cur->next;
    }

    if (prev == nullptr) {
        head = node;
    } else {
        prev->next = node;
    }

    node->next = cur;

    return node;
}

Node* SingleLinkedList::find(int data) const {
    Node *cur = head;
    while (cur) {
        if (cur->data == data) {
            break;
        }

        cur = cur->next;
    }
    return cur;
}

void SingleLinkedList::remove(const Node* node) {
    Node *cur = head;
    Node *prev = nullptr;
    while (cur) {
        if (cur == node) {
            if (prev) {
                prev->next = cur->next;
            } else {
                head = cur->next;
            }
            delete cur;
        }
        prev = cur;
        cur = cur->next;
    }
}