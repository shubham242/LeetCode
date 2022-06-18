class Solution
{
public:
    bool isPal(string s)
    {
        int i = 0;
        int j = s.size() - 1;
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(string s, int pos, int N, vector<vector<string>> &ans, vector<string> part)
    {
        if (N == pos)
        {
            ans.push_back(part);
            return;
        }

        for (int i = 1; i <= N - pos; i++)
        {
            if (isPal(s.substr(pos, i)))
            {
                part.push_back(s.substr(pos, i));
                solve(s, pos + i, N, ans, part);
                part.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> temp;

        solve(s, 0, s.size(), ans, temp);

        return ans;
    }
};