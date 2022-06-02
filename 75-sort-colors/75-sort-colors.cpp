class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int l = nums.size();
        int j = l - 1;
        while (j >= 0 && nums[j] == 2)
            j--;

        for (int i = 0; i < j; i++)
        {
            if (nums[i] == 2)
            {
                nums[i] = nums[i] + nums[j];
                nums[j] = nums[i] - nums[j];
                nums[i] = nums[i] - nums[j];
                j--;
                while (j >= 0 && nums[j] == 2)
                    j--;
            }
        }

        while (j >= 0 && nums[j] == 1)
            j--;

        for (int i = 0; i < j; i++)
        {
            if (nums[i] == 1)
            {
                nums[i] = nums[i] + nums[j];
                nums[j] = nums[i] - nums[j];
                nums[i] = nums[i] - nums[j];
                j--;
                while (j >= 0 && nums[j] == 1)
                    j--;
            }
        }
    }
};