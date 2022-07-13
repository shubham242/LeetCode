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
    int recurr(vector<string> &strs, int m, int n, int curr, vector<vector<vector<int>>> &dp)
    {
        pair<int, int> str = parse(strs[curr]);
        if (curr == 0)
        {
            if (str.first <= m && str.second <= n)
                return 1;
            else
                return 0;
        }
        if (dp[curr][m][n] != -1)
            return dp[curr][m][n];
        if (str.first <= m && str.second <= n)
            return dp[curr][m][n] = max(recurr(strs, m, n, curr - 1, dp), 1 + recurr(strs, m - str.first, n - str.second, curr - 1, dp));
        return dp[curr][m][n] = recurr(strs, m, n, curr - 1, dp);
    }
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return recurr(strs, m, n, strs.size() - 1, dp);
    }
};