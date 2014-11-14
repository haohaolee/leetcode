#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if (num.size() <= 1)
            return;

        vector<int>::reverse_iterator it = num.rbegin() + 1;

        while(it != num.rend()
                && *(it - 1) <= *it)
        {
            ++it;
        }

        if (it == num.rend())
            reverse(num.begin(), num.end());
        else
        {
            vector<int>::reverse_iterator it2 = num.rbegin();

            while (*it2 <= *it)
                ++it2;
            swap(*it, *it2);
            reverse(it.base(), num.end());
        }
    }
};

//int main()
//{
//    vector<int> v = {1, 3, 2};
//    Solution().nextPermutation(v);
//    for(auto i : v)
//        cout << i << ' ';
//    cout << endl;
//}

