class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int minl = nums.size() + 1;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            sum = 0;
            int j = i;
            while (sum < target && j < nums.size())
            {
                sum += nums[j];
                j++;
            }
            if (sum >= target)
                minl = min(minl, j - i);
        }

        if (minl == nums.size() + 1)
            return 0;
        else
            return minl;
    }
};