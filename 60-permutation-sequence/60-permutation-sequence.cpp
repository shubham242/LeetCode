class Solution
{
public:
    string solve(string s, int index)
    {
        if (index == 0)
            return s;
        int fact = 1;
        for (int i = 1; i < s.size(); i++)
            fact *= i;
        char c = s[index / fact];
        s.erase(s.begin() + index / fact);
        return c + solve(s, index % fact);
    }
    string getPermutation(int n, int k)
    {
        string s;
        for (int i = 0; i < n; i++)
            s += '1' + i;

        return solve(s, k - 1);
    }
};