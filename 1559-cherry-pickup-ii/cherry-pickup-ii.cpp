class Solution {
   public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> dp(grid[0].size(), vector<int>(grid[0].size(), 0));

        for (int r = rows - 1; r >= 0; r--) {
            vector<vector<int>> prev = dp;
            for (int c1 = cols - 1; c1 >= 0; c1--) {
                for (int c2 = cols - 1; c2 >= 0; c2--) {
                    for (int i = -1; i <= 1; i++)
                        for (int j = -1; j <= 1; j++)
                            if (c1 + i >= 0 && c1 + i < cols && c2 + j >= 0 && c2 + j < cols)
                                dp[c1][c2] = max(dp[c1][c2], prev[c1 + i][c2 + j]);
                    dp[c1][c2] += grid[r][c1] + (c1 != c2 ? grid[r][c2] : 0);
                }
            }
        }

        return dp[0][cols - 1];
    }
};