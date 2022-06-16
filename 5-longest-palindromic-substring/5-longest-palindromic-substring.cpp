class Solution
{
public:
    void solve(string &s, int l, int r, int n, int *ans, int *ansL, int *ansR)
    {
        if (l < 0 || r >= n)
            return;
        if (s[l] == s[r])
        {
            if (r - l + 1 > *ans)
            {
                *ansL = l;
                *ansR = r;
                *ans = r - l + 1;
            }
            solve(s, l - 1, r + 1, n, ans, ansL, ansR);
        }
    }
    string longestPalindrome(string s)
    {
        int l = 0, r = 0, ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            solve(s, i, i, n, &ans, &l, &r);
            solve(s, i, i + 1, n, &ans, &l, &r);
        }

        return s.substr(l, r - l + 1);
    }
};
