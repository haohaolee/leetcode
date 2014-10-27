#include <algorithm>
#include <iostream>
#include <limits>


class Solution {
public:
    int maxSubArray(int A[], int n) {
        return divideConquer(A, 0, n-1);
    }

    int divideConquer(int A[], int left, int right)
    {
        if (left > right)
            return std::numeric_limits<int>::min();
        if (left == right)
            return A[left];

        int mid = (left + right) / 2;

        int leftmax = divideConquer(A, left, mid - 1);
        int rightmax = divideConquer(A, mid + 1, right);

        int midmax = A[mid];
        for (int i = mid - 1, midsum = midmax; i >= left; --i)
        {
            midsum += A[i];
            if (midsum > midmax)
                midmax = midsum;
        }
        for (int i = mid + 1, midsum = midmax; i <= right; ++i)
        {
            midsum += A[i];
            if (midsum > midmax)
                midmax = midsum;
        }

        return std::max(std::max(leftmax, rightmax), midmax);
    }
};

int main()
{
    int A[] = {-2,1,-3,4,-1,2,1,-5,4};

    std::cout << Solution().maxSubArray(A, 9) << std::endl;
}

