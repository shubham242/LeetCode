class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<int> dp(n);
        vector<int> temp = dp;
        for (int i = 0; i < n; i++)
            dp[i] = INT_MAX;
        dp[0] = triangle[0][0];

        for (int i = 1; i < n; i++)
        {
            temp = dp;
            for (int j = 0; j <= i; j++)
                temp[j] = triangle[i][j] + (j > 0 ? min(dp[j], dp[j - 1]) : dp[j]);
            dp = temp;
        }
        int ans = INT_MAX;
        for (auto i : dp)
            ans = min(ans, i);
        return ans;
    }
};