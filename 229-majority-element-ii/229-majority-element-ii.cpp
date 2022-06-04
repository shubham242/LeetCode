class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int count1 = 0;
        int count2 = 0;
        int num1 = -1;
        int num2 = -1;

        for (auto i : nums)
        {
            if (i == num1)
                count1++;
            else if (i == num2)
                count2++;
            else if (count1 == 0)
            {
                num1 = i;
                count1++;
            }
            else if (count2 == 0)
            {
                num2 = i;
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;
        for (auto i : nums)
            if (i == num1)
                count1++;
            else if (i == num2)
                count2++;
        vector<int> res;
        if (count1 > nums.size() / 3)
            res.push_back(num1);
        if (count2 > nums.size() / 3)
            res.push_back(num2);
        return res;
    }
};