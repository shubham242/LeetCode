class Solution {
   public:
    int solve(vector<vector<int>>& grid, int rows, int cols, int x, int y1, int y2, vector<vector<vector<int>>>& dp) {
        if (x >= rows || y1 >= cols || y2 >= cols || y1 < 0 || y2 < 0) return 0;
        if (dp[x][y1][y2] != -1) return dp[x][y1][y2];

        int ans = 0;
        if (y1 == y2)
            ans = grid[x][y1];
        else
            ans = grid[x][y1] + grid[x][y2];

        int next = 0;
        for (int i = -1; i <= 1; i++)
            for (int j = -1; j <= 1; j++)
                next = max(next, solve(grid, rows, cols, x + 1, y1 + i, y2 + j, dp));

        return dp[x][y1][y2] = ans + next;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), -1)));
        return solve(grid, grid.size(), grid[0].size(), 0, 0, grid[0].size() - 1, dp);
    }
};