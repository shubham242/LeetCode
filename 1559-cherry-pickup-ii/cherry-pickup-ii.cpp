class Solution {
   public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), 0)));

        for (int y1 = 0; y1 < cols; y1++)
            for (int y2 = 0; y2 < cols; y2++)
                dp[rows - 1][y1][y2] = grid[rows - 1][y1] + (y1 != y2 ? grid[rows - 1][y2] : 0);

        for (int r = rows - 2; r >= 0; r--) {
            for (int c1 = cols - 1; c1 >= 0; c1--) {
                for (int c2 = cols - 1; c2 >= 0; c2--) {
                    for (int i = -1; i <= 1; i++)
                        for (int j = -1; j <= 1; j++)
                            if (c1 + i >= 0 && c1 + i < cols && c2 + j >= 0 && c2 + j < cols)
                                dp[r][c1][c2] = max(dp[r][c1][c2], dp[r + 1][c1 + i][c2 + j]);
                    dp[r][c1][c2] += grid[r][c1] + (c1 != c2 ? grid[r][c2] : 0);
                }
            }
        }
        
        return dp[0][0][cols - 1];
    }
};