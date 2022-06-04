class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0;
        int num = -1;

        for (auto i : nums)
        {
            if (count == 0)
                num = i;

            count += (num == i) ? 1 : -1;
        }
        return num;
    }
};