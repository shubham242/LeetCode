class Solution
{
public:
    int longestStrChain(vector<string> &words)
    {
        int n = words.size();
        unordered_map<string, int> dp;
        int maxCount = 1;
        sort(words.begin(), words.end(), [](const std::string &first, const std::string &second)
             { return first.size() < second.size(); });

        for (int i = 0; i < n; i++)
        {
            dp[words[i]] = 1;

            for (int j = 0; j < words[i].size(); j++)
            {
                string s = words[i];
                s.erase(s.begin() + j);
                if (dp.find(s) != dp.end())
                    dp[words[i]] = max(dp[words[i]], 1 + dp[s]);
            }
            maxCount = max(maxCount, dp[words[i]]);
        }

        return maxCount;
    }
};