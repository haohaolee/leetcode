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
        v[length - 1] = 0;
        for(int i = length - 2; i >=0; --i)
        {
            if (s[i] == ')')
                v[i] = 0;
            else if (s[i] == '(')
            {
                int j = i + 1 + v[i+1];
                if (j < length && s[j] == ')')
                {
                    v[i] = 2 + v[i+1];
                    if (j + 1 < length)
                        v[i] += v[j+1];
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

