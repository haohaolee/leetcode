#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
       int l = lower_bound(A, n, target);
       if (l == -1)
           return vector<int>(2, -1);

       int u = upper_bound(A, n, target);

       int re[] = {l, u};
       return vector<int>(re, re+2);
    }

    vector<int> searchRange2(int A[], int n, int target)
    {
        int* l = std::lower_bound(A, A+n, target);
        if (l == A+n)
            return vector<int>(2, -1);

        int* u = std::upper_bound(A, A+n, target) - 1;

        int re[] = { l - A, u - A };
        return vector<int>(re, re+2);
    }

    int lower_bound(int A[], int n, int target)
    {
        int first = 0, last = n - 1;
        int count = last - first + 1;
        while (count > 0)
        {
            int step = count / 2;
            int mid = first + step;
            if (A[mid] < target )
            {
                first = mid + 1;
                count -= 1 + step;
            }
            else
            {
                count = step;
            }
        }

        if (A[first] == target)
            return first;
        return -1;
    }

    int upper_bound(int A[], int n, int target)
    {
        int first = 0, last = n - 1;
        int count = last - first + 1;

        while (count > 0)
        {
            int step = count / 2;
            int mid = first + step;
            if (A[mid] <= target )
            {
                first = mid + 1;
                count -= 1 + step;
            }
            else
            {
                count = step;
            }
        }

        if (A[first - 1] == target)
            return first - 1;
        return -1;
    }
};

