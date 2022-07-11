class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp;
        int res = 0;

        for (int i = 0; i < n; i++)
        {
            auto it = lower_bound(dp.begin(), dp.end(), nums[i]);

            if (it == dp.end())
                dp.push_back(nums[i]);
            else
                dp[it - dp.begin()] = nums[i];
        }

        return dp.size();
    }
};
