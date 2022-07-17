class Solution
{
public:
    bool divisorGame(int n)
    {
        bool dp[n + 1];
        dp[1] = false;
        for (int i = 2; i <= n; i++)
            if (i % 2)
                dp[i] = !dp[i - 1];
            else
                dp[i] = !dp[i - 1] || !dp[i / 2];

        return dp[n];
    }
};