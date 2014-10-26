#include <algorithm>
#include <iostream>

class Solution {
public:
    int maxSubArray(int A[], int n) {
        if (n == 0)
            return 0;

        int max = A[0];
        int current_sum = 0;

        for (int i = 0; i < n; ++i)
        {
            int temp = current_sum + A[i];
            if (temp <= 0)
                current_sum = 0;
            else
                current_sum = temp;

            max = std::max(temp, max);
        }
        return max;
    }
};

int main()
{
    int A[] = { -5, -1};
    std::cout << Solution().maxSubArray(A, 2) << std::endl;
}

