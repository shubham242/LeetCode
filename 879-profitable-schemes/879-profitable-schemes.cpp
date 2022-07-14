class Solution
{
public:
    long dp[101][101][101];
    int M = 1e9 + 7;
    int solve(int n, int minProfit, vector<int> &group, vector<int> &profit, int index)
    {
        if (n == 0)
            return minProfit <= 0;
        if (index == group.size())
            return minProfit <= 0;
        if (dp[n][minProfit][index] != -1)
            return dp[n][minProfit][index];
        int res = solve(n, minProfit, group, profit, index + 1) % M;
        if (group[index] <= n)
            res += solve(n - group[index], max(0, minProfit - profit[index]), group, profit, index + 1) % M;
        return dp[n][minProfit][index] = res % M;
    }
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        memset(dp, -1, sizeof(dp));
        return solve(n, minProfit, group, profit, 0) % M;
    }
};