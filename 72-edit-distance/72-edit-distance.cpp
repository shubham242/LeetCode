class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();
        int dp[n + 1], prev[n + 1];
        memset(dp, 0, sizeof(dp));
        memset(prev, 0, sizeof(prev));

        for (int i = 0; i <= n; i++)
            dp[i] = i;

        for (int i = 1; i <= m; i++)
        {
            copy(&dp[0], &dp[0] + n + 1, &prev[0]);
            dp[0] = i;

            for (int j = 1; j <= n; j++)
                if (word1[i - 1] == word2[j - 1])
                    dp[j] = prev[j - 1];
                else
                    dp[j] = 1 + min({prev[j], dp[j - 1], prev[j - 1]});
        }

        return dp[n];
    }
};