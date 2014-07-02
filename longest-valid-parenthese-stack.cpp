#include <stack>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string const& s) {
        stack<size_t> index_stack; // index of the last unmatched index
        int m = 0;
        for(string::const_iterator it = s.begin(); it != s.end();
                ++it)
        {
            size_t i = it - s.begin();
            if (*it == ')' && !index_stack.empty()
                    && s[index_stack.top()] == '(') // if current char is ) try to match the corresponding (
                                                    // if not matched or is not ) push the index
            {
                index_stack.pop();
                if (index_stack.empty())
                {
                    m = i + 1;
                }
                else
                {
                    int distance = i - index_stack.top();
                    m = max(m, distance);
                }
            }
            else
                index_stack.push(i);
        }

        return m;
    }
};

int main()
{
    string s = "()(())";
    cout << Solution().longestValidParentheses(s) << endl;
}

