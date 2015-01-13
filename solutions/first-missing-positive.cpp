/*
 * https://oj.leetcode.com/problems/first-missing-positive/
 * */
#include <algorithm>
#include <gtest/gtest.h>

namespace {
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for (int i = 0; i < n; ++i)
        {
            loopSwap(A, n, i);
        }

        for (int i = 0; i < n; ++i)
        {
            if (i+1 != A[i])
                return i+1;
        }
        return n+1;
    }

    void loopSwap(int A[], int n, int index)
    {
        int expect = index + 1;
        int target = A[index];
        while (target > 0 && target <= n && expect != target)
        {
            std::swap(A[index], A[target-1]);
            if (target == A[index])
                break;
            target = A[index];
        }
    }
};
}

TEST(first_missing_positive, case1)
{
    Solution s;
    int A[] = {1,1};
    EXPECT_EQ(s.firstMissingPositive(A, 2), 2);
}

TEST(first_missing_positive, case2)
{
    Solution s;
    int A[] = {3,4,-1,1};
    EXPECT_EQ(s.firstMissingPositive(A, 4), 2);
}

