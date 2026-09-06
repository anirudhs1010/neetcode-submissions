class Solution {
public:
    bool search(vector<vector<char>> board, int x, int y, int l, string word) {
        if (l == word.size())
            return true;
        if (x < 0 || y < 0 || y >= board[0].size() || x >= board.size() || board[x][y] != word[l])
            return false;
        char temp = board[x][y];
        board[x][y] = '*';
        bool found = search(board, x+1, y, l+1, word) || search(board, x, y+1, l+1, word) || 
        search(board, x-1, y, l+1, word) ||  search(board, x, y-1, l+1, word);
        board[x][y] = temp;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                cout << i << " " << j << endl;
                if (search(board, i, j, 0, word))
                    return true;
            }
        }
        return false;
    }
};
