#include <vector>

class BinHeap {
    public:
        BinHeap();
        BinHeap(const std::vector<int> &v);
        BinHeap(std::vector<int> &&v);

        int get_max() const;
        void insert(int elem);
        void remove_max();
    private:
        std::vector<int> heap;

        void heapify();
        size_t lchild_idx(const size_t idx) const;
        size_t rchild_idx(const size_t idx) const;
        size_t parent_idx(const size_t idx) const;
};
