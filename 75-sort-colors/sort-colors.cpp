class Solution {
   public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(), zero = 0, two = n - 1;

        for (int i = zero; i <= two; i++) {
            if (nums[i] == 0)
                swap(nums[i], nums[zero++]);
            else if (nums[i] == 2)
                swap(nums[i--], nums[two--]);
        }
    }
};