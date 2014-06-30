#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


class Solution {
public:
    void reverseWords(string &s) {

        reverse(s.begin(), s.end());

        size_t boundary_start = string::npos;
        size_t start = 0;
        while((boundary_start = s.find_first_not_of(' ', start)) != string::npos)
        {
            size_t boundary_end = s.find_first_of(' ', boundary_start);
            string::iterator begin = s.begin() + boundary_start;
            string::iterator end = (boundary_end == string::npos) ? s.end() : s.begin() + boundary_end;
            reverse(begin, end);
            start = boundary_end;
        }

        string::iterator new_end = unique(s.begin(), s.end(), op());
        s.erase(new_end, s.end());
        s.erase(0, s.find_first_not_of(' '));
        s.erase(s.find_last_not_of(' ') + 1);
    }

    struct op
    {
        bool operator() (const char& s1, const char& s2)
        {
            return s1 == ' ' && s1 == s2;
        }
    };


};

int main()
{
    string str = "the sky is blue";
    Solution s;
    s.reverseWords(str);
    cout << str << endl;
}

