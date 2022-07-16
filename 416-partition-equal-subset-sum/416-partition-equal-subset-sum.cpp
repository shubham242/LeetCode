class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int l = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0)
            return false;

        int dp[l][total + 1];
        memset(dp, 0, sizeof(dp));

        dp[0][nums[0]] = 1;
        dp[0][0] = 1;
        for (int i = 1; i < l; i++)
            for (int j = 0; j < total / 2 + 1; j++)
                if (j - nums[i] >= 0)
                    dp[i][j] = dp[i - 1][j - nums[i]] || dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];

        return dp[l - 1][total / 2];
    }
};