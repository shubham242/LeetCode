class Solution
{
public:
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        int n = arr.size();
        int M = 1e9 + 7;
        long dp[n];
        sort(arr.begin(), arr.end());

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
            mp[arr[i]] = i;

        for (int i = 0; i < n; i++)
        {
            dp[i] = 1;
            for (int j = 0; j < i; j++)
                if (arr[i] % arr[j] == 0 && mp.find(arr[i] / arr[j]) != mp.end())
                    dp[i] += (dp[j] % M * dp[mp[arr[i] / arr[j]]]) % M;
        }

        long ans = 0;
        for (auto i : dp)
            ans += i % M;
        return ans % M;
    }
};