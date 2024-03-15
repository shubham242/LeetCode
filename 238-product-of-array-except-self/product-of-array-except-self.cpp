class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1, zero_count = 0;

        for (int num : nums)
            if (num == 0)
                zero_count++;
            else
                product *= num;

        if (zero_count == 0) {
            for (int& num : nums)
                num = product / num;
        } else if (zero_count == 1) {
            for (int& num : nums)
                if (num == 0)
                    num = product;
                else
                    num = 0;
        } else {
            for (int& num : nums)
                num = 0;
        }

        return nums;
    }
};