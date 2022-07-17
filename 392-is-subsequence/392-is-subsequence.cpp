class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int sl = s.size(), tl = t.size();
        int i = 0, j = 0;
        while (j < sl)
        {
            if (i >= tl)
                return false;
            if (s[j] == t[i])
            {
                j++;
                i++;
            }
            else
                i++;
        }
        return true;
    }
};