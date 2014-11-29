/*
 * https://oj.leetcode.com/problems/search-in-rotated-sorted-array/
 * */
#include <algorithm>
#include <gtest/gtest.h>


class Solution {
public:
    int search(int A[], int n, int target) {
        begin = A[0];
        end = A[n-1];
        int *it = std::lower_bound(A, A+n, target, *this);
        if (it == A+n || *it != target)
            return -1;
        return it - A;
    }

    bool operator() (int l, int r)
    {
        if (l < r)
           return cmp(l, r);
        else
           return !cmp(r, l);
    }

private:
    bool cmp(int l, int r) // l < r
    {
        if (l >= begin)
            return true;
        if (r <= end)
            return true;
        return false;
    }

private:
    int begin;
    int end;
};


TEST(search_in_rotated_sorted_array, case1)
{
    int A[] = {1,2,3,4,5};
    Solution s;
    EXPECT_EQ(s.search(A, 5, 3), 2);
    EXPECT_EQ(s.search(A, 5, 6), -1);
}

TEST(search_in_rotated_sorted_array, case2)
{
    int A[] = {3,4,5,6,0,1,2};
    Solution s;
    EXPECT_EQ(s.search(A, 7, 0), 4);
    EXPECT_EQ(s.search(A, 7, 8), -1);
}

