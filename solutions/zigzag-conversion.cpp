/*
 *https://oj.leetcode.com/problems/zigzag-conversion/
 * */

#include <string>
#include <gtest/gtest.h>


namespace {

class Solution {
public:
	std::string convert(std::string const& s, int nRows) {
		std::size_t length = s.size();
		std::string r = s;
		std::size_t rindex = 0;
		std::size_t zigsize = 2 * nRows - 2;
		for (int i = 0; i < nRows; ++i)
		{
			std::size_t size = zigsize - 2 * i;
			std::size_t size_2 = zigsize - size;
			std::size_t index = i;
			while (index < length)
			{
				r[rindex++] = s[index];

				if (size == 0)
				{
                    if (size_2 == 0)
						break;
					index += size_2;
				}
				else if (size_2 == 0)
				{
					index += size;
				}
				else
				{
					index += size;
					if (index >= length)
						break;
					r[rindex++] = s[index];
					index += size_2;
				}

			}
		}
		return r;
	}
};

}

TEST(zigzag_conversion, case1)
{
    Solution s;
    std::string l = s.convert("PAYPALISHIRING", 3);
    std::string r = "PAHNAPLSIIGYIR";
    EXPECT_EQ(l, r); 
}

TEST(zigzag_conversion, case2)
{
    Solution s;
    std::string l = s.convert("A", 1);
    std::string r = "A";
    EXPECT_EQ(l, r); 
}


