/*
 * https://oj.leetcode.com/problems/minimum-path-sum/
 * */

#include <vector>
#include <gtest/gtest.h>

namespace {

class Solution {
public:
    int minPathSum(std::vector<std::vector<int> > &grid) {
        if (grid.empty())
            return 0;
        std::size_t n = grid[0].size();
        std::size_t m = grid.size();

        std::vector<std::vector<int> >
                    sum_vec(m, std::vector<int>(n));

        sum_vec[0][0]  = grid[0][0];
        for (std::size_t i = 1; i < m; ++i)
        {
            sum_vec[i][0] = sum_vec[i-1][0] + grid[i][0];
        }

        for (std::size_t i = 1; i < n; ++i)
        {
            sum_vec[0][i] = sum_vec[0][i-1] + grid[0][i];
        }

        for (std::size_t i = 1; i < m; ++i)
            for (std::size_t j = 1; j < n; ++j)
            {
                sum_vec[i][j] = std::min(sum_vec[i-1][j], sum_vec[i][j-1])
                                        + grid[i][j];
            }

        return sum_vec[m-1][n-1];
    }
};

}

TEST(minimum_path_sum, case1)
{
    std::vector<std::vector<int> > v =
    {
        {1, 2},
        {5, 6},
        {1, 1}
    };

    Solution s;
    EXPECT_EQ(s.minPathSum(v), 8);
}

