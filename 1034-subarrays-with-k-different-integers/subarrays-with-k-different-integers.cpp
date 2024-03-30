class Solution {
   private:
    int subarray_with_atmost_k(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> _map;

        int left = 0, right = 0;
        int ans = 0;
        while (right < n) {
            _map[nums[right]]++;
            while (_map.size() > k) {
                _map[nums[left]]--;
                if (_map[nums[left]] == 0)
                    _map.erase(nums[left]);
                left++;
            }
            ans += right - left + 1;
            right++;
        }
        return ans;
    }

   public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int sub_with_max_element_k = subarray_with_atmost_k(nums, k);
        int reduced_sub_with_max_k = subarray_with_atmost_k(nums, k - 1);
        return (sub_with_max_element_k - reduced_sub_with_max_k);
    }
};