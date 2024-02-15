class Solution {
   public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        long long maxSum = -1;
        sort(nums.begin(), nums.end());
        vector<long long> prefixSum(n, 0);

        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++)
            prefixSum[i] = prefixSum[i - 1] + nums[i];

        for (int i = 2; i < n; i++)
            if (nums[i] < prefixSum[i - 1])
                maxSum = max(maxSum, prefixSum[i]);

        return maxSum;
    }
};