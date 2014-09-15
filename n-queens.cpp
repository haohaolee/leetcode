#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {

vector<vector<string> > result;
typedef vector<size_t> queen_vec;
public:
    vector<vector<string> >& solveNQueens(int n) {
        queen_vec queens;
        queens.reserve(n);

        start_search(queens, static_cast<size_t>(n));

        return result;
    }

private:

    void add_solution(queen_vec const &q)
    {
        string s(q.size(), '.');
        vector<string> temp;
        for (size_t r = 0; r < q.size(); ++r)
        {
            size_t c = q[r];
            s[c] = 'Q';
            temp.push_back(s);
            s[c] = '.';
        }
        result.push_back(temp);
    }

    void start_search(queen_vec &queens, size_t total)
    {
        size_t row = queens.size();
        for (size_t i = 0; i < total; ++i)
        {
            size_t column = i;
            if(is_valid(column, row, queens))
            {
                queens.push_back(column);
                if (row == total-1)
                {
                    add_solution(queens);
                }
                else
                {
                    start_search(queens, total);
                }
                queens.pop_back();
            }
        }
    }


    bool is_valid(size_t column, size_t row, queen_vec const &q)
    {
        for(size_t r = 0; r < q.size(); ++r)
        {
            size_t c = q[r];
            if (c == column)
                return false;

            if (c + row
                == column + r)
                return false;

            if (c + r
                == column + row)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution S;
    vector<vector<string> > & re = S.solveNQueens(4);
    for (auto &v : re)
        for (auto &s : v)
        {
            cout << s << '\n';
        }
    cout.flush();
}

