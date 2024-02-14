class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), start = 0, end = 0;

        for (int start = 0, end = 0; end < n; end++)
            if (nums[end] != 0)
                swap(nums[start], nums[end]), start++;
    }
};