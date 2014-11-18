#include <cstddef>
#include <gtest/gtest.h>


class Solution {
public:
    int sqrt(int x) {
        if (x == 0)
            return 0;
        double d = x;
        for (std::size_t i = 0; i < 1000; ++i)
        {
            d = (d + x/d)/2;
        }

        return static_cast<int>(d);
    }
};


TEST(sqrt, case1)
{
    Solution s;

    EXPECT_EQ(s.sqrt(0), 0);
}

TEST(sqrt, case2)
{
    Solution s;
    EXPECT_EQ(s.sqrt(4), 2);
}

