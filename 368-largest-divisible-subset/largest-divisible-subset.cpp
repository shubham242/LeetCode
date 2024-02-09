class Solution {
   public:
    vector<int> solve(vector<int>& nums, int size, int index, int prev_index, vector<vector<vector<int>>>& dp) {
        if (index == size)
            return vector<int>();
        if (dp[index][prev_index + 1].size() != 0)
            return dp[index][prev_index + 1];
        vector<int> ans1 = solve(nums, size, index + 1, prev_index, dp);
        vector<int> ans2;
        if (prev_index == -1 || nums[index] % nums[prev_index] == 0) {
            ans2 = solve(nums, size, index + 1, index, dp);
            ans2.push_back(nums[index]);
        }

        return dp[index][prev_index + 1] = (ans1.size() > ans2.size() ? ans1 : ans2);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<vector<vector<int>>> dp(nums.size(), vector<vector<int>>(nums.size() + 1, vector<int>()));
        sort(nums.begin(), nums.end());
        return solve(nums, nums.size(), 0, -1, dp);
    }
};