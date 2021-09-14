class Solution {
public:
    
    bool canJump(vector<int> &nums)
    {
        int l = nums.size();
        for (int i = 0; i < l; i++)
        {
            if (i != l - 1 && nums[i] == 0)
            {
                bool f = false;
                for (int j = i - 1; j >= 0; j--)
                {
                    if (i - j < nums[j])
                    {
                        f = true;
                        break;
                    }
                }
                if (!f)
                    return false;
            }
        }
        return true;
    }
};