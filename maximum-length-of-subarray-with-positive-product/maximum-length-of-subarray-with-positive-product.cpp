class Solution {
public:
    int getMaxLen(vector<int> &nums)
    {
        int res = 0;
        int l = nums.size();
        int negCountr = 0, currMaxr = 0;
        int negCountl = 0, currMaxl = 0;
        for (int i = 0; i < l; i++)
        {
            if (nums[i] == 0)
            {
                currMaxr = 0;
                negCountr = 0;
            }
            else
            {
                if (nums[i] < 0)
                    negCountr++;
                currMaxr++;
                if (negCountr % 2 == 0)
                    res = max(res, currMaxr);
            }
            
            if (nums[l-i-1] == 0)
            {
                currMaxl = 0;
                negCountl = 0;
            }
            else
            {
                if (nums[l-i-1] < 0)
                    negCountl++;
                currMaxl++;
                if (negCountl % 2 == 0)
                    res = max(res, currMaxl);
            }
        }
        return res;
    }
};