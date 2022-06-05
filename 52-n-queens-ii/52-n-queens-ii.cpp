class Solution
{
public:
    int recur(vector<bool> &col, vector<bool> &dia, vector<bool> &adia, int n, int pos)
    {
        int count = 0;
        if (pos == n)
            return 1;

        for (int i = 0; i < n; i++)
        {
            if (!col[i] && !dia[pos + i] && !adia[pos - i + n - 1])
            {
                col[i] = dia[pos + i] = adia[pos - i + n - 1] = true;
                count += recur(col, dia, adia, n, pos + 1);
                col[i] = dia[pos + i] = adia[pos - i + n - 1] = false;
            }
        }
        return count;
    }
    int totalNQueens(int n)
    {
        vector<bool> col(n), dia(2 * n - 1), adia(2 * n - 1);
        return recur(col, dia, adia, n, 0);
    }
};