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
        int dp[(int)strs.size() + 1][m + 1][n + 1];
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= strs.size(); i++)
        {
            pair<int, int> str = parse(strs[i - 1]);
            for (int j = 0; j <= m; j++)
                for (int k = 0; k <= n; k++)
                    if (str.first <= j && str.second <= k)
                        dp[i][j][k] = max(dp[i - 1][j][k], 1 + dp[i - 1][j - str.first][k - str.second]);
                    else
                        dp[i][j][k] = dp[i - 1][j][k];
        }

        return dp[strs.size()][m][n];
    }
};