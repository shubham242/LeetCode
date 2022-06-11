class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int l = nums.size();
        int total = 0;
        for (int i = 0; i < l; i++)
            total += nums[i];

        int toFind = total - x;
        int maxLen = -1;
        int sum = 0, i = 0, j = 0;

        if (toFind < 0)
            return -1;
        else if (toFind == 0)
            return l;

        while (j < l)
        {
            sum += nums[j];
            if (sum < toFind)
                j++;
            else if (sum == toFind)
            {
                maxLen = max(maxLen, j - i + 1);
                j++;
            }
            else if (sum > toFind)
            {
                while (sum > toFind)
                {
                    sum -= nums[i];
                    i++;
                }
                if (sum == toFind)
                    maxLen = max(maxLen, j - i + 1);
                j++;
            }
        }
        if (maxLen == -1)
            return -1;
        return l - maxLen;
    }
};