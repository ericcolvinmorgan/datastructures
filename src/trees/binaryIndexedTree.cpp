#include "include/binaryIndexedTree.hpp"

BinaryIndexTree::BinaryIndexTree(const int offset, const int size)
{
    _offset = offset;
    _size = size;
    _tree = std::vector<int>(_size);
}

int BinaryIndexTree::query(int value)
{
    int result = 0;
    int index = value + _offset;
    while (index >= 1)
    {
        result += _tree[index];
        index -= index & -index;
    }
    return result;
}

void BinaryIndexTree::update(int value)
{
    int index = value + _offset + 1;
    while (index < _size)
    {
        _tree[index] += 1;
        index += index & -index;
    }
}