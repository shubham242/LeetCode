class Solution {
   public:
    bool dfs(vector<vector<char>>& board, string word, int x, int y, int count) {
        if (count == word.size())
            return true;
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != word[count])
            return false;
        char temp = board[x][y];
        board[x][y] = '*';
        bool found = dfs(board, word, x + 1, y, count + 1) ||
                     dfs(board, word, x - 1, y, count + 1) ||
                     dfs(board, word, x, y + 1, count + 1) ||
                     dfs(board, word, x, y - 1, count + 1);
        board[x][y] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (dfs(board, word, i, j, 0))
                    return true;
        return false;
    }
};