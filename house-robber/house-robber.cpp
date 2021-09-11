class Solution {
public:
    int rob(vector<int> &nums)
    {
        int l = nums.size();
        if(l==1)
            return nums[0];
        else if (l ==2)
            return max(nums[0], nums[1]);
        else if (l == 3)
            return max(nums[0] + nums[2], nums[1]);
        int dp[l];
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[2] + nums[0];

        for (int i = 3; i < l; i++)
            dp[i] = nums[i] + max(dp[i - 2], dp[i - 3]);

        return max(dp[l - 1], dp[l - 2]);
    }
};