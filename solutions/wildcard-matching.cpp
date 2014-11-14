#include <gtest/gtest.h>

class Solution {
public:
    bool isMatch(const char *s, const char *p)
    {
        if (s == 0 || p == 0)
            return false;
        return matchHere2(s, p);
    }

private:
    bool matchHere2(const char *s, const char *p)
    {
        const char *last_star = 0;
        const char *last_begin = 0;
        while (true)
        {
            if (*p == '*')
            {
                last_star = p;
                last_begin = s;
                p++;
            }
            else if (*s == 0)
                break;
            else if (*p == *s || *p == '?')
            {
                p++; s++;
            }
            else
            {
                if (last_star== 0)
                    return false;
                p = last_star + 1;
                s = ++last_begin;
            }
        }

        return *p == 0;
    }
};

TEST(wildcard_matching, case1)
{
    Solution s;
    EXPECT_TRUE(s.isMatch("aa", "aa"));
    EXPECT_FALSE(s.isMatch("aaa", "aa"));
    EXPECT_TRUE(s.isMatch("aa", "*?"));
}

