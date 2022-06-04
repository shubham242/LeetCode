class Solution
{
public:
    bool isSafe(vector<string> &a, int i, int j, int n)
    {
        bool f = true;
        for (int k = 1; i - k >= 0 || j + k < n || j - k >= 0; k++)
            if ((i - k >= 0 && j - k >= 0 && a[i - k][j - k] == 'Q') || (i - k >= 0 && a[i - k][j] == 'Q') || (i - k >= 0 && j + k < n && a[i - k][j + k] == 'Q'))
            {
                f = false;
                break;
            }

        return f;
    }
    void recur(vector<string> &a, vector<vector<string>> &ans, int n, int pos)
    {
        if (pos == n)
        {
            ans.push_back(a);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (isSafe(a, pos, i, n))
            {
                a[pos][i] = 'Q';
                recur(a, ans, n, pos + 1);
                a[pos][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> a;
        for (int i = 0; i < n; i++)
        {
            string s(n, '.');
            a.push_back(s);
        }

        recur(a, ans, n, 0);
        return ans;
    }
};