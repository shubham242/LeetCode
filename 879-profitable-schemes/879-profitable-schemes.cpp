class Solution
{
public:
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        int l = group.size();
        int M = 1e9 + 7;
        long dp[minProfit + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        for (int i = l; i > 0; i--)
        {
            long prev[minProfit + 1][n + 1];
            copy(&dp[0][0], &dp[0][0] + (minProfit + 1) * (n + 1), &prev[0][0]);

            // for (int j = 0; j <= minProfit; j++)
            //     for (int k = 0; k <= n; k++)
            //         dp[j][k] = prev[j][k];

            for (int j = 0; j <= minProfit; j++)
                for (int k = 0; k <= n; k++)
                {
                    // dp[j][k] = prev[j][k];
                    if (k + group[i - 1] <= n)
                        dp[min(minProfit, j + profit[i - 1])][k + group[i - 1]] += prev[j][k] % M;
                }
        }
        long ans = 0;
        for (int i = 0; i <= n; i++)
            ans += dp[minProfit][i] % M;
        return ans % M;
    }
};