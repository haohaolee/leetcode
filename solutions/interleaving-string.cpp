/*
*https://oj.leetcode.com/problems/interleaving-string/
 * */

#include <string>
#include <gtest/gtest.h>

namespace {
class Solution {
public:
    bool isInterleave(std::string const& s1,
                    std::string const& s2,
                    std::string const& s3) {

        if (s1.size() + s2.size() != s3.size())
            return false;

        std::vector<std::vector<bool> > match(
                s1.size() + 1, std::vector<bool>(s2.size() + 1, false)
                ); 

        match[0][0] = true;
        for (std::size_t i = 1; i <= s1.size(); ++i)
        {
            if (s1[i-1] == s3[i-1])
                match[i][0] = true;
        }
        
        for (std::size_t i = 1; i <= s2.size(); ++i)
        {
            if (s2[i-1] == s3[i-1])
                match[0][i] = true;
        }

        for (std::size_t i = 1; i <= s1.size(); ++i)
        {
            char c1 = s1[i-1];
            for (std::size_t j = 1; j <= s2.size(); ++j)
            {
                char c2 = s2[j-1];
                char c3 = s3[i+j-1];
                if (c1 == c3)
                {
                    match[i][j] = match[i-1][j];
                }

                if (!match[i][j] && c2 == c3)
                {
                    match[i][j] = match[i][j-1];
                }
            }
        }

        return match[s1.size()][s2.size()];
    }
};

}


TEST(interleaving_string, case1)
{
    Solution s;
    EXPECT_TRUE(s.isInterleave("aabcc", "dbbca" ,"aadbbcbcac"));
}


