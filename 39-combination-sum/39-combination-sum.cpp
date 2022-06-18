class Solution
{
public:
    void solve(vector<int> &arr, int pos, vector<vector<int>> &ans, vector<int> sum, int N, int target)
    {
        if (target < 0)
            return;
        if (target == 0)
            ans.push_back(sum);

        for (int i = pos; i < N; i++)
        {
            if (i != pos && arr[i] == arr[i - 1])
                continue;
            sum.push_back(arr[i]);
            solve(arr, i, ans, sum, N, target - arr[i]);
            sum.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(candidates, 0, ans, temp, candidates.size(), target);

        return ans;
    }
};