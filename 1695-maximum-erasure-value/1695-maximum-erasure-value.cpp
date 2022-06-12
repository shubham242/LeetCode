class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int l = nums.size();
        unordered_map<int, int> mp;
        int start = -1;
        int maxLen = nums[0];
        mp[nums[0]] = 0;
        for (int i = 1; i < l; i++)
        {
            if (mp.find(nums[i]) != mp.end())
                start = max(start, mp[nums[i]] + 1);
            mp[nums[i]] = i;

            nums[i] += nums[i - 1];
            maxLen = max(maxLen, nums[i] - (start > 0 ? nums[start - 1] : 0));
        }

        return maxLen;
    }
};