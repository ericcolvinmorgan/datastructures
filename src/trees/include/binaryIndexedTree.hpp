#pragma once
#include <vector>

class BinaryIndexTree
{
    private:
        int _offset; //Index offset by min numeric item
        int _size; //Total number of elements (including the zero) plus 1 dummy item.
        std::vector<int> _tree; //Initialized to all zeros
    public:
        BinaryIndexTree(const int offset, const int size);
        int query(int value);
        void update(int value);
};