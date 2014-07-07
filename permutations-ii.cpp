#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > v;
        sort(num.begin(), num.end());
        do {
            v.push_back(num);
        }
        while(next_permutation(num.begin(), num.end()));

        return v;
    }

};

int main()
{
    vector<int> num = {1, 1, 2};
    vector<vector<int>> r = Solution().permuteUnique(num);
    for(auto &v: r)
    {
        for(auto i: v)
        {
            cout << i << ' ';
        }
        cout << '\n';
    }
}

