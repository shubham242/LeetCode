class Solution
{
public:
    void solve(vector<int> s, vector<int> hash, int count, vector<vector<int>> &ans, vector<int> curr)
    {
        if (count == s.size())
        {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (hash[i] == 0)
            {
                hash[i] = 1;
                curr[count] = s[i];
                solve(s, hash, count + 1, ans, curr);
                hash[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {

        vector<vector<int>> ans;
        vector<int> hash(nums.size(), 0);
        vector<int> temp(nums.size(), 0);
        solve(nums, hash, 0, ans, temp);
        return ans;
    }
};