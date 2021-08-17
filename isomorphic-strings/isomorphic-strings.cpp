class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        vector<char> vs(256, '\0');
        vector<char> vt(256, '\0');

        for (int i = 0; i < s.size(); i++)
        {
            if (vs[s[i]] == '\0')
                vs[s[i]] = t[i];
            else if (vs[s[i]] != t[i])
                return false;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (vt[t[i]] == '\0')
                vt[t[i]] = s[i];
            else if (vt[t[i]] != s[i])
                return false;
        }
        return true;
    }
};
