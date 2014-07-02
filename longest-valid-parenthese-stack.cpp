#include <stack>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string const& s) {
        stack<size_t> index_stack; // index of '('
        stack<pair<size_t, size_t> > range_stack; // range of every valid pair 

        for(string::const_iterator it = s.begin();it != s.end(); ++it)
        {
            if(*it == '(')
            {
                index_stack.push(it - s.begin());
            }
            else if(*it == ')')
            {
                if(!index_stack.empty())
                {
                    size_t start = index_stack.top();
                    index_stack.pop();

                    size_t end = it - s.begin();
                    while (!range_stack.empty())
                    {
                        pair<size_t, size_t> range = range_stack.top();
                        if (range.first > start && range.second < end)
                        {
                            range_stack.pop();
                        }
                        else if (range.second + 1 == start)
                        {
                            start = range.first;
                            range_stack.pop();
                        }
                        else
                            break;
                    }
                    range_stack.push(make_pair(start, it - s.begin()));
                }
            }
        }
        
        int max = 0;
        while (!range_stack.empty())
        {
            pair<size_t, size_t> range = range_stack.top();
            range_stack.pop();
            size_t length = range.second - range.first + 1;
            if (length > max)
                max = length;
        }
        return max;
    }
};

int main()
{
    string s = "()(())";
    cout << Solution().longestValidParentheses(s) << endl;
}

