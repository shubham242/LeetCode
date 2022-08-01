class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int dp[n];
        for (int i = 0; i < n; i++)
            dp[i] = 1;

        for (int i = 1; i < m; i++)
        {
            int prev[n];
            copy(dp, dp + n, prev);
            for (int j = 1; j < n; j++)
                dp[j] = prev[j] + dp[j - 1];
        }
        return dp[n - 1];
    }
};