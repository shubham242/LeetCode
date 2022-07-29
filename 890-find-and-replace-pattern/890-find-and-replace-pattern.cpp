class Solution
{
public:
    string stringToHash(string s)
    {
        int n = s.size();
        string hash = "";
        unordered_map<char, int> mp;
        int count = 1;
        for (int i = 0; i < n; i++)
            if (mp.find(s[i]) == mp.end())
            {
                mp[s[i]] = count;
                hash += '0' + count;
                count++;
            }
            else
                hash += '0' + mp[s[i]];
        return hash;
    }
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        string hash = stringToHash(pattern);
        vector<string> res;
        int n = words.size();
        for (int i = 0; i < n; i++)
            if (stringToHash(words[i]) == hash)
                res.push_back(words[i]);
        return res;
    }
};