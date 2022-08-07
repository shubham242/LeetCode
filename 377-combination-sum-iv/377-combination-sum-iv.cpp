class Solution
{
public:
    int dp[1001];
    int recurr(vector<int> &nums, int target)
    {
        if (target < 0)
            return 0;
        if (target == 0)
            return 1;
        if (dp[target] != -1)
            return dp[target];
        int sum = 0;

        for (int i = 0; i < nums.size(); i++)
            sum += recurr(nums, target - nums[i]);
        return dp[target] = sum;
    }
    int combinationSum4(vector<int> &nums, int target)
    {
        memset(dp, -1, sizeof(dp));
        return recurr(nums, target);
    }
};