class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int le = j + 1, ri = n - 1;

                while (le < ri) {
                    long sum = (long)nums[i] + (long)nums[j] + (long)nums[le] + (long)nums[ri];
                    if (sum < target)
                        le++;
                    else if (sum > target)
                        ri--;
                    else {
                        ans.push_back({nums[i], nums[j], nums[le], nums[ri]});
                        le++;
                        ri--;
                        while (le < ri && nums[le] == nums[le - 1])
                            le++;
                        while (ri > le && nums[ri] == nums[ri + 1])
                            ri--;
                    }
                }
            }
        }

        return ans;
    }
};