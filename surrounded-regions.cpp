#include <set>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

class Solution {
    set<pair<size_t, size_t> > points_set;
    size_t rows;
    size_t columns;

public:
    void solve(vector<vector<char>> &board) {
        rows = board.size();
        columns = board[0].size();
        for(size_t i = 0; i < columns; ++i)
        {
            process(board, 0, i);
            process(board, rows-1, i);
        }
        if (rows > 2)
        {
            for(size_t j = 1; j < rows - 1; ++j)
            {
                process(board, j, 0);
                process(board, j, columns - 1);
            }
        }
    }

private:
    void process(vector<vector<char> > &board, size_t i, size_t j)
    {
        char c =  board[i][j];
        if (c == 'O'
            && points_set.find(make_pair(i , j) == points_set.end()))
        {
           BFS(board, i, j);
        }
    }

    void BFS(vector<vector<char> > &board, size_t i, size_t j)
    {
        queue<pair<size_t, size_t> > points;
        points.push(make_pair(i, j));
        while (!points.empty())
        {
            pair<size_t, size_t> p = points.front();
            points.pop();
            size_t x = p.first;
            size_t y = p.second;
            points_set.insert(p); // valid O

            if (isValid(board, x - 1, y))
                points.push(make_pair(x - 1, y));

            if (isValid(board, x, y - 1))
                points.push(make_pair(x, y - 1));

            if (isValid(board, x + 1, y))
                points.push(make_pair(x + 1, y));

            if (isValid(board, x, y + 1))
                points.push(make_pair(x, y + 1));
        }
    }

    bool isValid(vector<vector<char> > &board, int x, int y)
    {

    }
};


