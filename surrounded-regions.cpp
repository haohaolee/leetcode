#include <set>
#include <queue>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

class Solution {
    set<pair<size_t, size_t> > points_set;

public:
    void solve(vector<vector<char>> &board) {
        size_t rows = board.size();
        if (rows <= 2)
            return;

        size_t columns = board[0].size();

        if (columns <= 2)
            return;

        for(size_t i = 0; i < columns; ++i)
        {
            process(board, 0, i);
            process(board, rows-1, i);
        }

        for(size_t j = 1; j < rows - 1; ++j)
        {
            process(board, j, 0);
            process(board, j, columns - 1);
        }

        for(size_t i = 1; i < rows - 1; ++i)
            for(size_t j = 1; j < columns - 1; ++j)
            {
                if(board[i][j] == 'O'
                   && points_set.find(make_pair(i, j)) ==  points_set.end())
                    board[i][j] = 'X';
            }

    }

private:
    void process(vector<vector<char> > &board, size_t row, size_t column)
    {
        char c =  board[row][column];
        if (c == 'O'
            && points_set.find(make_pair(row , column)) == points_set.end())
        {
           BFS(board, row, column);
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
        size_t rows = board.size();
        size_t columns = board[0].size();
        if (x < 0 || y < 0 || x >= rows || y >= columns)
            return false;
        if (board[x][y] == 'O' &&
            points_set.find(make_pair(x, y)) == points_set.end())
            return true;
        else
            return false;
    }
};

int main()
{
    vector<vector<char> > v = {
        { 'X', 'O', 'X', 'O', 'X', 'O' },
        { 'O', 'X', 'O', 'X', 'O', 'X' },
        { 'X', 'O', 'X', 'O', 'X', 'O' },
        { 'O', 'X', 'O', 'X', 'O', 'X' }
    };

    Solution s;
    s.solve(v);

    for(auto &row : v)
    {
        for(auto &i : row)
        {
            cout << i << ' ';
        }
        cout << '\n';
    }

}
