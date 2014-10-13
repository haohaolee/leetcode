#include <vector>

using namespace std;

class Solution {
public:
    //recursive
//    int uniquePaths(int m, int n) {
//        if (m == 1 || n == 1)
//            return 1;
//
//        return uniquePaths(m-1, n) + uniquePaths(m, n-1);
//    }

    int uniquePaths(int m, int n)
    {
        vector<vector<int> > re(m+1, vector<int>(n+1));

        for (int i = 1; i <= n; ++i)
        {
            re[1][i] = 1;
        }

        for (int i = 1; i <= m; ++i)
        {
            re[i][1] = 1;
        }

        for (int i = 2; i <= m; ++i)
        {
            for (int j = 2; j <= n; ++j)
            {
                re[i][j] = re[i-1][j] + re[i][j-1];
            }
        }

        return re[m][n];
    }
};

