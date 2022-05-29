class Solution
{
public:
    int maxProduct(vector<string> &words)
    {
        int res = 0;
        int l = words.size();
        int dp[l][26];
        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < 26; j++)
                dp[i][j] = 0;
            for (auto c : words[i])
                dp[i][c - 'a']++;
        }
        for (int i = 0; i < l; i++)
        {
            for (int j = i + 1; j < l; j++)
            {
                bool f = false;
                for (int k = 0; k < 26; k++)
                {
                    if (dp[i][k] > 0 && dp[j][k] > 0)
                    {
                        f = true;
                        break;
                    }
                }
                if (!f)
                    res = max(res, (int)words[i].size() * (int)words[j].size());
            }
        }
        return res;
    }
};