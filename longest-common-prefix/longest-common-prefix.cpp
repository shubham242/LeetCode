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
        sort(strs.begin(), strs.end());
        return com(strs[0],strs[strs.size()-1]);
    }
};