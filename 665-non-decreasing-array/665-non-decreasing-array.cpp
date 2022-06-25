class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        int n = nums.size();
        int pos = -1;

        for (int i = 0; i < n - 1; i++)
            if (nums[i + 1] < nums[i])
                if (pos == -1)
                    pos = i + 1;
                else
                    return false;

        if (pos > 1 && pos < n - 1)
            return nums[pos + 1] >= nums[pos - 1] || nums[pos] >= nums[pos - 2];
        else
            return true;
    }
};