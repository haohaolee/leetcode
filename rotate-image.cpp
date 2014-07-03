#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        size_t n = matrix.size();
        if (n == 0 && matrix[0].size() != n)
            return;

        for (size_t i = 0; i < n/2; ++i)
            for (size_t j = i; j < n-i-1; ++j)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = temp;
            }
    }
};

int main()
{
    vector<vector<int> > m = {
        { 1, 2, 3, 4},
        { 0, 0, 0, 0},
        { 0, 6, 0, 0},
        { 5, 0 ,0, 0}
    };

     
    for (auto &v : m)
    {
        for (auto &i : v)
        {
            cout << i << ' ';
        }
        cout << '\n';
    }


    Solution().rotate(m);
    
    for (auto &v : m)
    {
        for (auto &i : v)
        {
            cout << i << ' ';
        }
        cout << '\n';
    }
}

