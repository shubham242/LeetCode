class Solution
{
public:
    bool isCon(string s, unordered_map<string, int> mp, int l)
    {
        int count = 0;
        for (int i = 0; i < s.size();)
        {
            string t = s.substr(i, l);
            if (mp.find(t) == mp.end())
                return false;
            mp[t]--;
            i += l;
        }
        for (auto i : mp)
            if (i.second != 0)
                return false;
        return true;
    }
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> res;
        int l = words[0].size() * words.size();
        unordered_map<string, int> mp;
        for (auto w : words)
            if (mp.find(w) != mp.end())
                mp[w]++;
            else
                mp[w] = 1;

        for (int i = 0; i <= ((int)s.size() - l); i++)
            if (isCon(s.substr(i, l), mp, words[0].size()))
                res.push_back(i);
        return res;
    }
};