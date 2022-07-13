class Solution
{
public:
    pair<int, int> parse(string str)
    {
        int zero = 0;
        int one = 0;
        for (int j = 0; j < str.size(); j++)
            str[j] == '1' ? one++ : zero++;
        return {zero, one};
    }
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= strs.size(); i++)
        {
            int prev[m + 1][n + 1];
            copy(&dp[0][0], &dp[0][0] + (m + 1) * (n + 1), &prev[0][0]);
            pair<int, int> str = parse(strs[i - 1]);
            for (int j = 0; j <= m; j++)
                for (int k = 0; k <= n; k++)
                    if (str.first <= j && str.second <= k)
                        dp[j][k] = max(prev[j][k], 1 + prev[j - str.first][k - str.second]);
                    else
                        dp[j][k] = prev[j][k];
        }

        return dp[m][n];
    }
};
