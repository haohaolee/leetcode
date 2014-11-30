/*
 *  https://oj.leetcode.com/problems/search-in-rotated-sorted-array-ii/
 * */
#include <algorithm>
#include <gtest/gtest.h>

namespace {

class Solution {
public:
    bool search(int A[], int n, int target) {
        if (n <= 0)
            return false;
        begin = A[0];
        while (A[--n] == begin && n > 0); // iterate to the one not equal to begin

        return std::binary_search(A, A+n+1, target, *this);
    }

    bool operator() (int l, int r)
    {
        if (l < r)
            return cmp(l, r);
        else if (l > r)
            return !cmp(r, l);
        else
            return false;
    }

private:
    bool cmp(int l, int r) // assuming l < r
    {
        if (l >= begin || r < begin)
            return true;
        return false;
    }

    int begin;
};

}

TEST(search_in_rotated_sorted_array_ii, case1)
{
    Solution s;
    int A[] = {1,1,2,2,3,3};

    EXPECT_TRUE(s.search(A, 6, 2));
    EXPECT_FALSE(s.search(A, 6, 4));
}


TEST(search_in_rotated_sorted_array_ii, case2)
{
    Solution s;
    int A[] = {1,3,1,1};

    EXPECT_TRUE(s.search(A, 4, 3));
    EXPECT_FALSE(s.search(A, 4, 7));
}

