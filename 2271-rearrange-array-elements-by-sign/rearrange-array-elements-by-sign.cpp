class Solution {
   public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size(), pos = 0, neg = 0;
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++)
            if (nums[i] >= 0)
                ans[2 * (pos++)] = nums[i];
            else
                ans[2 * (neg++) + 1] = nums[i];

        return ans;
    }
};