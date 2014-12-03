/*
 * https://oj.leetcode.com/problems/jump-game-ii/
 * */
#include <utility>
#include <algorithm>
#include <gtest/gtest.h>

namespace {

class Solution {
public:
    int jump(int A[], int n) {
        std::pair<int, int> range(0, 0);
        for (int step = 1; step < n; ++step)
        {
            int begin = range.first;
            int end = range.second;

            int longest = 0;
            for (int i = begin; i <= end; ++i)
            {
                int jump_distance = A[i];
                longest = std::max(longest, i + jump_distance);
                if (longest >= n - 1)
                    return step;
            }
            range = std::make_pair(end + 1, longest);
        }

        return n - 1;
    }
};

}

TEST(jump_game_ii, case1)
{
    int A[] = {2,3,1,1,4};
    Solution s;
    EXPECT_EQ(s.jump(A, 5), 2);
}

TEST(jump_game_ii, case2)
{
    int A[] = {0};
    Solution s;
    EXPECT_EQ(s.jump(A, 1), 0);
}

