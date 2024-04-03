class Solution {
   public:
    bool dfs(vector<vector<char>>& board, string word, int x, int y, int count, vector<vector<bool>>& vis) {
        if (count == word.size())
            return true;
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || vis[x][y] || board[x][y] != word[count])
            return false;
        vis[x][y] = true;
        bool found = dfs(board, word, x + 1, y, count + 1, vis) ||
                     dfs(board, word, x - 1, y, count + 1, vis) ||
                     dfs(board, word, x, y + 1, count + 1, vis) ||
                     dfs(board, word, x, y - 1, count + 1, vis);
        vis[x][y] = false;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (dfs(board, word, i, j, 0, vis))
                    return true;
        return false;
    }
};