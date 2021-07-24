bool sortcol(const string &v1, const string &v2)
{
    return v1.size() < v2.size();
}

class Solution
{
public:
    string com(string &s1, string &s2)
    {
        int i;
        for (i = 0; i < min(s1.size(), s2.size()); i++)
        {
            if (s1[i] != s2[i])
                break;
        }
        return s1.substr(0, i);
    }
    string longestCommonPrefix(vector<string> &strs)
    {
        sort(strs.begin(), strs.end(), sortcol);
        int i;
        for (i = 0; i < strs[0].size(); i++)
        {
            int f = 0;
            for (int j = 1; j < strs.size(); j++)
            {
                if (strs[j][i] != strs[0][i])
                {
                    f = 1;
                    break;
                }
            }
            if (f)
                break;
        }
        return strs[0].substr(0, i);
    }
};