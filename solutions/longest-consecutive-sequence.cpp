#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, bool> hash_map;
        for (vector<int>::const_iterator it = num.begin();
                it != num.end(); ++it)
        {
            hash_map.insert(make_pair(*it, false));
        }

        int max_length = 0;
        for (unordered_map<int, bool>::iterator it = hash_map.begin();
                it != hash_map.end(); ++it)
        {
            bool checked = it->second;
            if (checked)
                continue;

            it->second = true;
            int i = it->first;

            int target = i;
            int length = 1;
            while(check(--target, hash_map))
            {
                length++;
            }

            target = i;
            while(check(++target, hash_map))
            {
                length++;
            }

            max_length = max(max_length, length);
        }

        return max_length;
    }

private:
    bool check(int i, unordered_map<int, bool>& hash_map)
    {
        unordered_map<int, bool>::iterator it
                                    = hash_map.find(i);

        if (it == hash_map.end())
            return false;
        else
        {
            it->second = true;
            return true;
        }
    }
};


