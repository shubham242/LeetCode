class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int l = nums.size();

        unordered_map<int, int> mp;
        mp[nums[0]] = 0;
        for (int i = 1; i < l; i++)
        {
            nums[i] += nums[i - 1];
            mp[nums[i]] = i;
        }

        int toFind = nums[l - 1] - x;
        int maxLen = -1;

        if (toFind < 0)
            return -1;
        else if (toFind == 0)
            return l;

        for (int i = 0; i < l; i++)
        {
            if (nums[i] == toFind)
                maxLen = max(maxLen, i + 1);
            if (mp.find(nums[i] - toFind) != mp.end())
                maxLen = max(maxLen, abs(mp[nums[i] - toFind] - i));
        }
        if (maxLen == -1)
            return -1;
        return l - maxLen;
    }
};