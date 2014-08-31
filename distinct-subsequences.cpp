#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string const& S, string const& T) {

        size_t m = T.length(); // rabbit
        size_t n = S.length(); // rabbbit

        if (m > n)
            return 0;

        vector<vector<int> > dp(m + 1, vector<int>(n + 1));

        for (size_t i = 0; i <= n; ++i)
        {
            dp[0][i] = 1;
        }

        for (size_t i = 1; i <= m; ++i)
            for (size_t j = 1; j <= n; ++j)
        {
            dp[i][j]= dp[i][j-1];
            if (S[j-1] == T[i-1])
            {
                dp[i][j] += dp[i-1][j-1];
            }
        }

        return dp[m][n];
    }
};

int main()
{
    string s = "rabbbit";
    string t = "rabbit";
    cout << Solution().numDistinct(s, t) << endl;
}

