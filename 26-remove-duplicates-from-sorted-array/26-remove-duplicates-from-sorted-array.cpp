class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int p = 0;
        int l = nums.size();
        for (int i = 0; i < l - 1; i++)
        {
            if (nums[i] != nums[i + 1])
            {
                nums[p] = nums[i];
                p++;
            }
        }
        nums[p] = nums[l - 1];

        return p + 1;
    }
};