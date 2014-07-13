#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    string minWindow(string const &S, string const &T) {

        unordered_map<char, size_t> need_to_find;
        size_t total_count = 0;
        for (string::const_iterator it = T.begin();
                it != T.end(); ++it)
        {
            ++need_to_find[*it];
            ++total_count;
        }

        unordered_map<char, size_t> actually_found;
        size_t actually_count = 0;
        pair<size_t, size_t> range_index = {0, S.length()};

        for(size_t begin = 0, end = 0; end < S.length(); ++end)
        {
            if (need_to_find.find(S[end]) != need_to_find.end())
            {
                size_t count = ++actually_found[S[end]];
                if (count <= need_to_find[S[end]])
                    ++actually_count;

                if (actually_count == total_count)
                {
                    // a valid window found
                    while (begin <= end)
                    {
                        char curr = S[begin];
                        if (need_to_find.find(curr) == need_to_find.end())
                        {
                            // not valid char
                            ++begin;
                        }
                        else if (need_to_find[curr] < actually_found[curr])
                        {
                            ++begin;
                            --actually_found[curr];
                        }
                        else
                            break;
                    }

                    if (range_index.second - range_index.first
                        > end - begin)
                    {
                        range_index.second = end;
                        range_index.first = begin;
                    }

                }
            }
        }

        size_t length = range_index.second - range_index.first;

        if (length == S.length())
            return "";
        else
            return S.substr(range_index.first, length +1 );

    }
};

int main()
{
    string S = "a";
    string T = "a";
    cout << Solution().minWindow(S, T) << endl;
}

