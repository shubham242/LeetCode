class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), start = 0, end = 0;

        while (end < n) {
            if (nums[end] != 0) {
                swap(nums[start], nums[end]);
                start++;
            }
            end++;
        }
    }
};