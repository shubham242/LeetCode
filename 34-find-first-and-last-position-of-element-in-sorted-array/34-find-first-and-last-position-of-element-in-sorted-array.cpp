class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> res;
        res.push_back(-1);
        res.push_back(-1);
        if (nums.size() == 0)
            return res;

        res[1] = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        res[0] = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (res[0] >= nums.size() || nums[res[0]] != target)
        {
            res[0] = -1;
            res[1] = -1;
        }
        return res;
    }
};