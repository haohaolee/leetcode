#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};

struct comp {
    bool operator()(Interval const &l, Interval const &r)
    {
        return l.start < r.start;
    }
};

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> r;
        if (intervals.empty())
            return r;

        sort(intervals.begin(), intervals.end(), comp());

        Interval pre = intervals.front();
        vector<Interval>::const_iterator next_it = intervals.begin() + 1;
        while(next_it != intervals.end())
        {
            Interval const& next = *next_it;
            if (pre.end < next.start)
            {
                r.push_back(pre);
                pre = next;
            }
            else
            {
                if (pre.end < next.end)
                {
                    pre.end = next.end;
                }
            }
            ++next_it;
        }

        r.push_back(pre);

        return r;
    }
};

