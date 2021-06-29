#pragma once
#include <vector>

class SegmentTree
{
    private:
        int _size;
        std::vector<int> _tree;
    public:
        SegmentTree(const int size);
        int query(int leftValue, int rightValue);
        void update(int index, const int updatedValue);
};