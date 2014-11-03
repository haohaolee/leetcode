#include <iostream>
#include <algorithm>

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n < 2)
            return n;
        int curr_index = 0;
        while (curr_index < n - 1)
        {
            int current = A[curr_index];
            int search_index = curr_index + 1;
            while (A[search_index] == current && search_index < n)
                ++ search_index;

            if (search_index == n)
                return curr_index + 1;

            if (search_index != curr_index + 1);
                std::copy(A + search_index, A + n, A + curr_index + 1);

            n = n - (search_index - curr_index - 1);
            curr_index++;
        }
        return n;
    }

    int removeDuplicates2(int A[], int n)
    {
        if (n < 2)
            return n;

        int curr_index = n - 1;
        while (curr_index > 0)
        {
            int current = A[curr_index];
            int search_index = curr_index - 1;
            while (search_index >= 0 && A[search_index] == current)
                search_index--;

            if (search_index != curr_index - 1)
                std::copy(A + curr_index, A + n, A + search_index + 1);

            n -= (curr_index - search_index - 1);
            curr_index = search_index;
        }

        return n;

    }
};

int main()
{
    int A[] = {1, 1, 2, 2, 2, 3};
    int n = Solution().removeDuplicates2(A, 6);
    for (int i = 0; i < n; ++i)
    {
        std::cout << A[i] << ' ';
    }
    std::cout << std::endl;
}

