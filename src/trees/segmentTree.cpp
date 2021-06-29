#include "include/segmentTree.hpp"
#include <algorithm>

SegmentTree::SegmentTree(const int size)
{
    _size = size;
    _tree = std::vector<int>(4 * _size);
}

//Returns the sum of leftValue up but excluding rightValue
int SegmentTree::query(int leftValue, int rightValue)
{
    int result = 0;
    //Update indexes to target leaf node
    leftValue += _size;  
    rightValue += _size;
    while (leftValue < rightValue)
    {
        if (leftValue % 2 == 1)
        {
            result += _tree[leftValue];
            leftValue++;
        }
        leftValue /= 2;
        if (rightValue % 2 == 1)
        {
            rightValue--;
            result += _tree[rightValue];
        }
        rightValue /= 2;
    }
    return result;
}

void SegmentTree::update(int index, const int updatedValue)
{
    index += _size;
    _tree[index] += updatedValue;
    while (index > 1)
    {
        index /= 2;
        _tree[index] = _tree[index * 2] + _tree[index * 2 + 1];
    }
}