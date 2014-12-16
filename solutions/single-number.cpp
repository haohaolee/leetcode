/*
 * https://oj.leetcode.com/problems/single-number/
 * */

#include <gtest/gtest.h>

namespace {

class Solution {
public:
    int singleNumber(int A[], int n) {
        int r = 0;
        for (int i = 0; i < n; ++i)
        {
            r ^= A[i];
        }

        return r;
    }
};

}

TEST(single_number, case1)
{
    int A[] = {1,2,3,2,1};
    EXPECT_EQ(Solution().singleNumber(A, 5), 3);
}

