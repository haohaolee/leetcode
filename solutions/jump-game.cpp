/*
 * https://oj.leetcode.com/problems/jump-game/
 * */
#include <algorithm>
#include <gtest/gtest.h>

namespace {

class Solution {
public:
    bool canJump(int A[], int n) {
        int longest_distance = 0;
        for (int i = 0; i < n; ++i)
        {
            if (longest_distance < i)
                return false;

            longest_distance = std::max(
                                longest_distance,
                                A[i] + i
                                );
            if (longest_distance >= n - 1)
                return true;
        }

        return false;
    }
};

}


TEST(jump_game, case1)
{
    Solution s;
    int A[] = {2,3,1,1,4};
    EXPECT_TRUE(s.canJump(A, 5));

    int B[] = {3,2,1,0,4};
    EXPECT_FALSE(s.canJump(B, 5));
}


