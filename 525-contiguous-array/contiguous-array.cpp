class Solution {
   public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int sum = 0, maxLen = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i] == 0 ? -1 : 1;
            if (sum == 0)
                maxLen = max(maxLen, i + 1);
            else if (mp.find(sum) != mp.end())
                maxLen = max(maxLen, i - mp[sum]);
            else
                mp[sum] = i;
        }
        return maxLen;
    }
};