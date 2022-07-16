class Solution
{
public:
    int dp[201][20001];
    int solve(vector<int> &nums, int i, int sum, int total)
    {
        if (sum == total / 2)
            return 1;

        if (i >= nums.size())
            return 0;

        if (sum > total / 2)
            return 0;

        if (dp[i][sum] != -1)
            return dp[i][sum];

        return dp[i][sum] = solve(nums, i + 1, sum + nums[i], total) || solve(nums, i + 1, sum, total);
    }
    bool canPartition(vector<int> &nums)
    {
        memset(dp, -1, sizeof(dp));
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0)
            return false;
        return solve(nums, 0, 0, total);
    }
};