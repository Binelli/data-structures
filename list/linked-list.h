struct Node {
    int data;
    Node *next;

    Node(int data);
    Node(const Node &) = delete;
    Node &operator=(const Node &) = delete;
};

class SingleLinkedList {
public:
    Node* push_front(int data);
    Node* front() const;

    Node* insert_sorted(int data);

    Node* find(int data) const;

    void remove(const Node* node);
    SingleLinkedList();
    ~SingleLinkedList();

    SingleLinkedList(const SingleLinkedList&) = delete;
    SingleLinkedList& operator=(const SingleLinkedList&) = delete;
private:
    Node* head;
};
