class Solution
{
public:
    bool isP(string s)
    {
        string t = s;
        reverse(t.begin(), t.end());
        return t == s;
    }
    int removePalindromeSub(string s)
    {
        if (isP(s))
            return 1;
        else
            return 2;
    }
};