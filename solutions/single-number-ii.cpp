/*
 * https://oj.leetcode.com/problems/single-number-ii/
 * */
#include <gtest/gtest.h>

namespace {
class Solution {
public:
    int singleNumber(int A[], int n) {

        int ones = 0, twos = 0, threes = 0;
        for (int i = 0; i < n; ++i)
        {
           twos |= (ones & A[i]);
           ones ^= A[i];
           threes = ones & twos;
           ones &= ~threes;
           twos &= ~threes;
        }

        return ones;
    }
};

}

TEST(single_number_ii, case1)
{
    int A[] = {1,2,3,2,1,2,1};
    EXPECT_EQ(Solution().singleNumber(A, 7), 3);
}

