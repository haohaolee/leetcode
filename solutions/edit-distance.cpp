/*
 *https://oj.leetcode.com/problems/edit-distance/
 * */
#include <string>
#include <algorithm>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int minDistance(const string& word1, const string& word2) {
        std::size_t l1 = word1.length();
        std::size_t l2 = word2.length();
        std::vector<std::vector<std::size_t> > D(l1+1, std::vector<std::size_t>(l2+1));

        for (std::size_t i = 1; i <= l1; ++i)
        {
            D[i][0] = i;
        }

        for (std::size_t i = 1; i <= l2; ++i)
        {
            D[0][i] = i;
        }

        D[0][0] = 0;

        for (std::size_t i = 1; i <= l1; ++i)
            for (std::size_t j = 1; j <= l2; ++j)
            {
                size_t m = std::min(D[i][j-1] + 1, D[i-1][j] + 1);
                D[i][j] = std::min(m, D[i-1][j-1] + one_char_distance(word1[i-1], word2[j-1]));
            }

        return D[l1][l2];
    }

private:
    static inline std::size_t one_char_distance(char l, char r)
    {
        return l == r ? 0 : 1;
    }
};


TEST(edit_distance, case1)
{
    Solution s;
    EXPECT_EQ(s.minDistance("a", "b"), 1);
}

TEST(edit_distance, case2)
{
    Solution s;
    EXPECT_EQ(s.minDistance("abcd", "dbcd"), 1);
}

TEST(edit_distance, case3)
{
    Solution s;
    EXPECT_EQ(s.minDistance("ab", "ab"), 0);
}

