class Solution
{
public:
    int countVowelPermutation(int n)
    {
        int M = 1e9 + 7;
        long dp[5][n];
        memset(dp, 0, sizeof(dp));

        for (int j = 0; j < 5; j++)
            dp[j][0] = 1;
        for (int i = 1; i < n; i++)
        {
            dp[0][i] = (dp[1][i - 1]) % M;
            dp[1][i] = (dp[0][i - 1] + dp[2][i - 1]) % M;
            dp[2][i] = (dp[0][i - 1] + dp[1][i - 1] + dp[3][i - 1] + dp[4][i - 1]) % M;
            dp[3][i] = (dp[2][i - 1] + dp[4][i - 1]) % M;
            dp[4][i] = (dp[0][i - 1]) % M;
        }

        return (dp[0][n - 1] + dp[1][n - 1] + dp[2][n - 1] + dp[3][n - 1] + dp[4][n - 1]) % M;
    }
};