class Solution {
   public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int mp[2 * n + 1];
        memset(mp, -1, sizeof(mp));
        int sum = 0, maxLen = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i] == 0 ? -1 : 1;
            if (sum == 0)
                maxLen = max(maxLen, i + 1);
            else if (mp[sum + n] != -1)
                maxLen = max(maxLen, i - mp[sum + n]);
            else
                mp[sum + n] = i;
        }
        return maxLen;
    }
};