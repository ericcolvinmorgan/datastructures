#include <gtest/gtest.h>
#include "../src/trees/include/segmentTree.hpp"

std::vector<int> countSmaller(std::vector<int> &nums);

TEST(Segment_Tree, count_smaller_custom_1)
{
    std::vector<int> input = {1, 0, 3, 0, 1, 1};
    std::vector<int> expectedOutput = {2, 0, 3, 0, 0, 0};

    SegmentTree st(4);
    std::vector<int> output(input.size());
    for (int i = input.size() - 1; i >= 0; i--)
    {
        output[i] = st.query(0, input[i]);
        st.update(input[i], 1);
    }

    ASSERT_EQ(expectedOutput, output);
}

TEST(Segment_Tree, count_higher_custom_0)
{
    std::vector<int> input = {0, 1, 2, 3, 4, 5, 6};
    std::vector<int> expectedOutput = {6, 5, 4, 3, 2, 1, 0};

    int size = 7;
    SegmentTree st(size);
    std::vector<int> output(input.size());
    for (int i = input.size() - 1; i >= 0; i--)
    {
        output[i] = st.query(input[i] + 1, size);
        st.update(input[i], 1);
    }

    ASSERT_EQ(expectedOutput, output);
}

TEST(Segment_Tree, count_higher_custom_1)
{
    std::vector<int> input = {0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6};
    std::vector<int> expectedOutput = {12, 10, 8, 6, 4, 2, 0, 6, 5, 4, 3, 2, 1, 0};

    int size = 7;
    SegmentTree st(size);
    std::vector<int> output(input.size());
    for (int i = input.size() - 1; i >= 0; i--)
    {
        output[i] = st.query(input[i] + 1, size);
        st.update(input[i], 1);
    }

    ASSERT_EQ(expectedOutput, output);
}

TEST(Segment_Tree, count_higher_custom_2)
{
    std::vector<int> input = {0, 1, 2, 3, 4, 5, 6, 7};
    std::vector<int> expectedOutput = {7, 6, 5, 4, 3, 2, 1, 0};

    int size = 8;
    SegmentTree st(size);
    std::vector<int> output(input.size());
    for (int i = input.size() - 1; i >= 0; i--)
    {
        output[i] = st.query(input[i] + 1, size);
        st.update(input[i], 1);
    }

    ASSERT_EQ(expectedOutput, output);
}

TEST(Segment_Tree, count_higher_custom_3)
{
    std::vector<int> input = {6, 5, 4, 3, 2, 1, 0};
    std::vector<int> expectedOutput = {0, 0, 0, 0, 0, 0, 0};

    SegmentTree st(7);
    std::vector<int> output(input.size());
    for (int i = input.size() - 1; i >= 0; i--)
    {
        output[i] = st.query(input[i] + 1, 7);
        st.update(input[i], 1);
    }

    ASSERT_EQ(expectedOutput, output);
}

TEST(Segment_Tree, count_higher_custom_4)
{
    std::vector<int> input = {0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7};
    std::vector<int> expectedOutput = {14, 12, 10, 8, 6, 4, 2, 0, 7, 6, 5, 4, 3, 2, 1, 0};

    int size = 8;
    SegmentTree st(size);
    std::vector<int> output(input.size());
    for (int i = input.size() - 1; i >= 0; i--)
    {
        output[i] = st.query(input[i] + 1, size);
        st.update(input[i], 1);
    }

    ASSERT_EQ(expectedOutput, output);
}

TEST(Segment_Tree, count_higher_custom_5)
{
    std::vector<int> input = {6, 5, 4, 3, 2, 1, 0, 6, 5, 4, 3, 2, 1, 0};
    std::vector<int> expectedOutput = {0, 1, 2, 3, 4, 5, 6, 0, 0, 0, 0, 0, 0, 0};

    SegmentTree st(7);
    std::vector<int> output(input.size());
    for (int i = input.size() - 1; i >= 0; i--)
    {
        output[i] = st.query(input[i] + 1, 7);
        st.update(input[i], 1);
    }

    ASSERT_EQ(expectedOutput, output);
}

TEST(Segment_Tree, count_smaller_after_self_1)
{
    std::vector<int> input = {5, 2, 6, 1};
    std::vector<int> expectedOutput = {2, 1, 1, 0};
    auto output = countSmaller(input);
    ASSERT_EQ(expectedOutput, output);
}

TEST(Segment_Tree, count_smaller_after_self_2)
{
    std::vector<int> input = {-1};
    std::vector<int> expectedOutput = {0};
    auto output = countSmaller(input);
    ASSERT_EQ(expectedOutput, output);
}

TEST(Segment_Tree, count_smaller_after_self_3)
{
    std::vector<int> input = {-1, -1};
    std::vector<int> expectedOutput = {0, 0};
    auto output = countSmaller(input);
    ASSERT_EQ(expectedOutput, output);
}

TEST(Segment_Tree, count_smaller_after_self_4)
{
    std::vector<int> input;
    for (int i = 0; i < 1000; i++)
    {
        input.push_back(i);
    }

    std::vector<int> expectedOutput(1000);
    auto output = countSmaller(input);
    ASSERT_EQ(expectedOutput, output);
}

TEST(Segment_Tree, count_smaller_after_self_5)
{
    std::vector<int> input;
    for (int i = 1000; i > 0; i--)
    {
        input.push_back(i);
    }

    std::vector<int> expectedOutput;
    for (int i = 1000; i > 0; i--)
    {
        expectedOutput.push_back(i - 1);
    }

    auto output = countSmaller(input);
    ASSERT_EQ(expectedOutput, output);
}

std::vector<int> countSmaller(std::vector<int> &nums)
{
    int offset = 1e4;
    SegmentTree st((offset * 2) + 1);
    std::vector<int> smaller(nums.size());
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        smaller[i] = st.query(0, nums[i] + offset);
        st.update(nums[i] + offset, 1);
    }

    return smaller;
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}