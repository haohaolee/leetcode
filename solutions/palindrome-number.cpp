/*
 *http://leetcode.com/2012/01/palindrome-number.html
 * */

#include <gtest/gtest.h>

namespace {

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        int div = 1;
        while (x / div >= 10)
            div *= 10;

        while (div != 0)
        {
            int lastdigit = x % 10;
            int firstdigit = (x / div) % 10;

            if (lastdigit != firstdigit)
                return false;

            x /= 10;
            div /= 100;
        }

        return true;
    }
};

}

TEST(palindrome_number, case1)
{
    Solution s;
    EXPECT_TRUE(s.isPalindrome(1));
}

TEST(palindrome_number, case2)
{
    Solution s;
    EXPECT_FALSE(s.isPalindrome(-1));
}

TEST(palindrome_number, case3)
{
    Solution s;
    EXPECT_FALSE(s.isPalindrome(1000021));
}

