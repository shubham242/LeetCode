class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int l = nums.size();
        int *a = new int[l];
        for (int i = 0; i < l; i++)
            a[i] = 0;

        for (auto i : nums)
            if (a[i] == 1)
                return i;
            else
                a[i] = 1;
        return -1;
    }
};