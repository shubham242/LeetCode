
class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return n;
        int prev = nums[1] - nums[0];
        int count = prev == 0 ? 1 : 2;

        for (int i = 1; i < n - 1; i++)
        {
            int curr = nums[i + 1] - nums[i];
            if ((curr > 0 && prev <= 0) || curr < 0 && prev >= 0)
            {
                count++;
                prev = curr;
            }
        }
        return count;
    }
};