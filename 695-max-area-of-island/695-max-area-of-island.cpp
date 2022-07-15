class Solution
{
public:
    int solve(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] == 0)
            return 0;

        grid[i][j] = 0;
        return 1 +
               solve(grid, i + 1, j) +
               solve(grid, i - 1, j) +
               solve(grid, i, j + 1) +
               solve(grid, i, j - 1);
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int maxx = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1)
                    maxx = max(maxx, solve(grid, i, j));

        return maxx;
    }
};