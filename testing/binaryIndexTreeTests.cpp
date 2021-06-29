#include <gtest/gtest.h>
#include "../src/trees/include/binaryIndexedTree.hpp"

std::vector<int> countSmaller(std::vector<int> &nums);

TEST(Binary_Index_Tree, count_smaller_after_self_1)
{
    std::vector<int> input = {5, 2, 6, 1};
    std::vector<int> expectedOutput = {2, 1, 1, 0};
    auto output = countSmaller(input);
    ASSERT_EQ(expectedOutput, output);
}

TEST(Binary_Index_Tree, count_smaller_after_self_2)
{
    std::vector<int> input = {-1};
    std::vector<int> expectedOutput = {0};
    auto output = countSmaller(input);
    ASSERT_EQ(expectedOutput, output);
}

TEST(Binary_Index_Tree, count_smaller_after_self_3)
{
    std::vector<int> input = {-1, -1};
    std::vector<int> expectedOutput = {0, 0};
    auto output = countSmaller(input);
    ASSERT_EQ(expectedOutput, output);
}

TEST(Binary_Index_Tree, count_smaller_after_self_4)
{
    std::vector<int> input;
    for(int i = 0; i < 1000; i++)
    {
        input.push_back(i);
    }

    std::vector<int> expectedOutput(1000);
    auto output = countSmaller(input);
    ASSERT_EQ(expectedOutput, output);
}

TEST(Binary_Index_Tree, count_smaller_after_self_5)
{
    std::vector<int> input;
    for(int i = 1000; i > 0; i--)
    {
        input.push_back(i);
    }

    std::vector<int> expectedOutput;
    for(int i = 1000; i > 0; i--)
    {
        expectedOutput.push_back(i - 1);
    }

    auto output = countSmaller(input);
    ASSERT_EQ(expectedOutput, output);
}

std::vector<int> countSmaller(std::vector<int> &nums)
{
    int offset = 1e4;
    BinaryIndexTree bit(offset, (2 * offset) + 2);
    std::vector<int> smaller(nums.size());
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        smaller[i] = bit.query(nums[i]);
        bit.update(nums[i]);
    }

    return smaller;
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}