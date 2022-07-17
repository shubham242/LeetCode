class Solution
{
public:
    int dp[46];
    int solve(int n)
    {
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = solve(n - 1) + solve(n - 2);
    }
    int climbStairs(int n)
    {
        memset(dp, -1, sizeof(dp));
        dp[1] = 1;
        dp[2] = 2;
        return solve(n);
    }
};