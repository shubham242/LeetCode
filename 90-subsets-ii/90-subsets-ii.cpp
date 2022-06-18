class Solution
{
public:
    struct hashFunction
    {
        size_t operator()(const vector<int> &myVector) const
        {
            hash<int> hasher;
            size_t answer = 0;

            for (int i : myVector)
                answer ^= hasher(i) + 0x9e3779b9 + (answer << 6) + (answer >> 2);

            return answer;
        }
    };

    void solve(vector<int> &arr, int pos, unordered_set<vector<int>, hashFunction> &ans, vector<int> sum, int N)
    {
        if (pos == N)
        {
            sort(sum.begin(), sum.end());
            ans.insert(sum);
            return;
        }
        solve(arr, pos + 1, ans, sum, N);
        sum.push_back(arr[pos]);
        solve(arr, pos + 1, ans, sum, N);
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        unordered_set<vector<int>, hashFunction> v;
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums, 0, v, temp, nums.size());
        for (auto i : v)
            ans.push_back(i);
        return ans;
    }
};