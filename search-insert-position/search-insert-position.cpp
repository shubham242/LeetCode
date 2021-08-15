class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int s = 0;
        int e = nums.size() - 1;
        while (s <= e)
        {
            if (nums[s + (e - s) / 2] < target)
                s = s + (e - s) / 2+1;
            else
                e = s + (e - s) / 2-1;
        }
        return s + (e - s) / 2;
    }
};