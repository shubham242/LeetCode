class Solution
{
public:
    int getMaximumGenerated(int n)
    {
        if (n < 2)
            return n;
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        int c = 1;
        for (int i = 2; i <= n; i++)
            c = max(c, dp[i] = i % 2 ? dp[(i - 1) / 2] + dp[(i + 1) / 2] : dp[i / 2]);
        return c;
    }
};