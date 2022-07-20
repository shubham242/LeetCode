class Solution
{
public:
    int numMatchingSubseq(string &s, vector<string> &words)
    {
        int ans = 0;
        vector<vector<int>> map(26);
        for (int i = 0; i < s.size(); i++)
            map[s[i] - 'a'].push_back(i);
        for (auto &w : words)
        {
            bool f = true;
            for (int i = 0, prev = -1; f && i < w.size(); i++)
            {
                vector<int> &v = map[w[i] - 'a'];
                auto it = upper_bound(begin(v), end(v), prev);
                if (it == end(v))
                    f = false;
                else
                    prev = *it;
            }
            if (f)
                ans++;
        }
        return ans;
    }
};