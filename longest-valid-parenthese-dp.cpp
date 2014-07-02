#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string const& s) {
        size_t length = s.size();
        if (length < 2)
            return 0;

        vector<int> v(length);
        int m = 0;
        for(size_t i = 1; i < length; ++i)
        {
            if (s[i] == '(')
                v[i] = 0;
            else if (s[i] == ')')
            {
                size_t j = i - v[i-1] - 1;
                if (s[j] == '(')
                {
                    v[i] = 2 + v[i-1];
                    if (j >= 1)
                        v[i] += v[j-1];
                }
            }
            m = max(m, v[i]);
        }

        return m;
    }
};

int main()
{
    string s = "()(())";
    cout << Solution().longestValidParentheses(s) << endl;
}

