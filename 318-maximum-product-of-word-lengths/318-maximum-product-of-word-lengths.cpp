
class Solution
{
public:
    int maxProduct(vector<string> &words)
    {
        int res = 0;
        int l = words.size();
        int dp[l];
        for (int i = 0; i < l; i++)
        {
            string s = "00000000000000000000000000";
            for (auto c : words[i])
                s[c - 'a'] = '1';
            dp[i] = stoi(s, 0, 2);
        }
        for (int i = 0; i < l; i++)
        {
            for (int j = i + 1; j < l; j++)
            {
                if ((dp[i] & dp[j]) == 0)
                    res = max(res, (int)words[i].size() * (int)words[j].size());
            }
        }
        return res;
    }
};