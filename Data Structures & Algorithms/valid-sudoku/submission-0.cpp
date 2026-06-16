class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
       set<int> rows[9];
       set<int> cols[9];
       set<int> subs[9];

       for (size_t i = 0; i < board.size(); i++)
       {
            for (size_t j = 0; j < board[i].size(); j++)
            {
                char val = board[i][j];
                if (val == '.')
                    continue ;
                if (rows[i].find(val) != rows[i].end())
                    return false;
                rows[i].insert(val);
                if (cols[j].find(val) != cols[j].end())
                    return false;
                cols[j].insert(val);
                int index = (i / 3) * 3 + j / 3;
                if (subs[index].find(val) != subs[index].end())
                    return false;
                subs[index].insert(val);
            }
       }
       return true;
    }
};
