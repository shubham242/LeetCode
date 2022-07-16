class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int l = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0)
            return false;

        int dp[total / 2 + 1];
        memset(dp, 0, sizeof(dp));

        if (nums[0] <= total / 2)
            dp[nums[0]] = 1;
        dp[0] = 1;

        for (int i = 1; i < l; i++)
        {
            int prev[total / 2 + 1];
            copy(&dp[0], &dp[0] + (total / 2 + 1), &prev[0]);

            for (int j = 0; j < total / 2 + 1; j++)
                if (j - nums[i] >= 0)
                    dp[j] = prev[j - nums[i]] || prev[j];
                else
                    dp[j] = prev[j];
        }

        return dp[total / 2];
    }
};