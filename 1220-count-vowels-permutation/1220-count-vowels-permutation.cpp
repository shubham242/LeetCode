class Solution
{
public:
    int countVowelPermutation(int n)
    {
        int M = 1e9 + 7;
        long dp[5];
        long prev[5];
        memset(dp, 0, sizeof(dp));

        for (int j = 0; j < 5; j++)
            dp[j] = 1;
        for (int i = 1; i < n; i++)
        {
            copy(dp, dp + 5, prev);
            dp[0] = (prev[1]) % M;
            dp[1] = (prev[0] + prev[2]) % M;
            dp[2] = (prev[0] + prev[1] + prev[3] + prev[4]) % M;
            dp[3] = (prev[2] + prev[4]) % M;
            dp[4] = (prev[0]) % M;
        }

        return (dp[0] + dp[1] + dp[2] + dp[3] + dp[4]) % M;
    }
};