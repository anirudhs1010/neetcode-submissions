class Solution {
public:
    string res;

    bool backtrack(vector<vector<char>> v, int l, int i , int j) {
        if (res.size() == l) {
            return true;
        }
     
        if (i < 0 || i >= v.size() || j < 0 || j >= v[0].size())
            return false;
        if (v[i][j] != res[l])
            return false;
        char temp = v[i][j];
        v[i][j] = '*';
        bool found = backtrack(v, l+1, i+1, j) || backtrack(v, l+1, i-1, j)
        || backtrack(v, l+1, i, j+1) || backtrack(v, l+1, i, j-1);
        v[i][j] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        res = word;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++)
                if (backtrack(board, 0, i, j))
                    return true;
        }
        return false;
    }
};
