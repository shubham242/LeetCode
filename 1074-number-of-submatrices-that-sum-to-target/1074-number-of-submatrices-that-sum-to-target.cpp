class Solution
{
public:
    int numSubmatrixSumTarget(vector<vector<int>> &m, int target)
    {
        int l = m.size();
        int b = m[0].size();
        vector<vector<int>> dp(l + 1, vector<int>(b + 1, 0));

        for (int i = 1; i <= l; i++)
            for (int j = 1; j <= b; j++)
                dp[i][j] = m[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];

        int count = 0;

        for (int x1 = 1; x1 <= l; x1++)
            for (int x2 = x1; x2 <= l; x2++)
            {
                unordered_map<int, int> mp;
                mp.insert({0, 1});
                for (int y1 = 1; y1 <= b; y1++)
                {
                    count += mp[dp[x2][y1] - dp[x1 - 1][y1] - target];
                    mp[dp[x2][y1] - dp[x1 - 1][y1]]++;
                }
            }
        return count;
    }
};