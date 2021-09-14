class Solution {
public:
    int getMaxLen(vector<int> &nums)
    {
        int res = 0;
        int l = nums.size();
        int negCount = 0, currMax = 0;
        for (int i = 0; i < l; i++)
        {
            if (nums[i] == 0)
            {
                currMax = 0;
                negCount = 0;
            }
            else
            {
                if (nums[i] < 0)
                    negCount++;
                currMax++;
                if (negCount % 2 == 0)
                    res = max(res, currMax);
            }
        }
        negCount = 0;
        currMax = 0;
        for (int i = l - 1; i >= 0; i--)
        {
            if (nums[i] == 0)
            {
                currMax = 0;
                negCount = 0;
            }
            else
            {
                if (nums[i] < 0)
                    negCount++;
                currMax++;
                if (negCount % 2 == 0)
                    res = max(res, currMax);
            }
        }

        return res;
    }
};