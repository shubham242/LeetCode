class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        int l = nums.size();
        unordered_map<int, int> st;

        for (int i = 0; i < l; i++)
        {
            if (st.find(target - nums[i]) != st.end())
            {
                ans.push_back(i);
                ans.push_back(st[target - nums[i]]);
                return ans;
            }
            st[nums[i]] = i;
        }
        return ans;
    }
};