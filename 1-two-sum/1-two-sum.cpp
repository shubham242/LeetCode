class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        int l = nums.size();
        unordered_map<int, int> st;

        for (int i = 0; i < l; i++)
            st[nums[i]] = i + 1;

        for (int i = 0; i < l; i++)
        {
            int x = st[target - nums[i]];
            if (x != 0 && x != i + 1)
            {
                ans.push_back(i);
                ans.push_back(x - 1);
                return ans;
            }
        }
        return ans;
    }
};