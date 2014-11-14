#include <stack>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> sk;
        for (string::const_iterator cit = s.begin();
             cit != s.end(); ++cit)
        {
            char p;
            switch (*cit)
            {
                case '{':
                    sk.push('}');
                    break;
                case '(':
                    sk.push(')');
                    break;
                case '[':
                    sk.push(']');
                    break;
                default:
                {
                    if (sk.empty())
                        return false;

                    char pop = sk.top();
                    sk.pop();
                    if(pop != *cit)
                        return false;
                }

            }
        }

        return sk.empty();
    }
};

/*int main()
{
    string s = "()";
    cout << Solution().isValid(s) << endl;
}*/



