#include <iostream>

// 0 red
// 1 white
// 2 blue
using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) {
       int temp[3] = {};
       for (size_t i = 0; i < n; ++i)
       {
           ++temp[A[i]];
       }

       size_t index = 0;
       for (size_t i = 0; i < 3; ++i)
           for (size_t j = 0; j < temp[i]; ++j)
           {
               A[index++] = i;
           }

    }
};

int main()
{
    int A[2] = {0, 1};
    Solution().sortColors(A, 2);
    for (int i : A)
        cout << i << ' ';
    cout.flush();
}

